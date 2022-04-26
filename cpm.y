%{
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


char Errors[1000];
int ErrorNum = 1;
extern FILE *yyout;

void yyerror(char* s);
extern int line;           /* line in source text where ID appears */
extern int col;		/* column in source text where ID appears */
extern int yylex(void);
int yywrap(){return 1;}


/* symbol table definition */

typedef struct symbolTable{                  /* symbol table struct */
	char *name;	                    // id name
	char *type;	                   // symbol type							
	int isDeclared;			  // If the variable is declare = 1, else 0 					
	int isConst;			 // If the variable is const = 1, else 0 								
	int isInit;			// If the variable is initialized = 1, else 0 				
	struct symbolTable *next;      // next origin in linked list
}symbol;


//functions
char* StringCat(char* first, char* sec);
char* getLabelNumber();
char* getTempRegister();
char* getFloatRegister();
void freeTempRegister(char* reg);
void freeFloatRegister(char* reg);
void PrintListingErrors(char* s);
char* MIPSCode;
char* sReg;
/* method declarations */
symbol* installSymTable (char *name, char *type, int isConst);
symbol* lookup(char *name);





/* ErrorFlag = 0 - there are no errors, ErrorFlag = 1 - there is error */
int ErrorFlag=0;


%}


%locations

%union{
       struct number{
	             char* type;
	             union{
		           int ival;		/* for int type */					  
		           float fval;		/* for float type */					 
	                  }val;
                    }number;
       struct declar{
                     int ival;			/* for int type */
	             float fval;		/* for float type */
	             char *type;
	             char *reg;
		     char *varList[4];		/* for list of variables */
	             char *label;
	             char *headCode;
	             char *bodyCode;
                    }dec;
       struct mipsCode{
	               char *label;
	               char *head;
	               char *body;
                      }mips;
       enum{PLUS,MINUS,MUL,DIV,ASSIGN,OR,AND,EQ,NEQ,LT,GT,GTEQ,LTEQ} op;
       char* sval;
      }


%token <sval> ID SENTENCE
%token <op> ADDOP MULOP ASSIGNOP OROP ANDOP RELOP
%token <number> NUM 
%token BGN BREAK CASE FINAL DEFAULT DO ELSE END FOREACH IF INT LET OUT PROGRAM REAL READ STRING SWITCH TILL VAR WHILE WITH
%left ADDOP MULOP OROP ANDOP RELOP
%right ASSIGNOP

%type <dec> expression term factor declarations declarlist list decl cdecl TYPE switch choice cases boolexpr boolterm boolfactor 
%type <mips> stmtlist stmt assignment_stmt out_stmt read_stmt control_stmt stmt_block step


%% 


program: PROGRAM ID BGN declarations stmtlist END {fprintf(stderr, "program done\n");} 
{	 

	 if(ErrorFlag == 0)
	 {
	 	char* s = (char*)malloc(sizeof(char*)*1000);
		s[0]='\0';
		if($5.head==NULL)
		   $5.head="";
		if($4.bodyCode==NULL)
		   $4.bodyCode="";
		sprintf(s,".data\n%s\n%s\nstrBuff: .space 200\n.text\nmain:\n%s\n%s\n",$4.headCode,$5.head,$4.bodyCode,$5.body);
		MIPSCode = s; 
	 
	 }
}
	 | error ID BGN declarations stmtlist END {PrintListingErrors("program is missing"); }
	 | PROGRAM error BGN declarations stmtlist END {PrintListingErrors("id is missing");}
	 | PROGRAM ID error declarations stmtlist END {PrintListingErrors("bgn is missing");}
	 | PROGRAM ID BGN error stmtlist END {PrintListingErrors("declarations is missing");}
	 | PROGRAM ID BGN declarations error END {PrintListingErrors("stmtlist is missing");}
	 | PROGRAM ID BGN declarations stmtlist error {PrintListingErrors("end is missing");}
	 | error ID error{PrintListingErrors("program unexpected error");}
	 
;


declarations: LET declarlist cdecl {fprintf(stderr, " declarations done\n");}
	    {
		    $$.headCode = strdup(strcat($2.headCode,$3.headCode));
		    $$.bodyCode = strdup($3.bodyCode);
	    }
	    | {printf("DECLARATIONS -> empty \n");}
	    {
		    $$.headCode = strdup(""); 
		    $$.bodyCode = strdup("");
	    }
	    | error declarlist cdecl {PrintListingErrors("let is missing from declarations");}
	    | LET error cdecl {PrintListingErrors("declaration list is missing from declarations");}
	    | LET declarlist error {PrintListingErrors("code declaration is missing from declarations");}
;


declarlist: declarlist decl {fprintf(stderr, " declarlist done\n");}
	    {
		   $$.headCode = StringCat($1.headCode,$2.headCode);
	    } 
	    | decl {fprintf(stderr, " declarlist -> decl done \n");}
	    {
		   $$.headCode = strdup($1.headCode);
	    }
	    | error {PrintListingErrors("decl is missing from declarations");}
	    | error decl {PrintListingErrors("declaration list is missing from declarations");}
	    | declarlist error {PrintListingErrors("declaration is missing from declarations");}
;

decl: TYPE ':' list {fprintf(stderr, " decl done\n");}
{
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStrTmp = (char*)malloc(sizeof(char)*256);
	 headCodeStr[0]='\0';
	 headCodeStrTmp[0]='\0';
	
	 int i;

	 for(i = 0 ; i < 3 ; i++)
	 {
	  if($3.varList[i] != NULL)
	  {
	   if(lookup($3.varList[i]) == NULL)
	   {
	    installSymTable($3.varList[i],$1.type,0);
	    if(!strcmp($1.type,"string"))
	    {
	     sprintf(headCodeStrTmp,"%s: .space 200\n",$3.varList[i]);
	     strcat(headCodeStr,headCodeStrTmp);
	    }
	    else
	    {
	     sprintf(headCodeStrTmp,"%s: .space 8\n",$3.varList[i]);
	     strcat(headCodeStr,headCodeStrTmp);
	    }
	   }
	  }
	 }
	
	$$.headCode = strdup(headCodeStr);
	free(headCodeStr);
	free(headCodeStrTmp);
}
    | error ':' list {PrintListingErrors("unknown type");}
    | TYPE error list {PrintListingErrors("colon is missing");}
    | TYPE ':' error {PrintListingErrors("decl unexpected error");}
;




list: ID ',' list {fprintf(stderr, "list done\n");}
{
	symbol* symPointer = lookup($1);
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat($1,"is multiply defined"));
		}
	}
	else
	{
		int i, j;
		 for(i = 0 ; i < 3 ; i++)
		 {
		  if($$.varList[i] == NULL)
		  {
		   $$.varList[i] = $1;
		   for(j = 0 ; j < 3 ; j++)
		   {
		     if($3.varList[i] != NULL)
		     {
		      $$.varList[i+1] = $3.varList[j];
		      i++;
		     }
		   }
		   break;
		  }
		 }
		//print error if list try to be more then 3 origans
		 if ($3.varList[3] != NULL)
		 {
			PrintListingErrors("List can be only with 3 origans");
		 }
	}
	

}
| ID ';' {fprintf(stderr, "ID in list done\n");} 
{
	symbol* symPointer = lookup($1);
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat($1,"is multiply defined"));
		}
	}
	else
	{

	 printf("LIST -> ID ';' \n");
	 int i;
	 for(i = 0 ; i < 3 ; i++)
	 {
	  if($$.varList[i] == NULL)
	  {
	   $$.varList[i] = $1;
	   break;
	  }
	 }
	}
}
    | error ';' {PrintListingErrors("ID befor semicolon is missing");}
    | ID error {PrintListingErrors(StringCat("semicolon is missing after ",$1));}
    | error ',' list {PrintListingErrors("ID is missing from list");}
    | ID error list {PrintListingErrors("missing ',' in list of variables");}
    | ID ',' error {PrintListingErrors(StringCat($1," is missing after ','"));}
   
;

TYPE: INT {fprintf(stderr, "TYPE -> INT \n");}
    {
	$$.type = strdup("int");
    }
    | REAL {fprintf(stderr, "TYPE -> REAL \n");}
    {
	$$.type = strdup("float");
    }
    | STRING {fprintf(stderr, "TYPE -> STRING \n");}
    {
	$$.type = strdup("string");
    }
    | error {PrintListingErrors("unknown type");}
;

cdecl: FINAL TYPE ID ASSIGNOP NUM ';' cdecl {fprintf(stderr, " cdecl done\n");}
{
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 headCodeStr[0]='\0';
	 bodyCodeStr[0]='\0';

	symbol* symPointer = lookup($3);
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat($3," is multiply defined."));
		}

		if(!strcmp(symPointer->type,"string"))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat($3," type must be int or float. it is allready string type. "));
		}

		if(!(strcmp(symPointer->type,"int") && !strcmp($5.type,"float")))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat($3," type is int and NUM type is float, need to be same type"));
		}
		if(!(strcmp(symPointer->type,"float") && !strcmp($5.type,"int")))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat($3," type is float and NUM type is int, need to be same type"));
		}

	}

	else
	{
		{fprintf(stderr, " ErrorFlag == 0 in cdecl\n");}
		if(strcmp($2.type,"int")==0)
		{
			sprintf(bodyCodeStr,"li $t0,%d\nsw $t0, %s\n",$5.val,$3);
		}

		else
		{
			sprintf(headCodeStr,"%s: .space 8\n",$3);
		}


	}

	installSymTable($3,$2.type,1);
	$$.headCode = StringCat(headCodeStr,$7.headCode);
	$$.bodyCode = StringCat(bodyCodeStr,$7.bodyCode);

}
  
      | error ID ASSIGNOP NUM ';' cdecl {PrintListingErrors("unknown type");}
      | TYPE error ASSIGNOP NUM ';' cdecl {PrintListingErrors("ID is missing");}
      | TYPE ID error NUM ';' cdecl {PrintListingErrors("assignment operation is missing");}
      | TYPE ID ASSIGNOP error ';' cdecl {PrintListingErrors("number is missing to the right side of the asssignment opeation");}
      | TYPE ID ASSIGNOP NUM error cdecl {PrintListingErrors("semicolon is missing");}
      | TYPE ID ASSIGNOP NUM ';' error {PrintListingErrors("cdecl unexpected error");}
      | {fprintf(stderr, " cdecl is empty\n");}
      {
	$$.headCode = strdup(""); $$.bodyCode = strdup("");
      }
      | error {PrintListingErrors("decleration is empty");}
      {
	$$.headCode = strdup(""); $$.bodyCode = strdup("");
      }


;



stmtlist: stmtlist stmt {fprintf(stderr, " stmtlist done\n");} 
	{
		$$.body = StringCat($1.body,$2.body);
	}
	| stmt {fprintf(stderr, "stmtlist -> stmtlist is epsilon, and we got stmt\n");}
	{
		$$.head = strdup($1.head); $$.body = strdup($1.body);
	}

	| error stmt {PrintListingErrors("stmtlist is missing ");}
	| stmtlist error {PrintListingErrors("stmt is missing ");}
	| {fprintf(stderr, "stmtlist -> empty\n");}

;

stmt: assignment_stmt {fprintf(stderr, " stmt->assignment_stmt done \n");}
    {
	 $$.head = strdup($1.head);
	 $$.body = strdup($1.body);
    }
    | ID ASSIGNOP SENTENCE ';' {fprintf(stderr, " stmt done \n");}
    {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg = getTempRegister();
	 bodyCodeStr[0]='\0';
	 headCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 symbol* symPointer = lookup($1);
	 if (symPointer !=NULL)
	 {
	  if(!symPointer->isDeclared)
	  {
	  PrintListingErrors(StringCat($1," must declare before assignment!"));   
	  sprintf(bodyCodeStr,"");
	 
	  }
	  else if(symPointer->isConst == 0)
	  {
	   if(!strcmp(symPointer->type,"string"))
	   {
	    sprintf(headCodeStr,"%s: .asciiz %s\n",label,$3);
	    sprintf(bodyCodeStr,"lw %s, %s\nsw %s, %s\n",reg,label,reg,$1);
	   }
	   else
	   {
	    PrintListingErrors("illegal assignment (assigning string to real or int)");
	    sprintf(bodyCodeStr,"");
	   
	   }
	  }
	  else
	  {
	   if(!strcmp(symPointer->type,"int"))
	   {
	   PrintListingErrors("illegal assignment (assigning string to int)");
	   sprintf(bodyCodeStr,"");
	  
	   }
	   if(!strcmp(symPointer->type,"float"))
	   {
	   PrintListingErrors("illegal assignment (assigning string to real)");
	   sprintf(bodyCodeStr,"");
	  
	   }
	  }
	 }
	 else
	 {
	 PrintListingErrors("symbol table is null");
	 sprintf(bodyCodeStr,"");
	
	 }

	 freeTempRegister(reg);
	 $$.head = strdup(headCodeStr);
	 $$.body = strdup(bodyCodeStr);
	 free(headCodeStr);
	 free(bodyCodeStr);
    }
    | control_stmt {fprintf(stderr, " stmt->control_stmt done \n");}
    {
	 $$.head = strdup($1.head);
	 $$.body = strdup($1.body);
	 fprintf(stderr, " we on stmt->control stmt\n");
    }
    | read_stmt {fprintf(stderr, " stmt->read_stmt done \n");}
    {
	 $$.body = strdup($1.body);	
    }
    | out_stmt {fprintf(stderr, " stmt->out_stmt done \n");}
    {
	 $$.head = strdup($1.head);
	 $$.body = strdup($1.body);
    }
    | stmt_block {fprintf(stderr, " stmt->stmt_block done \n");}
    {
	 $$.head = strdup($1.head);
	 $$.body = strdup($1.body);
    }
    | error {PrintListingErrors("assignment_stmt or control_stmt or read_stmt or out_stmt or stmt_block is missing ");}
    | error ASSIGNOP SENTENCE ';' {PrintListingErrors("ID is missing ");}
    | ID error SENTENCE ';' {PrintListingErrors("ASSIGNOP is missing ");}
    | ID ASSIGNOP error ';' {PrintListingErrors("SENTENCE is missing ");}
    | ID ASSIGNOP SENTENCE error {PrintListingErrors("';' is missing ");}
;


out_stmt: OUT '(' expression ')' ';' {fprintf(stderr, " out_stmt -> out(expression) done \n");}
      {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 bodyCodeStr[0]='\0';
		 if(!strcmp($3.type,"int"))
		 {
		    fprintf(stderr, " int in out_stmt - > out\n");
		    sprintf(bodyCodeStr,"li $v0,1\nmove $a0,%s\n syscall\n",$3.reg);
		  }
		 else if(!strcmp($3.type,"float"))
		 {
		    fprintf(stderr, " int in out_stmt - > out\n");
		    sprintf(bodyCodeStr,"li $v0,2\nmove $f12,%s\n syscall\n",$3.reg);
		  }
		 else{
		   fprintf(stderr, " type  :  %s \n", $3.type);
	            }

		 $$.head = $3.headCode;
		 $$.body = StringCat($3.bodyCode,bodyCodeStr);
		 free(bodyCodeStr);
      }
      | OUT '(' SENTENCE ')' ';' {fprintf(stderr, " out_stmt -> out(sentence) done \n");}
      {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* headCodeStr = (char*)malloc(sizeof(char)*256);
		 char* label = getLabelNumber();
		 bodyCodeStr[0]='\0';
		 headCodeStr[0]='\0';
		 sprintf(headCodeStr,"%s: .asciiz %s\n",label,$3);
		 sprintf(bodyCodeStr,"la $a0,%s\nli $v0,4\nsyscall\n",label);
		 $$.head = strdup(headCodeStr);
		 $$.body = strdup(bodyCodeStr);
		 free(headCodeStr);
		 free(bodyCodeStr);
      }
      | error '(' expression ')' ';' {PrintListingErrors("OUT is missing");}
      | OUT error expression ')' ';' {PrintListingErrors("'(' is missing");}
      | OUT '(' error ')' ';' {PrintListingErrors("expression or sentence is missing");}
      | OUT '(' expression error ';' {PrintListingErrors("')' is missing");}
      | OUT '(' expression ')' error {PrintListingErrors("';' is missing");}
      | error '(' SENTENCE ')' ';' {PrintListingErrors("OUT is missing");}
      | OUT error SENTENCE ')' ';' {PrintListingErrors("'(' is missing");}
      | OUT '(' SENTENCE error ';' {PrintListingErrors("')' is missing");}
      | OUT '(' SENTENCE ')' error {PrintListingErrors("\';\' is missing");}
      | OUT error {PrintListingErrors("expression is empty.");}
;


read_stmt: READ '(' ID ')' ';' {fprintf(stderr, " read_stmt done \n");}
	{
		char* bodyCodeStr = (char*)malloc(sizeof(char)*256);	
		bodyCodeStr[0]='\0';
		symbol* symPointer = lookup($3);
		if(symPointer != NULL)
		{
			if(!symPointer->isDeclared)
			{
				
				sprintf(bodyCodeStr,"");

				PrintListingErrors(StringCat($3," is not declared!"));
			}
			else if(symPointer->isConst)
			{
				
				sprintf(bodyCodeStr,"");
				PrintListingErrors("illegal assignment .can not assign to constant!");
			}

			else
			{
			   symPointer->isInit = 1;
			   if(!strcmp(symPointer->type,"int"))
			    sprintf(bodyCodeStr,"li $v0,5\nsyscall\nsw $v0, %s\n",symPointer->name);
			   if(!strcmp(symPointer->type,"float"))
			    sprintf(bodyCodeStr,"li $v0,6\nsyscall\ns.s $f0, %s\n",symPointer->name);
			   if(!strcmp(symPointer->type,"string"))
			   {
			    strcat(bodyCodeStr,"li $v0,8\nla $a0,");
			    strcat(bodyCodeStr,symPointer->name);
			    strcat(bodyCodeStr,"\nli $a1,200\nsyscall\n");
			   }
			}
		}
		else
		{
				sprintf(bodyCodeStr,"");
				PrintListingErrors(StringCat($3," is not found in symbol table"));
		}
		$$.body = strdup(bodyCodeStr);

	}


| error '(' ID ')' ';' {PrintListingErrors("READ is missing ");}
| READ error ID ')' ';' {PrintListingErrors("'(' is missing ");}
| READ '(' error ')' ';' {PrintListingErrors("ID is missing ");}
| READ '(' ID error ';' {PrintListingErrors("')' is missing ");}
| READ '(' ID ')' error {PrintListingErrors("';' is missing ");}

;



assignment_stmt: ID ASSIGNOP expression {fprintf(stderr, " assignment_stmt done \n");}
{
 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
 bodyCodeStr[0]='\0';
 char* reg;
 symbol* symPointer = lookup($1);
 if (symPointer != NULL)
 {
	if(symPointer->isConst)
	{
		sprintf(bodyCodeStr,"");
		PrintListingErrors("illegal assignment. can not assign to constant!");
	}
	else if(!symPointer->isDeclared)
	{
		sprintf(bodyCodeStr,"");
		PrintListingErrors(StringCat($1," is not decleare"));
	}
	else
	{
		   symPointer->isInit = 1 ;
		   if(!strcmp($3.type,"int") && !strcmp($3.type,symPointer->type))
		   {
			    sprintf(bodyCodeStr,"sw %s, %s\n",$3.reg,$1);
			    freeTempRegister($3.reg);
		   }	
		   else if(!strcmp($3.type,"float") && !strcmp($3.type,symPointer->type))
		   {
			    sprintf(bodyCodeStr,"s.s %s, %s\n",$3.reg,$1);
			    freeFloatRegister($3.reg);
		   }
		   else
		   {
			    if(!strcmp($3.type,"int") && !strcmp("float",symPointer->type))
			    {
				     reg = getFloatRegister();
				     sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ns.s %s, %s\n",$3.reg,reg,reg,reg,reg,$1);
				     freeTempRegister($3.reg);
				     freeFloatRegister(reg);
			    }
			    else
			    {
			             symPointer->isInit = 0 ;
				     PrintListingErrors("illegal assignment. can not convert from real to integer");
				     sprintf(bodyCodeStr,"");
				    
			    }
		   }

	}

 }
 else
 {
	sprintf(bodyCodeStr,"");
	PrintListingErrors(StringCat($1," is not found in symbol table"));
 }

 $$.head = strdup($3.headCode);
 $$.body = StringCat($3.bodyCode,bodyCodeStr);
 free(bodyCodeStr);

}
| error ASSIGNOP expression {PrintListingErrors("ID is missing ");}
| ID error expression {PrintListingErrors("ASSIGNOP is missing ");}
| ID ASSIGNOP error {PrintListingErrors("expression is missing ");}
;



control_stmt: IF '(' boolexpr ')' stmt ELSE stmt {fprintf(stderr, "control_stmt -> if (BOOLEXPR) STMT else STMT \n");}
	    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen($5.body)+ strlen($7.body)));
		 char* label = getLabelNumber();
		 char* s;
		 bodyCodeStr[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0,Else%s\n%s\nj End%s\nElse%s:\n%s\nEnd%s:\n",$3.reg,label,$5.body,label,label,$7.body,label);	
		 s = StringCat($5.head,$7.head);
		 $$.head = StringCat($3.headCode,s);
		 $$.body = StringCat($3.bodyCode,bodyCodeStr);
		 freeTempRegister($3.reg);
		 free(s);
		 free(bodyCodeStr);
	    }

	    | WHILE '(' boolexpr ')' stmt_block {fprintf(stderr, "control_stmt -> while (BOOLEXPR) STMT_BLOCK \n");}
	    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen($5.body)));
		 char* label = getLabelNumber();
		 char* s = (char*)malloc(sizeof(char)*(50 + strlen($3.bodyCode)));
		 bodyCodeStr[0]='\0';
		 s[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n",$3.reg,label,$5.body,label,label);
		 sprintf(s,"Loop%s:\n",label);
		 strcat(s,$3.bodyCode);
		 $$.head = StringCat($3.headCode,$5.head);
		 $$.body = StringCat(s,bodyCodeStr);
		 freeTempRegister($3.reg);
		 free(s);
		 free(bodyCodeStr);
	    }

	    | FOREACH ID ASSIGNOP NUM ':' NUM WITH step stmt {fprintf(stderr, "control_stmt -> foreach id assignop num:num with STEP STMT  \n");}
	    {

		char* strBeq = (char*)malloc(sizeof(char)*(256));
		char* strli = (char*)malloc(sizeof(char)*(256));
		char* labelNum = getLabelNumber();
		char* tmpForBody;
		char* startPoint = $8.head; // return the generated register
		char* targetPoint = getTempRegister();
		
		strli[0]='\0';
		strBeq[0]='\0';

		sprintf(strli, "li %s, %d \nli %s, %d \nLoop%s:\n",startPoint,$4.val,targetPoint,$6.val,labelNum);
		sprintf(strBeq,"beq %s, %s, End%s\n%s\n j Loop%s \nEnd%s:\n",startPoint,targetPoint,labelNum,$8.body,labelNum,labelNum);

		tmpForBody = StringCat(strli, $9.body); 
		$$.body = StringCat(tmpForBody, strBeq);
		$$.head=strdup("");

		freeTempRegister(targetPoint);
		freeFloatRegister(startPoint);
		free(strli);
		free(tmpForBody);
		free(strBeq);
		

	    }


	    | FOREACH ID ASSIGNOP NUM ':' ID WITH step stmt {fprintf(stderr, "control_stmt -> foreach id assignop num:id with STEP STMT  \n");}
	    {
			char* strBeq = (char*)malloc(sizeof(char)*(256));
			char* strli = (char*)malloc(sizeof(char)*(256));
			char* labelNum = getLabelNumber();
			char* tmpForBody;
			char* startPoint = $8.head; // return the generated register
			char* targetPoint = getTempRegister();
			
			// create loop variable
			installSymTable($2,"int",0);

			
			strBeq[0]='\0';
			strli[0]='\0';
			
			// str hold to counter increasment
			sprintf(strli, "li %s, %d \nlw %s, %s \nLoop%s:\n",startPoint,$4.val,targetPoint,$6,labelNum);

			
			sprintf(strBeq,"beq %s, %s, End%s\n%s\n j Loop%s \nEnd%s:\n",startPoint,targetPoint,labelNum,$8.body,labelNum,labelNum);

			

			tmpForBody = StringCat(strli, $9.body); // $9(STMT) - body/code of loop
			$$.body = StringCat(tmpForBody, strBeq);
			$$.head=strdup("");

			freeTempRegister(targetPoint);
			freeTempRegister(startPoint);
			free(strli);
			free(tmpForBody);
			free(strBeq);
			


	    }

	    | DO stmt_block TILL '(' boolexpr ')' {fprintf(stderr, "control_stmt -> do STMT_BLOCK till (BOOLEXPR)  \n");}
	    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen($2.body)));
		 char* labelNum = getLabelNumber();
		 char* s = (char*)malloc(sizeof(char)*(50 + strlen($5.bodyCode)));
		 bodyCodeStr[0]='\0';
		 s[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n",$5.reg,labelNum,$2.body,labelNum,labelNum);
		 sprintf(s,"Loop%s:\n",labelNum);
		 strcat(s,$5.bodyCode);
		 $$.head = StringCat($5.headCode,$2.head);
		 $$.body = StringCat(s,bodyCodeStr);
		 freeTempRegister($5.reg);
		 free(s);
		 free(bodyCodeStr);
	    }

	    | switch {fprintf(stderr, "control_stmt -> switch \n");}
	    {
		 $$.head = strdup($1.headCode);
		 $$.body = strdup($1.bodyCode);
	    }

	    | error '(' boolexpr ')' stmt ELSE stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : if is missing  ");}
	    | IF error boolexpr ')' stmt ELSE stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : '(' is missing  "); fprintf(stderr, "control_stmt -> '(' is missing \n");}
	    | IF '(' error ')' stmt ELSE stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : boolexpr is missing  ");}
	    | IF '(' boolexpr error stmt ELSE stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : ')' is missing  ");}
	    | IF '(' boolexpr ')' error ELSE stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : stmt after '(' is missing  ");}
	    | IF '(' boolexpr ')' stmt error stmt {PrintListingErrors("if (BOOLEXPR) STMT else STMT : else is missing  ");}

	    | error '(' boolexpr ')' stmt_block {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: while is missing  ");}
	    | WHILE error boolexpr ')' stmt_block {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: '(' is missing  ");}
	    | WHILE '(' error ')' stmt_block {PrintListingErrors("(BOOLEXPR) STMT_BLOCK: boolexpr is missing  ");}
	    | WHILE '(' boolexpr error stmt_block {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: ')' is missing  ");}
	    | WHILE '(' boolexpr ')' error {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: stmt_block is missing  ");}

	    | error ID ASSIGNOP NUM ':' NUM WITH step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : foreach is missing  ");}
	    | FOREACH error ASSIGNOP NUM ':' NUM WITH step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : id is missing  ");}
	    | FOREACH ID error NUM ':' NUM WITH step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : assignop is missing  ");}
	    | FOREACH ID ASSIGNOP error ':' NUM WITH step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : num after assignop  is missing  ");}
	    | FOREACH ID ASSIGNOP NUM error NUM WITH step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : ':'  is missing  ");}
	    | FOREACH ID ASSIGNOP NUM ':' NUM error step stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : with is missing  ");}
	    | FOREACH ID ASSIGNOP NUM ':' NUM WITH error stmt {PrintListingErrors("foreach id assignop num:num with STEP STMT : step is missing  ");}

	    | error ID ASSIGNOP NUM ':' ID WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : foreach is missing  ");}
	    | FOREACH error ASSIGNOP NUM ':' ID WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : id after foreach is missing  ");}
	    | FOREACH ID error NUM ':' ID WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : assignop is missing  ");}
	    | FOREACH ID ASSIGNOP error ':' ID WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : num after assignop  is missing  ");}
	    | FOREACH ID ASSIGNOP NUM error ID WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : ':'  is missing  ");}
	    | FOREACH ID ASSIGNOP NUM ':' error WITH step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : id or num is missing  ");}
	    | FOREACH ID ASSIGNOP NUM ':' ID error step stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : with is missing  ");}
	    | FOREACH ID ASSIGNOP NUM ':' ID WITH error stmt {PrintListingErrors("foreach id assignop num:id with STEP STMT : step is missing  ");}
	    
	    | error stmt_block TILL '(' boolexpr ')' {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) :do is missing  ");}
	    | DO error TILL '(' boolexpr ')' {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : stmt_block is missing  ");}
	    | DO stmt_block error '(' boolexpr ')' {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : till is missing  ");}
	    | DO stmt_block TILL error boolexpr ')' {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : '(' is missing  ");}
	    | DO stmt_block TILL '(' error ')' {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : boolexpr is missing  ");}
	    | DO stmt_block TILL '(' boolexpr error  {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : ')' is missing  ");}


;


stmt_block: '{' stmtlist '}' {fprintf(stderr, " stmt_block done \n");}
    {
	 $$.head = strdup($2.head);
	 $$.body = strdup($2.body);
    }
    | error stmtlist '}' {PrintListingErrors("'{' is missing ");}
    | '{' error '}' {PrintListingErrors("stmtlist is missing ");}
    | '{' stmtlist error {PrintListingErrors("'}' is missing ");}
;



switch: SWITCH '(' choice ')' '{' cases '}' {fprintf(stderr, " switch (CHOICE) { CASES }\n");}
      {
	 $$.bodyCode = StringCat($3.bodyCode,$6.bodyCode);
	 $$.headCode = StringCat($3.headCode,$6.headCode);
      }
      | error '(' choice ')' '{' cases '}' {PrintListingErrors("switch (CHOICE) { CASES } : switch is missing  ");}
      | switch error choice ')' '{' cases '}' {PrintListingErrors("switch (CHOICE) { CASES } : '(' is missing ");}
      | switch '(' error ')' '{' cases '}' {PrintListingErrors("switch (CHOICE) { CASES } : choice is missing ");}
      | switch '(' choice error '{' cases '}' {PrintListingErrors("switch (CHOICE) { CASES } : ')' is missing ");}
      | switch '(' choice ')' error cases '}' {PrintListingErrors("switch (CHOICE) { CASES } : '{' is missing ");}
      | switch '(' choice ')' '{' error '}' {PrintListingErrors("switch (CHOICE) { CASES } :  cases is missing");}
      | switch '(' choice ')' '{' cases error {PrintListingErrors("switch (CHOICE) { CASES } : '}' is missing");}

;



choice: ID 
{
	fprintf(stderr, "CHOICE -> ID \n");
	char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	char* reg;
	symbol* symPointer = lookup($1);
	bodyCodeStr[0]='\0';

	if(symPointer == NULL)
	{
		PrintListingErrors("unknown type in symbol table");
	}
	else
	{
		if(!strcmp(symPointer->type,"int"))
		{
		 sprintf(bodyCodeStr,"lw $s1,%s\n",$1);
		}
		else
		{
		 reg = getFloatRegister();
		 sprintf(bodyCodeStr,"l.s %s,%s\n",reg,$1);
		}
		$$.headCode = strdup("");
		$$.bodyCode = strdup(bodyCodeStr);
		free(bodyCodeStr);
	}
}

| NUM 
{
	printf("CHOICE -> NUM \n");
	char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	char* headCodeStr = (char*)malloc(sizeof(char)*256);
	char* reg;
	bodyCodeStr[0]='\0';
	headCodeStr[0]='\0';
	if(!strcmp($1.type,"int"))
	{
	 sprintf(bodyCodeStr,"li $s1,%d\n",$1.val);
	}
	else
	{
	 reg = getFloatRegister();
	 char* label = getLabelNumber();
	 sprintf(headCodeStr,"%s: .float %f\n",label,$1.val);
	 sprintf(bodyCodeStr,"l.s %s,%s\n",reg,label);
	}
	$$.headCode = strdup(headCodeStr);
	$$.bodyCode = strdup(bodyCodeStr);
	free(bodyCodeStr);
	free(headCodeStr);
}

| error {PrintListingErrors("choice -> ID or NUM is missing ");}

;


cases: CASE NUM ':' stmtlist BREAK ';' cases  {fprintf(stderr, " cases -> case num: STMTLIST break; CASES done \n");}
     {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen($4.body)));
	 bodyCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 char* reg=  getTempRegister();
	 sprintf(bodyCodeStr,"li %s, %d\n bne %s, $s1 ,next%s\n%s\nj end%s\nnext%s:\n",reg,$2.val.ival,reg,label,$4.body,$7.label,label);	
	 $$.label = $7.label;
	 $$.headCode = StringCat($4.head,$7.headCode);
	 $$.bodyCode = StringCat(bodyCodeStr,$7.bodyCode);
	 freeTempRegister(reg);
	 free(bodyCodeStr);

     }


     | DEFAULT ':' stmtlist  {fprintf(stderr, " cases 2 -> default: STMTLIST done \n");}
     {

	 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen($3.body)));
	 bodyCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 sprintf(bodyCodeStr,"default%s:\n%s\nend%s:",label,$3.body,label);
	 $$.label = strdup(label);
	 $$.headCode = strdup($3.head);
	 $$.bodyCode = strdup(bodyCodeStr);
	 free(bodyCodeStr);
     }

     | error NUM ':' stmtlist BREAK ';' cases {PrintListingErrors("CASE is missing ");}
     | CASE error ':' stmtlist BREAK ';' cases {PrintListingErrors("NUM is missing ");}
     | CASE NUM error stmtlist BREAK ';' cases {PrintListingErrors("':' is missing ");}
     | CASE NUM ':' error BREAK ';' cases {PrintListingErrors("stmtlist is missing ");}
     | CASE NUM ':' stmtlist error ';' cases {PrintListingErrors("BREAK is missing ");}
     | CASE NUM ':' stmtlist BREAK error cases {PrintListingErrors("';' is missing ");}
     | CASE NUM ':' stmtlist BREAK ';' error {PrintListingErrors("cases is missing ");}
     | error ':' stmtlist {PrintListingErrors("DEFAULT is missing ");}
     | DEFAULT error stmtlist {PrintListingErrors("':' is missing ");}
;



step: ID ASSIGNOP ID ADDOP NUM {fprintf(stderr, " ID ASSIGNOP ID ADDOP NUM\n");}
    {
    char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
    bodyCodeStr[0]='\0';
    symbol* sym1 = lookup($1);
    symbol* sym3 = lookup($3);

    
    if (sym1 == NULL)
    {
    	installSymTable($1,"int",0);
	fprintf(stderr, "step -> sym1\n");
	sym1 = lookup($1);
    }

    else if (sym3 == NULL)
    {
    	installSymTable($1,"int",0);
	fprintf(stderr, "step -> sym1\n");
	sym3 = lookup($3);
    }

    else
    {
	    if(!strcmp(sym1->type,"float") && !strcmp(sym3->type,"float") && !strcmp($5.type,"float"))
	    {
		  char* reg = getFloatRegister();
		  if($4==MINUS)
		    sprintf(bodyCodeStr,"l.s, %s, %s\nsub.s %s, %s ,%d\ns.s %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  else
		    sprintf(bodyCodeStr,"l.s, %s, %s\nadd.s %s, %s ,%d\ns.s %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  freeFloatRegister(reg);
	    }

	    else if(!strcmp(sym1->type,"int") && !strcmp(sym3->type,"int") && !strcmp($5.type,"int"))
	    {
		  char* reg = getTempRegister();
		  if($4==MINUS)
		    sprintf(bodyCodeStr,"lw, %s, %s\nsub %s, %s ,%d\nsw %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  else
		    sprintf(bodyCodeStr,"lw, %s, %s\naddi %s, %s ,%d\nsw %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  freeTempRegister(reg);
	    }
    }
    $$.head = strdup("");
    $$.body = strdup(bodyCodeStr);
    free(bodyCodeStr);
    }

    | ID ASSIGNOP ID MULOP NUM {fprintf(stderr, " ID ASSIGNOP ID MULOP NUM\n");}
    {


    char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
    bodyCodeStr[0]='\0';
    symbol* sym1 = lookup($1);
    symbol* sym3 = lookup($3);

    if( (!strcmp($5.type,"int") && ($5.val.ival)==0) || (!strcmp($5.type,"float") && ($5.val.fval)==0) )
    {
		
		PrintListingErrors("can not division by zero.");
    }

    else
    {
	    if(!strcmp(sym1->type,"float") && !strcmp(sym3->type,"float") && !strcmp($5.type,"float"))
	    {
		  char* reg = getFloatRegister();
		  if($4==DIV)
		    sprintf(bodyCodeStr,"l.s, %s, %s\ndiv.s %s, %s ,%d\ns.s %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  else
		    sprintf(bodyCodeStr,"l.s, %s, %s\nmul.s %s, %s ,%d\ns.s %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  freeFloatRegister(reg);
	    }

	    else if(!strcmp(sym1->type,"int") && !strcmp(sym3->type,"int") && !strcmp($5.type,"int"))
	    {
		  char* reg = getTempRegister();
		  if($4==DIV)
		    sprintf(bodyCodeStr,"la ,%s, %s\ndiv %s, %s ,%d\nsw %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  else
		    sprintf(bodyCodeStr,"la ,%s, %s\nmul %s, %s ,%d\nsw %s, %s\n",reg,$3,reg,reg,$5.val,reg,$1);
		  freeTempRegister(reg);
	    }
    }


    $$.head = strdup("");
    $$.body = strdup(bodyCodeStr);
    free(bodyCodeStr);

    }


    | ID ASSIGNOP error ADDOP NUM {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : second id is missing");}
    | error ASSIGNOP ID ADDOP NUM {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : first id is missing");}
    | ID error ID ADDOP NUM {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : assignop id is missing");}
    | ID ASSIGNOP ID error NUM {PrintListingErrors("ID addop or mulop ID ADDOP NUM : addop or mulop id is missing");}
    | ID ASSIGNOP ID ADDOP error {PrintListingErrors("ID addop ID ADDOP NUM : num id is missing");}
    | error ASSIGNOP ID MULOP NUM {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : first id is missing");}
    | ID error ID MULOP NUM {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : assignop id is missing");}
    | ID ASSIGNOP error MULOP NUM {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : second id is missing");}
    | ID ASSIGNOP ID MULOP error {PrintListingErrors("ID addop ID MULOP NUM : num id is missing");}

;



boolexpr: boolexpr OROP boolterm {fprintf(stderr, "boolexpr -> boolexpr OROP boolterm\n");}
	{
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';
		 char* reg = getTempRegister();
		 char* label = getLabelNumber();
		 sprintf(bodyCodeStr,"bne %s, %s, else%s\nadd %s, $0, %s\nj end%s\nelse%s: addi %s, $0, 1\nend%s",$1.reg,$3.reg,label,reg,$1.reg,label,label,reg,label);
		 $$.reg = strdup(reg);
		 tmp = StringCat($1.bodyCode,$3.bodyCode);
		 $$.bodyCode= StringCat(tmp,bodyCodeStr);
		 $$.headCode= StringCat($1.headCode,$3.headCode);
		 freeTempRegister($1.reg);
		 freeTempRegister($3.reg);
		 free(tmp);
		 free(bodyCodeStr);
	}

	| boolterm {fprintf(stderr, "boolexpr -> boolterm\n");}
	{
		 $$.reg = strdup($1.reg);
		 $$.bodyCode= strdup($1.bodyCode);
		 $$.headCode= strdup($1.headCode);
	}
        | error OROP boolterm {PrintListingErrors("boolexpr OROP boolterm : boolexpr is missing");}
	| boolexpr error boolterm {PrintListingErrors("boolexpr OROP boolterm : orop is missing");}
	| boolexpr OROP error {PrintListingErrors("boolexpr OROP boolterm : boolterm is missing");}
	| error {PrintListingErrors("boolterm : boolterm is missing");}



boolterm: boolterm ANDOP boolterm {fprintf(stderr, "boolterm -> boolterm ANDOP boolterm\n");}
	{
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';
		 char* reg = getTempRegister();
		 sprintf(bodyCodeStr,"mul %s, %s, %s\n",reg,$1.reg,$3.reg);
		 $$.reg = strdup(reg);
		 tmp = StringCat($1.bodyCode,$3.bodyCode);
		 $$.bodyCode= StringCat(tmp,bodyCodeStr);
		 $$.headCode= StringCat($1.headCode,$3.headCode);
		 freeTempRegister($1.reg);
		 freeTempRegister($3.reg);
		 free(tmp);
		 free(bodyCodeStr);

	}
	| boolfactor {fprintf(stderr, "boolterm -> boolfactor\n");}
	{
		 $$.reg = strdup($1.reg);
		 $$.bodyCode= strdup($1.bodyCode);
		 $$.headCode= strdup($1.headCode);
	}

        | error ANDOP boolterm {PrintListingErrors("boolterm ANDOP boolterm : first boolterm is missing");}
	| boolterm error boolterm {PrintListingErrors("boolterm ANDOP boolterm : andop is missing");}
	| boolterm ANDOP error {PrintListingErrors("boolterm ANDOP boolterm : second boolterm is missing");}
	| error {PrintListingErrors("boolfactor : boolfactor is missing");}

;


boolfactor: '!' '(' boolfactor ')' {fprintf(stderr, "boolfactor -> !(boolfactor)\n");}
	  {

		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* reg = getTempRegister();
		 bodyCodeStr[0]='\0';
		 sprintf(bodyCodeStr,"li %s ,1\nsub %s, %s, %s\n",reg,$3.reg,reg,$3.reg);
		 $$.reg= $3.reg;
		 $$.bodyCode= StringCat($3.bodyCode,bodyCodeStr);
		 $$.headCode= $3.headCode;
		 freeTempRegister(reg);
		 free(bodyCodeStr);

	  }
	  | expression RELOP expression {fprintf(stderr, "boolfactor -> expression RELOP expression\n");}
	  {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 bodyCodeStr[0]='\0';
		 char* tmpBody =(char*)malloc(sizeof(char)*256);
		 char* tmpHead =(char*)malloc(sizeof(char)*256);
		 tmpBody[0]='\0';
		 tmpHead[0]='\0';
		 char* reg = getTempRegister();
		 char* label = getLabelNumber();

		 if(!strcmp($1.type,"string") || !strcmp($3.type,"string"))
		 {
			PrintListingErrors(">= or <= operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
			
		 }
		 else if((!strcmp($1.type,"int") && !strcmp($3.type,"float"))  ||  (!strcmp($1.type,"float") && !strcmp($3.type,"int")))
		 {
			PrintListingErrors(">= or <= operation will performe only for variables from same type.");
			sprintf(bodyCodeStr,"");
			
		 }
		 else
		 {
			 if(!strcmp($1.type,"int") && !strcmp($3.type,"int"))
			 {
			  if($2==EQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nli %s , $0\nj end%s\nelse%s\nli %s,1\nend%s\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  if($2==NEQ)
			    sprintf(bodyCodeStr,"bne %s, %s, else%s\nli %s , $0\nj end%s\nelse%s\nli %s,1\nend%s\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  if($2==LT)
			    sprintf(bodyCodeStr,"slt %s, %s, %s\n",reg,$1.reg,$3.reg);
			  if($2==GT)
			    sprintf(bodyCodeStr,"slt %s, %s, %s\n",reg,$3.reg,$1.reg);
			  if($2==LTEQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nslt %s , %s, %s\nj end%s\nelse%s\nli %s,1\nend%s\n",$1.reg,$3.reg,label,reg,$1.reg,$3.reg,label,label,reg,label);
			  if($2==GTEQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nslt %s , %s, %s\nj end%s\nelse%s\nli %s,1\nend%s\n",$3.reg,$1.reg,label,reg,$3.reg,$1.reg,label,label,reg,label);
			  freeTempRegister($1.reg);
			  freeTempRegister($3.reg);			
			 }
			 if(!strcmp($1.type,"float") && !strcmp($3.type,"float"))
			 {
			  if($2==EQ)
			    sprintf(bodyCodeStr,"c.eq.s %s, %s\nbc1f else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  if($2==NEQ)
			    sprintf(bodyCodeStr,"c.eq.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  if($2==LT)
			    sprintf(bodyCodeStr,"c.lt.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$3.reg,$1.reg,label,reg,label,label,reg,label);
			  if($2==GT)
			    sprintf(bodyCodeStr,"c.lt.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  if($2==LTEQ)
			    sprintf(bodyCodeStr,"c.le.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$3.reg,$1.reg,label,reg,label,label,reg,label);
			  if($2==GTEQ)
			    sprintf(bodyCodeStr,"c.le.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",$1.reg,$3.reg,label,reg,label,label,reg,label);
			  freeFloatRegister($1.reg);
			  freeFloatRegister($3.reg);
			 }
		 }
		 $$.reg = strdup(reg);
		 strcat(tmpBody,$1.bodyCode);
		 strcat(tmpBody,$3.bodyCode);
		 strcat(tmpBody,bodyCodeStr);
	         strcat(tmpHead,$1.headCode);
		 strcat(tmpHead,$3.headCode);
		 $$.bodyCode = strdup(tmpBody);
		 $$.headCode = strdup(tmpHead);
		 free(tmpBody);
		 free(tmpHead);
		 free(bodyCodeStr);
	  }
          | error '(' boolfactor ')' {PrintListingErrors("!(boolfactor) : '!' is missing");}
          | '!' error boolfactor ')' {PrintListingErrors("!(boolfactor) : '(' is missing");}
	  | '!' '(' error ')' {PrintListingErrors("!(boolfactor) : boolfactor is missing");}
	  | '!' '(' boolfactor error {PrintListingErrors("!(boolfactor) : ')' is missing");}
	  | error  RELOP expression {PrintListingErrors("expression RELOP expression : first expression is missing");}
	  | expression error expression {PrintListingErrors("expression RELOP expression : relop is missing");}
	  | expression RELOP error {PrintListingErrors("expression RELOP expression : second expression is missing");}

;



expression: expression ADDOP term {fprintf(stderr, "expression -> expression ADDOP term\n");}
	  {
		 
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';

		 if(!strcmp($1.type,"string") || !strcmp($3.type,"string"))
		 {
			PrintListingErrors("+ or - operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
		 }
		 else
		 {
			 if(!strcmp($1.type,"int") && !strcmp($3.type,"int"))
			 {
			  if($2 == MINUS)
			    sprintf(bodyCodeStr,"sub %s, %s ,%s\n",$3.reg,$1.reg,$3.reg);
			  else
			    sprintf(bodyCodeStr,"add %s, %s ,%s\n",$3.reg,$3.reg,$1.reg);
			  freeTempRegister($1.reg);
			  $$.type = strdup("int");
			  $$.reg = strdup($3.reg);
			 }


			 else if(!strcmp($1.type,"float") && !strcmp($3.type,"float"))
			 {
			  if($2 == MINUS)
			    sprintf(bodyCodeStr,"sub.s %s, %s ,%s\n",$3.reg,$1.reg,$3.reg);
			  else
			    sprintf(bodyCodeStr,"add.s %s, %s ,%s\n",$3.reg,$1.reg,$3.reg);
			  freeFloatRegister($1.reg);
			  $$.type = strdup("float");
			  $$.reg = strdup($3.reg);
			 }

			 else
			 {
				 if(!strcmp($1.type,"float") && !strcmp($3.type,"int"))
				 {
				  char* reg = getFloatRegister();
				  if($2 == MINUS)
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n",$3.reg,reg,reg,reg,$1.reg,$1.reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n",$3.reg,reg,reg,reg,$1.reg,$1.reg,reg);

				  freeFloatRegister(reg);
				  freeTempRegister($3.reg);
				  $$.type = strdup("float");
				  $$.reg = strdup($1.reg);
				 }

				 else
				 {
				  char* reg = getFloatRegister();
				  if($2 == MINUS)
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n",$1.reg,reg,reg,reg,$3.reg,reg,$3.reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n",$1.reg,reg,reg,reg,$3.reg,$3.reg,reg);

				  freeFloatRegister(reg);
				  freeTempRegister($1.reg);
				  $$.type = strdup("float");
				  $$.reg = strdup($3.reg);

				 }
			 }

		 }
		 tmp = StringCat($1.bodyCode,$3.bodyCode);
		 $$.bodyCode= StringCat(tmp,bodyCodeStr);
		 $$.headCode= StringCat($1.headCode,$3.headCode);
		 free(tmp);
		 free(bodyCodeStr);

	  }
	  | term {fprintf(stderr, "expression -> term\n");}
	  {
		 $$.reg =  strdup($1.reg);
		 $$.bodyCode = strdup($1.bodyCode);
		 $$.headCode = strdup($1.headCode);
		 $$.type = strdup($1.type);
	  }
          | error ADDOP term {PrintListingErrors("expression ADDOP term : expression is missing");}
	  | expression error term {PrintListingErrors("expression ADDOP term : addop is missing");}
	  | expression ADDOP error {PrintListingErrors("expression ADDOP term : term is missing");}
	  | error {PrintListingErrors("term : term is missing");}
;


term: term MULOP factor {fprintf(stderr, "term -> term MULOP factor\n");} 
    {

		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';

		 if(!strcmp($1.type,"string") || !strcmp($3.type,"string"))
		 {
			PrintListingErrors("multiplication or division operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
		 }
		 else if(($3.ival == 0) || ($3.fval == 0.0))
		 {
			PrintListingErrors("can not perform a division operation with zero");
			sprintf(bodyCodeStr,"");
		 }
		 else
		 {
			 if(!strcmp($1.type,"int") && !strcmp($3.type,"int"))
			 {
			  if($2 == DIV) 
			    sprintf(bodyCodeStr,"div %s, %s ,%s\n",$3.reg,$1.reg,$3.reg);
			  else
			    sprintf(bodyCodeStr,"mul %s, %s ,%s\n",$3.reg,$3.reg,$1.reg);

			  freeTempRegister($1.reg);
			  $$.type = strdup("int");
			  $$.reg = strdup($3.reg);
			 }
			 else if(!strcmp($1.type,"float") && !strcmp($3.type,"float"))
			 {
			  if($2 == DIV)
			    sprintf(bodyCodeStr,"div.s %s, %s ,%s\n",$3.reg,$1.reg,$3.reg);
			  else
			    sprintf(bodyCodeStr,"mul.s %s, %s ,%s\n",$3.reg,$3.reg,$1.reg);

			  freeFloatRegister($1.reg);
			  $$.type = strdup("float");
			  $$.reg = strdup($3.reg);
			 }

			 else
			 {
				 if(!strcmp($1.type,"float") && !strcmp($3.type,"int"))
				 {
				  char* reg = getFloatRegister();
				  if($2 == DIV) 
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n",$3.reg,reg,reg,reg,$1.reg,$1.reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n",$3.reg,reg,reg,reg,$1.reg,$1.reg,reg);
				  freeFloatRegister(reg);
				  freeTempRegister($3.reg);
				  $$.type = strdup("float");
				  $$.reg = strdup($1.reg);
				 }

				 else
				 {
				  char* reg = getFloatRegister();
				  if($2 == DIV) 
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n",$1.reg,reg,reg,reg,$3.reg,$3.reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n",$1.reg,reg,reg,reg,$3.reg,$3.reg,reg);
				  
				  freeFloatRegister(reg);
				  freeTempRegister($1.reg);
				  $$.type = strdup("float");
				  $$.reg = strdup($3.reg);
				 }
			 }

		 }
		 tmp = StringCat($1.bodyCode,$3.bodyCode);
		 $$.bodyCode= StringCat(tmp,bodyCodeStr);
		 $$.headCode= StringCat($1.headCode,$3.headCode);
		 free(tmp);
		 free(bodyCodeStr);

    }
    | factor {fprintf(stderr, "term -> factor\n");}
    {
	 $$.reg =  strdup($1.reg);
	 $$.bodyCode = strdup($1.bodyCode);
	 $$.headCode = strdup($1.headCode);
	 $$.type = strdup($1.type);
    }
    | error MULOP factor {PrintListingErrors("term MULOP factor : term is missing");}
    | term error factor {PrintListingErrors("term MULOP factor:  mulop is missing");}
    | term MULOP error {PrintListingErrors("term MULOP factor: factor is missing");}
    | error {PrintListingErrors("factor : factor is missing");}
;

factor: '(' expression ')' {fprintf(stderr, "FACTOR -> (EXPRESSION)\n");}
      {
	 $$.reg =  strdup($2.reg);
	 $$.bodyCode = strdup($2.bodyCode);
	 $$.headCode = strdup($2.headCode);
	 $$.type = strdup($2.type);
      }
      | ID {fprintf(stderr, "FACTOR ->ID\n");}
      {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg;
	 char* label = getLabelNumber();
	 bodyCodeStr[0]='\0';
	 symbol* symPointer = lookup($1);
	 if(symPointer !=NULL)
	 {
	  if(symPointer->isDeclared)
	  {
		  if(!strcmp(symPointer->type,"int"))
		  {
		   reg = getTempRegister();
		   sprintf(bodyCodeStr,"lw %s, %s\n",reg,$1);
		  }
		  if(!strcmp(symPointer->type,"float"))
		  {
		   reg = getFloatRegister();
		   sprintf(bodyCodeStr,"l.s %s, %s\n",reg,$1);
		  }
		  if(!strcmp(symPointer->type,"string"))
		  {
		   reg= $1;
		  }
		  $$.reg = strdup(reg);
		  $$.type = strdup(symPointer->type);
		  $$.bodyCode = strdup(bodyCodeStr);
		  $$.headCode=strdup("");
		  free(bodyCodeStr);
	   }
	  else
	  {  
		  sprintf(bodyCodeStr,"");
		  PrintListingErrors(StringCat($1, " need to be declare."));
		  free(bodyCodeStr);
	  }
	}
      }
      | NUM {fprintf(stderr, "FACTOR ->NUM\n");}
      {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg;
	 bodyCodeStr[0]='\0';
	 headCodeStr[0]='\0';
	 fprintf(stderr, "FACTOR ->NUM 1\n");
	 if(!strcmp($1.type,"int"))
	 {
		  fprintf(stderr, "FACTOR ->NUM is int\n");
		  reg = getTempRegister();
		  sprintf(bodyCodeStr,"addi %s, $0, %d\n",reg,$1.val.ival);
	 }
	 else
	 {
	          fprintf(stderr, "FACTOR ->NUM is float\n");
		  reg = getFloatRegister();
		  char* label = getLabelNumber();
		  sprintf(headCodeStr,"%s: .float %f\n",label,$1.val.fval);
		  sprintf(bodyCodeStr,"l.s %s, %s\n",reg,label);
	 }
	 fprintf(stderr, "FACTOR ->NUM 2\n");
	 $$.type = strdup($1.type);
	 $$.reg = strdup(reg);
	 $$.headCode = strdup(headCodeStr);
	 $$.bodyCode = strdup(bodyCodeStr);
	 free(headCodeStr);
	 free(bodyCodeStr);
      }

      | error expression ')' {PrintListingErrors("'(' is missing");}
      | '(' error ')' {PrintListingErrors("expression is missing");}
      | '(' expression error {PrintListingErrors("')' is missing");}
      | error {PrintListingErrors("id or num is missing!");}
;

%%


//main
main (int argc, char **argv)
{
printf(".... starting ....\n");
extern FILE *yyin;
FILE *MIPS;
char str[20],strMIPS[20],strList[20];
yyin = fopen(argv[1],"r");


strcpy(str,argv[1]);
int len = strlen(str);
const char *last_four = &str[len-4];
if(strcmp(last_four, ".cpl")) /* check if the file name is .cpl */
{
	printf("file not ending in .cpl\n exiting...");
	exit(0);
}
yyout = fopen("listing.lst","w+");
fprintf(yyout, "------\nNames:\n%s\n------\nProgram\n------\n1.  ","Or Hadad 204308423 \nTali Yanous 203761309 \nGal Amram 305253965 \n\n");

if(yyparse() == 1)/* start parsing , 1 for incomplete parse*/
{
	printf("\n the program have errors!\n");
	fprintf(yyout, "\n\nErrors\n \n%s \n", Errors); /* add errors to listing file */
}
else
{
	if(ErrorFlag == 0)
	{
		fprintf(yyout, "\n no errors :) \n"); /* no errors */
		printf("creating mips file\n");
		MIPS = fopen("mips.s","w+");
		fprintf(MIPS,"Or Hadad 204308423 \nTali Yanous 203761309 \nGal Amram 305253965 \n \n%s",MIPSCode);
		printf("copied mips code to mips file...\n");
		fclose(MIPS);

	}
	else
	{
		fprintf(yyout, "\n\nErrors\n \n%s \n", Errors); /* add errors to listing file */
	}
}

printf(".... done! ....\n");
fclose(yyout);
fclose(MIPS);
fclose(yyin);
return 0;
}

void yyerror(char* s) {}


/* 
 printListingError: Prints the errors to listing file		                         
 receives: string - A string that describes the error and will appear in listing file. 						
 returns: void.                                                                        
 */ 

void PrintListingErrors(char* s){
	ErrorFlag = 1;
	char error[500];
	sprintf(error,"Error #%d: %s in line %d, column %d\n",ErrorNum++,s,line-1,col);
	strcat(Errors,error);

}



int LabelNumCounter =0;
symbol* headSymTbl = NULL;												
char* TempRegister[8] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7"};	// The list of available MIPS temp registers
char* FloatRegister[8] = {"$f0","$f1","$f2","$f3","$f4","$f5","$f6","$f7"}; // The list of available MIPS float registers
int TempIndex=0;
int FloatIndex=0;


/*************************************************************************
 installSymTable: put lexeme in symbol table and initializes its isDeclared field to 1 and isInit field to 0	
 receives: name ->id, type-> integer representing int, 
 float representing real or string name, isConst->if the id is const.	 
 returns:  pointer to a symbol table entry on success, NULL on failure 
*************************************************************************/

symbol* installSymTable (char *name ,char *type ,int isConst)
{
	symbol* sym = (symbol*)malloc(sizeof(symbol));
	sym->name = strdup(name);
	sym->type = strdup(type);
	sym->isConst = isConst;
	sym->isInit = 0;
	sym->isDeclared=1;
	if (headSymTbl != NULL)
	{
		sym->next = headSymTbl;
	}
	else
	{
		sym->next = NULL;
	}
	headSymTbl = sym;
	return sym;
}


/*************************************************************************
 Lookup: look for name in symbol table 					 
 receives: string name->id, check if name might be in the symbol table 
 returns:  pointer to name->id in the symbol table, NULL if name doesn't exist	 
*************************************************************************/

symbol* lookup(char *name)
{
	symbol* symPtr = headSymTbl;
	while (symPtr != NULL)
	{
		if (!strcmp(symPtr->name,name))
		return symPtr;
		symPtr=symPtr->next;
	}
	return NULL;
}


/*************************************************************************
 StringCat: stringCat function concatenates two strings and allocates space according to the size of the strings. 
 receives: get 2 strings: first, sec.						 
 returns: return a pointer to the string after the concatenate between them
*************************************************************************/

char* StringCat(char* first,char* sec)
{
	char* s =(char*)malloc(sizeof(char)*(strlen(first) + strlen(sec) + 1));
	s[0]='\0';
	strcat(s,first);
	strcat(s,sec);
	return s;
}


/*************************************************************************
 getLabelNum: creates a string label that appears in the Mips file, write the number of the label.  			 
 receives: null  
 returns:  return pointer to strLable  
*************************************************************************/

char* getLabelNumber()
{
	char s[100];
	sprintf(s,"Label%d",LabelNumCounter);
	LabelNumCounter++;
	return strdup(s);
}


/*************************************************************************
 getTempRegister: Returns pointer to a free register from the tempRegister array	
 receives: null 						 
 returns: pointer to free register in tempRegister array. 
*************************************************************************/

char* getTempRegister()
{
	char* res;
	res = TempRegister[TempIndex];
	TempIndex++;
	return res;
}


/*************************************************************************
 getFloatRegister: Returns pointer to a free register from the floatRegister array	
 receives: null  						 
 returns: pointer to free register in floatRegister array 
*************************************************************************/

char* getFloatRegister()
{
	char* res;
	res = FloatRegister[FloatIndex];
	FloatIndex++;
	return res;
}


/*************************************************************************
 freeTempRegister: deallocates the memory from tempRegister array previously allocated by a call to malloc .	
 receives: null  						 
 returns: void. 
*************************************************************************/

void freeTempRegister(char* reg)
{
	TempIndex--;
	TempRegister[TempIndex] = reg;
}


/*************************************************************************
 freeFloatRegister: deallocates the memory from floatRegister array previously allocated by a call to malloc .	
 receives: null  					 
 returns:  void. 
*************************************************************************/

void freeFloatRegister(char* reg)
{
	FloatIndex--;
	FloatRegister[FloatIndex] = reg;
}