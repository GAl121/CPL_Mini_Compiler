/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cpm.y"

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



/* Line 371 of yacc.c  */
#line 124 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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
      

/* Line 387 of yacc.c  */
#line 261 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 302 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  247
/* YYNRULES -- Number of states.  */
#define YYNSTATES  597

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    19,    26,    33,    40,    47,
      54,    58,    59,    64,    65,    67,    71,    75,    79,    80,
      84,    85,    88,    90,    93,    96,    97,   102,   106,   110,
     114,   115,   120,   121,   125,   128,   131,   135,   139,   143,
     144,   147,   148,   151,   152,   155,   157,   158,   167,   174,
     181,   188,   195,   202,   209,   210,   212,   213,   216,   217,
     221,   222,   225,   228,   231,   232,   233,   236,   237,   243,
     244,   247,   248,   251,   252,   255,   256,   259,   261,   266,
     271,   276,   281,   282,   289,   290,   297,   303,   309,   315,
     321,   327,   333,   339,   345,   351,   354,   355,   362,   368,
     374,   380,   386,   392,   393,   398,   402,   406,   410,   411,
     420,   421,   428,   429,   440,   441,   452,   453,   461,   462,
     465,   473,   481,   489,   497,   505,   513,   519,   525,   531,
     537,   543,   553,   563,   573,   583,   593,   603,   613,   623,
     633,   643,   653,   663,   673,   683,   693,   700,   707,   714,
     721,   728,   735,   736,   741,   745,   749,   753,   754,   763,
     771,   779,   787,   795,   803,   811,   819,   821,   823,   825,
     826,   835,   836,   841,   849,   857,   865,   873,   881,   889,
     897,   901,   905,   906,   913,   914,   921,   927,   933,   939,
     945,   951,   957,   963,   969,   975,   976,   981,   982,   985,
     989,   993,   997,   999,  1000,  1005,  1006,  1009,  1013,  1017,
    1021,  1023,  1024,  1030,  1031,  1036,  1041,  1046,  1051,  1056,
    1060,  1064,  1068,  1069,  1074,  1075,  1078,  1082,  1086,  1090,
    1092,  1093,  1098,  1099,  1102,  1106,  1110,  1114,  1116,  1117,
    1122,  1123,  1126,  1127,  1130,  1134,  1138,  1142
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    25,     3,    12,    45,    64,    19,
      44,    -1,     1,     3,    12,    45,    64,    19,    -1,    25,
       1,    12,    45,    64,    19,    -1,    25,     3,     1,    45,
      64,    19,    -1,    25,     3,    12,     1,    64,    19,    -1,
      25,     3,    12,    45,     1,    19,    -1,    25,     3,    12,
      45,    64,     1,    -1,     1,     3,     1,    -1,    -1,    23,
      48,    60,    46,    -1,    -1,    47,    -1,     1,    48,    60,
      -1,    23,     1,    60,    -1,    23,    48,     1,    -1,    -1,
      48,    51,    49,    -1,    -1,    51,    50,    -1,     1,    -1,
       1,    51,    -1,    48,     1,    -1,    -1,    56,    34,    53,
      52,    -1,     1,    34,    53,    -1,    56,     1,    53,    -1,
      56,    34,     1,    -1,    -1,     3,    35,    53,    54,    -1,
      -1,     3,    36,    55,    -1,     1,    36,    -1,     3,     1,
      -1,     1,    35,    53,    -1,     3,     1,    53,    -1,     3,
      35,     1,    -1,    -1,    22,    57,    -1,    -1,    26,    58,
      -1,    -1,    28,    59,    -1,     1,    -1,    -1,    15,    56,
       3,     7,    11,    36,    60,    61,    -1,     1,     3,     7,
      11,    36,    60,    -1,    56,     1,     7,    11,    36,    60,
      -1,    56,     3,     1,    11,    36,    60,    -1,    56,     3,
       7,     1,    36,    60,    -1,    56,     3,     7,    11,     1,
      60,    -1,    56,     3,     7,    11,    36,     1,    -1,    -1,
      62,    -1,    -1,     1,    63,    -1,    -1,    64,    67,    65,
      -1,    -1,    67,    66,    -1,     1,    67,    -1,    64,     1,
      -1,    -1,    -1,    79,    68,    -1,    -1,     3,     7,     4,
      36,    69,    -1,    -1,    81,    70,    -1,    -1,    77,    71,
      -1,    -1,    74,    72,    -1,    -1,    88,    73,    -1,     1,
      -1,     1,     7,     4,    36,    -1,     3,     1,     4,    36,
      -1,     3,     7,     1,    36,    -1,     3,     7,     4,     1,
      -1,    -1,    24,    37,   108,    38,    36,    75,    -1,    -1,
      24,    37,     4,    38,    36,    76,    -1,     1,    37,   108,
      38,    36,    -1,    24,     1,   108,    38,    36,    -1,    24,
      37,     1,    38,    36,    -1,    24,    37,   108,     1,    36,
      -1,    24,    37,   108,    38,     1,    -1,     1,    37,     4,
      38,    36,    -1,    24,     1,     4,    38,    36,    -1,    24,
      37,     4,     1,    36,    -1,    24,    37,     4,    38,     1,
      -1,    24,     1,    -1,    -1,    27,    37,     3,    38,    36,
      78,    -1,     1,    37,     3,    38,    36,    -1,    27,     1,
       3,    38,    36,    -1,    27,    37,     1,    38,    36,    -1,
      27,    37,     3,     1,    36,    -1,    27,    37,     3,    38,
       1,    -1,    -1,     3,     7,   108,    80,    -1,     1,     7,
     108,    -1,     3,     1,   108,    -1,     3,     7,     1,    -1,
      -1,    21,    37,    99,    38,    67,    18,    67,    82,    -1,
      -1,    32,    37,    99,    38,    88,    83,    -1,    -1,    20,
       3,     7,    11,    34,    11,    33,    96,    67,    84,    -1,
      -1,    20,     3,     7,    11,    34,     3,    33,    96,    67,
      85,    -1,    -1,    17,    88,    30,    37,    99,    38,    86,
      -1,    -1,    90,    87,    -1,     1,    37,    99,    38,    67,
      18,    67,    -1,    21,     1,    99,    38,    67,    18,    67,
      -1,    21,    37,     1,    38,    67,    18,    67,    -1,    21,
      37,    99,     1,    67,    18,    67,    -1,    21,    37,    99,
      38,     1,    18,    67,    -1,    21,    37,    99,    38,    67,
       1,    67,    -1,     1,    37,    99,    38,    88,    -1,    32,
       1,    99,    38,    88,    -1,    32,    37,     1,    38,    88,
      -1,    32,    37,    99,     1,    88,    -1,    32,    37,    99,
      38,     1,    -1,     1,     3,     7,    11,    34,    11,    33,
      96,    67,    -1,    20,     1,     7,    11,    34,    11,    33,
      96,    67,    -1,    20,     3,     1,    11,    34,    11,    33,
      96,    67,    -1,    20,     3,     7,     1,    34,    11,    33,
      96,    67,    -1,    20,     3,     7,    11,     1,    11,    33,
      96,    67,    -1,    20,     3,     7,    11,    34,    11,     1,
      96,    67,    -1,    20,     3,     7,    11,    34,    11,    33,
       1,    67,    -1,     1,     3,     7,    11,    34,     3,    33,
      96,    67,    -1,    20,     1,     7,    11,    34,     3,    33,
      96,    67,    -1,    20,     3,     1,    11,    34,     3,    33,
      96,    67,    -1,    20,     3,     7,     1,    34,     3,    33,
      96,    67,    -1,    20,     3,     7,    11,     1,     3,    33,
      96,    67,    -1,    20,     3,     7,    11,    34,     1,    33,
      96,    67,    -1,    20,     3,     7,    11,    34,     3,     1,
      96,    67,    -1,    20,     3,     7,    11,    34,     3,    33,
       1,    67,    -1,     1,    88,    30,    37,    99,    38,    -1,
      17,     1,    30,    37,    99,    38,    -1,    17,    88,     1,
      37,    99,    38,    -1,    17,    88,    30,     1,    99,    38,
      -1,    17,    88,    30,    37,     1,    38,    -1,    17,    88,
      30,    37,    99,     1,    -1,    -1,    39,    64,    40,    89,
      -1,     1,    64,    40,    -1,    39,     1,    40,    -1,    39,
      64,     1,    -1,    -1,    29,    37,    92,    38,    39,    93,
      40,    91,    -1,     1,    37,    92,    38,    39,    93,    40,
      -1,    90,     1,    92,    38,    39,    93,    40,    -1,    90,
      37,     1,    38,    39,    93,    40,    -1,    90,    37,    92,
       1,    39,    93,    40,    -1,    90,    37,    92,    38,     1,
      93,    40,    -1,    90,    37,    92,    38,    39,     1,    40,
      -1,    90,    37,    92,    38,    39,    93,     1,    -1,     3,
      -1,    11,    -1,     1,    -1,    -1,    14,    11,    34,    64,
      13,    36,    93,    94,    -1,    -1,    16,    34,    64,    95,
      -1,     1,    11,    34,    64,    13,    36,    93,    -1,    14,
       1,    34,    64,    13,    36,    93,    -1,    14,    11,     1,
      64,    13,    36,    93,    -1,    14,    11,    34,     1,    13,
      36,    93,    -1,    14,    11,    34,    64,     1,    36,    93,
      -1,    14,    11,    34,    64,    13,     1,    93,    -1,    14,
      11,    34,    64,    13,    36,     1,    -1,     1,    34,    64,
      -1,    16,     1,    64,    -1,    -1,     3,     7,     3,     5,
      11,    97,    -1,    -1,     3,     7,     3,     6,    11,    98,
      -1,     3,     7,     1,     5,    11,    -1,     1,     7,     3,
       5,    11,    -1,     3,     1,     3,     5,    11,    -1,     3,
       7,     3,     1,    11,    -1,     3,     7,     3,     5,     1,
      -1,     1,     7,     3,     6,    11,    -1,     3,     1,     3,
       6,    11,    -1,     3,     7,     1,     6,    11,    -1,     3,
       7,     3,     6,     1,    -1,    -1,    99,     8,   102,   100,
      -1,    -1,   102,   101,    -1,     1,     8,   102,    -1,    99,
       1,   102,    -1,    99,     8,     1,    -1,     1,    -1,    -1,
     102,     9,   102,   103,    -1,    -1,   105,   104,    -1,     1,
       9,   102,    -1,   102,     1,   102,    -1,   102,     9,     1,
      -1,     1,    -1,    -1,    41,    37,   105,    38,   106,    -1,
      -1,   108,    10,   108,   107,    -1,     1,    37,   105,    38,
      -1,    41,     1,   105,    38,    -1,    41,    37,     1,    38,
      -1,    41,    37,   105,     1,    -1,     1,    10,   108,    -1,
     108,     1,   108,    -1,   108,    10,     1,    -1,    -1,   108,
       5,   111,   109,    -1,    -1,   111,   110,    -1,     1,     5,
     111,    -1,   108,     1,   111,    -1,   108,     5,     1,    -1,
       1,    -1,    -1,   111,     6,   114,   112,    -1,    -1,   114,
     113,    -1,     1,     6,   114,    -1,   111,     1,   114,    -1,
     111,     6,     1,    -1,     1,    -1,    -1,    37,   108,    38,
     115,    -1,    -1,     3,   116,    -1,    -1,    11,   117,    -1,
       1,   108,    38,    -1,    37,     1,    38,    -1,    37,   108,
       1,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   102,   118,   119,   120,   121,   122,   123,
     124,   129,   129,   134,   134,   139,   140,   141,   145,   145,
     149,   149,   153,   154,   155,   158,   158,   192,   193,   194,
     200,   200,   239,   239,   265,   266,   267,   268,   269,   273,
     273,   277,   277,   281,   281,   285,   288,   288,   348,   349,
     350,   351,   352,   353,   354,   354,   358,   358,   368,   368,
     372,   372,   377,   378,   379,   383,   383,   388,   388,   448,
     448,   454,   454,   458,   458,   463,   463,   468,   469,   470,
     471,   472,   476,   476,   498,   498,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   525,   525,   571,   572,
     573,   574,   575,   581,   581,   644,   645,   646,   651,   651,
     666,   666,   683,   683,   713,   713,   751,   751,   768,   768,
     774,   775,   776,   777,   778,   779,   781,   782,   783,   784,
     785,   787,   788,   789,   790,   791,   792,   793,   795,   796,
     797,   798,   799,   800,   801,   802,   804,   805,   806,   807,
     808,   809,   815,   815,   820,   821,   822,   827,   827,   832,
     833,   834,   835,   836,   837,   838,   844,   873,   898,   903,
     903,   919,   919,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   945,   945,   994,   994,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1054,  1054,  1072,  1072,  1078,
    1079,  1080,  1081,  1085,  1085,  1102,  1102,  1109,  1110,  1111,
    1112,  1117,  1117,  1131,  1131,  1203,  1204,  1205,  1206,  1207,
    1208,  1209,  1215,  1215,  1292,  1292,  1299,  1300,  1301,  1302,
    1306,  1306,  1386,  1386,  1393,  1394,  1395,  1396,  1399,  1399,
    1406,  1406,  1445,  1445,  1476,  1477,  1478,  1479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "SENTENCE", "ADDOP", "MULOP",
  "ASSIGNOP", "OROP", "ANDOP", "RELOP", "NUM", "BGN", "BREAK", "CASE",
  "FINAL", "DEFAULT", "DO", "ELSE", "END", "FOREACH", "IF", "INT", "LET",
  "OUT", "PROGRAM", "REAL", "READ", "STRING", "SWITCH", "TILL", "VAR",
  "WHILE", "WITH", "':'", "','", "';'", "'('", "')'", "'{'", "'}'", "'!'",
  "$accept", "program", "$@1", "declarations", "$@2", "$@3", "declarlist",
  "$@4", "$@5", "decl", "$@6", "list", "$@7", "$@8", "TYPE", "$@9", "$@10",
  "$@11", "cdecl", "$@12", "$@13", "$@14", "stmtlist", "$@15", "$@16",
  "stmt", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "out_stmt",
  "$@23", "$@24", "read_stmt", "$@25", "assignment_stmt", "$@26",
  "control_stmt", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "stmt_block", "$@33", "switch", "$@34", "choice", "cases", "$@35",
  "$@36", "step", "$@37", "$@38", "boolexpr", "$@39", "$@40", "boolterm",
  "$@41", "$@42", "boolfactor", "$@43", "$@44", "expression", "$@45",
  "$@46", "term", "$@47", "$@48", "factor", "$@49", "$@50", "$@51", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    58,    44,    59,    40,    41,   123,
     125,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    43,    43,    43,    43,    43,    43,
      43,    46,    45,    47,    45,    45,    45,    45,    49,    48,
      50,    48,    48,    48,    48,    52,    51,    51,    51,    51,
      54,    53,    55,    53,    53,    53,    53,    53,    53,    57,
      56,    58,    56,    59,    56,    56,    61,    60,    60,    60,
      60,    60,    60,    60,    62,    60,    63,    60,    65,    64,
      66,    64,    64,    64,    64,    68,    67,    69,    67,    70,
      67,    71,    67,    72,    67,    73,    67,    67,    67,    67,
      67,    67,    75,    74,    76,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    78,    77,    77,    77,
      77,    77,    77,    80,    79,    79,    79,    79,    82,    81,
      83,    81,    84,    81,    85,    81,    86,    81,    87,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    89,    88,    88,    88,    88,    91,    90,    90,
      90,    90,    90,    90,    90,    90,    92,    92,    92,    94,
      93,    95,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    97,    96,    98,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,   100,    99,   101,    99,    99,
      99,    99,    99,   103,   102,   104,   102,   102,   102,   102,
     102,   106,   105,   107,   105,   105,   105,   105,   105,   105,
     105,   105,   109,   108,   110,   108,   108,   108,   108,   108,
     112,   111,   113,   111,   111,   111,   111,   111,   115,   114,
     116,   114,   117,   114,   114,   114,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     6,     6,     6,     6,     6,     6,
       3,     0,     4,     0,     1,     3,     3,     3,     0,     3,
       0,     2,     1,     2,     2,     0,     4,     3,     3,     3,
       0,     4,     0,     3,     2,     2,     3,     3,     3,     0,
       2,     0,     2,     0,     2,     1,     0,     8,     6,     6,
       6,     6,     6,     6,     0,     1,     0,     2,     0,     3,
       0,     2,     2,     2,     0,     0,     2,     0,     5,     0,
       2,     0,     2,     0,     2,     0,     2,     1,     4,     4,
       4,     4,     0,     6,     0,     6,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     2,     0,     6,     5,     5,
       5,     5,     5,     0,     4,     3,     3,     3,     0,     8,
       0,     6,     0,    10,     0,    10,     0,     7,     0,     2,
       7,     7,     7,     7,     7,     7,     5,     5,     5,     5,
       5,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     6,     6,     6,     6,
       6,     6,     0,     4,     3,     3,     3,     0,     8,     7,
       7,     7,     7,     7,     7,     7,     1,     1,     1,     0,
       8,     0,     4,     7,     7,     7,     7,     7,     7,     7,
       3,     3,     0,     6,     0,     6,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     0,     4,     0,     2,     3,
       3,     3,     1,     0,     4,     0,     2,     3,     3,     3,
       1,     0,     5,     0,     4,     4,     4,     4,     4,     3,
       3,     3,     0,     4,     0,     2,     3,     3,     3,     1,
       0,     4,     0,     2,     3,     3,     3,     1,     0,     4,
       0,     2,     0,     2,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     1,    10,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,    39,    41,    43,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    73,    71,    65,    69,    75,     0,     0,     0,
       0,     0,     0,     0,    45,     0,    23,    40,    42,    44,
      24,     0,    18,     0,    15,    55,    21,     0,     0,    56,
      16,    17,    11,     0,     0,     0,     0,    60,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    58,    61,
      74,    72,    66,    70,    76,     0,     0,   119,     5,     6,
       0,     7,     8,     0,     2,     0,     0,    27,     0,    57,
      45,     0,    19,     0,     0,    28,    29,    25,    12,     0,
       0,   240,     0,   242,     0,     0,     0,   232,     0,   240,
       0,   242,     0,     0,     0,     0,   205,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   166,   167,     0,     0,     0,
       0,   155,     0,   152,    59,     0,   168,     0,     3,     0,
      34,     0,     0,    32,     0,     0,     0,     0,     0,    26,
     242,     0,     0,     0,   241,    78,   243,     0,     0,     0,
       0,     0,     0,   225,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     206,     0,     0,     0,     0,    79,    80,    81,    67,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,     0,
       0,     0,     0,    36,    37,    38,    30,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   244,
     245,     0,   238,     0,     0,     0,   235,     0,   230,     0,
       0,     0,     0,     0,     0,     0,    98,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,    86,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    87,    88,    93,
      94,    84,    89,    90,    82,    99,   100,   101,   102,    96,
       0,     0,   127,   128,     0,   129,     0,   110,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   223,   231,   215,     0,   216,   217,
     218,   211,     0,     0,     0,     0,   196,     0,   204,   214,
     146,   147,   148,   149,   150,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    83,    97,
       0,   111,     0,     0,     0,     0,     0,     0,    56,     0,
      48,     0,    49,    50,    51,    52,    53,     0,     0,   212,
       0,     0,     0,     0,     0,     0,   159,   120,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,     0,   205,     0,   123,   124,
     125,   108,   157,   160,   161,   162,   163,   164,   165,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,   109,   158,
      47,     0,     0,     0,   138,   131,     0,     0,     0,     0,
       0,   172,   139,   132,   140,   133,   141,   134,   142,   135,
     143,   144,   145,   114,   136,   137,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,   191,   188,   192,   186,
     193,   189,   190,   182,   194,   184,   173,   174,   175,   176,
     177,   178,   179,   169,   183,   185,   170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   188,    15,   128,    16,    25,   122,    66,    26,
     199,   125,   373,   277,   439,    57,    58,    59,    64,   520,
      65,   119,    76,   184,    99,    41,   102,   328,   103,   101,
     100,   104,    42,   428,   427,    43,   429,    44,   239,    45,
     518,   431,   558,   557,   458,   107,    46,   268,    47,   519,
     143,   395,   596,   531,   493,   594,   595,   144,   396,   229,
     145,   398,   230,   146,   449,   399,   203,   384,   213,   136,
     385,   214,   137,   383,   204,   206
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -360
static const yytype_int16 yypact[] =
{
     197,     1,   129,   256,   125,   123,   350,  -360,  -360,  1856,
    1856,  1856,  1881,  1124,  1237,  1906,  -360,  1906,  1906,  1826,
    1931,  1646,  -360,  -360,  -360,  1706,  -360,    44,  1676,  1736,
    1116,   199,    33,   505,    51,    53,    91,    20,   153,  1469,
    1956,  -360,  -360,  -360,  -360,  -360,  -360,  1141,  1981,  2006,
     856,  2031,  1335,  2056,   243,   531,  -360,  -360,  -360,  -360,
     306,  1452,  -360,   279,  -360,  -360,  -360,   531,   760,   358,
    -360,  1591,  -360,   893,  1127,    57,  1494,   959,   273,  1283,
    1323,   357,   318,   329,   981,   138,   150,   966,  1392,   309,
     863,   510,   138,   156,  1444,  1519,  1176,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,   510,   790,  -360,  -360,  -360,
    1203,  -360,  -360,   278,  -360,    41,    85,  -360,   359,  -360,
    -360,   379,  -360,   761,  1025,  -360,    41,  -360,  -360,  1432,
     509,  -360,   355,  -360,  1225,  1228,   417,  -360,   534,   367,
     391,   421,   194,   435,   401,    95,  -360,   366,  -360,   380,
     473,  1253,   886,    66,  1278,   494,   528,   215,   563,   594,
     550,   574,   413,  1106,   614,   675,   576,   133,  1649,    55,
     135,   607,   616,    86,  -360,  -360,  -360,   647,   715,   654,
     864,  -360,  1001,  -360,  -360,   673,   696,   179,  -360,   531,
    -360,  1766,  1012,  -360,   710,   744,   754,   763,   590,  -360,
     771,  1340,  1476,   202,  -360,  -360,  -360,  1711,   469,  1340,
    1491,  1476,  1516,  -360,  -360,   167,   167,  1541,   191,   778,
     807,   218,   290,   792,   167,   327,  2226,   167,   332,  -360,
    -360,  1541,  1566,   843,   138,  -360,  -360,  -360,  -360,  -360,
     138,   138,   138,   338,   852,   867,   887,    45,  2226,  2226,
     305,  2253,   862,   897,   900,   912,    72,  1138,   229,   919,
     930,   935,   238,   941,    35,    35,    88,    36,  -360,   942,
     955,   958,    43,  -360,  -360,    41,  -360,  -360,   965,   999,
     987,   988,  1000,   248,   342,   549,   789,   589,  -360,  -360,
    -360,   629,  -360,   911,   669,   829,  -360,   709,  -360,   694,
     180,   237,   795,   405,  1017,   402,  -360,  -360,  1006,  1022,
    1181,   262,   349,   515,   734,   555,  1081,  1032,  1045,   595,
     774,   635,   953,   457,  1048,   991,  -360,   873,  -360,   926,
     951,  1026,   814,  1089,   377,   449,   461,   833,   859,  1065,
    1071,   749,  1086,  1077,  1362,   303,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,
     349,  1544,  -360,  -360,   936,  -360,  1387,  -360,   349,   349,
     349,   349,   369,  -360,  1796,  1030,  1796,  1796,  1796,  1796,
    1105,  1076,  1082,  -360,  -360,  -360,  -360,  1741,  -360,  -360,
    -360,  -360,   313,   630,   149,  1107,  -360,  2226,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,   145,  -360,  1093,  1118,  1130,
    1133,  1136,  1143,  1152,  1161,  1165,     2,   261,  2226,  2226,
    1041,   282,   106,  2226,  2226,  2226,  2226,  -360,  -360,  -360,
    1117,  -360,  1162,  1171,  1172,  1174,   165,  1121,  1034,  1111,
    -360,  1796,  -360,  -360,  -360,  -360,  -360,  1131,  1131,  -360,
    1183,  1544,  1191,   289,  1544,  1544,  -360,  -360,  -360,  1131,
    1131,  1131,  1131,  1131,  1131,  1131,  1131,  1131,  1131,  1187,
    1131,  1198,  -360,  -360,   106,  1066,  1017,   423,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  1214,
    -360,  1227,  1038,  2226,  2226,  2081,  1569,  2081,  2081,  2106,
    1594,  1619,  2226,  2226,  2226,  2226,  2226,  2226,  2226,  2226,
    2226,  2226,  2133,  2226,  2226,  2133,  2226,   843,  -360,  -360,
    -360,  1236,  1241,  1206,  -360,  -360,  2146,  2173,  2186,  1417,
    2213,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,   487,   719,   903,
    1166,  1215,  1217,  1233,  1239,  1308,   260,  -360,  -360,  1250,
    1265,  1267,  1277,  1279,  1289,  1290,   670,   683,   349,   349,
     349,   349,   349,   349,   431,  -360,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,
    -360,  -360,   313,  -360,  -360,  -360,  -360
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -360,  -360,  -360,  1302,  -360,  -360,  1275,  -360,  -360,  1438,
    -360,   -47,  -360,  -360,    34,  -360,  -360,  -360,   -22,  -360,
    -360,  -360,    -1,  -360,  -360,   -25,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,   -30,  -360,  -360,  -360,
     735,  -359,  -360,  -360,  1835,  -360,  -360,    30,  -360,  -360,
    -185,  -360,  -360,  -189,  -360,  -360,    26,  -360,  -360,  -160,
    -360,  -360,   643,  -360,  -360,  -360
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -248
static const yytype_int16 yytable[] =
{
      78,   430,    82,   468,     4,    77,    70,    72,   117,   432,
     433,   434,   435,   437,    40,    98,    48,    49,    51,    53,
      78,   127,    78,    98,    98,    77,    98,    77,    98,   304,
     300,   301,   309,   311,    81,   469,   361,   366,    95,   313,
     315,   286,   319,   321,   371,    67,   337,    27,    27,   293,
     295,    98,    85,    27,    87,    27,   255,    91,   138,    63,
     139,   140,    63,    63,    78,   313,    78,   237,   141,    77,
      98,   323,    39,   350,    39,    39,   189,   190,    68,   338,
      78,   313,   372,    78,    27,    77,   191,   261,    86,   364,
      88,   131,    89,   256,   134,   121,   227,   293,   142,   133,
     135,   147,   238,  -197,   228,   151,   154,   475,   351,   139,
     140,   163,   163,   167,   170,   162,   165,   141,   163,   163,
     192,   193,   178,   180,   262,   134,     8,    39,    90,   142,
       5,   293,     6,  -197,   209,    10,   257,     9,   210,   161,
     210,   131,   273,   134,   274,   276,   299,   142,   131,   133,
     454,   164,    78,   131,    92,   154,   133,   179,  -151,   131,
     208,   133,  -151,  -151,  -151,  -151,  -151,   133,   299,  -151,
     131,   253,  -151,   258,  -151,   134,   450,  -151,   133,   142,
     271,   227,   134,   455,  -151,  -151,   142,   134,  -199,   228,
      93,   142,   303,   134,   131,   221,   318,   142,     1,   451,
      79,   317,   133,   209,   134,   487,    80,   210,   142,   586,
     587,   588,   589,   590,   591,   593,   242,   272,  -199,   308,
     313,   131,     2,   339,   340,   343,   345,   323,   134,   133,
     353,   222,   142,   476,   362,   363,   365,   367,   227,   358,
     289,   163,   163,   302,   305,  -207,  -207,   163,   163,   379,
     163,   163,   243,   163,   163,   134,     7,   322,   325,   142,
     163,   573,   470,   390,   327,   354,   163,   163,   163,   163,
     329,   330,   331,   333,   359,  -207,   163,    55,    -9,    30,
     123,    73,   124,    79,   380,    74,    78,  -240,  -240,   129,
     498,   310,   163,   131,   471,    32,   574,   -63,    33,    34,
     391,   133,    35,   149,   425,    36,   341,    37,   342,   118,
      38,    78,   171,    68,    78,    75,   133,    39,   -64,   156,
    -240,   426,    32,   499,   450,    33,    34,   134,   314,    35,
     131,   142,    36,   320,    37,   131,   158,    38,   133,   332,
      55,   131,   134,   133,    39,   381,   142,   451,   157,   133,
     392,    11,   440,   382,   442,   443,   444,   445,    30,   -45,
      31,   118,    12,   393,   134,   394,   194,   231,   142,   134,
     436,   210,   457,   142,    32,   134,   232,    33,    34,   142,
     407,    35,   195,   393,    36,   394,    37,   155,   408,    38,
      78,   205,    55,   472,   473,    77,    39,   -64,   478,   479,
     480,   481,   224,   387,   233,   219,   130,   210,   131,   225,
     201,   202,   232,   322,   224,   217,   133,   234,   211,   490,
    -224,   225,  -224,   212,   387,  -224,  -224,  -224,   210,   220,
    -224,   163,   592,   232,  -224,  -224,  -224,  -224,  -224,   226,
     292,  -224,   218,   290,  -224,   393,  -224,   394,   477,  -224,
     496,   248,   409,   500,   501,  -224,  -224,  -224,   211,  -167,
     410,   517,  -224,   212,   411,  -224,  -224,  -227,   524,   525,
     291,    98,   412,   223,   210,    98,    98,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   559,   560,   526,  -224,   527,   528,   530,    78,
     477,    98,    98,    98,    77,    98,    83,   292,    84,   235,
     130,   174,   131,   175,   201,   202,   227,  -229,  -229,  -237,
     133,   176,  -229,  -200,   228,    78,  -229,  -229,  -229,  -229,
    -229,   240,   115,  -229,   116,   130,  -229,   131,  -229,   201,
     202,  -229,   215,   216,   217,   133,   134,  -229,  -229,  -229,
     130,   246,   131,  -200,  -237,   202,   227,  -237,  -237,  -237,
     133,   247,  -237,  -195,   228,   241,  -237,  -237,  -237,  -237,
    -237,   218,  -168,  -237,   244,   130,  -237,   131,  -237,   201,
     202,  -237,   215,   216,   217,   133,   134,  -237,  -237,  -237,
     130,   282,   131,  -195,  -247,  -247,   227,  -247,  -247,  -247,
     133,   283,  -247,  -208,   228,   245,  -247,  -247,  -247,  -247,
    -247,   218,  -202,  -247,   252,   130,  -247,   131,  -247,   201,
     202,  -247,   215,   216,   217,   133,   134,  -247,  -247,  -247,
     285,   452,   131,  -208,  -246,  -246,   227,  -246,  -246,  -246,
     133,   453,  -246,  -203,   228,   259,  -246,  -246,  -246,  -246,
    -246,   218,   249,  -246,   260,   130,  -246,   131,  -246,   201,
     202,  -246,   215,   216,   217,   133,   134,  -246,  -246,  -246,
     130,   582,   131,  -203,  -228,   202,   250,  -228,  -228,  -228,
     133,   583,  -228,   225,   584,   263,  -228,  -228,  -228,  -228,
    -228,   218,   265,  -228,   585,   130,  -228,   131,  -228,   201,
     202,  -228,  -210,   216,   217,   133,   134,  -228,  -228,  -228,
     130,   269,   131,   251,  -236,  -236,   224,  -236,  -236,  -236,
     133,   278,  -236,   225,   561,   562,  -236,  -236,  -236,  -236,
    -236,   218,  -210,  -236,   270,   130,  -236,   131,  -236,   201,
     202,  -236,  -201,   216,   217,   133,   134,  -236,  -236,  -236,
     420,   279,   421,   264,   201,   202,    74,  -210,   216,   217,
     133,   126,   115,   116,   116,   280,    32,   -77,   196,    33,
      34,   218,  -201,    35,   281,   130,    36,   131,    37,   201,
     202,    38,  -209,   216,   217,   133,   422,  -210,    39,   -64,
     211,   186,  -226,   175,  -226,   212,   209,  -226,  -226,  -226,
     210,   176,  -226,  -219,  -219,   284,  -226,  -226,  -226,  -226,
    -226,   218,  -209,  -226,   306,   130,  -226,   131,  -226,   201,
     202,  -226,   215,   216,   217,   133,   177,  -226,  -226,  -226,
     211,   312,  -222,  -219,  -222,   212,   413,  -222,  -222,  -222,
     185,   187,  -222,   307,   414,   288,  -222,  -222,  -222,  -222,
    -222,   218,   404,  -222,   296,   298,  -222,   110,  -222,    73,
     415,  -222,   416,    74,   172,   266,   173,  -222,  -222,  -222,
     417,   -22,   225,    32,   224,   -22,    33,    34,    22,   326,
      35,   225,    23,    36,    24,    37,   334,   130,    38,   131,
      55,   201,   202,    75,    79,    39,   -64,   133,   346,  -107,
     129,   335,   267,  -107,  -107,  -107,  -107,  -107,   563,   564,
    -107,   400,   211,  -107,  -227,  -107,  -227,   212,  -107,  -227,
    -227,   336,   236,   134,  -227,  -107,  -107,   224,  -227,  -227,
    -227,  -227,  -227,   347,   225,  -227,   348,   420,  -227,   342,
    -227,   201,   202,  -227,  -210,   216,   217,   133,   349,  -227,
    -227,  -227,   224,    32,   209,   355,    33,    34,   210,   225,
      35,  -220,  -220,    36,   401,    37,   356,   130,    38,   131,
     166,   357,   -62,   218,  -210,    39,   -64,   133,   -62,   -95,
     360,   368,   159,   -95,   -95,   -95,   -95,   -95,   160,   402,
     -95,  -220,   209,   -95,   369,   -95,   210,   370,   -95,  -213,
    -213,   374,    30,   134,    73,   -95,   -95,   130,    74,   131,
     375,   201,   202,   275,  -156,   116,   217,   133,    32,  -156,
    -156,    33,    34,   376,   377,    35,   197,   224,    36,  -213,
      37,  -156,   198,    38,   225,   -45,   378,   118,    75,   522,
      39,   -63,   420,   218,   421,   523,   201,   202,    74,   130,
     397,   131,   133,   201,   202,   386,  -221,  -221,    32,   133,
     388,    33,    34,   -75,   403,    35,   441,   130,    36,   131,
      37,   201,   202,    38,   215,   216,   217,   133,   474,  -229,
      39,   -64,    30,   418,    73,   134,  -221,    79,    74,   419,
     405,  -240,  -240,    80,   -77,   423,  -240,   225,    32,   -77,
     -77,    33,    34,   218,   290,    35,   446,   231,    36,   447,
      37,   210,   489,    38,   124,   448,   232,    30,    75,    73,
      39,   -64,   488,    74,  -240,    21,   459,   406,   130,   -77,
     131,   132,   491,    32,   492,   -77,    33,    34,   133,   285,
      35,   131,   105,    36,  -118,    37,    22,   456,    38,   133,
      23,   460,    24,    75,  -118,    39,   -64,   482,  -118,  -118,
    -118,  -118,  -118,   461,   134,  -118,   462,   565,  -118,   463,
    -118,   566,   567,  -118,   352,   134,   464,    30,   106,    73,
    -118,  -118,   130,    74,   131,   465,   201,   202,   512,   -63,
     492,   217,   133,    32,   466,   -63,    33,    34,   467,   515,
      35,   492,   483,    36,    30,    37,    73,   549,    38,   550,
      74,   484,   485,    75,   486,    39,   -63,   495,   218,   389,
      32,   196,   -77,    33,    34,   497,   207,    35,   131,   209,
      36,  -105,    37,   210,   521,    38,   133,    55,    28,   547,
      75,  -105,    39,   -64,   548,  -105,  -105,  -105,  -105,  -105,
       0,   568,  -105,   569,   209,  -105,  -106,  -105,   210,    22,
    -105,   575,   134,    23,     0,    24,  -106,  -105,  -105,   570,
    -106,  -106,  -106,  -106,  -106,   571,   576,  -106,   577,   209,
    -106,  -103,  -106,   210,   130,  -106,   131,   150,   578,    29,
     579,  -103,  -106,  -106,   133,  -103,  -103,  -103,  -103,  -103,
     580,   581,  -103,     0,     0,  -103,     0,  -103,     0,    30,
    -103,    73,    17,    18,    20,    74,     0,  -103,  -103,     0,
     134,   -63,     0,     0,   152,    32,   131,   153,    33,    34,
       0,     0,    35,     0,   133,    36,    30,    37,    73,     0,
      38,   285,    74,   131,   572,    75,     0,    39,   -64,     0,
       0,   133,    32,     0,   112,    33,    34,     0,     0,    35,
     134,     0,    36,    30,    37,    73,     0,    38,     0,    74,
       0,     0,    75,     0,    39,   -64,     0,   134,     0,    32,
     424,     0,    33,    34,     0,     0,    35,     0,    30,    36,
      31,    37,     0,   168,    38,   131,   169,     0,     0,    75,
    -130,    39,   -64,   133,    32,  -130,  -130,    33,    34,     0,
       0,    35,     0,     0,    36,     0,    37,     0,    30,    38,
      73,     0,     0,     0,    74,     0,    39,   -64,     0,   134,
     554,     0,     0,   152,    32,   131,   153,    33,    34,     0,
       0,    35,     0,   200,    36,    30,    37,    73,     0,    38,
       0,    74,     0,   120,    75,     0,    39,   -64,     0,    56,
       0,    32,     0,    62,    33,    34,    56,    62,    35,   134,
      94,    36,    31,    37,    22,     0,    38,   287,    23,   131,
      24,    75,     0,    39,   181,     0,    32,   133,    56,    33,
      34,     0,   294,    35,   131,    96,    36,    31,    37,     0,
       0,    38,   133,     0,     0,     0,     0,     0,    39,   -64,
       0,    32,     0,   134,    33,    34,     0,   297,    35,   131,
     182,    36,    31,    37,     0,     0,    38,   133,   134,     0,
       0,     0,     0,    39,   148,     0,    32,     0,     0,    33,
      34,     0,   130,    35,   131,    30,    36,    31,    37,     0,
       0,    38,   133,   134,     0,     0,     0,     0,    39,   183,
       0,    32,     0,     0,    33,    34,     0,   324,    35,   131,
      96,    36,    31,    37,     0,     0,    38,   133,   134,     0,
       0,     0,     0,    39,   -64,     0,    32,     0,     0,    33,
      34,     0,     0,    35,   118,    96,    36,    31,    37,     0,
       0,    38,     0,   134,     0,     0,   -24,     0,    39,  -180,
       0,    32,     0,   -24,    33,    34,     0,   -24,    35,   -24,
      96,    36,    31,    37,     0,    55,    38,     0,     0,     0,
       0,     0,     0,    39,  -181,     0,    32,     0,     0,    33,
      34,     0,     0,    35,     0,     0,    36,    54,    37,   -22,
     130,    38,   131,     0,   201,   202,     0,     0,    39,  -171,
     133,   -22,     0,   -22,     0,   -22,   -22,   -22,    22,     0,
     -22,     0,    23,   -22,    24,   -22,     0,    69,   -22,   -22,
      55,     0,     0,     0,     0,   -22,   134,   254,     0,     0,
       0,    61,     0,   -22,     0,   -22,   -22,   -22,    22,     0,
     -22,     0,    23,   -22,    24,   -22,     0,    60,   -22,   -54,
      55,     0,   130,     0,   131,   -22,   201,   202,     0,     0,
       0,    61,   133,   -54,     0,   -54,   -54,   -54,    22,     0,
     -54,     0,    23,   -54,    24,   -54,     0,    71,   -54,   -54,
       0,     0,   130,     0,   131,   -54,  -246,  -246,   134,   290,
       0,    61,   133,   -54,     0,   -54,   -54,   -54,    22,     0,
     -54,     0,    23,   -54,    24,   -54,     0,   115,   -54,   116,
       0,     0,     0,     0,     0,   -54,     0,     0,   134,  -246,
       0,   -35,     0,   -35,     0,   -35,   -35,   -35,   -35,     0,
     -35,     0,   -35,   -35,   -35,   -35,     0,   438,   -35,   -54,
       0,     0,     0,     0,     0,   -35,     0,     0,     0,     0,
       0,    61,     0,   -54,     0,   -54,   -54,   -54,    22,     0,
     -54,     0,    23,   -54,    24,   -54,     0,    50,   -54,    31,
       0,     0,     0,     0,     0,   -54,     0,     0,     0,     0,
       0,     0,     0,    32,     0,   -64,    33,    34,    22,     0,
      35,     0,    23,    36,    24,    37,     0,    13,    38,   -13,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,   -13,     0,   -13,   -13,   -13,     0,    14,
     -13,     0,    19,   -13,   -13,   -13,     0,     0,   -13,     0,
       0,     0,     0,     0,     0,   -13,     0,     0,   -13,     0,
     -13,   -13,   -13,     0,    14,   -13,     0,    30,   -13,    31,
     -13,     0,     0,   -13,     0,     0,     0,     0,     0,     0,
     -13,     0,     0,    32,     0,   -64,    33,    34,     0,     0,
      35,     0,    52,    36,    31,    37,     0,     0,    38,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    32,     0,
     -64,    33,    34,     0,     0,    35,     0,    96,    36,    31,
      37,     0,     0,    38,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    32,     0,    97,    33,    34,     0,     0,
      35,     0,    96,    36,    31,    37,     0,     0,    38,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    32,     0,
     108,    33,    34,     0,     0,    35,     0,    96,    36,    31,
      37,     0,     0,    38,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    32,     0,   109,    33,    34,     0,     0,
      35,     0,    96,    36,    31,    37,     0,     0,    38,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    32,     0,
     111,    33,    34,     0,     0,    35,     0,   113,    36,    31,
      37,     0,     0,    38,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    32,     0,   114,    33,    34,     0,     0,
      35,     0,    30,    36,    31,    37,     0,     0,    38,     0,
       0,     0,     0,     0,   -64,    39,     0,     0,    32,     0,
       0,    33,    34,     0,     0,    35,     0,   529,    36,    31,
      37,     0,     0,    38,     0,     0,     0,     0,     0,   -64,
      39,     0,     0,    32,     0,     0,    33,    34,     0,     0,
      35,     0,     0,    36,   316,    37,    31,     0,    38,     0,
     521,     0,     0,     0,     0,    39,     0,    96,     0,    31,
      32,     0,     0,    33,    34,     0,     0,    35,     0,   551,
      36,     0,    37,    32,     0,    38,    33,    34,     0,     0,
      35,     0,    39,    36,    96,    37,    31,     0,    38,     0,
       0,     0,     0,     0,     0,    39,   552,    96,     0,    31,
      32,     0,     0,    33,    34,     0,     0,    35,     0,   553,
      36,     0,    37,    32,     0,    38,    33,    34,     0,     0,
      35,     0,    39,    36,   555,    37,    31,     0,    38,     0,
       0,     0,     0,     0,     0,    39,   556,   316,     0,    31,
      32,     0,     0,    33,    34,     0,     0,    35,     0,     0,
      36,     0,    37,    32,     0,    38,    33,    34,     0,     0,
      35,     0,    39,    36,   344,    37,    31,     0,    38,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
      32,     0,     0,    33,    34,     0,     0,    35,     0,     0,
      36,     0,    37,   494,     0,    38,     0,     0,     0,     0,
       0,     0,    39,     0,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   513,   514,   516
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-360)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      30,   360,    32,     1,     3,    30,    28,    29,    55,   368,
     369,   370,   371,   372,    15,    40,    17,    18,    19,    20,
      50,    68,    52,    48,    49,    50,    51,    52,    53,   218,
     215,   216,   221,   222,     1,    33,     1,     1,    39,   224,
     225,   201,   227,   228,     1,     1,     1,    13,    14,   209,
     210,    76,     1,    19,     1,    21,     1,    37,     1,    25,
       3,     4,    28,    29,    94,   250,    96,     1,    11,    94,
      95,   231,    39,     1,    39,    39,    35,    36,    34,    34,
     110,   266,    39,   113,    50,   110,     1,     1,    37,     1,
      37,     3,     1,    38,    37,    61,     1,   257,    41,    11,
      74,    75,    36,     8,     9,    79,    80,     1,    36,     3,
       4,    85,    86,    87,    88,    85,    86,    11,    92,    93,
      35,    36,    92,    93,    38,    37,     1,    39,    37,    41,
       1,   291,     3,    38,     1,    12,     1,    12,     5,     1,
       5,     3,   189,    37,   191,   192,     1,    41,     3,    11,
       1,     1,   182,     3,     1,   129,    11,     1,    13,     3,
     134,    11,    17,    18,    19,    20,    21,    11,     1,    24,
       3,    38,    27,    38,    29,    37,    11,    32,    11,    41,
       1,     1,    37,    34,    39,    40,    41,    37,     8,     9,
      37,    41,     1,    37,     3,     1,   226,    41,     1,    34,
       1,   226,    11,     1,    37,    40,     7,     5,    41,   568,
     569,   570,   571,   572,   573,   574,     1,    38,    38,     1,
     405,     3,    25,   248,   249,   250,   251,   387,    37,    11,
       1,    37,    41,   422,   264,   265,   266,   267,     1,     1,
      38,   215,   216,   217,   218,     8,     9,   221,   222,     1,
     224,   225,    37,   227,   228,    37,     0,   231,   232,    41,
     234,     1,     1,     1,   234,    36,   240,   241,   242,   243,
     240,   241,   242,   243,    36,    38,   250,    34,     0,     1,
       1,     3,     3,     1,    36,     7,   316,     5,     6,     7,
       1,     1,   266,     3,    33,    17,    36,    19,    20,    21,
      38,    11,    24,    30,     1,    27,     1,    29,     3,     3,
      32,   341,     3,    34,   344,    37,    11,    39,    40,     1,
      38,    18,    17,    34,    11,    20,    21,    37,     1,    24,
       3,    41,    27,     1,    29,     3,     7,    32,    11,     1,
      34,     3,    37,    11,    39,     3,    41,    34,    30,    11,
       1,     1,   374,    11,   376,   377,   378,   379,     1,     1,
       3,     3,    12,    14,    37,    16,     7,     1,    41,    37,
       1,     5,   397,    41,    17,    37,    10,    20,    21,    41,
       3,    24,     3,    14,    27,    16,    29,    30,    11,    32,
     420,    36,    34,   418,   419,   420,    39,    40,   423,   424,
     425,   426,     1,     1,    38,    38,     1,     5,     3,     8,
       5,     6,    10,   387,     1,    10,    11,    37,     1,   441,
       3,     8,     5,     6,     1,     8,     9,    10,     5,    38,
      13,   405,     1,    10,    17,    18,    19,    20,    21,    38,
      38,    24,    37,    38,    27,    14,    29,    16,   422,    32,
     451,    38,     3,   454,   455,    38,    39,    40,     1,    38,
      11,    38,     5,     6,     3,     8,     9,    10,   493,   494,
       1,   496,    11,    38,     5,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,     5,     6,   495,    38,   497,   498,   499,   529,
     474,   526,   527,   528,   529,   530,     1,    38,     3,    36,
       1,     1,     3,     3,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     9,   555,    17,    18,    19,    20,
      21,    37,     1,    24,     3,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     1,     3,    38,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     9,    37,    17,    18,    19,    20,
      21,    37,    38,    24,    11,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     1,     3,    38,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     9,    11,    17,    18,    19,    20,
      21,    37,    38,    24,    38,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     1,     3,    38,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     9,    38,    17,    18,    19,    20,
      21,    37,    38,    24,    38,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     1,     3,    38,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     1,    38,    17,    18,    19,    20,
      21,    37,    38,    24,    11,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,    38,     3,    38,     5,     6,     1,     8,     9,    10,
      11,    11,    13,     8,     5,     6,    17,    18,    19,    20,
      21,    37,    38,    24,    38,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     7,     3,    38,     5,     6,     7,     8,     9,    10,
      11,     1,     1,     3,     3,    11,    17,    18,     7,    20,
      21,    37,    38,    24,    11,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    37,    38,    39,    40,
       1,     1,     3,     3,     5,     6,     1,     8,     9,    10,
       5,    11,    13,     8,     9,    34,    17,    18,    19,    20,
      21,    37,    38,    24,    36,     1,    27,     3,    29,     5,
       6,    32,     8,     9,    10,    11,    91,    38,    39,    40,
       1,    39,     3,    38,     5,     6,     3,     8,     9,    10,
     105,   106,    13,    36,    11,   202,    17,    18,    19,    20,
      21,    37,    38,    24,   211,   212,    27,     1,    29,     3,
       1,    32,     3,     7,     1,     1,     3,    38,    39,    40,
      11,    15,     8,    17,     1,    19,    20,    21,    22,    36,
      24,     8,    26,    27,    28,    29,    34,     1,    32,     3,
      34,     5,     6,    37,     1,    39,    40,    11,    36,    13,
       7,    34,    38,    17,    18,    19,    20,    21,     5,     6,
      24,    38,     1,    27,     3,    29,     5,     6,    32,     8,
       9,    34,    36,    37,    13,    39,    40,     1,    17,    18,
      19,    20,    21,    36,     8,    24,    36,     1,    27,     3,
      29,     5,     6,    32,     8,     9,    10,    11,    36,    38,
      39,    40,     1,    17,     1,    36,    20,    21,     5,     8,
      24,     8,     9,    27,    38,    29,    36,     1,    32,     3,
       4,    36,    13,    37,    38,    39,    40,    11,    19,    13,
      39,    39,     1,    17,    18,    19,    20,    21,     7,    38,
      24,    38,     1,    27,    39,    29,     5,    39,    32,     8,
       9,    36,     1,    37,     3,    39,    40,     1,     7,     3,
      11,     5,     6,     1,    13,     3,    10,    11,    17,    18,
      19,    20,    21,    36,    36,    24,     1,     1,    27,    38,
      29,    30,     7,    32,     8,     1,    36,     3,    37,     1,
      39,    40,     1,    37,     3,     7,     5,     6,     7,     1,
      18,     3,    11,     5,     6,    38,     8,     9,    17,    11,
      38,    20,    21,    18,    38,    24,    36,     1,    27,     3,
      29,     5,     6,    32,     8,     9,    10,    11,    37,    38,
      39,    40,     1,    18,     3,    37,    38,     1,     7,    18,
       1,     5,     6,     7,    13,    18,    10,     8,    17,    18,
      19,    20,    21,    37,    38,    24,     1,     1,    27,    33,
      29,     5,     1,    32,     3,    33,    10,     1,    37,     3,
      39,    40,     1,     7,    38,     1,    33,    38,     1,    13,
       3,     4,     1,    17,     3,    19,    20,    21,    11,     1,
      24,     3,     1,    27,     3,    29,    22,    40,    32,    11,
      26,    33,    28,    37,    13,    39,    40,    40,    17,    18,
      19,    20,    21,    33,    37,    24,    33,     1,    27,    33,
      29,     5,     6,    32,    36,    37,    33,     1,    37,     3,
      39,    40,     1,     7,     3,    33,     5,     6,     1,    13,
       3,    10,    11,    17,    33,    19,    20,    21,    33,     1,
      24,     3,    40,    27,     1,    29,     3,     1,    32,     3,
       7,    40,    40,    37,    40,    39,    40,    34,    37,    38,
      17,     7,    19,    20,    21,    34,     1,    24,     3,     1,
      27,     3,    29,     5,     7,    32,    11,    34,     1,     3,
      37,    13,    39,    40,     3,    17,    18,    19,    20,    21,
      -1,    36,    24,    36,     1,    27,     3,    29,     5,    22,
      32,    11,    37,    26,    -1,    28,    13,    39,    40,    36,
      17,    18,    19,    20,    21,    36,    11,    24,    11,     1,
      27,     3,    29,     5,     1,    32,     3,     4,    11,    14,
      11,    13,    39,    40,    11,    17,    18,    19,    20,    21,
      11,    11,    24,    -1,    -1,    27,    -1,    29,    -1,     1,
      32,     3,    10,    11,    12,     7,    -1,    39,    40,    -1,
      37,    13,    -1,    -1,     1,    17,     3,     4,    20,    21,
      -1,    -1,    24,    -1,    11,    27,     1,    29,     3,    -1,
      32,     1,     7,     3,    36,    37,    -1,    39,    40,    -1,
      -1,    11,    17,    -1,    19,    20,    21,    -1,    -1,    24,
      37,    -1,    27,     1,    29,     3,    -1,    32,    -1,     7,
      -1,    -1,    37,    -1,    39,    40,    -1,    37,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    24,    -1,     1,    27,
       3,    29,    -1,     1,    32,     3,     4,    -1,    -1,    37,
      13,    39,    40,    11,    17,    18,    19,    20,    21,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    -1,     1,    32,
       3,    -1,    -1,    -1,     7,    -1,    39,    40,    -1,    37,
      13,    -1,    -1,     1,    17,     3,     4,    20,    21,    -1,
      -1,    24,    -1,    11,    27,     1,    29,     3,    -1,    32,
      -1,     7,    -1,     1,    37,    -1,    39,    40,    -1,    21,
      -1,    17,    -1,    25,    20,    21,    28,    29,    24,    37,
       1,    27,     3,    29,    22,    -1,    32,     1,    26,     3,
      28,    37,    -1,    39,    40,    -1,    17,    11,    50,    20,
      21,    -1,     1,    24,     3,     1,    27,     3,    29,    -1,
      -1,    32,    11,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    17,    -1,    37,    20,    21,    -1,     1,    24,     3,
       1,    27,     3,    29,    -1,    -1,    32,    11,    37,    -1,
      -1,    -1,    -1,    39,    40,    -1,    17,    -1,    -1,    20,
      21,    -1,     1,    24,     3,     1,    27,     3,    29,    -1,
      -1,    32,    11,    37,    -1,    -1,    -1,    -1,    39,    40,
      -1,    17,    -1,    -1,    20,    21,    -1,     1,    24,     3,
       1,    27,     3,    29,    -1,    -1,    32,    11,    37,    -1,
      -1,    -1,    -1,    39,    40,    -1,    17,    -1,    -1,    20,
      21,    -1,    -1,    24,     3,     1,    27,     3,    29,    -1,
      -1,    32,    -1,    37,    -1,    -1,    15,    -1,    39,    40,
      -1,    17,    -1,    22,    20,    21,    -1,    26,    24,    28,
       1,    27,     3,    29,    -1,    34,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    17,    -1,    -1,    20,
      21,    -1,    -1,    24,    -1,    -1,    27,     1,    29,     3,
       1,    32,     3,    -1,     5,     6,    -1,    -1,    39,    40,
      11,    15,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      34,    -1,    -1,    -1,    -1,    39,    37,    38,    -1,    -1,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      34,    -1,     1,    -1,     3,    39,     5,     6,    -1,    -1,
      -1,    15,    11,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      -1,    -1,     1,    -1,     3,    39,     5,     6,    37,    38,
      -1,    15,    11,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    37,    38,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,     1,    32,     3,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    -1,    23,
      24,    -1,     1,    27,     3,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    17,    -1,
      19,    20,    21,    -1,    23,    24,    -1,     1,    27,     3,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    17,    -1,    19,    20,    21,    -1,    -1,
      24,    -1,     1,    27,     3,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    17,    -1,
      19,    20,    21,    -1,    -1,    24,    -1,     1,    27,     3,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    17,    -1,    19,    20,    21,    -1,    -1,
      24,    -1,     1,    27,     3,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    17,    -1,
      19,    20,    21,    -1,    -1,    24,    -1,     1,    27,     3,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    17,    -1,    19,    20,    21,    -1,    -1,
      24,    -1,     1,    27,     3,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    17,    -1,
      19,    20,    21,    -1,    -1,    24,    -1,     1,    27,     3,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    17,    -1,    19,    20,    21,    -1,    -1,
      24,    -1,     1,    27,     3,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    13,    39,    -1,    -1,    17,    -1,
      -1,    20,    21,    -1,    -1,    24,    -1,     1,    27,     3,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    13,
      39,    -1,    -1,    17,    -1,    -1,    20,    21,    -1,    -1,
      24,    -1,    -1,    27,     1,    29,     3,    -1,    32,    -1,
       7,    -1,    -1,    -1,    -1,    39,    -1,     1,    -1,     3,
      17,    -1,    -1,    20,    21,    -1,    -1,    24,    -1,    13,
      27,    -1,    29,    17,    -1,    32,    20,    21,    -1,    -1,
      24,    -1,    39,    27,     1,    29,     3,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    13,     1,    -1,     3,
      17,    -1,    -1,    20,    21,    -1,    -1,    24,    -1,    13,
      27,    -1,    29,    17,    -1,    32,    20,    21,    -1,    -1,
      24,    -1,    39,    27,     1,    29,     3,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    13,     1,    -1,     3,
      17,    -1,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    17,    -1,    32,    20,    21,    -1,    -1,
      24,    -1,    39,    27,     1,    29,     3,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,   448,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    25,    43,     3,     1,     3,     0,     1,    12,
      12,     1,    12,     1,    23,    45,    47,    45,    45,     1,
      45,     1,    22,    26,    28,    48,    51,    56,     1,    48,
       1,     3,    17,    20,    21,    24,    27,    29,    32,    39,
      64,    67,    74,    77,    79,    81,    88,    90,    64,    64,
       1,    64,     1,    64,     1,    34,    51,    57,    58,    59,
       1,    15,    51,    56,    60,    62,    50,     1,    34,     1,
      60,     1,    60,     3,     7,    37,    64,    67,    88,     1,
       7,     1,    88,     1,     3,     1,    37,     1,    37,     1,
      37,    37,     1,    37,     1,    64,     1,    19,    67,    66,
      72,    71,    68,    70,    73,     1,    37,    87,    19,    19,
       1,    19,    19,     1,    19,     1,     3,    53,     3,    63,
       1,    56,    49,     1,     3,    53,     1,    53,    46,     7,
       1,     3,     4,    11,    37,   108,   111,   114,     1,     3,
       4,    11,    41,    92,    99,   102,   105,   108,    40,    30,
       4,   108,     1,     4,   108,    30,     1,    30,     7,     1,
       7,     1,    99,   108,     1,    99,     4,   108,     1,     4,
     108,     3,     1,     3,     1,     3,    11,    92,    99,     1,
      99,    40,     1,    40,    65,    92,     1,    92,    44,    35,
      36,     1,    35,    36,     7,     3,     7,     1,     7,    52,
      11,     5,     6,   108,   116,    36,   117,     1,   108,     1,
       5,     1,     6,   110,   113,     8,     9,    10,    37,    38,
      38,     1,    37,    38,     1,     8,    38,     1,     9,   101,
     104,     1,    10,    38,    37,    36,    36,     1,    36,    80,
      37,    37,     1,    37,    11,    11,     1,    11,    38,    38,
       1,    38,    38,    38,    38,     1,    38,     1,    38,    38,
      38,     1,    38,    38,    38,    38,     1,    38,    89,    38,
      38,     1,    38,    53,    53,     1,    53,    55,    11,     7,
      11,    11,     1,    11,    34,     1,   111,     1,   114,    38,
      38,     1,    38,   111,     1,   111,   114,     1,   114,     1,
     102,   102,   108,     1,   105,   108,    36,    36,     1,   105,
       1,   105,    39,   102,     1,   102,     1,    67,    88,   102,
       1,   102,   108,   111,     1,   108,    36,    99,    69,    99,
      99,    99,     1,    99,    34,    34,    34,     1,    34,    67,
      67,     1,     3,    67,     1,    67,    36,    36,    36,    36,
       1,    36,    36,     1,    36,    36,    36,    36,     1,    36,
      39,     1,    88,    88,     1,    88,     1,    88,    39,    39,
      39,     1,    39,    54,    36,    11,    36,    36,    36,     1,
      36,     3,    11,   115,   109,   112,    38,     1,    38,    38,
       1,    38,     1,    14,    16,    93,   100,    18,   103,   107,
      38,    38,    38,    38,    38,     1,    38,     3,    11,     3,
      11,     3,    11,     3,    11,     1,     3,    11,    18,    18,
       1,     3,    37,    18,    18,     1,    18,    76,    75,    78,
      93,    83,    93,    93,    93,    93,     1,    93,     1,    56,
      60,    36,    60,    60,    60,    60,     1,    33,    33,   106,
      11,    34,     1,    11,     1,    34,    40,    67,    86,    33,
      33,    33,    33,    33,    33,    33,    33,    33,     1,    33,
       1,    33,    67,    67,    37,     1,   105,   108,    67,    67,
      67,    67,    40,    40,    40,    40,    40,    40,     1,     1,
      60,     1,     3,    96,    96,    34,    64,    34,     1,    34,
      64,    64,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,     1,    96,    96,     1,    96,    38,    82,    91,
      61,     7,     1,     7,    67,    67,    64,    64,    64,     1,
      64,    95,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,     3,     3,     1,
       3,    13,    13,    13,    13,     1,    13,    85,    84,     5,
       6,     5,     6,     5,     6,     1,     5,     6,    36,    36,
      36,    36,    36,     1,    36,    11,    11,    11,    11,    11,
      11,    11,     1,    11,     1,    11,    93,    93,    93,    93,
      93,    93,     1,    93,    97,    98,    94
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 102 "cpm.y"
    {fprintf(stderr, "program done\n");}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 103 "cpm.y"
    {	 

	 if(ErrorFlag == 0)
	 {
	 	char* s = (char*)malloc(sizeof(char*)*1000);
		s[0]='\0';
		if((yyvsp[(5) - (7)].mips).head==NULL)
		   (yyvsp[(5) - (7)].mips).head="";
		if((yyvsp[(4) - (7)].dec).bodyCode==NULL)
		   (yyvsp[(4) - (7)].dec).bodyCode="";
		sprintf(s,".data\n%s\n%s\nstrBuff: .space 200\n.text\nmain:\n%s\n%s\n",(yyvsp[(4) - (7)].dec).headCode,(yyvsp[(5) - (7)].mips).head,(yyvsp[(4) - (7)].dec).bodyCode,(yyvsp[(5) - (7)].mips).body);
		MIPSCode = s; 
	 
	 }
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 118 "cpm.y"
    {PrintListingErrors("program is missing"); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 119 "cpm.y"
    {PrintListingErrors("id is missing");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 120 "cpm.y"
    {PrintListingErrors("bgn is missing");}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 121 "cpm.y"
    {PrintListingErrors("declarations is missing");}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 122 "cpm.y"
    {PrintListingErrors("stmtlist is missing");}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 123 "cpm.y"
    {PrintListingErrors("end is missing");}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 124 "cpm.y"
    {PrintListingErrors("program unexpected error");}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 129 "cpm.y"
    {fprintf(stderr, " declarations done\n");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 130 "cpm.y"
    {
		    (yyval.dec).headCode = strdup(strcat((yyvsp[(2) - (4)].dec).headCode,(yyvsp[(3) - (4)].dec).headCode));
		    (yyval.dec).bodyCode = strdup((yyvsp[(3) - (4)].dec).bodyCode);
	    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 134 "cpm.y"
    {printf("DECLARATIONS -> empty \n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 135 "cpm.y"
    {
		    (yyval.dec).headCode = strdup(""); 
		    (yyval.dec).bodyCode = strdup("");
	    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 139 "cpm.y"
    {PrintListingErrors("let is missing from declarations");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 140 "cpm.y"
    {PrintListingErrors("declaration list is missing from declarations");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 141 "cpm.y"
    {PrintListingErrors("code declaration is missing from declarations");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 145 "cpm.y"
    {fprintf(stderr, " declarlist done\n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 146 "cpm.y"
    {
		   (yyval.dec).headCode = StringCat((yyvsp[(1) - (3)].dec).headCode,(yyvsp[(2) - (3)].dec).headCode);
	    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 149 "cpm.y"
    {fprintf(stderr, " declarlist -> decl done \n");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 150 "cpm.y"
    {
		   (yyval.dec).headCode = strdup((yyvsp[(1) - (2)].dec).headCode);
	    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 153 "cpm.y"
    {PrintListingErrors("decl is missing from declarations");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 154 "cpm.y"
    {PrintListingErrors("declaration list is missing from declarations");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 155 "cpm.y"
    {PrintListingErrors("declaration is missing from declarations");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 158 "cpm.y"
    {fprintf(stderr, " decl done\n");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 159 "cpm.y"
    {
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStrTmp = (char*)malloc(sizeof(char)*256);
	 headCodeStr[0]='\0';
	 headCodeStrTmp[0]='\0';
	
	 int i;

	 for(i = 0 ; i < 3 ; i++)
	 {
	  if((yyvsp[(3) - (4)].dec).varList[i] != NULL)
	  {
	   if(lookup((yyvsp[(3) - (4)].dec).varList[i]) == NULL)
	   {
	    installSymTable((yyvsp[(3) - (4)].dec).varList[i],(yyvsp[(1) - (4)].dec).type,0);
	    if(!strcmp((yyvsp[(1) - (4)].dec).type,"string"))
	    {
	     sprintf(headCodeStrTmp,"%s: .space 200\n",(yyvsp[(3) - (4)].dec).varList[i]);
	     strcat(headCodeStr,headCodeStrTmp);
	    }
	    else
	    {
	     sprintf(headCodeStrTmp,"%s: .space 8\n",(yyvsp[(3) - (4)].dec).varList[i]);
	     strcat(headCodeStr,headCodeStrTmp);
	    }
	   }
	  }
	 }
	
	(yyval.dec).headCode = strdup(headCodeStr);
	free(headCodeStr);
	free(headCodeStrTmp);
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 192 "cpm.y"
    {PrintListingErrors("unknown type");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 193 "cpm.y"
    {PrintListingErrors("colon is missing");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 194 "cpm.y"
    {PrintListingErrors("decl unexpected error");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 200 "cpm.y"
    {fprintf(stderr, "list done\n");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 201 "cpm.y"
    {
	symbol* symPointer = lookup((yyvsp[(1) - (4)].sval));
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat((yyvsp[(1) - (4)].sval),"is multiply defined"));
		}
	}
	else
	{
		int i, j;
		 for(i = 0 ; i < 3 ; i++)
		 {
		  if((yyval.dec).varList[i] == NULL)
		  {
		   (yyval.dec).varList[i] = (yyvsp[(1) - (4)].sval);
		   for(j = 0 ; j < 3 ; j++)
		   {
		     if((yyvsp[(3) - (4)].dec).varList[i] != NULL)
		     {
		      (yyval.dec).varList[i+1] = (yyvsp[(3) - (4)].dec).varList[j];
		      i++;
		     }
		   }
		   break;
		  }
		 }
		//print error if list try to be more then 3 origans
		 if ((yyvsp[(3) - (4)].dec).varList[3] != NULL)
		 {
			PrintListingErrors("List can be only with 3 origans");
		 }
	}
	

}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 239 "cpm.y"
    {fprintf(stderr, "ID in list done\n");}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 240 "cpm.y"
    {
	symbol* symPointer = lookup((yyvsp[(1) - (3)].sval));
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat((yyvsp[(1) - (3)].sval),"is multiply defined"));
		}
	}
	else
	{

	 printf("LIST -> ID ';' \n");
	 int i;
	 for(i = 0 ; i < 3 ; i++)
	 {
	  if((yyval.dec).varList[i] == NULL)
	  {
	   (yyval.dec).varList[i] = (yyvsp[(1) - (3)].sval);
	   break;
	  }
	 }
	}
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 265 "cpm.y"
    {PrintListingErrors("ID befor semicolon is missing");}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 266 "cpm.y"
    {PrintListingErrors(StringCat("semicolon is missing after ",(yyvsp[(1) - (2)].sval)));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 267 "cpm.y"
    {PrintListingErrors("ID is missing from list");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 268 "cpm.y"
    {PrintListingErrors("missing ',' in list of variables");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 269 "cpm.y"
    {PrintListingErrors(StringCat((yyvsp[(1) - (3)].sval)," is missing after ','"));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 273 "cpm.y"
    {fprintf(stderr, "TYPE -> INT \n");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 274 "cpm.y"
    {
	(yyval.dec).type = strdup("int");
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 277 "cpm.y"
    {fprintf(stderr, "TYPE -> REAL \n");}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 278 "cpm.y"
    {
	(yyval.dec).type = strdup("float");
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 281 "cpm.y"
    {fprintf(stderr, "TYPE -> STRING \n");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 282 "cpm.y"
    {
	(yyval.dec).type = strdup("string");
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 285 "cpm.y"
    {PrintListingErrors("unknown type");}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 288 "cpm.y"
    {fprintf(stderr, " cdecl done\n");}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 289 "cpm.y"
    {
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 headCodeStr[0]='\0';
	 bodyCodeStr[0]='\0';

	symbol* symPointer = lookup((yyvsp[(3) - (8)].sval));
	if(symPointer != NULL)
	{
		if(symPointer->isDeclared)
		{
			
			PrintListingErrors(StringCat((yyvsp[(3) - (8)].sval)," is multiply defined."));
		}

		if(!strcmp(symPointer->type,"string"))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat((yyvsp[(3) - (8)].sval)," type must be int or float. it is allready string type. "));
		}

		if(!(strcmp(symPointer->type,"int") && !strcmp((yyvsp[(5) - (8)].number).type,"float")))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat((yyvsp[(3) - (8)].sval)," type is int and NUM type is float, need to be same type"));
		}
		if(!(strcmp(symPointer->type,"float") && !strcmp((yyvsp[(5) - (8)].number).type,"int")))
		{
			
			sprintf(headCodeStr,"");
			PrintListingErrors(StringCat((yyvsp[(3) - (8)].sval)," type is float and NUM type is int, need to be same type"));
		}

	}

	else
	{
		{fprintf(stderr, " ErrorFlag == 0 in cdecl\n");}
		if(strcmp((yyvsp[(2) - (8)].dec).type,"int")==0)
		{
			sprintf(bodyCodeStr,"li $t0,%d\nsw $t0, %s\n",(yyvsp[(5) - (8)].number).val,(yyvsp[(3) - (8)].sval));
		}

		else
		{
			sprintf(headCodeStr,"%s: .space 8\n",(yyvsp[(3) - (8)].sval));
		}


	}

	installSymTable((yyvsp[(3) - (8)].sval),(yyvsp[(2) - (8)].dec).type,1);
	(yyval.dec).headCode = StringCat(headCodeStr,(yyvsp[(7) - (8)].dec).headCode);
	(yyval.dec).bodyCode = StringCat(bodyCodeStr,(yyvsp[(7) - (8)].dec).bodyCode);

}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 348 "cpm.y"
    {PrintListingErrors("unknown type");}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 349 "cpm.y"
    {PrintListingErrors("ID is missing");}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 350 "cpm.y"
    {PrintListingErrors("assignment operation is missing");}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 351 "cpm.y"
    {PrintListingErrors("number is missing to the right side of the asssignment opeation");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 352 "cpm.y"
    {PrintListingErrors("semicolon is missing");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 353 "cpm.y"
    {PrintListingErrors("cdecl unexpected error");}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 354 "cpm.y"
    {fprintf(stderr, " cdecl is empty\n");}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 355 "cpm.y"
    {
	(yyval.dec).headCode = strdup(""); (yyval.dec).bodyCode = strdup("");
      }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 358 "cpm.y"
    {PrintListingErrors("decleration is empty");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 359 "cpm.y"
    {
	(yyval.dec).headCode = strdup(""); (yyval.dec).bodyCode = strdup("");
      }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 368 "cpm.y"
    {fprintf(stderr, " stmtlist done\n");}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 369 "cpm.y"
    {
		(yyval.mips).body = StringCat((yyvsp[(1) - (3)].mips).body,(yyvsp[(2) - (3)].mips).body);
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 372 "cpm.y"
    {fprintf(stderr, "stmtlist -> stmtlist is epsilon, and we got stmt\n");}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 373 "cpm.y"
    {
		(yyval.mips).head = strdup((yyvsp[(1) - (2)].mips).head); (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);
	}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 377 "cpm.y"
    {PrintListingErrors("stmtlist is missing ");}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 378 "cpm.y"
    {PrintListingErrors("stmt is missing ");}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 379 "cpm.y"
    {fprintf(stderr, "stmtlist -> empty\n");}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 383 "cpm.y"
    {fprintf(stderr, " stmt->assignment_stmt done \n");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 384 "cpm.y"
    {
	 (yyval.mips).head = strdup((yyvsp[(1) - (2)].mips).head);
	 (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 388 "cpm.y"
    {fprintf(stderr, " stmt done \n");}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 389 "cpm.y"
    {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg = getTempRegister();
	 bodyCodeStr[0]='\0';
	 headCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 symbol* symPointer = lookup((yyvsp[(1) - (5)].sval));
	 if (symPointer !=NULL)
	 {
	  if(!symPointer->isDeclared)
	  {
	  PrintListingErrors(StringCat((yyvsp[(1) - (5)].sval)," must declare before assignment!"));   
	  sprintf(bodyCodeStr,"");
	 
	  }
	  else if(symPointer->isConst == 0)
	  {
	   if(!strcmp(symPointer->type,"string"))
	   {
	    sprintf(headCodeStr,"%s: .asciiz %s\n",label,(yyvsp[(3) - (5)].sval));
	    sprintf(bodyCodeStr,"lw %s, %s\nsw %s, %s\n",reg,label,reg,(yyvsp[(1) - (5)].sval));
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
	 (yyval.mips).head = strdup(headCodeStr);
	 (yyval.mips).body = strdup(bodyCodeStr);
	 free(headCodeStr);
	 free(bodyCodeStr);
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 448 "cpm.y"
    {fprintf(stderr, " stmt->control_stmt done \n");}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 449 "cpm.y"
    {
	 (yyval.mips).head = strdup((yyvsp[(1) - (2)].mips).head);
	 (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);
	 fprintf(stderr, " we on stmt->control stmt\n");
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 454 "cpm.y"
    {fprintf(stderr, " stmt->read_stmt done \n");}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 455 "cpm.y"
    {
	 (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);	
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 458 "cpm.y"
    {fprintf(stderr, " stmt->out_stmt done \n");}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 459 "cpm.y"
    {
	 (yyval.mips).head = strdup((yyvsp[(1) - (2)].mips).head);
	 (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 463 "cpm.y"
    {fprintf(stderr, " stmt->stmt_block done \n");}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 464 "cpm.y"
    {
	 (yyval.mips).head = strdup((yyvsp[(1) - (2)].mips).head);
	 (yyval.mips).body = strdup((yyvsp[(1) - (2)].mips).body);
    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 468 "cpm.y"
    {PrintListingErrors("assignment_stmt or control_stmt or read_stmt or out_stmt or stmt_block is missing ");}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 469 "cpm.y"
    {PrintListingErrors("ID is missing ");}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 470 "cpm.y"
    {PrintListingErrors("ASSIGNOP is missing ");}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 471 "cpm.y"
    {PrintListingErrors("SENTENCE is missing ");}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 472 "cpm.y"
    {PrintListingErrors("';' is missing ");}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 476 "cpm.y"
    {fprintf(stderr, " out_stmt -> out(expression) done \n");}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 477 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 bodyCodeStr[0]='\0';
		 if(!strcmp((yyvsp[(3) - (6)].dec).type,"int"))
		 {
		    fprintf(stderr, " int in out_stmt - > out\n");
		    sprintf(bodyCodeStr,"li $v0,1\nmove $a0,%s\n syscall\n",(yyvsp[(3) - (6)].dec).reg);
		  }
		 else if(!strcmp((yyvsp[(3) - (6)].dec).type,"float"))
		 {
		    fprintf(stderr, " int in out_stmt - > out\n");
		    sprintf(bodyCodeStr,"li $v0,2\nmove $f12,%s\n syscall\n",(yyvsp[(3) - (6)].dec).reg);
		  }
		 else{
		   fprintf(stderr, " type  :  %s \n", (yyvsp[(3) - (6)].dec).type);
	            }

		 (yyval.mips).head = (yyvsp[(3) - (6)].dec).headCode;
		 (yyval.mips).body = StringCat((yyvsp[(3) - (6)].dec).bodyCode,bodyCodeStr);
		 free(bodyCodeStr);
      }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 498 "cpm.y"
    {fprintf(stderr, " out_stmt -> out(sentence) done \n");}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 499 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* headCodeStr = (char*)malloc(sizeof(char)*256);
		 char* label = getLabelNumber();
		 bodyCodeStr[0]='\0';
		 headCodeStr[0]='\0';
		 sprintf(headCodeStr,"%s: .asciiz %s\n",label,(yyvsp[(3) - (6)].sval));
		 sprintf(bodyCodeStr,"la $a0,%s\nli $v0,4\nsyscall\n",label);
		 (yyval.mips).head = strdup(headCodeStr);
		 (yyval.mips).body = strdup(bodyCodeStr);
		 free(headCodeStr);
		 free(bodyCodeStr);
      }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 512 "cpm.y"
    {PrintListingErrors("OUT is missing");}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 513 "cpm.y"
    {PrintListingErrors("'(' is missing");}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 514 "cpm.y"
    {PrintListingErrors("expression or sentence is missing");}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 515 "cpm.y"
    {PrintListingErrors("')' is missing");}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 516 "cpm.y"
    {PrintListingErrors("';' is missing");}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 517 "cpm.y"
    {PrintListingErrors("OUT is missing");}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 518 "cpm.y"
    {PrintListingErrors("'(' is missing");}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 519 "cpm.y"
    {PrintListingErrors("')' is missing");}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 520 "cpm.y"
    {PrintListingErrors("\';\' is missing");}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 521 "cpm.y"
    {PrintListingErrors("expression is empty.");}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 525 "cpm.y"
    {fprintf(stderr, " read_stmt done \n");}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 526 "cpm.y"
    {
		char* bodyCodeStr = (char*)malloc(sizeof(char)*256);	
		bodyCodeStr[0]='\0';
		symbol* symPointer = lookup((yyvsp[(3) - (6)].sval));
		if(symPointer != NULL)
		{
			if(!symPointer->isDeclared)
			{
				
				sprintf(bodyCodeStr,"");

				PrintListingErrors(StringCat((yyvsp[(3) - (6)].sval)," is not declared!"));
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
				PrintListingErrors(StringCat((yyvsp[(3) - (6)].sval)," is not found in symbol table"));
		}
		(yyval.mips).body = strdup(bodyCodeStr);

	}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 571 "cpm.y"
    {PrintListingErrors("READ is missing ");}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 572 "cpm.y"
    {PrintListingErrors("'(' is missing ");}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 573 "cpm.y"
    {PrintListingErrors("ID is missing ");}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 574 "cpm.y"
    {PrintListingErrors("')' is missing ");}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 575 "cpm.y"
    {PrintListingErrors("';' is missing ");}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 581 "cpm.y"
    {fprintf(stderr, " assignment_stmt done \n");}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 582 "cpm.y"
    {
 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
 bodyCodeStr[0]='\0';
 char* reg;
 symbol* symPointer = lookup((yyvsp[(1) - (4)].sval));
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
		PrintListingErrors(StringCat((yyvsp[(1) - (4)].sval)," is not decleare"));
	}
	else
	{
		   symPointer->isInit = 1 ;
		   if(!strcmp((yyvsp[(3) - (4)].dec).type,"int") && !strcmp((yyvsp[(3) - (4)].dec).type,symPointer->type))
		   {
			    sprintf(bodyCodeStr,"sw %s, %s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].sval));
			    freeTempRegister((yyvsp[(3) - (4)].dec).reg);
		   }	
		   else if(!strcmp((yyvsp[(3) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,symPointer->type))
		   {
			    sprintf(bodyCodeStr,"s.s %s, %s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].sval));
			    freeFloatRegister((yyvsp[(3) - (4)].dec).reg);
		   }
		   else
		   {
			    if(!strcmp((yyvsp[(3) - (4)].dec).type,"int") && !strcmp("float",symPointer->type))
			    {
				     reg = getFloatRegister();
				     sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ns.s %s, %s\n",(yyvsp[(3) - (4)].dec).reg,reg,reg,reg,reg,(yyvsp[(1) - (4)].sval));
				     freeTempRegister((yyvsp[(3) - (4)].dec).reg);
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
	PrintListingErrors(StringCat((yyvsp[(1) - (4)].sval)," is not found in symbol table"));
 }

 (yyval.mips).head = strdup((yyvsp[(3) - (4)].dec).headCode);
 (yyval.mips).body = StringCat((yyvsp[(3) - (4)].dec).bodyCode,bodyCodeStr);
 free(bodyCodeStr);

}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 644 "cpm.y"
    {PrintListingErrors("ID is missing ");}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 645 "cpm.y"
    {PrintListingErrors("ASSIGNOP is missing ");}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 646 "cpm.y"
    {PrintListingErrors("expression is missing ");}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 651 "cpm.y"
    {fprintf(stderr, "control_stmt -> if (BOOLEXPR) STMT else STMT \n");}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 652 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen((yyvsp[(5) - (8)].mips).body)+ strlen((yyvsp[(7) - (8)].mips).body)));
		 char* label = getLabelNumber();
		 char* s;
		 bodyCodeStr[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0,Else%s\n%s\nj End%s\nElse%s:\n%s\nEnd%s:\n",(yyvsp[(3) - (8)].dec).reg,label,(yyvsp[(5) - (8)].mips).body,label,label,(yyvsp[(7) - (8)].mips).body,label);	
		 s = StringCat((yyvsp[(5) - (8)].mips).head,(yyvsp[(7) - (8)].mips).head);
		 (yyval.mips).head = StringCat((yyvsp[(3) - (8)].dec).headCode,s);
		 (yyval.mips).body = StringCat((yyvsp[(3) - (8)].dec).bodyCode,bodyCodeStr);
		 freeTempRegister((yyvsp[(3) - (8)].dec).reg);
		 free(s);
		 free(bodyCodeStr);
	    }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 666 "cpm.y"
    {fprintf(stderr, "control_stmt -> while (BOOLEXPR) STMT_BLOCK \n");}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 667 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen((yyvsp[(5) - (6)].mips).body)));
		 char* label = getLabelNumber();
		 char* s = (char*)malloc(sizeof(char)*(50 + strlen((yyvsp[(3) - (6)].dec).bodyCode)));
		 bodyCodeStr[0]='\0';
		 s[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n",(yyvsp[(3) - (6)].dec).reg,label,(yyvsp[(5) - (6)].mips).body,label,label);
		 sprintf(s,"Loop%s:\n",label);
		 strcat(s,(yyvsp[(3) - (6)].dec).bodyCode);
		 (yyval.mips).head = StringCat((yyvsp[(3) - (6)].dec).headCode,(yyvsp[(5) - (6)].mips).head);
		 (yyval.mips).body = StringCat(s,bodyCodeStr);
		 freeTempRegister((yyvsp[(3) - (6)].dec).reg);
		 free(s);
		 free(bodyCodeStr);
	    }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 683 "cpm.y"
    {fprintf(stderr, "control_stmt -> foreach id assignop num:num with STEP STMT  \n");}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 684 "cpm.y"
    {

		char* strBeq = (char*)malloc(sizeof(char)*(256));
		char* strli = (char*)malloc(sizeof(char)*(256));
		char* labelNum = getLabelNumber();
		char* tmpForBody;
		char* startPoint = (yyvsp[(8) - (10)].mips).head; // return the generated register
		char* targetPoint = getTempRegister();
		
		strli[0]='\0';
		strBeq[0]='\0';

		sprintf(strli, "li %s, %d \nli %s, %d \nLoop%s:\n",startPoint,(yyvsp[(4) - (10)].number).val,targetPoint,(yyvsp[(6) - (10)].number).val,labelNum);
		sprintf(strBeq,"beq %s, %s, End%s\n%s\n j Loop%s \nEnd%s:\n",startPoint,targetPoint,labelNum,(yyvsp[(8) - (10)].mips).body,labelNum,labelNum);

		tmpForBody = StringCat(strli, (yyvsp[(9) - (10)].mips).body); 
		(yyval.mips).body = StringCat(tmpForBody, strBeq);
		(yyval.mips).head=strdup("");

		freeTempRegister(targetPoint);
		freeFloatRegister(startPoint);
		free(strli);
		free(tmpForBody);
		free(strBeq);
		

	    }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 713 "cpm.y"
    {fprintf(stderr, "control_stmt -> foreach id assignop num:id with STEP STMT  \n");}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 714 "cpm.y"
    {
			char* strBeq = (char*)malloc(sizeof(char)*(256));
			char* strli = (char*)malloc(sizeof(char)*(256));
			char* labelNum = getLabelNumber();
			char* tmpForBody;
			char* startPoint = (yyvsp[(8) - (10)].mips).head; // return the generated register
			char* targetPoint = getTempRegister();
			
			// create loop variable
			installSymTable((yyvsp[(2) - (10)].sval),"int",0);

			
			strBeq[0]='\0';
			strli[0]='\0';
			
			// str hold to counter increasment
			sprintf(strli, "li %s, %d \nlw %s, %s \nLoop%s:\n",startPoint,(yyvsp[(4) - (10)].number).val,targetPoint,(yyvsp[(6) - (10)].sval),labelNum);

			
			sprintf(strBeq,"beq %s, %s, End%s\n%s\n j Loop%s \nEnd%s:\n",startPoint,targetPoint,labelNum,(yyvsp[(8) - (10)].mips).body,labelNum,labelNum);

			

			tmpForBody = StringCat(strli, (yyvsp[(9) - (10)].mips).body); // $9(STMT) - body/code of loop
			(yyval.mips).body = StringCat(tmpForBody, strBeq);
			(yyval.mips).head=strdup("");

			freeTempRegister(targetPoint);
			freeTempRegister(startPoint);
			free(strli);
			free(tmpForBody);
			free(strBeq);
			


	    }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 751 "cpm.y"
    {fprintf(stderr, "control_stmt -> do STMT_BLOCK till (BOOLEXPR)  \n");}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 752 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen((yyvsp[(2) - (7)].mips).body)));
		 char* labelNum = getLabelNumber();
		 char* s = (char*)malloc(sizeof(char)*(50 + strlen((yyvsp[(5) - (7)].dec).bodyCode)));
		 bodyCodeStr[0]='\0';
		 s[0]='\0';
		 sprintf(bodyCodeStr,"beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n",(yyvsp[(5) - (7)].dec).reg,labelNum,(yyvsp[(2) - (7)].mips).body,labelNum,labelNum);
		 sprintf(s,"Loop%s:\n",labelNum);
		 strcat(s,(yyvsp[(5) - (7)].dec).bodyCode);
		 (yyval.mips).head = StringCat((yyvsp[(5) - (7)].dec).headCode,(yyvsp[(2) - (7)].mips).head);
		 (yyval.mips).body = StringCat(s,bodyCodeStr);
		 freeTempRegister((yyvsp[(5) - (7)].dec).reg);
		 free(s);
		 free(bodyCodeStr);
	    }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 768 "cpm.y"
    {fprintf(stderr, "control_stmt -> switch \n");}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 769 "cpm.y"
    {
		 (yyval.mips).head = strdup((yyvsp[(1) - (2)].dec).headCode);
		 (yyval.mips).body = strdup((yyvsp[(1) - (2)].dec).bodyCode);
	    }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 774 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : if is missing  ");}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 775 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : '(' is missing  "); fprintf(stderr, "control_stmt -> '(' is missing \n");}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 776 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : boolexpr is missing  ");}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 777 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : ')' is missing  ");}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 778 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : stmt after '(' is missing  ");}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 779 "cpm.y"
    {PrintListingErrors("if (BOOLEXPR) STMT else STMT : else is missing  ");}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 781 "cpm.y"
    {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: while is missing  ");}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 782 "cpm.y"
    {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: '(' is missing  ");}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 783 "cpm.y"
    {PrintListingErrors("(BOOLEXPR) STMT_BLOCK: boolexpr is missing  ");}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 784 "cpm.y"
    {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: ')' is missing  ");}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 785 "cpm.y"
    {PrintListingErrors("while (BOOLEXPR) STMT_BLOCK: stmt_block is missing  ");}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 787 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : foreach is missing  ");}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 788 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : id is missing  ");}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 789 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : assignop is missing  ");}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 790 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : num after assignop  is missing  ");}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 791 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : ':'  is missing  ");}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 792 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : with is missing  ");}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 793 "cpm.y"
    {PrintListingErrors("foreach id assignop num:num with STEP STMT : step is missing  ");}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 795 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : foreach is missing  ");}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 796 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : id after foreach is missing  ");}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 797 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : assignop is missing  ");}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 798 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : num after assignop  is missing  ");}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 799 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : ':'  is missing  ");}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 800 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : id or num is missing  ");}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 801 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : with is missing  ");}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 802 "cpm.y"
    {PrintListingErrors("foreach id assignop num:id with STEP STMT : step is missing  ");}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 804 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) :do is missing  ");}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 805 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : stmt_block is missing  ");}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 806 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : till is missing  ");}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 807 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : '(' is missing  ");}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 808 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : boolexpr is missing  ");}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 809 "cpm.y"
    {PrintListingErrors("do STMT_BLOCK till (BOOLEXPR) : ')' is missing  ");}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 815 "cpm.y"
    {fprintf(stderr, " stmt_block done \n");}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 816 "cpm.y"
    {
	 (yyval.mips).head = strdup((yyvsp[(2) - (4)].mips).head);
	 (yyval.mips).body = strdup((yyvsp[(2) - (4)].mips).body);
    }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 820 "cpm.y"
    {PrintListingErrors("'{' is missing ");}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 821 "cpm.y"
    {PrintListingErrors("stmtlist is missing ");}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 822 "cpm.y"
    {PrintListingErrors("'}' is missing ");}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 827 "cpm.y"
    {fprintf(stderr, " switch (CHOICE) { CASES }\n");}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 828 "cpm.y"
    {
	 (yyval.dec).bodyCode = StringCat((yyvsp[(3) - (8)].dec).bodyCode,(yyvsp[(6) - (8)].dec).bodyCode);
	 (yyval.dec).headCode = StringCat((yyvsp[(3) - (8)].dec).headCode,(yyvsp[(6) - (8)].dec).headCode);
      }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 832 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : switch is missing  ");}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 833 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : '(' is missing ");}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 834 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : choice is missing ");}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 835 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : ')' is missing ");}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 836 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : '{' is missing ");}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 837 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } :  cases is missing");}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 838 "cpm.y"
    {PrintListingErrors("switch (CHOICE) { CASES } : '}' is missing");}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 845 "cpm.y"
    {
	fprintf(stderr, "CHOICE -> ID \n");
	char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	char* reg;
	symbol* symPointer = lookup((yyvsp[(1) - (1)].sval));
	bodyCodeStr[0]='\0';

	if(symPointer == NULL)
	{
		PrintListingErrors("unknown type in symbol table");
	}
	else
	{
		if(!strcmp(symPointer->type,"int"))
		{
		 sprintf(bodyCodeStr,"lw $s1,%s\n",(yyvsp[(1) - (1)].sval));
		}
		else
		{
		 reg = getFloatRegister();
		 sprintf(bodyCodeStr,"l.s %s,%s\n",reg,(yyvsp[(1) - (1)].sval));
		}
		(yyval.dec).headCode = strdup("");
		(yyval.dec).bodyCode = strdup(bodyCodeStr);
		free(bodyCodeStr);
	}
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 874 "cpm.y"
    {
	printf("CHOICE -> NUM \n");
	char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	char* headCodeStr = (char*)malloc(sizeof(char)*256);
	char* reg;
	bodyCodeStr[0]='\0';
	headCodeStr[0]='\0';
	if(!strcmp((yyvsp[(1) - (1)].number).type,"int"))
	{
	 sprintf(bodyCodeStr,"li $s1,%d\n",(yyvsp[(1) - (1)].number).val);
	}
	else
	{
	 reg = getFloatRegister();
	 char* label = getLabelNumber();
	 sprintf(headCodeStr,"%s: .float %f\n",label,(yyvsp[(1) - (1)].number).val);
	 sprintf(bodyCodeStr,"l.s %s,%s\n",reg,label);
	}
	(yyval.dec).headCode = strdup(headCodeStr);
	(yyval.dec).bodyCode = strdup(bodyCodeStr);
	free(bodyCodeStr);
	free(headCodeStr);
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 898 "cpm.y"
    {PrintListingErrors("choice -> ID or NUM is missing ");}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 903 "cpm.y"
    {fprintf(stderr, " cases -> case num: STMTLIST break; CASES done \n");}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 904 "cpm.y"
    {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen((yyvsp[(4) - (8)].mips).body)));
	 bodyCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 char* reg=  getTempRegister();
	 sprintf(bodyCodeStr,"li %s, %d\n bne %s, $s1 ,next%s\n%s\nj end%s\nnext%s:\n",reg,(yyvsp[(2) - (8)].number).val.ival,reg,label,(yyvsp[(4) - (8)].mips).body,(yyvsp[(7) - (8)].dec).label,label);	
	 (yyval.dec).label = (yyvsp[(7) - (8)].dec).label;
	 (yyval.dec).headCode = StringCat((yyvsp[(4) - (8)].mips).head,(yyvsp[(7) - (8)].dec).headCode);
	 (yyval.dec).bodyCode = StringCat(bodyCodeStr,(yyvsp[(7) - (8)].dec).bodyCode);
	 freeTempRegister(reg);
	 free(bodyCodeStr);

     }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 919 "cpm.y"
    {fprintf(stderr, " cases 2 -> default: STMTLIST done \n");}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 920 "cpm.y"
    {

	 char* bodyCodeStr = (char*)malloc(sizeof(char)*(256 + strlen((yyvsp[(3) - (4)].mips).body)));
	 bodyCodeStr[0]='\0';
	 char* label = getLabelNumber();
	 sprintf(bodyCodeStr,"default%s:\n%s\nend%s:",label,(yyvsp[(3) - (4)].mips).body,label);
	 (yyval.dec).label = strdup(label);
	 (yyval.dec).headCode = strdup((yyvsp[(3) - (4)].mips).head);
	 (yyval.dec).bodyCode = strdup(bodyCodeStr);
	 free(bodyCodeStr);
     }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 932 "cpm.y"
    {PrintListingErrors("CASE is missing ");}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 933 "cpm.y"
    {PrintListingErrors("NUM is missing ");}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 934 "cpm.y"
    {PrintListingErrors("':' is missing ");}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 935 "cpm.y"
    {PrintListingErrors("stmtlist is missing ");}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 936 "cpm.y"
    {PrintListingErrors("BREAK is missing ");}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 937 "cpm.y"
    {PrintListingErrors("';' is missing ");}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 938 "cpm.y"
    {PrintListingErrors("cases is missing ");}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 939 "cpm.y"
    {PrintListingErrors("DEFAULT is missing ");}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 940 "cpm.y"
    {PrintListingErrors("':' is missing ");}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 945 "cpm.y"
    {fprintf(stderr, " ID ASSIGNOP ID ADDOP NUM\n");}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 946 "cpm.y"
    {
    char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
    bodyCodeStr[0]='\0';
    symbol* sym1 = lookup((yyvsp[(1) - (6)].sval));
    symbol* sym3 = lookup((yyvsp[(3) - (6)].sval));

    
    if (sym1 == NULL)
    {
    	installSymTable((yyvsp[(1) - (6)].sval),"int",0);
	fprintf(stderr, "step -> sym1\n");
	sym1 = lookup((yyvsp[(1) - (6)].sval));
    }

    else if (sym3 == NULL)
    {
    	installSymTable((yyvsp[(1) - (6)].sval),"int",0);
	fprintf(stderr, "step -> sym1\n");
	sym3 = lookup((yyvsp[(3) - (6)].sval));
    }

    else
    {
	    if(!strcmp(sym1->type,"float") && !strcmp(sym3->type,"float") && !strcmp((yyvsp[(5) - (6)].number).type,"float"))
	    {
		  char* reg = getFloatRegister();
		  if((yyvsp[(4) - (6)].op)==MINUS)
		    sprintf(bodyCodeStr,"l.s, %s, %s\nsub.s %s, %s ,%d\ns.s %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  else
		    sprintf(bodyCodeStr,"l.s, %s, %s\nadd.s %s, %s ,%d\ns.s %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  freeFloatRegister(reg);
	    }

	    else if(!strcmp(sym1->type,"int") && !strcmp(sym3->type,"int") && !strcmp((yyvsp[(5) - (6)].number).type,"int"))
	    {
		  char* reg = getTempRegister();
		  if((yyvsp[(4) - (6)].op)==MINUS)
		    sprintf(bodyCodeStr,"lw, %s, %s\nsub %s, %s ,%d\nsw %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  else
		    sprintf(bodyCodeStr,"lw, %s, %s\naddi %s, %s ,%d\nsw %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  freeTempRegister(reg);
	    }
    }
    (yyval.mips).head = strdup("");
    (yyval.mips).body = strdup(bodyCodeStr);
    free(bodyCodeStr);
    }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 994 "cpm.y"
    {fprintf(stderr, " ID ASSIGNOP ID MULOP NUM\n");}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 995 "cpm.y"
    {


    char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
    bodyCodeStr[0]='\0';
    symbol* sym1 = lookup((yyvsp[(1) - (6)].sval));
    symbol* sym3 = lookup((yyvsp[(3) - (6)].sval));

    if( (!strcmp((yyvsp[(5) - (6)].number).type,"int") && ((yyvsp[(5) - (6)].number).val.ival)==0) || (!strcmp((yyvsp[(5) - (6)].number).type,"float") && ((yyvsp[(5) - (6)].number).val.fval)==0) )
    {
		
		PrintListingErrors("can not division by zero.");
    }

    else
    {
	    if(!strcmp(sym1->type,"float") && !strcmp(sym3->type,"float") && !strcmp((yyvsp[(5) - (6)].number).type,"float"))
	    {
		  char* reg = getFloatRegister();
		  if((yyvsp[(4) - (6)].op)==DIV)
		    sprintf(bodyCodeStr,"l.s, %s, %s\ndiv.s %s, %s ,%d\ns.s %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  else
		    sprintf(bodyCodeStr,"l.s, %s, %s\nmul.s %s, %s ,%d\ns.s %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  freeFloatRegister(reg);
	    }

	    else if(!strcmp(sym1->type,"int") && !strcmp(sym3->type,"int") && !strcmp((yyvsp[(5) - (6)].number).type,"int"))
	    {
		  char* reg = getTempRegister();
		  if((yyvsp[(4) - (6)].op)==DIV)
		    sprintf(bodyCodeStr,"la ,%s, %s\ndiv %s, %s ,%d\nsw %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  else
		    sprintf(bodyCodeStr,"la ,%s, %s\nmul %s, %s ,%d\nsw %s, %s\n",reg,(yyvsp[(3) - (6)].sval),reg,reg,(yyvsp[(5) - (6)].number).val,reg,(yyvsp[(1) - (6)].sval));
		  freeTempRegister(reg);
	    }
    }


    (yyval.mips).head = strdup("");
    (yyval.mips).body = strdup(bodyCodeStr);
    free(bodyCodeStr);

    }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1040 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : second id is missing");}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1041 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : first id is missing");}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1042 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID ADDOP NUM : assignop id is missing");}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1043 "cpm.y"
    {PrintListingErrors("ID addop or mulop ID ADDOP NUM : addop or mulop id is missing");}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1044 "cpm.y"
    {PrintListingErrors("ID addop ID ADDOP NUM : num id is missing");}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1045 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : first id is missing");}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1046 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : assignop id is missing");}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1047 "cpm.y"
    {PrintListingErrors("ID ASSIGNOP ID MULOP NUM : second id is missing");}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1048 "cpm.y"
    {PrintListingErrors("ID addop ID MULOP NUM : num id is missing");}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1054 "cpm.y"
    {fprintf(stderr, "boolexpr -> boolexpr OROP boolterm\n");}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1055 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';
		 char* reg = getTempRegister();
		 char* label = getLabelNumber();
		 sprintf(bodyCodeStr,"bne %s, %s, else%s\nadd %s, $0, %s\nj end%s\nelse%s: addi %s, $0, 1\nend%s",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,(yyvsp[(1) - (4)].dec).reg,label,label,reg,label);
		 (yyval.dec).reg = strdup(reg);
		 tmp = StringCat((yyvsp[(1) - (4)].dec).bodyCode,(yyvsp[(3) - (4)].dec).bodyCode);
		 (yyval.dec).bodyCode= StringCat(tmp,bodyCodeStr);
		 (yyval.dec).headCode= StringCat((yyvsp[(1) - (4)].dec).headCode,(yyvsp[(3) - (4)].dec).headCode);
		 freeTempRegister((yyvsp[(1) - (4)].dec).reg);
		 freeTempRegister((yyvsp[(3) - (4)].dec).reg);
		 free(tmp);
		 free(bodyCodeStr);
	}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1072 "cpm.y"
    {fprintf(stderr, "boolexpr -> boolterm\n");}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1073 "cpm.y"
    {
		 (yyval.dec).reg = strdup((yyvsp[(1) - (2)].dec).reg);
		 (yyval.dec).bodyCode= strdup((yyvsp[(1) - (2)].dec).bodyCode);
		 (yyval.dec).headCode= strdup((yyvsp[(1) - (2)].dec).headCode);
	}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1078 "cpm.y"
    {PrintListingErrors("boolexpr OROP boolterm : boolexpr is missing");}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1079 "cpm.y"
    {PrintListingErrors("boolexpr OROP boolterm : orop is missing");}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1080 "cpm.y"
    {PrintListingErrors("boolexpr OROP boolterm : boolterm is missing");}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1081 "cpm.y"
    {PrintListingErrors("boolterm : boolterm is missing");}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 1085 "cpm.y"
    {fprintf(stderr, "boolterm -> boolterm ANDOP boolterm\n");}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 1086 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';
		 char* reg = getTempRegister();
		 sprintf(bodyCodeStr,"mul %s, %s, %s\n",reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
		 (yyval.dec).reg = strdup(reg);
		 tmp = StringCat((yyvsp[(1) - (4)].dec).bodyCode,(yyvsp[(3) - (4)].dec).bodyCode);
		 (yyval.dec).bodyCode= StringCat(tmp,bodyCodeStr);
		 (yyval.dec).headCode= StringCat((yyvsp[(1) - (4)].dec).headCode,(yyvsp[(3) - (4)].dec).headCode);
		 freeTempRegister((yyvsp[(1) - (4)].dec).reg);
		 freeTempRegister((yyvsp[(3) - (4)].dec).reg);
		 free(tmp);
		 free(bodyCodeStr);

	}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 1102 "cpm.y"
    {fprintf(stderr, "boolterm -> boolfactor\n");}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 1103 "cpm.y"
    {
		 (yyval.dec).reg = strdup((yyvsp[(1) - (2)].dec).reg);
		 (yyval.dec).bodyCode= strdup((yyvsp[(1) - (2)].dec).bodyCode);
		 (yyval.dec).headCode= strdup((yyvsp[(1) - (2)].dec).headCode);
	}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 1109 "cpm.y"
    {PrintListingErrors("boolterm ANDOP boolterm : first boolterm is missing");}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 1110 "cpm.y"
    {PrintListingErrors("boolterm ANDOP boolterm : andop is missing");}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 1111 "cpm.y"
    {PrintListingErrors("boolterm ANDOP boolterm : second boolterm is missing");}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 1112 "cpm.y"
    {PrintListingErrors("boolfactor : boolfactor is missing");}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 1117 "cpm.y"
    {fprintf(stderr, "boolfactor -> !(boolfactor)\n");}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 1118 "cpm.y"
    {

		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* reg = getTempRegister();
		 bodyCodeStr[0]='\0';
		 sprintf(bodyCodeStr,"li %s ,1\nsub %s, %s, %s\n",reg,(yyvsp[(3) - (5)].dec).reg,reg,(yyvsp[(3) - (5)].dec).reg);
		 (yyval.dec).reg= (yyvsp[(3) - (5)].dec).reg;
		 (yyval.dec).bodyCode= StringCat((yyvsp[(3) - (5)].dec).bodyCode,bodyCodeStr);
		 (yyval.dec).headCode= (yyvsp[(3) - (5)].dec).headCode;
		 freeTempRegister(reg);
		 free(bodyCodeStr);

	  }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 1131 "cpm.y"
    {fprintf(stderr, "boolfactor -> expression RELOP expression\n");}
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 1132 "cpm.y"
    {
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 bodyCodeStr[0]='\0';
		 char* tmpBody =(char*)malloc(sizeof(char)*256);
		 char* tmpHead =(char*)malloc(sizeof(char)*256);
		 tmpBody[0]='\0';
		 tmpHead[0]='\0';
		 char* reg = getTempRegister();
		 char* label = getLabelNumber();

		 if(!strcmp((yyvsp[(1) - (4)].dec).type,"string") || !strcmp((yyvsp[(3) - (4)].dec).type,"string"))
		 {
			PrintListingErrors(">= or <= operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
			
		 }
		 else if((!strcmp((yyvsp[(1) - (4)].dec).type,"int") && !strcmp((yyvsp[(3) - (4)].dec).type,"float"))  ||  (!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"int")))
		 {
			PrintListingErrors(">= or <= operation will performe only for variables from same type.");
			sprintf(bodyCodeStr,"");
			
		 }
		 else
		 {
			 if(!strcmp((yyvsp[(1) - (4)].dec).type,"int") && !strcmp((yyvsp[(3) - (4)].dec).type,"int"))
			 {
			  if((yyvsp[(2) - (4)].op)==EQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nli %s , $0\nj end%s\nelse%s\nli %s,1\nend%s\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==NEQ)
			    sprintf(bodyCodeStr,"bne %s, %s, else%s\nli %s , $0\nj end%s\nelse%s\nli %s,1\nend%s\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==LT)
			    sprintf(bodyCodeStr,"slt %s, %s, %s\n",reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  if((yyvsp[(2) - (4)].op)==GT)
			    sprintf(bodyCodeStr,"slt %s, %s, %s\n",reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg);
			  if((yyvsp[(2) - (4)].op)==LTEQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nslt %s , %s, %s\nj end%s\nelse%s\nli %s,1\nend%s\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==GTEQ)
			    sprintf(bodyCodeStr,"beq %s, %s, else%s\nslt %s , %s, %s\nj end%s\nelse%s\nli %s,1\nend%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,label,reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,label,label,reg,label);
			  freeTempRegister((yyvsp[(1) - (4)].dec).reg);
			  freeTempRegister((yyvsp[(3) - (4)].dec).reg);			
			 }
			 if(!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"float"))
			 {
			  if((yyvsp[(2) - (4)].op)==EQ)
			    sprintf(bodyCodeStr,"c.eq.s %s, %s\nbc1f else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==NEQ)
			    sprintf(bodyCodeStr,"c.eq.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==LT)
			    sprintf(bodyCodeStr,"c.lt.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==GT)
			    sprintf(bodyCodeStr,"c.lt.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==LTEQ)
			    sprintf(bodyCodeStr,"c.le.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,label,reg,label,label,reg,label);
			  if((yyvsp[(2) - (4)].op)==GTEQ)
			    sprintf(bodyCodeStr,"c.le.s %s, %s\nbc1t else%s\naddi %s,$0,1\nj end%s\nelse%s: move %s,$0\nend%s:\n",(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,label,reg,label,label,reg,label);
			  freeFloatRegister((yyvsp[(1) - (4)].dec).reg);
			  freeFloatRegister((yyvsp[(3) - (4)].dec).reg);
			 }
		 }
		 (yyval.dec).reg = strdup(reg);
		 strcat(tmpBody,(yyvsp[(1) - (4)].dec).bodyCode);
		 strcat(tmpBody,(yyvsp[(3) - (4)].dec).bodyCode);
		 strcat(tmpBody,bodyCodeStr);
	         strcat(tmpHead,(yyvsp[(1) - (4)].dec).headCode);
		 strcat(tmpHead,(yyvsp[(3) - (4)].dec).headCode);
		 (yyval.dec).bodyCode = strdup(tmpBody);
		 (yyval.dec).headCode = strdup(tmpHead);
		 free(tmpBody);
		 free(tmpHead);
		 free(bodyCodeStr);
	  }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1203 "cpm.y"
    {PrintListingErrors("!(boolfactor) : '!' is missing");}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1204 "cpm.y"
    {PrintListingErrors("!(boolfactor) : '(' is missing");}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1205 "cpm.y"
    {PrintListingErrors("!(boolfactor) : boolfactor is missing");}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1206 "cpm.y"
    {PrintListingErrors("!(boolfactor) : ')' is missing");}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1207 "cpm.y"
    {PrintListingErrors("expression RELOP expression : first expression is missing");}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1208 "cpm.y"
    {PrintListingErrors("expression RELOP expression : relop is missing");}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1209 "cpm.y"
    {PrintListingErrors("expression RELOP expression : second expression is missing");}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1215 "cpm.y"
    {fprintf(stderr, "expression -> expression ADDOP term\n");}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1216 "cpm.y"
    {
		 
		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';

		 if(!strcmp((yyvsp[(1) - (4)].dec).type,"string") || !strcmp((yyvsp[(3) - (4)].dec).type,"string"))
		 {
			PrintListingErrors("+ or - operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
		 }
		 else
		 {
			 if(!strcmp((yyvsp[(1) - (4)].dec).type,"int") && !strcmp((yyvsp[(3) - (4)].dec).type,"int"))
			 {
			  if((yyvsp[(2) - (4)].op) == MINUS)
			    sprintf(bodyCodeStr,"sub %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  else
			    sprintf(bodyCodeStr,"add %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg);
			  freeTempRegister((yyvsp[(1) - (4)].dec).reg);
			  (yyval.dec).type = strdup("int");
			  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);
			 }


			 else if(!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"float"))
			 {
			  if((yyvsp[(2) - (4)].op) == MINUS)
			    sprintf(bodyCodeStr,"sub.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  else
			    sprintf(bodyCodeStr,"add.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  freeFloatRegister((yyvsp[(1) - (4)].dec).reg);
			  (yyval.dec).type = strdup("float");
			  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);
			 }

			 else
			 {
				 if(!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"int"))
				 {
				  char* reg = getFloatRegister();
				  if((yyvsp[(2) - (4)].op) == MINUS)
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,reg,reg,reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,reg,reg,reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,reg);

				  freeFloatRegister(reg);
				  freeTempRegister((yyvsp[(3) - (4)].dec).reg);
				  (yyval.dec).type = strdup("float");
				  (yyval.dec).reg = strdup((yyvsp[(1) - (4)].dec).reg);
				 }

				 else
				 {
				  char* reg = getFloatRegister();
				  if((yyvsp[(2) - (4)].op) == MINUS)
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n",(yyvsp[(1) - (4)].dec).reg,reg,reg,reg,(yyvsp[(3) - (4)].dec).reg,reg,(yyvsp[(3) - (4)].dec).reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n",(yyvsp[(1) - (4)].dec).reg,reg,reg,reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,reg);

				  freeFloatRegister(reg);
				  freeTempRegister((yyvsp[(1) - (4)].dec).reg);
				  (yyval.dec).type = strdup("float");
				  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);

				 }
			 }

		 }
		 tmp = StringCat((yyvsp[(1) - (4)].dec).bodyCode,(yyvsp[(3) - (4)].dec).bodyCode);
		 (yyval.dec).bodyCode= StringCat(tmp,bodyCodeStr);
		 (yyval.dec).headCode= StringCat((yyvsp[(1) - (4)].dec).headCode,(yyvsp[(3) - (4)].dec).headCode);
		 free(tmp);
		 free(bodyCodeStr);

	  }
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1292 "cpm.y"
    {fprintf(stderr, "expression -> term\n");}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1293 "cpm.y"
    {
		 (yyval.dec).reg =  strdup((yyvsp[(1) - (2)].dec).reg);
		 (yyval.dec).bodyCode = strdup((yyvsp[(1) - (2)].dec).bodyCode);
		 (yyval.dec).headCode = strdup((yyvsp[(1) - (2)].dec).headCode);
		 (yyval.dec).type = strdup((yyvsp[(1) - (2)].dec).type);
	  }
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1299 "cpm.y"
    {PrintListingErrors("expression ADDOP term : expression is missing");}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1300 "cpm.y"
    {PrintListingErrors("expression ADDOP term : addop is missing");}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1301 "cpm.y"
    {PrintListingErrors("expression ADDOP term : term is missing");}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1302 "cpm.y"
    {PrintListingErrors("term : term is missing");}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1306 "cpm.y"
    {fprintf(stderr, "term -> term MULOP factor\n");}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1307 "cpm.y"
    {

		 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
		 char* tmp;
		 bodyCodeStr[0]='\0';

		 if(!strcmp((yyvsp[(1) - (4)].dec).type,"string") || !strcmp((yyvsp[(3) - (4)].dec).type,"string"))
		 {
			PrintListingErrors("multiplication or division operation be performed for int or float variables, can not performed for string variable");
			sprintf(bodyCodeStr,"");
		 }
		 else if(((yyvsp[(3) - (4)].dec).ival == 0) || ((yyvsp[(3) - (4)].dec).fval == 0.0))
		 {
			PrintListingErrors("can not perform a division operation with zero");
			sprintf(bodyCodeStr,"");
		 }
		 else
		 {
			 if(!strcmp((yyvsp[(1) - (4)].dec).type,"int") && !strcmp((yyvsp[(3) - (4)].dec).type,"int"))
			 {
			  if((yyvsp[(2) - (4)].op) == DIV) 
			    sprintf(bodyCodeStr,"div %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  else
			    sprintf(bodyCodeStr,"mul %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg);

			  freeTempRegister((yyvsp[(1) - (4)].dec).reg);
			  (yyval.dec).type = strdup("int");
			  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);
			 }
			 else if(!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"float"))
			 {
			  if((yyvsp[(2) - (4)].op) == DIV)
			    sprintf(bodyCodeStr,"div.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg);
			  else
			    sprintf(bodyCodeStr,"mul.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg);

			  freeFloatRegister((yyvsp[(1) - (4)].dec).reg);
			  (yyval.dec).type = strdup("float");
			  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);
			 }

			 else
			 {
				 if(!strcmp((yyvsp[(1) - (4)].dec).type,"float") && !strcmp((yyvsp[(3) - (4)].dec).type,"int"))
				 {
				  char* reg = getFloatRegister();
				  if((yyvsp[(2) - (4)].op) == DIV) 
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,reg,reg,reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n",(yyvsp[(3) - (4)].dec).reg,reg,reg,reg,(yyvsp[(1) - (4)].dec).reg,(yyvsp[(1) - (4)].dec).reg,reg);
				  freeFloatRegister(reg);
				  freeTempRegister((yyvsp[(3) - (4)].dec).reg);
				  (yyval.dec).type = strdup("float");
				  (yyval.dec).reg = strdup((yyvsp[(1) - (4)].dec).reg);
				 }

				 else
				 {
				  char* reg = getFloatRegister();
				  if((yyvsp[(2) - (4)].op) == DIV) 
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n",(yyvsp[(1) - (4)].dec).reg,reg,reg,reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,reg);
				  else
				    sprintf(bodyCodeStr,"mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n",(yyvsp[(1) - (4)].dec).reg,reg,reg,reg,(yyvsp[(3) - (4)].dec).reg,(yyvsp[(3) - (4)].dec).reg,reg);
				  
				  freeFloatRegister(reg);
				  freeTempRegister((yyvsp[(1) - (4)].dec).reg);
				  (yyval.dec).type = strdup("float");
				  (yyval.dec).reg = strdup((yyvsp[(3) - (4)].dec).reg);
				 }
			 }

		 }
		 tmp = StringCat((yyvsp[(1) - (4)].dec).bodyCode,(yyvsp[(3) - (4)].dec).bodyCode);
		 (yyval.dec).bodyCode= StringCat(tmp,bodyCodeStr);
		 (yyval.dec).headCode= StringCat((yyvsp[(1) - (4)].dec).headCode,(yyvsp[(3) - (4)].dec).headCode);
		 free(tmp);
		 free(bodyCodeStr);

    }
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1386 "cpm.y"
    {fprintf(stderr, "term -> factor\n");}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1387 "cpm.y"
    {
	 (yyval.dec).reg =  strdup((yyvsp[(1) - (2)].dec).reg);
	 (yyval.dec).bodyCode = strdup((yyvsp[(1) - (2)].dec).bodyCode);
	 (yyval.dec).headCode = strdup((yyvsp[(1) - (2)].dec).headCode);
	 (yyval.dec).type = strdup((yyvsp[(1) - (2)].dec).type);
    }
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1393 "cpm.y"
    {PrintListingErrors("term MULOP factor : term is missing");}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1394 "cpm.y"
    {PrintListingErrors("term MULOP factor:  mulop is missing");}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1395 "cpm.y"
    {PrintListingErrors("term MULOP factor: factor is missing");}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1396 "cpm.y"
    {PrintListingErrors("factor : factor is missing");}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1399 "cpm.y"
    {fprintf(stderr, "FACTOR -> (EXPRESSION)\n");}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1400 "cpm.y"
    {
	 (yyval.dec).reg =  strdup((yyvsp[(2) - (4)].dec).reg);
	 (yyval.dec).bodyCode = strdup((yyvsp[(2) - (4)].dec).bodyCode);
	 (yyval.dec).headCode = strdup((yyvsp[(2) - (4)].dec).headCode);
	 (yyval.dec).type = strdup((yyvsp[(2) - (4)].dec).type);
      }
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 1406 "cpm.y"
    {fprintf(stderr, "FACTOR ->ID\n");}
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 1407 "cpm.y"
    {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg;
	 char* label = getLabelNumber();
	 bodyCodeStr[0]='\0';
	 symbol* symPointer = lookup((yyvsp[(1) - (2)].sval));
	 if(symPointer !=NULL)
	 {
	  if(symPointer->isDeclared)
	  {
		  if(!strcmp(symPointer->type,"int"))
		  {
		   reg = getTempRegister();
		   sprintf(bodyCodeStr,"lw %s, %s\n",reg,(yyvsp[(1) - (2)].sval));
		  }
		  if(!strcmp(symPointer->type,"float"))
		  {
		   reg = getFloatRegister();
		   sprintf(bodyCodeStr,"l.s %s, %s\n",reg,(yyvsp[(1) - (2)].sval));
		  }
		  if(!strcmp(symPointer->type,"string"))
		  {
		   reg= (yyvsp[(1) - (2)].sval);
		  }
		  (yyval.dec).reg = strdup(reg);
		  (yyval.dec).type = strdup(symPointer->type);
		  (yyval.dec).bodyCode = strdup(bodyCodeStr);
		  (yyval.dec).headCode=strdup("");
		  free(bodyCodeStr);
	   }
	  else
	  {  
		  sprintf(bodyCodeStr,"");
		  PrintListingErrors(StringCat((yyvsp[(1) - (2)].sval), " need to be declare."));
		  free(bodyCodeStr);
	  }
	}
      }
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 1445 "cpm.y"
    {fprintf(stderr, "FACTOR ->NUM\n");}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1446 "cpm.y"
    {
	 char* bodyCodeStr = (char*)malloc(sizeof(char)*256);
	 char* headCodeStr = (char*)malloc(sizeof(char)*256);
	 char* reg;
	 bodyCodeStr[0]='\0';
	 headCodeStr[0]='\0';
	 fprintf(stderr, "FACTOR ->NUM 1\n");
	 if(!strcmp((yyvsp[(1) - (2)].number).type,"int"))
	 {
		  fprintf(stderr, "FACTOR ->NUM is int\n");
		  reg = getTempRegister();
		  sprintf(bodyCodeStr,"addi %s, $0, %d\n",reg,(yyvsp[(1) - (2)].number).val.ival);
	 }
	 else
	 {
	          fprintf(stderr, "FACTOR ->NUM is float\n");
		  reg = getFloatRegister();
		  char* label = getLabelNumber();
		  sprintf(headCodeStr,"%s: .float %f\n",label,(yyvsp[(1) - (2)].number).val.fval);
		  sprintf(bodyCodeStr,"l.s %s, %s\n",reg,label);
	 }
	 fprintf(stderr, "FACTOR ->NUM 2\n");
	 (yyval.dec).type = strdup((yyvsp[(1) - (2)].number).type);
	 (yyval.dec).reg = strdup(reg);
	 (yyval.dec).headCode = strdup(headCodeStr);
	 (yyval.dec).bodyCode = strdup(bodyCodeStr);
	 free(headCodeStr);
	 free(bodyCodeStr);
      }
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1476 "cpm.y"
    {PrintListingErrors("'(' is missing");}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1477 "cpm.y"
    {PrintListingErrors("expression is missing");}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1478 "cpm.y"
    {PrintListingErrors("')' is missing");}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 1479 "cpm.y"
    {PrintListingErrors("id or num is missing!");}
    break;


/* Line 1792 of yacc.c  */
#line 4968 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1482 "cpm.y"



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