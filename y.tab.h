/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     SENTENCE = 259,
     ADDOP = 260,
     MULOP = 261,
     ASSIGNOP = 262,
     OROP = 263,
     ANDOP = 264,
     RELOP = 265,
     NUM = 266,
     BGN = 267,
     BREAK = 268,
     CASE = 269,
     FINAL = 270,
     DEFAULT = 271,
     DO = 272,
     ELSE = 273,
     END = 274,
     FOREACH = 275,
     IF = 276,
     INT = 277,
     LET = 278,
     OUT = 279,
     PROGRAM = 280,
     REAL = 281,
     READ = 282,
     STRING = 283,
     SWITCH = 284,
     TILL = 285,
     VAR = 286,
     WHILE = 287,
     WITH = 288
   };
#endif
/* Tokens.  */
#define ID 258
#define SENTENCE 259
#define ADDOP 260
#define MULOP 261
#define ASSIGNOP 262
#define OROP 263
#define ANDOP 264
#define RELOP 265
#define NUM 266
#define BGN 267
#define BREAK 268
#define CASE 269
#define FINAL 270
#define DEFAULT 271
#define DO 272
#define ELSE 273
#define END 274
#define FOREACH 275
#define IF 276
#define INT 277
#define LET 278
#define OUT 279
#define PROGRAM 280
#define REAL 281
#define READ 282
#define STRING 283
#define SWITCH 284
#define TILL 285
#define VAR 286
#define WHILE 287
#define WITH 288



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 60 "cpm.y"

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
      

/* Line 2058 of yacc.c  */
#line 151 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
