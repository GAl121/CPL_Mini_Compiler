%{
	#include <malloc.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "y.tab.h"
	extern int atoi (const char *);
	int col = 1;
        int line = 2;
%}

%option noyywrap 
DIGIT [0-9]
LETTER [a-zA-Z]
SPACE [\t ]
%x comment1 comment2

%%
[\n]		{fprintf(yyout, "\n%d. ", line++); col = 1;}
{SPACE}+	{col += yyleng; fprintf(yyout, "%s", yytext);};

	/* reserved words */ 

"bgn"		{ col += yyleng; fprintf(yyout, "%s", yytext); return BGN;}
"break"		{ col += yyleng; fprintf(yyout, "%s", yytext); return BREAK;}
"case"		{ col += yyleng; fprintf(yyout, "%s", yytext); return CASE;}
"final"		{ col += yyleng; fprintf(yyout, "%s", yytext); return FINAL;}
"default"	{ col += yyleng; fprintf(yyout, "%s", yytext); return DEFAULT;}
"do"		{ col += yyleng; fprintf(yyout, "%s", yytext); return DO;}
"else"		{ col += yyleng; fprintf(yyout, "%s", yytext); return ELSE;}
"end"		{ col += yyleng; fprintf(yyout, "%s", yytext); return END;}
"foreach"	{ col += yyleng; fprintf(yyout, "%s", yytext); return FOREACH;}
"if"		{ col += yyleng; fprintf(yyout, "%s", yytext); return IF;}
"int"		{ col += yyleng; fprintf(yyout, "%s", yytext); return INT;}
"let"		{ col += yyleng; fprintf(yyout, "%s", yytext); return LET;}
"out"		{ col += yyleng; fprintf(yyout, "%s", yytext); return OUT;}
"program"	{ col += yyleng; fprintf(yyout, "%s", yytext); return PROGRAM;}
"real"		{ col += yyleng; fprintf(yyout, "%s", yytext); return REAL;}
"read"		{ col += yyleng; fprintf(yyout, "%s", yytext); return READ;}
"string"	{ col += yyleng; fprintf(yyout, "%s", yytext); return STRING;}
"switch"	{ col += yyleng; fprintf(yyout, "%s", yytext); return SWITCH;}
"till"		{ col += yyleng; fprintf(yyout, "%s", yytext); return TILL;}
"var"		{ col += yyleng; fprintf(yyout, "%s", yytext); return VAR;}
"while"		{ col += yyleng; fprintf(yyout, "%s", yytext); return WHILE;}
"with"		{ col += yyleng; fprintf(yyout, "%s", yytext); return WITH;}

	/* reserved symbols */

"("	 {col += yyleng; fprintf(yyout, "%s", yytext); return '(';}
")"	 {col += yyleng; fprintf(yyout, "%s", yytext); return ')';}
"{"	 {col += yyleng; fprintf(yyout, "%s", yytext); return '{';}
"}"	 {col += yyleng; fprintf(yyout, "%s", yytext); return '}';}
","	 {col += yyleng; fprintf(yyout, "%s", yytext);; return ',';}
":"	 {col += yyleng; fprintf(yyout, "%s", yytext); return ':';}
";"	 {col += yyleng; fprintf(yyout, "%s", yytext); return ';';}
"!"	 {col += yyleng; fprintf(yyout, "%s", yytext); return '!';}

"=="	{col += yyleng; yylval.op=EQ; fprintf(yyout,"%s",yytext); return RELOP;}
"<>"	{col += yyleng; yylval.op=NEQ; fprintf(yyout,"%s",yytext); return RELOP;}	 
"<"	{col += yyleng; yylval.op=LT; fprintf(yyout,"%s",yytext); return RELOP;}
">"	{col += yyleng; yylval.op=GT; fprintf(yyout,"%s",yytext); return RELOP;}
">="	{col += yyleng; yylval.op=GTEQ; fprintf(yyout,"%s",yytext); return RELOP;}
"<=" 	{col += yyleng; yylval.op=LTEQ; fprintf(yyout,"%s",yytext); return RELOP;}	 
"+"	{col += yyleng; yylval.op=PLUS; fprintf(yyout,"%s",yytext); return ADDOP;}
"-" 	{col += yyleng; yylval.op=MINUS; fprintf(yyout,"%s",yytext); return ADDOP;}
"*"	{col += yyleng; yylval.op=MUL; fprintf(yyout,"%s",yytext); return MULOP;}
"/" 	{col += yyleng; yylval.op=DIV; fprintf(yyout,"%s",yytext); return MULOP;}			
"=" 	{col += yyleng; yylval.op=ASSIGN; fprintf(yyout,"%s",yytext); return ASSIGNOP;}				
"&&" 	{col += yyleng; yylval.op=AND; fprintf(yyout,"%s",yytext); return ANDOP;}
"||" 	{col += yyleng; yylval.op=OR; fprintf(yyout,"%s",yytext); return OROP;}

	/* composed tokens */

"/*" BEGIN(comment1);
<comment1>[^*]*                 /*do nothing till   */
<comment1>[\n*]                      /* delete new line in multi-line comment */
<comment1>"*/" {BEGIN(0);}

"//" BEGIN(comment2);
<comment2>[^\n]                    /*do nothing till new line */
<comment2>\n   {BEGIN(0);}



{LETTER}({LETTER}|{DIGIT}){0,8}		{col += yyleng; fprintf(yyout, "%s", yytext); yylval.sval=strdup(yytext); return ID;}
{DIGIT}+				{col += yyleng; fprintf(yyout, "%s", yytext); yylval.number.val.fval=atoi(yytext); return NUM;}
{DIGIT}+"."{DIGIT}*			{col += yyleng; fprintf(yyout, "%s", yytext);yylval.number.val.fval=atof(yytext); return NUM;}
\"([a-zA-Z|.|,|!|?|" "|0-9|{SPACE}])*\"         {col += yyleng; yylval.sval = (char*) malloc(yyleng * sizeof(char)+1); strcpy(yylval.sval, yytext); fprintf(yyout, "%s", yytext); return SENTENCE;}
			
%%
