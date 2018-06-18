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

#line 1 "parser.y"

/*includes*/
#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.hpp"
#include "scanner.h"
#include "y.tab.h"

int yylex();
int yyerror(char* msg);

/*variables*/
SymbolTable* table;
FILE* file;
int scope = 0;
int top = 0;

int if_count = 0;
int finish_count = 0;
int and_count = 0;
int or_count = 0;
int while_count = 0;
#line 42 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

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

#define IDENTIFIER 257
#define NUMBER_SCI 258
#define NUMBER_DOUBLE 259
#define NUMBER_INTEGER 260
#define CHARACTER 261
#define VOID 262
#define INT 263
#define DOUBLE 264
#define BOOL 265
#define CHAR 266
#define STRING 267
#define K_NULL 268
#define FOR 269
#define WHILE 270
#define DO 271
#define IF 272
#define ELSE 273
#define SWITCH 274
#define RETURN 275
#define BREAK 276
#define CONTINUE 277
#define CONST 278
#define TRUE 279
#define FALSE 280
#define STRUCT 281
#define CASE 282
#define DEFAULT 283
#define FCLOSE 284
#define CLEARERR 285
#define FERROR 286
#define FFLUSH 287
#define FGETPOS 288
#define FOPEN 289
#define FREAD 290
#define FREOPEN 291
#define FSEEK 292
#define FTELL 293
#define FWRITE 294
#define REMOVE 295
#define RENAME 296
#define REWIND 297
#define SETBUF 298
#define SETVBUF 299
#define TMPFILE 300
#define TMPNAM 301
#define FPRINTF 302
#define PRINTF 303
#define SPRINTF 304
#define VFPRINTF 305
#define VPRINTF 306
#define VSPRINTF 307
#define FSCANF 308
#define SCANF 309
#define SSCANF 310
#define FGETC 311
#define FGETS 312
#define FPUTC 313
#define FPUTS 314
#define GETC 315
#define GETCHAR 316
#define GETS 317
#define PUTC 318
#define PUTCHAR 319
#define PUTS 320
#define UNGETC 321
#define PERROR 322
#define FFPRINTF 323
#define INC_OP 324
#define DEC_OP 325
#define LE_OP 326
#define GE_OP 327
#define EQ_OP 328
#define NE_OP 329
#define AND_OP 330
#define OR_OP 331
#define POINTER_OP 332
#define ADD_ASSIGN 333
#define SUB_ASSIGN 334
#define DIV_ASSIGN 335
#define MUL_ASSIGN 336
#define INVALIDNUM 337
#define DELAY 338
#define DIGITALWRITE 339
#define HIGH 340
#define LOW 341
#define ELSE_DUMMY_FOR_CONFLICT 342
#define OR 343
#define AND 344
#define unary 345
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    3,    3,    5,    5,    4,    4,    6,
    6,    8,   10,   10,   10,   10,    9,    9,   11,   11,
   12,   14,   14,   14,   14,   14,   14,    7,    7,   18,
   18,   19,   19,   20,   20,   21,   22,   22,   22,   22,
   22,   22,   22,    2,    2,    2,    2,   13,   13,   13,
   13,   25,   25,   25,   25,   27,   28,   28,   29,   16,
   16,   30,   30,   17,   17,   24,   31,   32,   32,   33,
   33,   33,   33,   33,   33,   33,   33,   41,   41,   39,
   40,   37,   37,   37,   38,   38,   38,   38,   34,   34,
   43,   35,   44,   45,   46,   35,   35,   47,   36,   36,
   36,   36,   42,   42,   48,   48,   26,   26,   15,   15,
   51,   51,   52,   52,   53,   53,   53,   54,   54,   54,
   54,   54,   55,   55,   55,   56,   56,   56,   56,   49,
   49,   49,   49,   23,   23,   59,   59,   60,   60,   61,
   61,   61,   62,   62,   62,   62,   62,   63,   63,   63,
   64,   64,   64,   64,   50,   50,   50,   50,   65,   65,
   65,   65,   65,   66,   66,   66,   66,   58,   58,   58,
   58,   57,   57,   57,   57,   57,   57,   57,   69,   69,
   68,   68,   68,   68,   67,   67,   67,   67,
};
static const short yylen[] = {                            2,
    2,    0,    2,    1,    1,    1,    2,    1,    1,    2,
    3,    2,    1,    1,    1,    1,    1,    3,    3,    1,
    1,    1,    3,    3,    4,    4,    4,    2,    3,    1,
    2,    1,    3,    3,    1,    1,    1,    3,    3,    3,
    4,    4,    4,    4,    3,    4,    3,    2,    3,    4,
    1,    2,    1,    3,    3,    2,    1,    2,    2,    1,
    3,    2,    1,    1,    3,    3,    2,    0,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    4,
    6,    3,    4,    3,    2,    2,    2,    3,    1,    2,
    0,    6,    0,    0,    0,   10,    5,    0,    6,    7,
    6,    7,    1,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    1,    3,    1,    3,    3,    1,    3,    3,
    3,    3,    1,    3,    3,    1,    3,    3,    3,    1,
    2,    2,    2,    1,    3,    1,    3,    1,    3,    1,
    3,    3,    1,    3,    3,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    2,    2,    2,    1,    3,
    3,    2,    2,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    4,    3,    4,    3,    2,    2,    1,    3,
    1,    1,    1,    3,    1,    1,    1,    1,
};
static const short yydefred[] = {                         2,
    0,    0,    0,   13,   14,   15,   16,    0,    0,    3,
    5,    8,    9,    0,    0,    0,   37,    0,    0,    0,
   12,   22,   10,    0,    0,   17,    0,    0,   31,   28,
    0,   32,    0,    0,    2,    6,    0,    0,   47,    0,
    0,    0,   11,    0,    0,    0,    0,   29,    0,    0,
    0,   45,   38,    0,    0,    7,   46,    0,  164,  187,
  186,  185,  188,  166,    0,    0,  171,  169,  170,   40,
    0,  168,    0,  151,    0,    0,    0,    0,    0,    0,
    0,    0,  159,  165,   64,   39,    0,    0,    0,   60,
   23,   18,    0,   19,    0,   51,    0,  181,  183,    0,
    0,   24,    0,    0,  126,    0,    0,    0,    0,    0,
    0,    0,    0,  182,  172,    0,    0,   33,   34,   44,
    4,    0,   66,  156,  157,    0,    0,  103,    0,    0,
   41,  158,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  162,  163,    0,    0,    0,
   42,    0,   43,   62,   48,    0,   53,    0,    0,    0,
   57,    0,  131,  132,    0,    0,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  177,  178,    0,    0,    0,  133,   26,   27,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   89,   70,   69,   71,   72,   73,   74,   75,   76,
   77,    0,    0,  167,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  152,  153,  154,  160,
  161,   61,   65,   59,    0,   49,   52,   56,   58,  108,
  184,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  127,  128,  129,    0,  174,  179,    0,  176,
    0,    0,    0,    0,    0,    0,   87,    0,   86,   85,
    0,    0,    0,    0,   90,  104,  106,   50,   55,   54,
  173,    0,  175,   82,    0,    0,    0,    0,    0,   88,
    0,   84,    0,    0,  180,    0,   98,    0,   91,    0,
   83,   80,    0,    0,    0,    0,    0,    0,    0,   97,
   78,   79,    0,  101,    0,   99,    0,   92,   94,   81,
  102,  100,    0,   95,    0,   96,
};
static const short yydgoto[] = {                          1,
    2,    9,   10,   11,   37,   12,   13,   14,   25,   15,
   26,   27,   94,   28,  126,   87,   88,   38,   31,   32,
   58,   20,   95,  203,  158,   96,  159,  160,  161,   90,
   55,  122,  204,  205,  206,  207,  208,  209,  210,  211,
  313,  212,  308,  309,  323,  325,  306,  128,  129,   74,
  106,  107,  108,  109,  110,  111,  112,  113,   76,   77,
   78,   79,   80,   81,   82,   83,  114,  115,  259,
};
static const short yysindex[] = {                         0,
    0,  343,  -39,    0,    0,    0,    0,  481,    0,    0,
    0,    0,    0,  -36,  481,  -12,    0,  -39,  634,  -18,
    0,    0,    0,  -26,  -42,    0,  -13,  -16,    0,    0,
  118,    0,  764,  -30,    0,    0,  634,  -12,    0,  112,
  119,   -5,    0,  -26,  245,  301,  268,    0,  -39,  245,
  634,    0,    0,  343,  -64,    0,    0,  -11,    0,    0,
    0,    0,    0,    0,  428,  428,    0,    0,    0,    0,
  439,    0,  -84,    0,  428, -221, -217,   14,   48,   11,
  175,   53,    0,    0,    0,    0,   47,   91,  -39,    0,
    0,    0,  150,    0, -206,    0,   90,    0,    0,  439,
  439,    0,  439,  -75,    0, -165, -164,   52,   76,  113,
  604,  254,  439,    0,    0,   93,  167,    0,    0,    0,
    0,   -6,    0,    0,    0, -155,  179,    0,  117,  428,
    0,    0,  428,  428,  428,  428,  428,  428,  428,  428,
  428,  428,  428,  428,  428,    0,    0,   99,  -57,  481,
    0,    3,    0,    0,    0,   27,    0,  -25,  245,  124,
    0,  428,    0,    0,  188,  439,    0,  439,  439,  439,
  439,  439,  439,  439,  439,  439,  439,  439,  439,  439,
    0,    0,  439,  269,   29,    0,    0,    0,  161,  206,
  222,   -6,  264,  273,  395,  256,  262,  439,  280,  291,
  309,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  120,  439,    0,  439, -221, -217,   14,   48,   48,
   11,   11,   11,   11,  175,  175,    0,    0,    0,    0,
    0,    0,    0,    0,  164,    0,    0,    0,    0,    0,
    0, -165, -164,   52,   76,   76,  113,  113,  113,  113,
  604,  604,    0,    0,    0,  -19,    0,    0,  189,    0,
   -6,  406,  439,   88,  439,  439,    0,  128,    0,    0,
  -50,   -6,  439,  133,    0,    0,    0,    0,    0,    0,
    0,  439,    0,    0,  406,  276,  366,  306,  385,    0,
   -6,    0,  401,  372,    0,  417,    0,  439,    0,   -6,
    0,    0,   64,   -6,  415,   -6,  426,   -6,   -6,    0,
    0,    0,  377,    0,   -6,    0,  368,    0,    0,    0,
    0,    0,  159,    0,   -6,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,
    0,    0,    0,    0,  102,    0,    0,    0,    0,  695,
    0,    0,    0,    0,    0,    0,  130,  673,    0,    0,
    0,    0,  157,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -33,    0,    0,    0,  157,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  110,  215,  155,  223,  599,
  667,   34,    0,    0,    0,    0,    0,    0,  454,    0,
    0,    0,    0,    0,  154,    0,   69,    0,    0,    0,
    0,    0,    0,    0,    0,  -38,   89,    5,  506,  522,
  449,   25,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  338,    0,    0,    0,   80,    0,    0,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  147,  590,  371,  730,  820,
  753,  770,  831,  875,  678,  706,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -28,  122,   82,  586,  650,  530,  542,  554,  578,
  456,  479,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  399,  422,    0,  591,  436,    0,    0,    0,    0,  475,
  447,  486,  208,    0,  -31,  466,  470,  936,    0,  472,
  168,    0,  495,  903,    0,  357,  305,    0,  388,  407,
    0,    0, 1019, -233,    0,    0,    0,    0,    0,    0,
    0,  868,    0,    0,    0,    0,    0, -133, 1128, 1133,
  390,  405,  398,  277,  621,  304,    0,  981,  455,  444,
  453,  408,  682,  434,    0,    0, 1125,    0,    0,
};
#define YYTABLESIZE 1368
static const short yytable[] = {                         68,
   18,   44,  109,   24,   68,  109,   68,  291,  131,   68,
   53,   68,  110,   24,  104,  110,   43,  167,  235,  109,
  109,   41,   23,   47,  213,   68,   67,   18,  285,  110,
  110,   72,    1,  103,  181,   91,   68,  181,   69,  181,
  181,  181,  181,  181,  181,  113,   30,   45,  113,   50,
  258,  296,  202,  141,  109,  142,  181,  181,  181,  181,
  123,  130,  113,  113,  110,  130,  130,  130,  130,  130,
  155,  130,   40,  281,   46,  155,  155,  155,  155,  276,
  155,  277,  130,  130,  130,  130,  130,  151,  181,   68,
  150,   68,  155,  155,  155,  155,  126,  113,  149,  236,
  126,  126,  126,  126,  126,  151,  126,  139,  133,  140,
  151,  151,  151,  151,  134,  151,   35,  130,  126,  126,
  105,  126,  114,  105,  130,  114,  155,  151,  151,  111,
  151,  153,  111,  187,  152,  174,  150,  175,  105,  114,
  114,   30,   30,  148,   67,   30,  111,  111,  295,   72,
  162,   71,  126,  134,   68,  176,   69,  177,  155,   86,
   30,   49,  112,  213,  168,  112,  271,  169,  134,  156,
   19,  213,  105,   20,  114,  166,   48,  215,  275,  112,
  112,  111,   67,   33,  238,   34,  290,   72,   20,   71,
  135,  230,   68,  151,   69,  156,   67,  107,  138,  231,
   35,   72,  134,   71,   70,  135,   68,  188,   69,  156,
  152,  145,  107,  138,  112,   35,  143,   17,  261,  214,
   22,  144,  213,   68,   68,   68,   68,   68,  241,  283,
   22,  213,  282,   68,  134,   68,   68,   68,   68,  135,
   68,   68,   68,   68,   17,  262,  130,  138,   68,   68,
  189,   60,   61,   62,   63,  166,  154,  119,  136,  233,
   99,  263,  190,  191,  192,  193,  140,  194,  195,  196,
  197,  135,   93,  136,  155,  198,  199,   67,  107,  138,
  166,  140,   72,  234,   71,  260,   93,   68,  278,   69,
   68,   68,  109,  184,    4,    4,    4,    4,    4,  185,
  157,   67,  110,  265,   68,   68,   72,  136,  103,  257,
    4,   68,  266,   69,  269,  140,  297,  100,  101,  213,
  270,  181,  181,  181,  181,  181,  181,  181,  181,  181,
  273,  200,  201,   67,  113,  113,  113,  272,   72,  136,
  103,  135,  136,   68,  183,   69,  299,  140,  274,  213,
  130,  130,  130,  130,  130,  130,  130,  287,   30,  155,
  155,  155,  155,  155,  155,  155,  237,   93,   59,   60,
   61,   62,   63,  137,  138,   85,  146,  147,   64,  170,
  171,    4,    5,    6,    7,  126,  126,  126,  126,  126,
  126,  126,  294,  102,  151,  151,  151,  151,  151,  151,
  151,  172,  173,  311,  312,  298,   59,   60,   61,   62,
   63,  114,  114,  114,  139,  303,   64,  320,  111,  111,
   59,   60,   61,   62,   63,  300,  322,   67,  213,  139,
   64,  324,   72,   54,  103,   65,   66,   68,   67,   69,
  134,  302,  279,   72,  213,  103,  245,  246,   68,   67,
   69,  112,  112,  267,   72,  315,  103,  304,  213,   68,
   67,   69,   67,  139,  202,   72,  317,   71,   51,  213,
   68,   67,   69,   65,   66,  121,   72,  135,  103,  251,
  252,   68,   21,   69,  138,  138,  138,   65,   66,  123,
   92,  123,  123,  123,   63,  139,  124,   63,  124,  124,
  124,   59,   60,   61,   62,   63,  123,  123,  123,   42,
  123,   64,  116,  124,  124,  124,  117,  124,  240,  125,
  118,  125,  125,  125,   85,   98,   60,   61,   62,   63,
    4,    5,    6,    7,   73,   99,  125,  125,  125,  280,
  125,  123,  219,  220,  136,  136,  115,  239,  124,  115,
  140,  140,  140,  140,  140,  242,  232,   98,   60,   61,
   62,   63,  118,  115,  115,  118,  244,   99,   65,   66,
  122,  125,  243,  122,  225,  226,  217,  181,  182,  118,
  118,  118,  121,  118,  216,  121,  218,  122,  122,  122,
    0,  122,  100,  101,  120,    0,    0,  120,  115,  121,
  121,  121,    0,  121,    3,    4,    5,    6,    7,   36,
    0,  120,  120,  120,  118,  120,    0,    0,  119,    0,
    8,  119,  122,   36,  100,  101,  116,   56,    0,  116,
    0,    0,    0,  137,  121,  119,  119,  119,    0,  119,
  180,   56,  143,  116,  116,  178,  120,    0,  137,    0,
  179,   98,   60,   61,   62,   63,    0,  143,  143,    0,
  143,   99,   98,   60,   61,   62,   63,    0,    0,    0,
  119,    0,   99,   98,   60,   61,   62,   63,  116,    0,
    0,    0,  137,   99,   59,   60,   61,   62,   63,    0,
  117,  143,    0,  117,   64,   98,   60,   61,   62,   63,
  139,  139,  139,    0,    0,   99,    0,  117,  117,  148,
  148,  148,    0,   21,  137,    0,   21,    0,  100,  101,
  149,  149,  149,  143,    0,  148,  148,    0,  148,  100,
  101,   21,    0,   21,    0,   36,  149,  149,   36,  149,
  100,  101,  117,    4,    5,    6,    7,    0,  150,  150,
  150,   65,   66,   36,    0,   36,   35,    0,    0,  148,
    0,    0,  100,  101,  150,  150,    0,  150,    0,    0,
  149,    0,    0,  141,  123,  123,  123,  123,  123,  123,
  123,  124,  124,  124,  124,  124,  124,  124,  141,    0,
    0,  148,  247,  248,  249,  250,  147,    0,  150,    0,
    0,    0,  149,    0,  125,  125,  125,  125,  125,  125,
  125,  147,  147,  146,  147,    0,    0,   36,  221,  222,
  223,  224,  141,    0,   50,    0,    0,    0,  146,  146,
  150,  146,    0,  115,  115,  115,  115,  115,    0,    0,
    0,    0,    0,    0,    0,  147,    0,  118,  118,  118,
  118,  118,  118,  118,  141,  122,  122,  122,  122,  122,
  122,  122,  146,  142,    0,    0,    0,  121,  121,  121,
  121,  121,  121,  121,  145,    0,    0,  147,  142,  120,
  120,  120,  120,  120,  120,  120,   35,    0,    0,  145,
  145,    0,  145,    0,  146,    0,    4,    5,    6,    7,
    0,    0,    0,  119,  119,  119,  119,  119,  119,  119,
    0,    8,  142,  116,  116,  116,  116,  116,  144,  137,
  137,   39,    0,  145,  143,  143,  143,  143,  143,  143,
  143,    0,    0,  144,  144,   52,  144,   16,  127,   57,
    0,    0,    0,    0,  142,    0,    0,    0,    0,    0,
   29,    0,    0,  120,    0,  145,    0,   36,   36,   36,
   36,    0,    0,    0,    0,    0,    0,  144,    0,    0,
  165,    0,   36,    0,    0,    0,   89,  117,  117,  117,
  117,  117,   89,    0,    0,    0,    0,    0,    0,   16,
    0,    0,  148,  148,  148,  148,  148,  148,  148,  144,
    0,    0,    0,  149,  149,  149,  149,  149,  149,  149,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   75,    0,    0,    0,    0,   75,    4,    5,    6,    7,
   75,  150,  150,  150,  150,  150,  150,  150,    0,    0,
    0,    8,    0,    0,    0,   75,   75,    0,    0,    0,
  256,    0,    0,    0,    0,   75,    0,  141,  141,  141,
  141,  141,  268,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,    0,    0,    0,    0,  147,  147,
  147,  147,  147,  147,  147,   89,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  146,  146,  146,  146,  146,
  146,  146,    0,    0,    0,    0,    0,    0,    0,    0,
   75,    0,    0,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,    0,    0,    0,    0,
  286,    0,  288,  289,    0,    0,    0,    0,    0,   75,
  293,    0,   75,    0,    0,    0,    0,  142,  142,  142,
  142,  142,    0,    0,    0,    0,  145,  145,  145,  145,
  145,  145,  145,  305,   84,  307,    0,    0,    0,   84,
    0,    0,    0,  105,   84,    0,    0,   97,    0,    0,
    0,    0,   97,    0,    0,    0,    0,    0,    0,   84,
   84,    0,    0,    0,    0,    0,    0,  124,  125,   84,
  144,  144,  144,  144,  144,  144,  144,  132,    0,    0,
  264,    0,    0,    0,    0,   75,    0,   84,    0,    0,
    0,    0,    0,    0,    0,   97,    0,  163,  164,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  186,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,    0,   84,   84,   84,
   84,   84,   84,   84,   84,   84,   84,   84,   84,   84,
    0,    0,    0,    0,    0,  227,  228,  229,    0,  284,
    0,    0,    0,   84,    0,    0,   84,    0,    0,    0,
  292,   97,    0,  105,   97,  105,  105,  105,  105,  105,
  105,  105,  105,  105,  105,  253,  254,  255,    0,  301,
    0,    0,    0,    0,    0,    0,    0,    0,  310,    0,
    0,    0,  314,    0,  316,  105,  318,  319,    0,    0,
    0,    0,    0,  321,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  326,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   84,
    0,    0,    0,    0,    0,    0,    0,   97,
};
static const short yycheck[] = {                         33,
   40,   44,   41,   40,   38,   44,   40,   58,   93,   43,
   41,   45,   41,   40,   46,   44,   59,   93,   44,   58,
   59,   40,   59,   40,   44,   59,   33,   40,  262,   58,
   59,   38,    0,   40,   37,   41,   43,   40,   45,   42,
   43,   44,   45,   46,   47,   41,   59,   61,   44,   61,
  184,  285,   59,   43,   93,   45,   59,   60,   61,   62,
  125,   37,   58,   59,   93,   41,   42,   43,   44,   45,
   37,   47,   91,   93,   91,   42,   43,   44,   45,  213,
   47,  215,   58,   59,   60,   61,   62,   41,   91,  123,
   44,  125,   59,   60,   61,   62,   37,   93,   46,  125,
   41,   42,   43,   44,   45,   37,   47,   60,  330,   62,
   42,   43,   44,   45,  332,   47,  123,   93,   59,   60,
   41,   62,   41,   44,  331,   44,   93,   59,   60,   41,
   62,   41,   44,   41,   44,   60,   44,   62,   59,   58,
   59,   40,   41,   91,   33,   44,   58,   59,  282,   38,
   61,   40,   93,   44,   43,   43,   45,   45,  125,   41,
   59,   44,   41,   44,  330,   44,  198,  332,   59,   46,
    3,   44,   93,   44,   93,  331,   59,   61,   59,   58,
   59,   93,   33,   16,   61,   18,   59,   38,   59,   40,
   44,   93,   43,  125,   45,   46,   33,   44,   44,  257,
   44,   38,   93,   40,   93,   59,   43,   41,   45,   46,
   44,   37,   59,   59,   93,   59,   42,  257,   58,   41,
  257,   47,   44,  257,  258,  259,  260,  261,   41,   41,
  257,   44,   44,  267,  125,  269,  270,  271,  272,   93,
  274,  275,  276,  277,  257,   40,  331,   93,  282,  283,
  257,  258,  259,  260,  261,  331,   89,   50,   44,  257,
  267,   40,  269,  270,  271,  272,   44,  274,  275,  276,
  277,  125,  123,   59,  125,  282,  283,   33,  125,  125,
  331,   59,   38,  257,   40,  257,  123,   43,  125,   45,
  324,  325,  331,   40,  262,  263,  264,  265,  266,   46,
   93,   33,  331,   40,  338,  339,   38,   93,   40,   41,
  278,   43,   40,   45,   59,   93,   41,  324,  325,   44,
   59,  324,  325,  326,  327,  328,  329,  330,  331,  332,
   40,  338,  339,   33,  330,  331,  332,   58,   38,  125,
   40,  328,  329,   43,   91,   45,   41,  125,   40,   44,
  326,  327,  328,  329,  330,  331,  332,  270,  257,  326,
  327,  328,  329,  330,  331,  332,  159,  123,  257,  258,
  259,  260,  261,  326,  327,  257,  324,  325,  267,  328,
  329,  263,  264,  265,  266,  326,  327,  328,  329,  330,
  331,  332,  260,   93,  326,  327,  328,  329,  330,  331,
  332,  326,  327,  340,  341,   40,  257,  258,  259,  260,
  261,  330,  331,  332,   44,   44,  267,   41,  330,  331,
  257,  258,  259,  260,  261,   41,   59,   33,   44,   59,
  267,  273,   38,   35,   40,  324,  325,   43,   33,   45,
  331,   41,  235,   38,   44,   40,  170,  171,   43,   33,
   45,  330,  331,   59,   38,   41,   40,   41,   44,   43,
   33,   45,  125,   93,   59,   38,   41,   40,   33,   44,
   43,   33,   45,  324,  325,   54,   38,  331,   40,  176,
  177,   43,    8,   45,  330,  331,  332,  324,  325,   41,
   44,   43,   44,   45,   41,  125,   41,   44,   43,   44,
   45,  257,  258,  259,  260,  261,   58,   59,   60,   24,
   62,  267,   47,   58,   59,   60,   47,   62,  162,   41,
   49,   43,   44,   45,  257,  257,  258,  259,  260,  261,
  263,  264,  265,  266,   40,  267,   58,   59,   60,  235,
   62,   93,  135,  136,  330,  331,   41,  160,   93,   44,
  328,  329,  330,  331,  332,  166,  150,  257,  258,  259,
  260,  261,   41,   58,   59,   44,  169,  267,  324,  325,
   41,   93,  168,   44,  141,  142,  133,  324,  325,   58,
   59,   60,   41,   62,  130,   44,  134,   58,   59,   60,
   -1,   62,  324,  325,   41,   -1,   -1,   44,   93,   58,
   59,   60,   -1,   62,  262,  263,  264,  265,  266,   19,
   -1,   58,   59,   60,   93,   62,   -1,   -1,   41,   -1,
  278,   44,   93,   33,  324,  325,   41,   37,   -1,   44,
   -1,   -1,   -1,   44,   93,   58,   59,   60,   -1,   62,
   37,   51,   44,   58,   59,   42,   93,   -1,   59,   -1,
   47,  257,  258,  259,  260,  261,   -1,   59,   60,   -1,
   62,  267,  257,  258,  259,  260,  261,   -1,   -1,   -1,
   93,   -1,  267,  257,  258,  259,  260,  261,   93,   -1,
   -1,   -1,   93,  267,  257,  258,  259,  260,  261,   -1,
   41,   93,   -1,   44,  267,  257,  258,  259,  260,  261,
  330,  331,  332,   -1,   -1,  267,   -1,   58,   59,   43,
   44,   45,   -1,   41,  125,   -1,   44,   -1,  324,  325,
   43,   44,   45,  125,   -1,   59,   60,   -1,   62,  324,
  325,   59,   -1,   61,   -1,   41,   59,   60,   44,   62,
  324,  325,   93,  263,  264,  265,  266,   -1,   43,   44,
   45,  324,  325,   59,   -1,   61,  123,   -1,   -1,   93,
   -1,   -1,  324,  325,   59,   60,   -1,   62,   -1,   -1,
   93,   -1,   -1,   44,  326,  327,  328,  329,  330,  331,
  332,  326,  327,  328,  329,  330,  331,  332,   59,   -1,
   -1,  125,  172,  173,  174,  175,   44,   -1,   93,   -1,
   -1,   -1,  125,   -1,  326,  327,  328,  329,  330,  331,
  332,   59,   60,   44,   62,   -1,   -1,  123,  137,  138,
  139,  140,   93,   -1,   61,   -1,   -1,   -1,   59,   60,
  125,   62,   -1,  328,  329,  330,  331,  332,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,  326,  327,  328,
  329,  330,  331,  332,  125,  326,  327,  328,  329,  330,
  331,  332,   93,   44,   -1,   -1,   -1,  326,  327,  328,
  329,  330,  331,  332,   44,   -1,   -1,  125,   59,  326,
  327,  328,  329,  330,  331,  332,  123,   -1,   -1,   59,
   60,   -1,   62,   -1,  125,   -1,  263,  264,  265,  266,
   -1,   -1,   -1,  326,  327,  328,  329,  330,  331,  332,
   -1,  278,   93,  328,  329,  330,  331,  332,   44,  330,
  331,   19,   -1,   93,  326,  327,  328,  329,  330,  331,
  332,   -1,   -1,   59,   60,   33,   62,    2,   71,   37,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   15,   -1,   -1,   51,   -1,  125,   -1,  263,  264,  265,
  266,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,
  103,   -1,  278,   -1,   -1,   -1,   41,  328,  329,  330,
  331,  332,   47,   -1,   -1,   -1,   -1,   -1,   -1,   54,
   -1,   -1,  326,  327,  328,  329,  330,  331,  332,  125,
   -1,   -1,   -1,  326,  327,  328,  329,  330,  331,  332,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   -1,   -1,   -1,   -1,   45,  263,  264,  265,  266,
   50,  326,  327,  328,  329,  330,  331,  332,   -1,   -1,
   -1,  278,   -1,   -1,   -1,   65,   66,   -1,   -1,   -1,
  183,   -1,   -1,   -1,   -1,   75,   -1,  328,  329,  330,
  331,  332,  195,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,  326,  327,
  328,  329,  330,  331,  332,  150,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  326,  327,  328,  329,  330,
  331,  332,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  130,   -1,   -1,  133,  134,  135,  136,  137,  138,  139,
  140,  141,  142,  143,  144,  145,   -1,   -1,   -1,   -1,
  263,   -1,  265,  266,   -1,   -1,   -1,   -1,   -1,  159,
  273,   -1,  162,   -1,   -1,   -1,   -1,  328,  329,  330,
  331,  332,   -1,   -1,   -1,   -1,  326,  327,  328,  329,
  330,  331,  332,  296,   40,  298,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   46,   50,   -1,   -1,   45,   -1,   -1,
   -1,   -1,   50,   -1,   -1,   -1,   -1,   -1,   -1,   65,
   66,   -1,   -1,   -1,   -1,   -1,   -1,   65,   66,   75,
  326,  327,  328,  329,  330,  331,  332,   75,   -1,   -1,
  192,   -1,   -1,   -1,   -1,  235,   -1,   93,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,  100,  101,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  113,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  130,   -1,   -1,  133,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,  145,
   -1,   -1,   -1,   -1,   -1,  143,  144,  145,   -1,  261,
   -1,   -1,   -1,  159,   -1,   -1,  162,   -1,   -1,   -1,
  272,  159,   -1,  166,  162,  168,  169,  170,  171,  172,
  173,  174,  175,  176,  177,  178,  179,  180,   -1,  291,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,   -1,
   -1,   -1,  304,   -1,  306,  198,  308,  309,   -1,   -1,
   -1,   -1,   -1,  315,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  325,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  235,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  235,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 345
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,
0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER","NUMBER_SCI",
"NUMBER_DOUBLE","NUMBER_INTEGER","CHARACTER","VOID","INT","DOUBLE","BOOL",
"CHAR","STRING","K_NULL","FOR","WHILE","DO","IF","ELSE","SWITCH","RETURN",
"BREAK","CONTINUE","CONST","TRUE","FALSE","STRUCT","CASE","DEFAULT","FCLOSE",
"CLEARERR","FERROR","FFLUSH","FGETPOS","FOPEN","FREAD","FREOPEN","FSEEK",
"FTELL","FWRITE","REMOVE","RENAME","REWIND","SETBUF","SETVBUF","TMPFILE",
"TMPNAM","FPRINTF","PRINTF","SPRINTF","VFPRINTF","VPRINTF","VSPRINTF","FSCANF",
"SCANF","SSCANF","FGETC","FGETS","FPUTC","FPUTS","GETC","GETCHAR","GETS","PUTC",
"PUTCHAR","PUTS","UNGETC","PERROR","FFPRINTF","INC_OP","DEC_OP","LE_OP","GE_OP",
"EQ_OP","NE_OP","AND_OP","OR_OP","POINTER_OP","ADD_ASSIGN","SUB_ASSIGN",
"DIV_ASSIGN","MUL_ASSIGN","INVALIDNUM","DELAY","DIGITALWRITE","HIGH","LOW",
"ELSE_DUMMY_FOR_CONFLICT","OR","AND","unary","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : valid_structure",
"valid_structure : global_declarations function_definition",
"global_declarations :",
"global_declarations : global_declarations external_declaration",
"external_declaration : function_definition",
"external_declaration : declaration",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"declaration : declaration_const",
"declaration : declaration_array",
"declaration_const : declaration_specifiers_const ';'",
"declaration_const : declaration_specifiers_const init_declarator_list_const ';'",
"declaration_specifiers_const : CONST scalar_type_specifier",
"scalar_type_specifier : INT",
"scalar_type_specifier : DOUBLE",
"scalar_type_specifier : BOOL",
"scalar_type_specifier : CHAR",
"init_declarator_list_const : init_declarator_const",
"init_declarator_list_const : init_declarator_list_const ',' init_declarator_const",
"init_declarator_const : declarator_const '=' initializer",
"init_declarator_const : declarator_const",
"declarator_const : direct_declarator_const",
"direct_declarator_const : IDENTIFIER",
"direct_declarator_const : '(' declarator_const ')'",
"direct_declarator_const : direct_declarator_const '[' ']'",
"direct_declarator_const : direct_declarator_const '[' logical_or_expression ']'",
"direct_declarator_const : direct_declarator_const '(' parameter_list ')'",
"direct_declarator_const : direct_declarator_const '(' identifier_list ')'",
"declaration_array : declaration_specifiers_array ';'",
"declaration_array : declaration_specifiers_array init_declarator_list_array ';'",
"declaration_specifiers_array : scalar_type_specifier",
"declaration_specifiers_array : scalar_type_specifier declaration_specifiers_array",
"init_declarator_list_array : init_declarator_array",
"init_declarator_list_array : init_declarator_list_array ',' init_declarator_array",
"init_declarator_array : declarator_array '=' initializer",
"init_declarator_array : declarator_array",
"declarator_array : direct_declarator_array",
"direct_declarator_array : IDENTIFIER",
"direct_declarator_array : '(' declarator_array ')'",
"direct_declarator_array : direct_declarator_array '(' ')'",
"direct_declarator_array : direct_declarator_array '[' ']'",
"direct_declarator_array : direct_declarator_array '[' logical_or_expression_no_function ']'",
"direct_declarator_array : direct_declarator_array '(' parameter_list ')'",
"direct_declarator_array : direct_declarator_array '(' identifier_list ')'",
"function_definition : declaration_specifiers_array declarator_array declaration_list compound_statement",
"function_definition : declaration_specifiers_array declarator_array compound_statement",
"function_definition : VOID declarator_array declaration_list compound_statement",
"function_definition : VOID declarator_array compound_statement",
"initializer : '{' '}'",
"initializer : '{' initializer_list '}'",
"initializer : '{' initializer_list ',' '}'",
"initializer : assignment_expression_no_function",
"initializer_list : designator_list_and_equal_op initializer",
"initializer_list : initializer",
"initializer_list : initializer_list ',' designator_list_and_equal_op",
"initializer_list : initializer_list ',' initializer",
"designator_list_and_equal_op : designator_list '='",
"designator_list : designator",
"designator_list : designator_list designator",
"designator : '.' IDENTIFIER",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers_array declarator_array",
"parameter_declaration : declaration_specifiers_array",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list ',' IDENTIFIER",
"compound_statement : '{' statements_within_function '}'",
"statements_within_function : global_declarations statement_group",
"statement_group :",
"statement_group : statement_group statement",
"statement : compound_statement",
"statement : expression_statement",
"statement : selection_statement",
"statement : iteration_statement",
"statement : labeled_statement",
"statement : jump_statement",
"statement : delay_statement",
"statement : digital_write_statement",
"high_or_low : HIGH",
"high_or_low : LOW",
"delay_statement : DELAY '(' expression ')'",
"digital_write_statement : DIGITALWRITE '(' NUMBER_INTEGER ',' high_or_low ')'",
"labeled_statement : IDENTIFIER ':' statement",
"labeled_statement : CASE logical_or_expression ':' statement",
"labeled_statement : DEFAULT ':' statement",
"jump_statement : CONTINUE ';'",
"jump_statement : BREAK ';'",
"jump_statement : RETURN ';'",
"jump_statement : RETURN expression ';'",
"expression_statement : ';'",
"expression_statement : expression ';'",
"$$1 :",
"selection_statement : IF '(' expression ')' $$1 statement",
"$$2 :",
"$$3 :",
"$$4 :",
"selection_statement : IF '(' expression ')' $$2 statement $$3 ELSE $$4 statement",
"selection_statement : SWITCH '(' expression ')' statement",
"$$5 :",
"iteration_statement : WHILE '(' expression ')' $$5 statement",
"iteration_statement : DO statement WHILE '(' expression ')' ';'",
"iteration_statement : FOR '(' expression_statement expression_statement ')' statement",
"iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement",
"expression : assignment_expression",
"expression : expression ',' assignment_expression",
"assignment_expression : logical_or_expression",
"assignment_expression : unary_expression '=' assignment_expression",
"assignment_expression_no_function : logical_or_expression_no_function",
"assignment_expression_no_function : unary_expression_no_function '=' assignment_expression_no_function",
"logical_or_expression : logical_and_expression",
"logical_or_expression : logical_or_expression OR_OP logical_and_expression",
"logical_and_expression : and_expression",
"logical_and_expression : logical_and_expression AND_OP and_expression",
"and_expression : equality_expression",
"and_expression : and_expression POINTER_OP equality_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression EQ_OP relational_expression",
"equality_expression : equality_expression NE_OP relational_expression",
"relational_expression : additive_expression",
"relational_expression : relational_expression '>' additive_expression",
"relational_expression : relational_expression '<' additive_expression",
"relational_expression : relational_expression GE_OP additive_expression",
"relational_expression : relational_expression LE_OP additive_expression",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression '+' multiplicative_expression",
"additive_expression : additive_expression '-' multiplicative_expression",
"multiplicative_expression : unary_expression",
"multiplicative_expression : multiplicative_expression '*' unary_expression",
"multiplicative_expression : multiplicative_expression '/' unary_expression",
"multiplicative_expression : multiplicative_expression '%' unary_expression",
"unary_expression : postfix_expression",
"unary_expression : INC_OP unary_expression",
"unary_expression : DEC_OP unary_expression",
"unary_expression : unary_operator unary_expression",
"logical_or_expression_no_function : logical_and_expression_no_function",
"logical_or_expression_no_function : logical_or_expression_no_function OR_OP logical_and_expression_no_function",
"logical_and_expression_no_function : and_expression_no_function",
"logical_and_expression_no_function : logical_and_expression_no_function AND_OP and_expression_no_function",
"and_expression_no_function : equality_expression_no_function",
"and_expression_no_function : and_expression_no_function POINTER_OP equality_expression_no_function",
"equality_expression_no_function : relational_expression_no_function",
"equality_expression_no_function : equality_expression_no_function EQ_OP relational_expression_no_function",
"equality_expression_no_function : equality_expression_no_function NE_OP relational_expression_no_function",
"relational_expression_no_function : additive_expression_no_function",
"relational_expression_no_function : relational_expression_no_function '>' additive_expression_no_function",
"relational_expression_no_function : relational_expression_no_function '<' additive_expression_no_function",
"relational_expression_no_function : relational_expression_no_function GE_OP additive_expression_no_function",
"relational_expression_no_function : relational_expression_no_function LE_OP additive_expression_no_function",
"additive_expression_no_function : multiplicative_expression_no_function",
"additive_expression_no_function : additive_expression_no_function '+' multiplicative_expression_no_function",
"additive_expression_no_function : additive_expression_no_function '-' multiplicative_expression_no_function",
"multiplicative_expression_no_function : unary_expression_no_function",
"multiplicative_expression_no_function : multiplicative_expression_no_function '*' unary_expression_no_function",
"multiplicative_expression_no_function : multiplicative_expression_no_function '/' unary_expression_no_function",
"multiplicative_expression_no_function : multiplicative_expression_no_function '%' unary_expression_no_function",
"unary_expression_no_function : postfix_expression_no_function",
"unary_expression_no_function : INC_OP unary_expression_no_function",
"unary_expression_no_function : DEC_OP unary_expression_no_function",
"unary_expression_no_function : unary_operator unary_expression_no_function",
"postfix_expression_no_function : primary_expression_no_function",
"postfix_expression_no_function : postfix_expression_no_function '[' ']'",
"postfix_expression_no_function : postfix_expression_no_function '.' IDENTIFIER",
"postfix_expression_no_function : postfix_expression_no_function INC_OP",
"postfix_expression_no_function : postfix_expression_no_function DEC_OP",
"primary_expression_no_function : IDENTIFIER",
"primary_expression_no_function : number",
"primary_expression_no_function : STRING",
"primary_expression_no_function : '(' expression ')'",
"unary_operator : '&'",
"unary_operator : '+'",
"unary_operator : '-'",
"unary_operator : '!'",
"postfix_expression : primary_expression",
"postfix_expression : postfix_expression '[' expression ']'",
"postfix_expression : postfix_expression '(' ')'",
"postfix_expression : postfix_expression '(' argument_expression_list ')'",
"postfix_expression : postfix_expression '.' IDENTIFIER",
"postfix_expression : postfix_expression INC_OP",
"postfix_expression : postfix_expression DEC_OP",
"argument_expression_list : assignment_expression",
"argument_expression_list : argument_expression_list ',' assignment_expression",
"primary_expression : IDENTIFIER",
"primary_expression : number",
"primary_expression : STRING",
"primary_expression : '(' expression ')'",
"number : NUMBER_INTEGER",
"number : NUMBER_DOUBLE",
"number : NUMBER_SCI",
"number : CHARACTER",

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
#line 559 "parser.y"
 
#include <stdio.h>
#include <stdlib.h>

extern int lineCount;

extern char** lineContents;
extern int numStrings;
extern int wordCount;
extern void freeLineContents();

void popStack(const char* op){
	
	if(!strcmp(op, "+")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "add $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "-")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "sub $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "*")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "mul $r0, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "/")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "divsr $r0, $r2, $r0, $r1\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "%")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "divsr $r0, $r2, $r0, $r1\n");
		fprintf(file, "swi $r2, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "++")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "addi $r0, $r0, 1\n");
		fprintf(file, "swi $r0, [$sp +%d]\n", top*4);
		top++;
	}else if(!strcmp(op, "--")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "addi $r0, $r0, -1\n");
		fprintf(file, "swi $r0, [$sp +%d]\n", top*4);
		top++;
	}else if(!strcmp(op, ">")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top ++;
	}else if(!strcmp(op, ">=")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "xori $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top ++;
	}else if(!strcmp(op, "<")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top ++;
	}else if(!strcmp(op, "<=")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "slts $r0, $r1, $r0\n");
		fprintf(file, "xori $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "==")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "xor $r0, $r1, $r0\n");
		fprintf(file, "slti $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "!=")){
		top--;
		fprintf(file, "lwi $r1, [$sp + %d]\n", top*4);
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "xor $r0, $r1, $r0\n");
		fprintf(file, "movi $r1, 0\n");
		fprintf(file, "slt $r0, $r1, $r0\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "&&")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .AND%d\n", and_count);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .AND%d\n", and_count);

		fprintf(file, "movi $r0, 1\n");
		fprintf(file, "j .AND%d\n", and_count+1);
		fprintf(file, ".AND%d:\n", and_count);
		and_count++;
		fprintf(file, "movi $r0, 0\n");
		fprintf(file, ".AND%d:\n", and_count);
		and_count++;
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;

	}else if(!strcmp(op, "||")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .OR%d\n", or_count+1);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .OR%d\n", or_count);
		fprintf(file, ".OR%d:\n", or_count);
		or_count++;
		fprintf(file, "movi $r0, 1\n");
		fprintf(file, "j .OR%d\n", or_count+1);
		fprintf(file, ".OR%d:\n", or_count);
		or_count++;
		fprintf(file, "movi $r0, 0\n");
		fprintf(file, ".OR%d:\n", or_count);
		or_count++;
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}else if(!strcmp(op, "!")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "addi $r0, $r0, 0\n");
		fprintf(file, "slti $r0, $r0, 1\n");
		fprintf(file, "zeb $r0, $r0\n");
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}
}

int main(int argc, char*argv[]){
	++argv;
	--argc;	/*skip over program name*/

	file = fopen("assembly","w");
	table = new SymbolTable();
 	lineContents = (char**)malloc(sizeof(char*)*numStrings); 
	yyparse();
	printf("No syntax error!\n");
	freeLineContents();
	return 0;
}
#line 1052 "y.tab.c"

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
case 4:
#line 61 "parser.y"
	{
		scope++;
	}
break;
case 19:
#line 99 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "swi  $r0, [$sp + %d]\n", table->lookupSymbol(yystack.l_mark[-2]) * 4);
	}
break;
case 22:
#line 112 "parser.y"
	{
		table->updateScope(scope);
		table->installSymbol(yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], table->lookupSymbol(yystack.l_mark[0]));
		top++;
	}
break;
case 34:
#line 140 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "swi  $r0, [$sp + %d]\n", table->lookupSymbol(yystack.l_mark[-2]) * 4);
	}
break;
case 37:
#line 153 "parser.y"
	{
		table->updateScope(scope);
		table->installSymbol(yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], table->lookupSymbol(yystack.l_mark[0]));
		top++;
	}
break;
case 64:
#line 213 "parser.y"
	{
		table->updateScope(scope);
		table->installSymbol(yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], table->lookupSymbol(yystack.l_mark[0]));
		top++;
	}
break;
case 65:
#line 220 "parser.y"
	{
		table->updateScope(scope);
		table->installSymbol(yystack.l_mark[-2], top);
		printf("%d installed as %d\n", yystack.l_mark[-2], top);
		printf("%d installed as %d\n", yystack.l_mark[-2], table->lookupSymbol(yystack.l_mark[-2]));
		top++;
	}
break;
case 78:
#line 254 "parser.y"
	{ 
		yyval = 1;
	}
break;
case 79:
#line 257 "parser.y"
	{
		yyval = 0;
	}
break;
case 80:
#line 263 "parser.y"
	{
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "bal delay\n");
	}
break;
case 81:
#line 271 "parser.y"
	{
		fprintf(file, "movi $r0, %d\n", yystack.l_mark[-3]);
		fprintf(file, "movi $r1, %d\n", yystack.l_mark[-1]);
		fprintf(file, "bal digitalWrite\n");
    }
break;
case 91:
#line 296 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .ELSE%d\n", if_count);
		scope++;
		table->updateScope(scope);
	}
break;
case 92:
#line 303 "parser.y"
	{
		fprintf(file, "j .FIN%d\n", finish_count);
		int pop_count = table->popSymbol();
		top = top - pop_count;
		scope --;
		table->updateScope(scope);
		/*rest*/
		fprintf(file, ".ELSE%d:\n", if_count);
		if_count++;
		fprintf(file, ".FIN%d:\n", finish_count);
		finish_count++;
	}
break;
case 93:
#line 316 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .ELSE%d\n", if_count);
		scope++;
		table->updateScope(scope);
    }
break;
case 94:
#line 323 "parser.y"
	{
		fprintf(file, "j .FIN%d\n", finish_count);
		int pop_count = table->popSymbol();
		top = top - pop_count;
		scope --;
		table->updateScope(scope);
		/*rest*/
		fprintf(file, ".FIN%d:\n", finish_count);
		finish_count++;
	}
break;
case 95:
#line 333 "parser.y"
	{
		scope ++;
		table->updateScope(scope);
		fprintf(file, ".ELSE%d:\n", if_count);
		if_count++;
	}
break;
case 98:
#line 344 "parser.y"
	{
		fprintf(file, ".WHILE%d:\n", while_count);
		while_count++;
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "bnez $r0, .WHILE%d\n", while_count);
		fprintf(file, "j .WHILE%d\n", while_count + 1);
		fprintf(file, ".WHILE%d:\n", while_count);
		while_count++;
		scope++;
		table->updateScope(scope);
	}
break;
case 99:
#line 356 "parser.y"
	{
		fprintf(file, "j .WHILE%d\n", while_count-2);
		fprintf(file, ".WHILE%d:\n", while_count);
		while_count++;
		int pop_count = table->popSymbol();
		top = top - pop_count;
		scope --;
		table->updateScope(scope);
	}
break;
case 106:
#line 377 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "swi  $r0, [$sp + %d]\n", table->lookupSymbol(yystack.l_mark[-2]) * 4);
		printf("%d offset is %d\n", yystack.l_mark[-2], table->lookupSymbol(yystack.l_mark[-2]));
	}
break;
case 108:
#line 387 "parser.y"
	{
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "swi  $r0, [$sp + %d]\n", table->lookupSymbol(yystack.l_mark[-2]) * 4);
		printf("%d offset is %d\n", yystack.l_mark[-2], table->lookupSymbol(yystack.l_mark[-2]));
	}
break;
case 110:
#line 397 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 112:
#line 402 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 116:
#line 412 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 117:
#line 413 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 119:
#line 418 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 120:
#line 419 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 121:
#line 420 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 122:
#line 421 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 124:
#line 426 "parser.y"
	{popStack("+");}
break;
case 125:
#line 427 "parser.y"
	{popStack("-");}
break;
case 127:
#line 432 "parser.y"
	{popStack("*");}
break;
case 128:
#line 433 "parser.y"
	{popStack("/");}
break;
case 129:
#line 434 "parser.y"
	{popStack("%");}
break;
case 131:
#line 439 "parser.y"
	{popStack("++");}
break;
case 132:
#line 440 "parser.y"
	{popStack("--");}
break;
case 135:
#line 446 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 137:
#line 451 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 141:
#line 461 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 142:
#line 462 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 144:
#line 467 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 145:
#line 468 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 146:
#line 469 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 147:
#line 470 "parser.y"
	{popStack(yystack.l_mark[-1]);}
break;
case 149:
#line 475 "parser.y"
	{popStack("+");}
break;
case 150:
#line 476 "parser.y"
	{popStack("-");}
break;
case 152:
#line 481 "parser.y"
	{popStack("*");}
break;
case 153:
#line 482 "parser.y"
	{popStack("/");}
break;
case 154:
#line 483 "parser.y"
	{popStack("%");}
break;
case 156:
#line 488 "parser.y"
	{popStack("++");}
break;
case 157:
#line 489 "parser.y"
	{popStack("--");}
break;
case 162:
#line 497 "parser.y"
	{popStack("++");}
break;
case 163:
#line 498 "parser.y"
	{popStack("--");}
break;
case 164:
#line 502 "parser.y"
	{
		table->updateScope(scope);
		table->installSymbol(yystack.l_mark[0], top);
		printf("%d installed as %d\n", yystack.l_mark[0], top);
		printf("%d install as %d\n", yystack.l_mark[0], table->lookupSymbol(yystack.l_mark[0]));
		top ++;
	}
break;
case 168:
#line 515 "parser.y"
	{popStack("&");}
break;
case 169:
#line 516 "parser.y"
	{}
break;
case 170:
#line 517 "parser.y"
	{}
break;
case 171:
#line 518 "parser.y"
	{popStack("!");}
break;
case 181:
#line 537 "parser.y"
	{
		printf("%d offset is  %d\n", yystack.l_mark[0], table->lookupSymbol(yystack.l_mark[0]));
		fprintf(file, "lwi $r0, [$sp + %d]\n", table->lookupSymbol(yystack.l_mark[0]) * 4);
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}
break;
case 185:
#line 549 "parser.y"
	{
		fprintf(file, "movi $r0, %d\n", yystack.l_mark[0]);
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}
break;
#line 1617 "y.tab.c"
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
