#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.hpp"
#include "scanner.h"
#include "y.tab.h"
extern int lineCount;
extern char curString[2000];
extern char* yytext;
int function_main_flag = 0;
int top = 0;
int scope = 0;
SymbolTable* table;
FILE* file;
int if_label_count = 0;
int finish_label_count = 0;
int and_label_count = 0;
int or_label_count = 0;
int while_label_count = 0;
#line 21 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	int intVal;
	char idVal[4096];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KVOID 257
#define KINT 258
#define KDOUBLE 259
#define KBOOL 260
#define KCHAR 261
#define KNULL 262
#define KFOR 263
#define KWHILE 264
#define KDO 265
#define KIF 266
#define KELSE 267
#define KSWITCH 268
#define KRETURN 269
#define KBREAK 270
#define KCONTINUE 271
#define KCONST 272
#define KTRUE 273
#define KFALSE 274
#define KSTRUCT 275
#define KCASE 276
#define KDEFAULT 277
#define ID 278
#define INT 279
#define DOUBLE 280
#define CHAR 281
#define DOUBLE_MINUS 282
#define DOUBLE_PLUS 283
#define AND 284
#define OR 285
#define COMPARE 286
#define STRING 287
#define HIGH 288
#define LOW 289
#define DIGIT_WRITE 290
#define DELAY 291
#define unary 292
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    6,    3,    4,    4,    5,   10,   10,
    9,    9,    9,   13,   13,   12,   12,   12,   12,   12,
   12,   12,   12,   20,   21,    1,    1,   14,   14,   14,
   14,   14,   14,   14,   19,   19,   25,   25,   26,   28,
   28,   27,   27,   17,   29,   18,   15,   15,   30,   31,
   32,   16,   33,   33,   24,   24,    8,    8,    8,   34,
   34,    2,    2,   35,   35,   38,   38,   39,   39,   39,
   36,   36,   37,   37,   41,   42,   40,   40,   40,    7,
    7,    7,    7,   11,   11,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   43,   43,   43,   44,   44,
};
static const short yylen[] = {                            2,
    2,    2,    0,    0,    3,    5,    5,    3,    4,    3,
    2,    2,    0,    2,    0,    2,    1,    1,    1,    1,
    1,    2,    2,    6,    4,    1,    1,    3,    7,    3,
    1,    1,    1,    2,    7,    7,    5,    3,    5,    5,
    0,    1,    1,    4,    4,    9,    2,    2,    4,    3,
    3,   11,    1,    0,    3,    0,    3,    1,    0,    2,
    6,    3,    4,    4,    0,    4,    0,    3,    0,    1,
    3,    1,    3,    1,    3,    0,    4,    1,    6,    1,
    1,    1,    1,    3,    1,    3,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    1,
    1,    1,    1,    5,    1,    3,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    1,
    1,    1,    1,    2,    2,    1,    1,    1,
};
static const short yydefred[] = {                         3,
    0,    0,   80,   81,   83,   82,    0,    1,    2,    4,
    0,    0,    0,    0,    0,    0,   72,    0,    0,    0,
   74,    0,    5,    0,    0,    0,   62,    0,    0,    0,
   58,    0,   63,    0,    0,    0,    0,    0,    0,    0,
   32,   33,    0,    0,    0,    0,    0,    0,   31,    0,
    0,   17,   18,   19,   20,   21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,    0,    7,    0,  121,
  120,    0,  127,  128,  118,  119,    0,    0,    0,    0,
    0,  122,  126,   73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   12,    8,   11,   16,   22,
   23,    0,    0,    0,   48,    0,    6,    0,    0,   57,
  108,  107,    0,  124,  125,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  101,  100,    0,   98,   99,    0,    0,  105,    0,  102,
   10,    0,    0,    0,   30,    0,    0,    0,    0,    0,
   51,    0,    0,    0,  106,    0,    0,    0,    0,    0,
  111,  112,  113,    0,   45,    0,   49,    0,    0,    0,
    0,   88,   87,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    9,    0,    0,   25,   44,   50,    0,    0,
   79,    0,    0,    0,    0,    0,   86,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   84,   26,   27,
    0,    0,    0,   61,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,   64,    0,    0,    0,    0,   43,
   42,    0,    0,   35,   36,  104,   55,    0,   66,    0,
    0,    0,    0,    0,   38,    0,    0,   46,    0,   14,
    0,    0,   37,   39,   52,    0,    0,    0,   40,
};
static const short yydgoto[] = {                          1,
  211,   46,    9,   10,   23,   14,   47,   30,   48,  138,
  142,   50,  245,   51,   52,   53,   54,   55,   56,   57,
   58,  125,  143,  207,  253,  220,  232,  254,   59,   60,
  104,   61,  126,   31,  153,   16,   20,  191,  227,   17,
   21,   26,   82,   83,
};
static const short yysindex[] = {                         0,
  231, -273,    0,    0,    0,    0,  267,    0,    0,    0,
 -259,   37, -196,  -37,  -31,   -8,    0,  267,   41,   68,
    0,  452,    0, -183,  267,   57,    0, -148, -139,   -3,
    0,  -22,    0, -196,  112,  130,   59,  138,  148,  -22,
    0,    0,   85,  152,  159,  452, -148,   76,    0,  452,
  147,    0,    0,    0,    0,    0,  154,  156,   97,   99,
   99,  143,   -2,  -22,  134,    0,  140,    0,  267,    0,
    0, -269,    0,    0,    0,    0,  -22,    1,    1,  -22,
  -12,    0,    0,    0,  -22,  -22,  452,  -22,  -36,  -12,
  -11,  -33,    4,  -29,  -22,    0,    0,    0,    0,    0,
    0,  452,  452,   95,    0,  199,    0,  -12,   93,    0,
    0,    0,  324,    0,    0,  116,  -22,  -22,  -22,  -22,
  -22,  -22,  -22,  -22,  -12,  249,  132,  201,  144,  294,
    0,    0,  -13,    0,    0,  -11,  -11,    0,   38,    0,
    0,  329,   47,  -39,    0,  -12,  330,  153,  255,  262,
    0,  118,  337,  306,    0,  324,  192,  476,    3,    3,
    0,    0,    0,  -22,    0,  146,    0,  281,  -11,  181,
   56,    0,    0,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
  -11,  323,    0,  -11,   55,    0,    0,    0,  322,  296,
    0,  199,  374,  387,   23,   63,    0,  181,  160,  336,
  113,  113,   35,   35,   35,  -11,  375,    0,    0,    0,
  394,  199,  -22,    0,  -22,  -22, -117,  389,  325,  332,
  323,   72,  -22,    0,    0,  -12,  -38,  413,  167,    0,
    0,  404,  311,    0,    0,    0,    0,  -12,    0,  -22,
  343,  410,  311,  311,    0,  -12,  452,    0,   83,    0,
  350, -117,    0,    0,    0,  421,  311,   83,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  194,    0,    0,  107,    0,    0,
    0,  357,    0,    0,  107,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  357,    0,    0,    0,  357,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  194,    0,  127,    0,    0,    0,
    0,   29,    0,    0,    0,    0,    0,    0,    0,    0,
  275,    0,    0,    0,  425,    0,  357,    0,    0,  435,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  357,  357,  295,    0,  205,    0,  292,    0,    0,
    0,    0,  309,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,    0,    0,    0,    0,    0,
    0,    0,   11,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  445,  174,    0,  436,    0,    0,    0,    0,
    0,    0,  293,    0,    0,  381,  382,  257,  266,  349,
    0,    0,    0,  425,    0,    0,    0,    0,    0,  -24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  438,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  248,    0,    0,    0,    0,    0,  186,  139,    2,
  362,  368,   79,   91,  100,    0,    0,    0,    0,    0,
    0,  424,  -18,    0,  456,    0,    0,    0,    0,    0,
   20,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    0,    0,  376,    0,    0,    0,    0,  441,    0,    0,
    0,    0, -110, -110,    0,   24,  357,    0,  383,    0,
    0,    0,    0,    0,    0,    0, -110,  383,    0,
};
static const short yygindex[] = {                         0,
    0,  509,    0,    0,    0,    0,  480,  487,  225,  427,
  331,  188, -241,    0,    0,    0,    0,    0,    0,    0,
    0,  416,  526,  301,  321,    0,  265,  273,    0,    0,
  463,    0, -136,  475, -188,    0,    0,    0,    0,  504,
  511,    0,  513,  310,
};
#define YYTABLESIZE 743
static const short yytable[] = {                        136,
   92,  249,  250,  214,   12,  240,  137,  141,   25,   78,
   77,   79,  111,  112,   15,  258,   97,   80,   15,   97,
   78,  136,   79,  225,  124,   69,   92,  193,  137,  122,
  120,   78,  121,   79,  123,   28,   77,   68,  107,  124,
   69,   69,   94,   80,  122,   94,   78,  103,   79,  123,
   27,  103,  103,  103,  103,  103,   56,  103,   70,   24,
   56,   56,   56,   56,   56,  123,   56,   68,   97,  123,
  123,  123,  123,  123,  181,  123,   18,  169,  228,  179,
  177,   19,  178,  181,  180,   22,  239,  123,  179,  177,
  184,  178,  181,  180,   94,   62,  197,  179,  177,  181,
  178,   32,  180,  103,  179,  177,   69,  178,  181,  180,
   53,   34,   56,  179,  177,   91,  178,   64,  180,   91,
   91,   91,   91,   91,   92,   91,   33,   92,   53,   65,
  182,   92,   92,   92,   92,   92,   93,   92,   67,   70,
   93,   93,   93,   93,   93,   93,   93,   59,   68,  181,
   59,   85,  124,  123,  179,  221,  155,  122,  120,  180,
  121,  230,  123,  231,  237,   15,   15,   60,  124,   86,
   60,   91,  165,  122,  120,   91,  121,   88,  123,   96,
  124,   87,   96,   92,  167,  122,  120,   89,  121,  124,
  123,   94,   93,  186,  122,  120,  181,  121,   95,  123,
   97,  179,  177,  124,  178,   99,  180,  242,  122,  120,
  123,  121,  100,  123,  101,  123,  123,  181,  123,  102,
  123,  103,  179,  177,   24,  178,   95,  180,  124,   95,
  109,   96,  123,  122,  120,  106,  121,   78,  123,  131,
  132,  130,  111,  112,  133,   73,   74,  134,   65,  147,
   70,   71,   78,  135,   76,   72,   73,   74,   75,   97,
   97,  131,  132,   65,   76,   65,  133,   73,   74,  134,
   96,  117,  118,  119,   98,  135,   70,   71,   95,   73,
   74,  144,   73,   74,   75,   94,   94,   94,   65,  152,
   76,   65,  103,  103,  103,  103,  103,  114,  217,  218,
  114,   56,   56,   56,   56,   56,  109,  164,  109,  109,
  109,  128,  123,  123,  123,  114,  172,  173,   75,  172,
  173,  174,  175,  176,  109,  166,  149,  150,  172,  173,
  174,  175,  176,   75,  168,   77,   67,  172,  173,  174,
  175,  176,  209,  210,  172,  173,  174,  175,  176,  117,
   77,   67,  117,  172,  173,  174,  175,  176,  252,  218,
  124,  151,   91,   91,   91,  122,  120,  117,  121,  183,
  123,  154,  181,  185,   92,   92,   92,  179,  177,  187,
  178,  114,  180,   93,   93,   93,  188,  114,  115,  110,
  109,  110,  110,  110,  172,  173,  189,  190,  192,  117,
  118,  119,   89,  195,   89,   89,   89,  110,   90,  194,
   90,   90,   90,  206,  212,  117,  118,  119,  213,   47,
  244,  115,  116,   96,  115,  116,  216,  117,  118,  119,
  244,  244,  215,  117,  224,  223,  117,  118,  119,  115,
  116,  172,  173,  174,  244,  176,  233,   81,   49,  234,
  117,  118,  119,  241,   89,   90,  235,  123,  123,  123,
   90,  243,  172,  173,   65,  247,  176,   65,  248,   95,
   95,  251,   49,  110,  255,  117,   49,  119,  257,  108,
   11,   13,   65,   54,   65,   85,   13,    2,    3,    4,
    5,    6,  113,   34,   28,  116,   54,   29,   56,   29,
   15,  127,    7,  129,   29,  115,  116,   41,  146,    8,
  148,   63,  124,   49,  208,  219,  256,  122,  120,  145,
  121,  236,  123,  105,    3,    4,    5,    6,   49,   49,
  259,   66,  156,  157,  158,  159,  160,  161,  162,  163,
  114,  114,  114,  110,   84,    0,    0,    0,   29,  109,
  109,  109,   47,   47,   47,   47,    0,   47,   47,   47,
   47,    0,   47,   47,   47,   47,   47,    0,    0,    0,
   47,   47,   47,   35,   36,   37,   38,    0,   39,   40,
   41,   42,    0,    0,   47,   47,    0,    0,   43,    0,
    0,    0,  117,  117,    0,    0,    0,    0,    0,    0,
   44,   45,    0,  140,  140,    0,    0,    0,    0,  119,
    0,    0,    0,    0,    0,    0,  139,  172,  173,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  226,    0,
    0,  229,  110,  110,  110,    0,    0,    0,  238,    0,
    0,    0,    0,    0,    0,   89,   89,   89,  140,  140,
    0,   90,   90,   90,    0,  246,    0,    0,    0,   49,
    0,  170,  171,    0,  115,  115,  116,    0,    0,   49,
   49,    0,    0,   49,    0,    0,    0,    0,    0,    0,
    0,  140,    0,   49,    0,    0,  140,  140,  140,  140,
  140,  140,  140,  140,  196,    0,  140,    0,    0,  198,
  199,  200,  201,  202,  203,  204,  205,    0,    0,    3,
    4,    5,    6,    0,   35,   36,   37,   38,  140,   39,
   40,   41,   42,    7,    0,    0,    0,    0,    0,   43,
    0,  222,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,
};
static const short yycheck[] = {                         33,
   40,  243,  244,  192,  278,   44,   40,   41,   40,   43,
   33,   45,  282,  283,  125,  257,   41,   40,  278,   44,
   43,   33,   45,  212,   37,   44,   40,  164,   40,   42,
   43,   43,   45,   45,   47,   44,   33,   41,   41,   37,
   44,   44,   41,   40,   42,   44,   43,   37,   45,   47,
   59,   41,   42,   43,   44,   45,   37,   47,   44,   91,
   41,   42,   43,   44,   45,   37,   47,   44,   93,   41,
   42,   43,   44,   45,   37,   47,   40,   91,  215,   42,
   43,  278,   45,   37,   47,  123,  125,   59,   42,   43,
   44,   45,   37,   47,   93,  279,   41,   42,   43,   37,
   45,   61,   47,   93,   42,   43,  125,   45,   37,   47,
   41,   44,   93,   42,   43,   37,   45,   61,   47,   41,
   42,   43,   44,   45,   40,   47,   59,   37,   59,  278,
   93,   41,   42,   43,   44,   45,   37,   47,  278,  125,
   41,   42,   43,   44,   45,   61,   47,   41,  125,   37,
   44,   40,   37,  125,   42,   93,   41,   42,   43,   47,
   45,  279,   47,  281,   93,  276,  277,   41,   37,   40,
   44,   93,   41,   42,   43,   91,   45,   40,   47,   41,
   37,  123,   44,   93,   41,   42,   43,   40,   45,   37,
   47,   40,   93,   41,   42,   43,   37,   45,   40,   47,
  125,   42,   43,   37,   45,   59,   47,   41,   42,   43,
   37,   45,   59,   47,   59,   42,   43,   37,   45,  123,
   47,  123,   42,   43,   91,   45,   41,   47,   37,   44,
   91,   93,   59,   42,   43,   93,   45,   44,   47,  273,
  274,  278,  282,  283,  278,  279,  280,  281,   44,  279,
  273,  274,   59,  287,   61,  278,  279,  280,  281,  284,
  285,  273,  274,   59,  287,   61,  278,  279,  280,  281,
   46,  284,  285,  286,   50,  287,  273,  274,   93,  279,
  280,  278,  279,  280,  281,  284,  285,  286,   41,   91,
  287,   44,  282,  283,  284,  285,  286,   41,  276,  277,
   44,  282,  283,  284,  285,  286,   41,   59,   43,   44,
   45,   87,  284,  285,  286,   59,  282,  283,   44,  282,
  283,  284,  285,  286,   59,  125,  102,  103,  282,  283,
  284,  285,  286,   59,   41,   44,   44,  282,  283,  284,
  285,  286,  288,  289,  282,  283,  284,  285,  286,   41,
   59,   59,   44,  282,  283,  284,  285,  286,  276,  277,
   37,  267,  284,  285,  286,   42,   43,   59,   45,   41,
   47,  279,   37,   44,  284,  285,  286,   42,   43,  125,
   45,  125,   47,  284,  285,  286,  125,   78,   79,   41,
  125,   43,   44,   45,  282,  283,  279,   61,   93,  284,
  285,  286,   41,  123,   43,   44,   45,   59,   41,  264,
   43,   44,   45,   91,   93,  284,  285,  286,  123,  125,
  233,   41,   41,  285,   44,   44,   40,  284,  285,  286,
  243,  244,   59,  125,   41,   61,  284,  285,  286,   59,
   59,  282,  283,  284,  257,  286,   58,   32,   22,  125,
  284,  285,  286,   41,   93,   40,  125,  284,  285,  286,
   93,   58,  282,  283,   41,  123,  286,   44,   59,  284,
  285,  247,   46,  125,  125,  284,   50,  286,   58,   64,
    1,  125,   59,   59,   61,   41,    7,  257,  258,  259,
  260,  261,   77,   59,   59,   80,   41,   18,   61,   59,
  125,   86,  272,   88,   25,  125,  125,  125,   93,    1,
   95,   25,   37,   87,  184,  195,  252,   42,   43,   93,
   45,  221,   47,   61,  258,  259,  260,  261,  102,  103,
  258,   28,  117,  118,  119,  120,  121,  122,  123,  124,
  284,  285,  286,   69,   34,   -1,   -1,   -1,   69,  284,
  285,  286,  258,  259,  260,  261,   -1,  263,  264,  265,
  266,   -1,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  276,  277,  278,  263,  264,  265,  266,   -1,  268,  269,
  270,  271,   -1,   -1,  290,  291,   -1,   -1,  278,   -1,
   -1,   -1,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,
  290,  291,   -1,   91,   92,   -1,   -1,   -1,   -1,  286,
   -1,   -1,   -1,   -1,   -1,   -1,   91,  282,  283,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  213,   -1,
   -1,  216,  284,  285,  286,   -1,   -1,   -1,  223,   -1,
   -1,   -1,   -1,   -1,   -1,  284,  285,  286,  136,  137,
   -1,  284,  285,  286,   -1,  240,   -1,   -1,   -1,  233,
   -1,  136,  137,   -1,  284,  285,  285,   -1,   -1,  243,
  244,   -1,   -1,  247,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  169,   -1,  257,   -1,   -1,  174,  175,  176,  177,
  178,  179,  180,  181,  169,   -1,  184,   -1,   -1,  174,
  175,  176,  177,  178,  179,  180,  181,   -1,   -1,  258,
  259,  260,  261,   -1,  263,  264,  265,  266,  206,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,  278,
   -1,  206,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  290,  291,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KVOID","KINT","KDOUBLE","KBOOL","KCHAR",
"KNULL","KFOR","KWHILE","KDO","KIF","KELSE","KSWITCH","KRETURN","KBREAK",
"KCONTINUE","KCONST","KTRUE","KFALSE","KSTRUCT","KCASE","KDEFAULT","ID","INT",
"DOUBLE","CHAR","DOUBLE_MINUS","DOUBLE_PLUS","AND","OR","COMPARE","STRING",
"HIGH","LOW","DIGIT_WRITE","DELAY","unary","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program : program S",
"program : program function",
"program :",
"$$1 :",
"function : function_outer $$1 function_inner",
"function_outer : type ID '(' para ')'",
"function_outer : KVOID ID '(' para ')'",
"function_inner : '{' full_stats '}'",
"function_var : ID '(' lots_of_expression_var ')'",
"function_var : ID '(' ')'",
"full_stats : stats full_stats",
"full_stats : S full_stats",
"full_stats :",
"nf : stats nf",
"nf :",
"stats : stat ';'",
"stats : if_stat",
"stats : for_loop",
"stats : while_stat",
"stats : do_while_stat",
"stats : switch_stat",
"stats : digit_write ';'",
"stats : delay ';'",
"digit_write : DIGIT_WRITE '(' INT ',' hl ')'",
"delay : DELAY '(' expression ')'",
"hl : HIGH",
"hl : LOW",
"stat : ID '=' expression",
"stat : ID '[' expression_var ']' stat_element_dim '=' expression",
"stat : ID '=' function_var",
"stat : function_var",
"stat : KBREAK",
"stat : KCONTINUE",
"stat : KRETURN expression",
"switch_stat : KSWITCH '(' ID ')' '{' default_stat '}'",
"switch_stat : KSWITCH '(' ID ')' '{' non_default_stat '}'",
"default_stat : KCASE const ':' nf default_stat",
"default_stat : KDEFAULT ':' nf",
"non_default_stat : KCASE const ':' nf non_default_case_stat",
"non_default_case_stat : KCASE const ':' nf non_default_case_stat",
"non_default_case_stat :",
"const : CHAR",
"const : INT",
"while_stat : while_outer '{' full_stats '}'",
"while_outer : KWHILE '(' expression ')'",
"do_while_stat : KDO '{' full_stats '}' KWHILE '(' expression ')' ';'",
"if_stat : if_outer if_inner",
"if_stat : if_else_outer if_inner",
"if_outer : KIF '(' expression ')'",
"if_inner : '{' full_stats '}'",
"if_else_outer : if_outer if_inner KELSE",
"for_loop : KFOR '(' for_loop_para ';' for_loop_para ';' for_loop_para ')' '{' full_stats '}'",
"for_loop_para : expression",
"for_loop_para :",
"stat_element_dim : '[' expression_var ']'",
"stat_element_dim :",
"para : para ',' para_style",
"para : para_style",
"para :",
"para_style : type ID",
"para_style : type ID '[' INT ']' dim",
"S : type lots_of_type ';'",
"S : KCONST type lots_of_const_type ';'",
"dim : '[' INT ']' dim",
"dim :",
"array_init : '=' '{' array_element '}'",
"array_init :",
"array_element : array_element ',' expression",
"array_element :",
"array_element : expression",
"lots_of_type : lots_of_type ',' type_init",
"lots_of_type : type_init",
"lots_of_const_type : lots_of_const_type ',' const_type_init",
"lots_of_const_type : const_type_init",
"const_type_init : ID '=' expression",
"$$2 :",
"type_init : ID $$2 '=' expression",
"type_init : ID",
"type_init : ID '[' INT ']' dim array_init",
"type : KINT",
"type : KDOUBLE",
"type : KCHAR",
"type : KBOOL",
"lots_of_expression_var : expression_var ',' lots_of_expression_var",
"lots_of_expression_var : expression_var",
"expression_var : '(' expression_var ')'",
"expression_var : expression_var DOUBLE_PLUS",
"expression_var : expression_var DOUBLE_MINUS",
"expression_var : expression_var '+' expression_var",
"expression_var : expression_var '-' expression_var",
"expression_var : expression_var '*' expression_var",
"expression_var : expression_var '/' expression_var",
"expression_var : expression_var '%' expression_var",
"expression_var : expression_var COMPARE expression_var",
"expression_var : expression_var AND expression_var",
"expression_var : expression_var OR expression_var",
"expression_var : '!' expression_var",
"expression_var : CHAR",
"expression_var : STRING",
"expression_var : KFALSE",
"expression_var : KTRUE",
"expression_var : UNUM",
"expression_var : ID",
"expression_var : ID '[' expression_var ']' stat_element_dim",
"expression_var : function_var",
"expression : '(' expression ')'",
"expression : ID DOUBLE_PLUS",
"expression : ID DOUBLE_MINUS",
"expression : expression '+' expression",
"expression : expression '-' expression",
"expression : expression '*' expression",
"expression : expression '/' expression",
"expression : expression '%' expression",
"expression : expression COMPARE expression",
"expression : expression AND expression",
"expression : expression OR expression",
"expression : '!' expression",
"expression : CHAR",
"expression : STRING",
"expression : KFALSE",
"expression : KTRUE",
"expression : UNUM",
"expression : ID",
"UNUM : '+' NUM",
"UNUM : '-' NUM",
"UNUM : NUM",
"NUM : INT",
"NUM : DOUBLE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 320 "parser.y"
void popStack(const char* op){
	
	if(!strcmp(op, "+")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "add $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "-")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "sub $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "*")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		
		fprintf(file, "mul $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "/")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		
		fprintf(file, "divsr $r0, $r2, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "%")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		
		fprintf(file, "divsr $r0, $r2, $r0, $r1\n");
		fprintf(file, "swi $r2, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "++")){
		
		
	}else if(!strcmp(op, "--")){
		

	}else if(!strcmp(op, ">")){
		
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);

		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top ++;
	}else if(!strcmp(op, ">=")){
		
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);

		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "xori $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top ++;
	}else if(!strcmp(op, "<")){
		
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top ++;
	}else if(!strcmp(op, "<=")){
		
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "xori $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "==")){
		
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		
		fprintf(file, "xor $r0, $r1, $r0\n");
		fprintf(file, "slti $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "!=")){
		
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top * 4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);

		fprintf(file, "xor $r0, $r1, $r0\n");
		fprintf(file, "movi $r1, 0\n");
		fprintf(file, "slt $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "&&")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "beqz $r0, .AND%d\n", and_label_count);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "beqz $r0, .AND%d\n", and_label_count);

		fprintf(file, "movi $r0, 1\n");
		fprintf(file, "j .AND%d\n", and_label_count+1);
		fprintf(file, ".AND%d:\n", and_label_count);
		and_label_count++;
		fprintf(file, "movi $r0, 0\n");
		fprintf(file, ".AND%d:\n", and_label_count);
		and_label_count++;
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;

	}else if(!strcmp(op, "||")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "beqz $r0, .OR%d\n", or_label_count+1);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "beqz $r0, .OR%d\n", or_label_count);
		fprintf(file, ".OR%d:\n", or_label_count);
		or_label_count++;
		fprintf(file, "movi $r0, 1\n");
		fprintf(file, "j .OR%d\n", or_label_count+1);
		fprintf(file, ".OR%d:\n", or_label_count);
		or_label_count++;
		fprintf(file, "movi $r0, 0\n");
		fprintf(file, ".OR%d:\n", or_label_count);
		or_label_count++;
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}else if(!strcmp(op, "!")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "addi $r0, $r0, 0\n");
		fprintf(file, "slti $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}
}
int yyerror(const char* msg){
	fprintf(stderr, "***Error at line %d: %s\n",lineCount + 1, curString);
	fprintf(stderr,"\n");
	fprintf(stderr, "Unmatched token: %s\n", yytext);
	fprintf(stderr, "***syntax error\n");
	exit(-1);
}
int main(void)
{
	file = fopen("assembly","w");
	table = new SymbolTable();
	yyparse();
	if(function_main_flag == 0){
		curString[0] = '\0';
		printf("No main function!!\n");
		yyerror(" ");
	}
	
	fprintf(stdout, "No syntax error!\n");
	return 0;
}


#line 783 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 54 "parser.y"
	{function_main_flag = 1;}
break;
case 4:
#line 57 "parser.y"
	{
			scope++;
		}
break;
case 24:
#line 86 "parser.y"
	{
				fprintf(file, "movi $r0, %d\n", yystack.l_mark[-3].intVal);
				fprintf(file, "movi $r1, %d\n", yystack.l_mark[-1].intVal);
				fprintf(file, "bal digitalWrite\n");
		   }
break;
case 25:
#line 92 "parser.y"
	{
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "bal delay\n");
	 }
break;
case 26:
#line 98 "parser.y"
	{
     yyval.intVal = 1;
  }
break;
case 27:
#line 101 "parser.y"
	{
	yyval.intVal = 0;
  }
break;
case 28:
#line 105 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
		fprintf(file, "swi $r0, [$sp + %d]\n", table->lookup(yystack.l_mark[-2].idVal) * 4);
		printf("%s offset is %d\n", yystack.l_mark[-2].idVal, table->lookup(yystack.l_mark[-2].idVal));
	}
break;
case 34:
#line 116 "parser.y"
	{
		top --;
	}
break;
case 44:
#line 137 "parser.y"
	{
			fprintf(file, "j .WHILE%d\n", while_label_count-2);
			fprintf(file, ".WHILE%d:\n", while_label_count);
			while_label_count++;
			int pop_count = table->pop();
			top = top - pop_count;
			scope --;
			table->updateScope(scope);
		  }
break;
case 45:
#line 147 "parser.y"
	{
				fprintf(file, ".WHILE%d:\n", while_label_count);
				while_label_count++;
				top--;
				fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
				fprintf(file, "bnez $r0, .WHILE%d\n", while_label_count);
				fprintf(file, "j .WHILE%d\n", while_label_count + 1);
				fprintf(file, ".WHILE%d:\n", while_label_count);
				while_label_count++;
				scope++;
				table->updateScope(scope);
		   }
break;
case 47:
#line 162 "parser.y"
	{
			fprintf(file, ".ELSE%d:\n", if_label_count);
			if_label_count++;
			fprintf(file, ".FIN%d:\n", finish_label_count);
			finish_label_count++;
	   }
break;
case 48:
#line 168 "parser.y"
	{
			fprintf(file, ".FIN%d:\n", finish_label_count);
			finish_label_count++;
	   }
break;
case 49:
#line 173 "parser.y"
	{
			top --;
			fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
			fprintf(file, "beqz $r0, .ELSE%d\n", if_label_count);
			scope++;
			table->updateScope(scope);
	    }
break;
case 50:
#line 181 "parser.y"
	{
			fprintf(file, "j .FIN%d\n", finish_label_count);
			int pop_count = table->pop();
			top = top - pop_count;
			scope --;
			table->updateScope(scope);
		}
break;
case 51:
#line 189 "parser.y"
	{
				scope ++;
				table->updateScope(scope);
				fprintf(file, ".ELSE%d:\n", if_label_count);
				if_label_count++;
			 }
break;
case 76:
#line 232 "parser.y"
	{
				table->updateScope(scope);
				table->install(yystack.l_mark[0].idVal, top);
				printf("%s is install to %d\n", yystack.l_mark[0].idVal, top);
				printf("%s is install to %d\n", yystack.l_mark[0].idVal, table->lookup(yystack.l_mark[0].idVal));
				top ++;
			}
break;
case 77:
#line 238 "parser.y"
	{
			
			top --;
			fprintf(file, "lwi $r0, [$sp + %d]\n", top * 4);
			fprintf(file, "swi  $r0, [$sp + %d]\n", table->lookup(yystack.l_mark[-3].idVal) * 4);
			
		 }
break;
case 78:
#line 245 "parser.y"
	{
			table->updateScope(scope);
			table->install(yystack.l_mark[0].idVal, top);
			printf("%s is install to %d\n", yystack.l_mark[0].idVal, top);
			printf("%s is install to %d\n", yystack.l_mark[0].idVal, table->lookup(yystack.l_mark[0].idVal));
			top++;
		 }
break;
case 107:
#line 284 "parser.y"
	{popStack("++");}
break;
case 108:
#line 285 "parser.y"
	{popStack("--");}
break;
case 109:
#line 286 "parser.y"
	{popStack("+");}
break;
case 110:
#line 287 "parser.y"
	{popStack("-");}
break;
case 111:
#line 288 "parser.y"
	{popStack("*");}
break;
case 112:
#line 289 "parser.y"
	{popStack("/");}
break;
case 113:
#line 290 "parser.y"
	{popStack("%");}
break;
case 114:
#line 291 "parser.y"
	{popStack(yystack.l_mark[-1].idVal);}
break;
case 115:
#line 292 "parser.y"
	{popStack(yystack.l_mark[-1].idVal);}
break;
case 116:
#line 293 "parser.y"
	{popStack(yystack.l_mark[-1].idVal);}
break;
case 117:
#line 294 "parser.y"
	{popStack("!");}
break;
case 123:
#line 300 "parser.y"
	{
			printf("%s offset = %d\n", yystack.l_mark[0].idVal, table->lookup(yystack.l_mark[0].idVal));
			fprintf(file, "lwi $r0, [$sp + %d]\n", table->lookup(yystack.l_mark[0].idVal) * 4);
			fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
			top++;
		  }
break;
case 127:
#line 311 "parser.y"
	{
		fprintf(file, "movi $r0, %d\n", yystack.l_mark[0].intVal);
		fprintf(file, "swi $r0, [$sp + %d]\n", top * 4);
		top++;
	}
break;
#line 1201 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
