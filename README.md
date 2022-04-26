CPL – Language
Lexical rules:

Reserved words

bgn break case final	default do  else	end  foreach if   int let    
out program real   read  string  switch till  var  while with

a

(   )   {	}  
,   :   ;   !  
 Composed tokens

id:             letter (letter|digit)*
num:            digit+  | digit+.digit*
relop:          ==  |  <> | <  |  >  | >= | <=
addop:          +   |  -   
mulop:          *   |  /
assignop:       =   
orop:           ||
andop:          &&
sentance:       "(letter|.|,|!|?| |digit)* "

Where:  (Note: digit and letter are not tokens)
   digit:  0  |  1  | ... |  9
   letter: a  |  b  | ... |  z  |  A  |  B  | ... | Z

•	Token can include \n \t and space
•	Each identifier can include maximum 9 characters.
•	The code can include multi comment using /* comments */ , or single line comment using // 

Extensions:
•	if cpl program have errors mips file will not create
•	The compiler will create list file with the original program and show each error points to the row and column.
•	File that not end in .cpl will not works






CPLG - Grammar for the programming language CPL


PROGRAM   -> program id  bgn  DECLARATIONS  STMTLIST end 

DECLARATIONS ->  let  DECLARLIST CDECL 
               | epsilon
 
DECLARLIST -> DECLARLIST  DECL
                    |   DECL
 
DECL ->  TYPE : LIST

LIST -> id , LIST
 	|   id ;

TYPE ->  int 
| real
| string  
 
 
CDECL -> final TYPE id assignop num; CDECL
        | epsilon
	/* the value of id should not be changed during the program*/


STMTLIST  ->  STMTLIST  STMT  
               | epsilon

STMT -> ASSIGNMENT_STMT
 | id assignop sentence;
 | CONTROL_STMT 
 | READ_STMT 
 | OUT_STMT
 | STMT_BLOCK

OUT_STMT -> out(EXPRESSION);
| out(sentence);

READ_STMT -> read(id);

ASSIGNMENT_STMT -> id assignop EXPRESSION;

CONTROL_STMT -> if )BOOLEXPR(STMT else STMT 
		   | while )BOOLEXPR(STMT_BLOCK
   | foreach id assignop num:num with STEP STMT 
   | foreach id assignop num:id with STEP STMT
   | do STMT_BLOCK till (BOOLEXPR(
    /*do the block until BOOLEXPR is true*/	
   | SWITCH	

STMT_BLOCK -> { STMTLIST }

SWITCH -> switch (CHOICE) { CASES }

CHOICE -> id 
	| num

CASES -> case num: STMTLIST break; CASES
	| default: STMTLIST

STEP -> id assignop id addop num
	   | id assignop id mulop num

BOOLEXPR -> BOOLEXPR orop BOOLTERM
   |         BOOLTERM

BOOLTERM -> BOOLTERM andop BOOLFACTOR
   |         BOOLFACTOR

BOOLFACTOR ->  ! (BOOLFACTOR) /*Meaning not BOOLFACTOR*/
|EXPRESSION  relop  EXPRESSION  

EXPRESSION -> EXPRESSION  addop  TERM 
 | TERM

TERM -> TERM mulop FACTOR
  | FACTOR

FACTOR -> ( EXPRESSION )
          | id
          | num
          
* epsilon = empty word

![image](https://user-images.githubusercontent.com/39697797/165337828-b89c36f5-9073-4aa7-84bb-e3da30a45e17.png)
