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

#include <stdio.h>
int yylex();
int yyerror(char* msg);
#line 24 "y.tab.c"

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
#define ELSE_DUMMY_FOR_CONFLICT 338
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    3,    3,    5,    5,    4,    4,    6,
    6,    8,   10,   10,   10,   10,    9,    9,   11,   11,
   12,   14,   14,   14,   14,   14,   14,    7,    7,   18,
   18,   19,   19,   20,   20,   21,   22,   22,   22,   22,
   22,   22,   22,    2,    2,    2,    2,   13,   13,   13,
   13,   25,   25,   25,   25,   27,   28,   28,   29,   16,
   16,   30,   30,   17,   17,   24,   31,   32,   32,   33,
   33,   33,   33,   33,   33,   37,   37,   37,   38,   38,
   38,   38,   34,   34,   35,   35,   35,   36,   36,   36,
   36,   39,   39,   40,   40,   26,   26,   15,   15,   43,
   43,   44,   44,   45,   45,   45,   46,   46,   46,   46,
   46,   47,   47,   47,   48,   48,   48,   48,   41,   41,
   41,   41,   23,   23,   51,   51,   52,   52,   53,   53,
   53,   54,   54,   54,   54,   54,   55,   55,   55,   56,
   56,   56,   56,   42,   42,   42,   42,   57,   57,   57,
   57,   57,   58,   58,   58,   58,   50,   50,   50,   50,
   49,   49,   49,   49,   49,   49,   49,   61,   61,   60,
   60,   60,   60,   59,   59,   59,   59,
};
static const short yylen[] = {                            2,
    2,    0,    2,    1,    1,    1,    2,    1,    1,    2,
    3,    2,    1,    1,    1,    1,    1,    3,    3,    1,
    1,    1,    3,    3,    4,    4,    4,    2,    3,    1,
    2,    1,    3,    3,    1,    1,    1,    3,    3,    3,
    4,    4,    4,    4,    3,    4,    3,    2,    3,    4,
    1,    2,    1,    3,    3,    2,    1,    2,    2,    1,
    3,    2,    1,    1,    3,    3,    2,    0,    2,    1,
    1,    1,    1,    1,    1,    3,    4,    3,    2,    2,
    2,    3,    1,    2,    5,    7,    5,    5,    7,    6,
    7,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    1,    3,    1,    3,    3,    1,    3,    3,    3,
    3,    1,    3,    3,    1,    3,    3,    3,    1,    2,
    2,    2,    1,    3,    1,    3,    1,    3,    1,    3,
    3,    1,    3,    3,    3,    3,    1,    3,    3,    1,
    3,    3,    3,    1,    2,    2,    2,    1,    3,    3,
    2,    2,    1,    1,    1,    3,    1,    1,    1,    1,
    1,    4,    3,    4,    3,    2,    2,    1,    3,    1,
    1,    1,    3,    1,    1,    1,    1,
};
static const short yydefred[] = {                         2,
    0,    0,    0,   13,   14,   15,   16,    0,    0,    3,
    5,    8,    9,    0,    0,    0,   37,    0,    0,    0,
   12,   22,   10,    0,    0,   17,    0,    0,   31,   28,
    0,   32,    0,    0,    2,    6,    0,    0,   47,    0,
    0,    0,   11,    0,    0,    0,    0,   29,    0,    0,
    0,   45,   38,    0,    0,    7,   46,    0,   64,   39,
    0,    0,    0,   60,  153,  176,  175,  174,  177,  155,
    0,    0,    0,   40,  158,  159,  157,  160,    0,  140,
    0,    0,    0,    0,    0,    0,    0,    0,  148,  154,
   23,   18,    0,   19,    0,   51,    0,    0,    0,  170,
  172,    0,    0,    0,   24,    0,  115,    0,    0,    0,
    0,    0,    0,    0,    0,  171,  161,   33,   34,   44,
    4,    0,   66,    0,   42,    0,   43,   62,  145,  146,
    0,    0,   92,    0,    0,   41,  147,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  151,  152,    0,    0,   48,    0,   53,    0,    0,    0,
   57,    0,   26,   27,  120,  121,    0,    0,   25,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  166,  167,    0,    0,    0,  122,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   70,   69,   71,   72,   73,   74,   75,    0,   61,   65,
    0,  156,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,  142,  143,  149,  150,   59,
    0,   49,   52,   56,   58,   97,  173,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  116,  117,
  118,  163,  168,    0,    0,  165,    0,    0,    0,    0,
    0,    0,   81,    0,   80,   79,    0,    0,   84,   93,
   95,   50,   55,   54,    0,  164,  162,   76,    0,    0,
    0,    0,    0,   82,    0,   78,  169,    0,    0,    0,
    0,    0,   77,    0,    0,   88,    0,    0,   87,   90,
    0,    0,    0,   91,   89,   86,
};
static const short yydgoto[] = {                          1,
    2,    9,   10,   11,   37,   12,   13,   14,   25,   15,
   26,   27,   94,   28,  131,   61,   62,   38,   31,   32,
   58,   20,   95,  201,  158,   96,  159,  160,  161,   64,
   55,  122,  202,  203,  204,  205,  206,  207,  208,  133,
  134,   80,  108,  109,  110,  111,  112,  113,  114,  115,
   82,   83,   84,   85,   86,   87,   88,   89,  116,  117,
  254,
};
static const short yysindex[] = {                         0,
    0,  735,  -36,    0,    0,    0,    0,   86,    0,    0,
    0,    0,    0,   -9,   86,   -1,    0,  -36,  -71,   73,
    0,    0,    0,  -27,   71,    0,  -41,   85,    0,    0,
   84,    0,  699,    8,    0,    0,  -71,   -1,    0,  710,
  214,   35,    0,  -27,  225,  745,  461,    0,  -36,  225,
  -71,    0,    0,  735,  -83,    0,    0,   66,    0,    0,
   -4,   65,  -36,    0,    0,    0,    0,    0,    0,    0,
  483,  483,  542,    0,    0,    0,    0,    0,  -65,    0,
  483, -199, -192, -166,  -48,  124,  178,  -44,    0,    0,
    0,    0,   78,    0, -198,    0,   83,   94,  168,    0,
    0,  542,  542,  542,    0,  -64,    0, -157, -152, -106,
   -5,  154,  235,   19,  542,    0,    0,    0,    0,    0,
    0,  173,    0,   86,    0,  -66,    0,    0,    0,    0,
 -145,  190,    0,  147,  483,    0,    0,  483,  483,  483,
  483,  483,  483,  483,  483,  483,  483,  483,  483,  483,
    0,    0,  136,  -38,    0,  -21,    0,   -3,  225,  122,
    0,  483,    0,    0,    0,    0,  209,  542,    0,  542,
  542,  542,  542,  542,  542,  542,  542,  542,  542,  542,
  542,  542,    0,    0,  275,  542,  -13,    0,  191,  215,
  221,  173,  229,  231,  472,  240,  251,  542,  226,    0,
    0,    0,    0,    0,    0,    0,    0,   90,    0,    0,
  542,    0,  542, -199, -192, -166,  -48,  -48,  124,  124,
  124,  124,  178,  178,    0,    0,    0,    0,    0,    0,
  200,    0,    0,    0,    0,    0,    0, -157, -152, -106,
   -5,   -5,  154,  154,  154,  154,  235,  235,    0,    0,
    0,    0,    0,  349,  -18,    0,  173,  508,  542,    3,
  542,  542,    0,   97,    0,    0,  -57,  173,    0,    0,
    0,    0,    0,    0,  542,    0,    0,    0,  508,  376,
  274,  410,  421,    0,  173,    0,    0,  523,  173,  542,
  173,  173,    0,  173,  425,    0,  452,   46,    0,    0,
  173,  265,  173,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  682,    0,
    0,    0,    0,    0,   60,    0,    0,    0,    0,  927,
    0,    0,    0,    0,    0,    0,  126,  459,    0,    0,
    0,    0,  130,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  112,    0,    0,    0,  130,    0,    0,
    0,    0,  467,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  216,  253,  158,  694,  702,  652,    1,    0,    0,
    0,    0,    0,    0,   33,    0,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   49,  183,   44,
   95,  570,  514,  -26,    0,    0,    0,    0,    0,    0,
    0,  217,    0,    0,    0,    0,    0,    0,    0,    0,
   88,    0,    0,   27,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  612,  267,  926,  780,  910,  732,  769,
  790,  810,  664,  711,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  107,  620,  146,
  360,  486,  580,  590,  600,  610,  550,  560,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  139,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  299,  286,    0,  177,  314,    0,    0,    0,    0,  353,
  333,  361,   67,    0,  -20,  345,  359,   51,    0,  358,
   96,    0,  371,  647,    0,  273,  208,    0,  281,  322,
    0,    0,  875, -228,    0,    0,    0,    0,  885, -129,
 1202, 1209,  284,  298,  316,  113,  500,  250,    0, 1084,
  335,  357,  352,  339,  557,  423,    0,    0, 1203,    0,
    0,
};
#define YYTABLESIZE 1440
static const short yytable[] = {                        170,
  285,  154,  170,   18,  170,  170,  170,  170,  170,  170,
  119,  145,   24,  144,  119,  119,  119,  119,  119,   45,
  119,  170,  170,  170,  170,  211,  106,  136,  169,  279,
   24,  119,  119,  119,  119,  119,  125,  144,   18,  124,
  231,  123,  144,  144,  144,  144,  153,  144,   53,   23,
  288,   35,   16,  170,  177,  253,  176,   30,  185,  144,
  144,  144,  144,  115,  187,   29,  119,  115,  115,  115,
  115,  115,  140,  115,  277,   91,   96,  140,  140,  140,
  140,  270,  140,  271,  102,  115,  115,  102,  115,   98,
   63,   96,   98,  144,  140,  140,   63,  140,   19,   30,
   30,  102,  102,   30,   16,  127,   98,   98,  126,  186,
   78,   33,   40,   34,   44,   77,  119,   73,   30,  115,
   75,  232,   76,  156,   46,  144,   50,   49,   94,   43,
  138,   94,  135,  211,  163,  104,  102,  124,  104,  139,
  211,   98,   48,  162,   68,  287,   94,   99,  269,   68,
   99,   68,  104,  104,   68,  284,   68,   96,  128,  157,
  140,  140,  141,   41,   99,   99,  146,  156,  147,   20,
   68,   85,  170,   35,   63,   47,   85,  267,   85,  171,
   94,   85,  234,   85,   20,  168,  103,  104,   35,  103,
  210,    4,    5,    6,    7,   36,  178,   85,  179,   99,
   93,  127,  155,  103,  103,   78,    8,  213,  164,   36,
   77,  126,  104,   56,  150,   75,  127,   76,  229,  148,
   17,  172,  173,  100,  149,  233,  100,   56,  228,   22,
  212,  200,   78,  211,   68,  230,   68,   77,  103,   73,
  100,  100,   75,  256,   76,  156,   78,   22,  257,  237,
  127,   77,  211,   73,  258,   17,   75,   78,   76,  123,
  259,   85,   77,   85,   73,  135,  168,   75,  261,   76,
  262,  182,  281,  168,  123,  100,  180,  142,  143,  151,
  152,  181,  127,  268,  241,  242,  170,  170,  170,  170,
  170,  170,  170,  170,  170,   35,  125,  273,  265,  119,
  119,  119,  119,  119,  119,  119,   74,   78,  123,  266,
  126,  125,   77,  290,  104,  252,   30,   75,  303,   76,
  174,  175,   93,  305,  272,  126,  144,  144,  144,  144,
  144,  144,  144,   54,   65,   66,   67,   68,   69,  121,
  123,   67,  183,  184,   70,  125,   51,   93,    4,    5,
    6,    7,  115,  115,  115,  115,  115,  115,  115,  126,
   21,  140,  140,  140,  140,  140,  140,  140,   68,   68,
   68,   68,   68,  102,  102,  102,   92,  125,   68,   98,
   68,   68,   68,   68,   42,   68,   68,   68,   68,  276,
   98,  126,  275,   68,   68,   85,   85,   85,   85,   85,
  105,   71,   72,  105,   99,   85,  118,   85,   85,   85,
   85,   79,   85,   85,   85,   85,  289,  105,  105,  211,
   85,   85,  104,  104,  104,  104,  104,  247,  248,  189,
   66,   67,   68,   69,  236,   68,   68,   99,  274,  101,
  235,  190,  191,  192,  193,  209,  194,  195,  196,  197,
  291,  238,  105,  211,  198,  199,   65,   66,   67,   68,
   69,  292,   85,   85,  211,  301,   70,  239,  211,  214,
   65,   66,   67,   68,   69,  103,  103,  103,  217,  218,
   70,   65,   66,   67,   68,   69,  240,  127,  127,  127,
  216,   70,  302,   78,  215,  211,  102,  103,   77,   21,
  104,    0,   21,   75,   78,   76,    0,   63,    0,   77,
   63,  104,  100,  100,   75,   78,   76,   21,    0,   21,
   77,    0,   73,   71,   72,   75,  106,   76,    0,  106,
  263,  100,   66,   67,   68,   69,    0,   71,   72,    0,
   78,  101,    0,  106,  106,   77,  123,  104,   71,   72,
   75,    0,   76,  105,  112,   78,  112,  112,  112,    0,
   77,    0,  104,  294,    0,   75,  200,   76,  223,  224,
    0,  112,  112,  112,   78,  112,    0,    0,  106,   77,
    0,  104,  125,  125,   75,    0,   76,    0,    0,    0,
  113,    0,  113,  113,  113,    0,  126,  126,  102,  103,
  114,    0,  114,  114,  114,    0,  112,  113,  113,  113,
  107,  113,    0,  107,    0,    0,    0,  114,  114,  114,
  111,  114,    0,  111,    0,    0,    0,  107,  107,  107,
  110,  107,    0,  110,    0,    0,    0,  111,  111,  111,
  108,  111,  113,  108,    0,    0,    0,  110,  110,  110,
  109,  110,  114,  109,    0,  124,    0,  108,  108,  108,
  101,  108,  107,  101,    0,   39,    0,  109,  109,  109,
  124,  109,  111,  243,  244,  245,  246,  101,  101,   52,
    0,    1,  110,   57,    0,    0,    0,  105,  105,  105,
  105,  105,  108,    0,  137,  137,  137,  120,  219,  220,
  221,  222,  109,    0,  124,    0,  138,  138,  138,    0,
  137,  137,  101,  137,    0,    0,    0,  100,   66,   67,
   68,   69,  138,  138,    0,  138,    0,  101,  100,   66,
   67,   68,   69,    0,    0,    0,  124,  129,  101,   65,
   66,   67,   68,   69,  137,  132,    0,    0,    0,   70,
   60,    0,  129,  139,  139,  139,  138,    0,    0,   50,
  132,  132,    0,  132,  100,   66,   67,   68,   69,  139,
  139,    0,  139,    0,  101,  136,  137,    0,    0,  100,
   66,   67,   68,   69,  102,  103,  129,    0,  138,  101,
  136,  136,    0,  136,  132,  102,  103,    0,  100,   66,
   67,   68,   69,  139,    0,    0,   71,   72,  101,    0,
    0,    0,  135,  106,  106,  106,  106,  106,  129,    0,
    0,   35,    0,  130,  136,    0,  132,  135,  135,    0,
  135,  102,  103,  133,    0,  139,    0,    0,  130,  112,
  112,  112,  112,  112,  112,  112,  102,  103,  133,  133,
    0,  133,    0,  134,    0,    0,  136,    0,    0,    0,
    0,  135,    0,    0,    0,  102,  103,    0,  134,  134,
    0,  134,  130,    0,    0,  113,  113,  113,  113,  113,
  113,  113,  133,    0,    0,  114,  114,  114,  114,  114,
  114,  114,    0,  135,    0,  107,  107,  107,  107,  107,
  107,  107,  134,    0,  130,  111,  111,  111,  111,  111,
  111,  111,    0,    0,  133,  110,  110,  110,  110,  110,
  110,  110,    0,    0,    0,  108,  108,  108,  108,  108,
  108,  108,    0,    0,  134,  109,  109,  109,  109,  109,
  109,  109,  124,    4,    4,    4,    4,    4,    0,  101,
  101,    0,    0,  131,    0,    0,    0,  132,    0,    4,
    0,    4,    5,    6,    7,    0,   59,   36,  131,  128,
   36,    0,    4,    5,    6,    7,    8,  137,  137,  137,
  137,  137,  137,  137,  128,   36,    0,   36,  167,  138,
  138,  138,  138,  138,  138,  138,    3,    4,    5,    6,
    7,   59,  131,    0,    0,    0,    0,    4,    5,    6,
    7,    0,    8,    0,    0,    0,    0,    0,  128,    0,
    0,  129,  129,  129,  129,  129,    0,  132,  132,  132,
  132,  132,  132,  132,  131,    0,  139,  139,  139,  139,
  139,  139,  139,    0,    0,    0,    0,    0,    0,   36,
  128,    0,    0,    0,    0,    0,    0,  136,  136,  136,
  136,  136,  136,  136,    0,    0,  260,    0,    0,    0,
  255,    0,    0,    0,    0,    0,    0,    0,    0,  264,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  135,  135,  135,  135,  135,  135,
  135,    0,    0,    0,    0,    0,    0,  130,  130,  130,
  130,  130,    0,    0,    0,  133,  133,  133,  133,  133,
  133,  133,    0,    0,   81,    0,    0,    0,   81,    0,
    0,  278,    0,   81,    0,  134,  134,  134,  134,  134,
  134,  134,  286,  280,    0,  282,  283,    0,    0,    0,
    0,    0,    0,    0,   81,   81,    0,    0,    0,  293,
    0,    0,    0,  296,   81,  298,  299,    0,  300,    0,
    0,    0,  295,    0,  297,  304,   81,  306,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
   36,   36,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   81,    0,
    0,   81,   81,   81,   81,   81,   81,   81,   81,   81,
   81,   81,   81,   81,    0,    0,    0,  131,  131,  131,
  131,  131,   81,   90,    0,   81,    0,   90,  107,    0,
    0,    0,   90,   97,    0,  128,  128,  128,   97,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   90,   90,    0,    0,    0,    0,  129,
  130,    0,    0,   90,    0,    0,    0,    0,    0,  137,
    0,    0,    0,    0,    0,   90,    0,    0,    0,    0,
    0,   97,    0,  165,  166,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   81,    0,  188,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   90,    0,    0,
   90,   90,   90,   90,   90,   90,   90,   90,   90,   90,
   90,   90,   90,    0,    0,    0,  225,  226,  227,    0,
    0,   90,    0,    0,   90,    0,    0,   97,    0,  107,
   97,  107,  107,  107,  107,  107,  107,  107,  107,  107,
  107,  249,  250,  251,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  107,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   90,    0,    0,    0,    0,    0,   97,
};
static const short yycheck[] = {                         37,
   58,   46,   40,   40,   42,   43,   44,   45,   46,   47,
   37,   60,   40,   62,   41,   42,   43,   44,   45,   61,
   47,   59,   60,   61,   62,   44,   47,   93,   93,  258,
   40,   58,   59,   60,   61,   62,   41,   37,   40,   44,
   44,  125,   42,   43,   44,   45,   91,   47,   41,   59,
  279,  123,    2,   91,   60,  185,   62,   59,   40,   59,
   60,   61,   62,   37,   46,   15,   93,   41,   42,   43,
   44,   45,   37,   47,   93,   41,   44,   42,   43,   44,
   45,  211,   47,  213,   41,   59,   60,   44,   62,   41,
   40,   59,   44,   93,   59,   60,   46,   62,    3,   40,
   41,   58,   59,   44,   54,   41,   58,   59,   44,   91,
   33,   16,   40,   18,   44,   38,   50,   40,   59,   93,
   43,  125,   45,   46,   40,  125,   61,   44,   41,   59,
  330,   44,  331,   44,   41,   41,   93,   44,   44,  332,
   44,   93,   59,   61,   33,  275,   59,   41,   59,   38,
   44,   40,   58,   59,   43,   59,   45,  125,   63,   93,
  125,  328,  329,   91,   58,   59,   43,   46,   45,   44,
   59,   33,  330,   44,  124,   91,   38,  198,   40,  332,
   93,   43,   61,   45,   59,  331,   41,   93,   59,   44,
  257,  263,  264,  265,  266,   19,   43,   59,   45,   93,
  123,   44,  125,   58,   59,   33,  278,   61,   41,   33,
   38,   44,   40,   37,   37,   43,   59,   45,  257,   42,
  257,  328,  329,   41,   47,  159,   44,   51,   93,  257,
   41,   59,   33,   44,  123,  257,  125,   38,   93,   40,
   58,   59,   43,  257,   45,   46,   33,  257,   58,   41,
   93,   38,   44,   40,   40,  257,   43,   33,   45,   44,
   40,  123,   38,  125,   40,  331,  331,   43,   40,   45,
   40,   37,  270,  331,   59,   93,   42,  326,  327,  324,
  325,   47,  125,   58,  172,  173,  324,  325,  326,  327,
  328,  329,  330,  331,  332,  123,   44,  231,   59,  326,
  327,  328,  329,  330,  331,  332,   93,   33,   93,   59,
   44,   59,   38,   40,   40,   41,  257,   43,  273,   45,
  326,  327,  123,   59,  125,   59,  326,  327,  328,  329,
  330,  331,  332,   35,  257,  258,  259,  260,  261,   54,
  125,  125,  324,  325,  267,   93,   33,  123,  263,  264,
  265,  266,  326,  327,  328,  329,  330,  331,  332,   93,
    8,  326,  327,  328,  329,  330,  331,  332,  257,  258,
  259,  260,  261,  330,  331,  332,   44,  125,  267,  331,
  269,  270,  271,  272,   24,  274,  275,  276,  277,   41,
   46,  125,   44,  282,  283,  257,  258,  259,  260,  261,
   41,  324,  325,   44,   46,  267,   49,  269,  270,  271,
  272,   41,  274,  275,  276,  277,   41,   58,   59,   44,
  282,  283,  328,  329,  330,  331,  332,  178,  179,  257,
  258,  259,  260,  261,  162,  324,  325,  331,  231,  267,
  160,  269,  270,  271,  272,  124,  274,  275,  276,  277,
   41,  168,   93,   44,  282,  283,  257,  258,  259,  260,
  261,   41,  324,  325,   44,   41,  267,  170,   44,  135,
  257,  258,  259,  260,  261,  330,  331,  332,  140,  141,
  267,  257,  258,  259,  260,  261,  171,  330,  331,  332,
  139,  267,   41,   33,  138,   44,  324,  325,   38,   41,
   40,   -1,   44,   43,   33,   45,   -1,   41,   -1,   38,
   44,   40,  330,  331,   43,   33,   45,   59,   -1,   61,
   38,   -1,   40,  324,  325,   43,   41,   45,   -1,   44,
   59,  257,  258,  259,  260,  261,   -1,  324,  325,   -1,
   33,  267,   -1,   58,   59,   38,  331,   40,  324,  325,
   43,   -1,   45,   93,   41,   33,   43,   44,   45,   -1,
   38,   -1,   40,   41,   -1,   43,   59,   45,  146,  147,
   -1,   58,   59,   60,   33,   62,   -1,   -1,   93,   38,
   -1,   40,  330,  331,   43,   -1,   45,   -1,   -1,   -1,
   41,   -1,   43,   44,   45,   -1,  330,  331,  324,  325,
   41,   -1,   43,   44,   45,   -1,   93,   58,   59,   60,
   41,   62,   -1,   44,   -1,   -1,   -1,   58,   59,   60,
   41,   62,   -1,   44,   -1,   -1,   -1,   58,   59,   60,
   41,   62,   -1,   44,   -1,   -1,   -1,   58,   59,   60,
   41,   62,   93,   44,   -1,   -1,   -1,   58,   59,   60,
   41,   62,   93,   44,   -1,   44,   -1,   58,   59,   60,
   41,   62,   93,   44,   -1,   19,   -1,   58,   59,   60,
   59,   62,   93,  174,  175,  176,  177,   58,   59,   33,
   -1,    0,   93,   37,   -1,   -1,   -1,  328,  329,  330,
  331,  332,   93,   -1,   43,   44,   45,   51,  142,  143,
  144,  145,   93,   -1,   93,   -1,   43,   44,   45,   -1,
   59,   60,   93,   62,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   59,   60,   -1,   62,   -1,  267,  257,  258,
  259,  260,  261,   -1,   -1,   -1,  125,   44,  267,  257,
  258,  259,  260,  261,   93,   44,   -1,   -1,   -1,  267,
   41,   -1,   59,   43,   44,   45,   93,   -1,   -1,   61,
   59,   60,   -1,   62,  257,  258,  259,  260,  261,   59,
   60,   -1,   62,   -1,  267,   44,  125,   -1,   -1,  257,
  258,  259,  260,  261,  324,  325,   93,   -1,  125,  267,
   59,   60,   -1,   62,   93,  324,  325,   -1,  257,  258,
  259,  260,  261,   93,   -1,   -1,  324,  325,  267,   -1,
   -1,   -1,   44,  328,  329,  330,  331,  332,  125,   -1,
   -1,  123,   -1,   44,   93,   -1,  125,   59,   60,   -1,
   62,  324,  325,   44,   -1,  125,   -1,   -1,   59,  326,
  327,  328,  329,  330,  331,  332,  324,  325,   59,   60,
   -1,   62,   -1,   44,   -1,   -1,  125,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,  324,  325,   -1,   59,   60,
   -1,   62,   93,   -1,   -1,  326,  327,  328,  329,  330,
  331,  332,   93,   -1,   -1,  326,  327,  328,  329,  330,
  331,  332,   -1,  125,   -1,  326,  327,  328,  329,  330,
  331,  332,   93,   -1,  125,  326,  327,  328,  329,  330,
  331,  332,   -1,   -1,  125,  326,  327,  328,  329,  330,
  331,  332,   -1,   -1,   -1,  326,  327,  328,  329,  330,
  331,  332,   -1,   -1,  125,  326,  327,  328,  329,  330,
  331,  332,  331,  262,  263,  264,  265,  266,   -1,  330,
  331,   -1,   -1,   44,   -1,   -1,   -1,   73,   -1,  278,
   -1,  263,  264,  265,  266,   -1,  257,   41,   59,   44,
   44,   -1,  263,  264,  265,  266,  278,  326,  327,  328,
  329,  330,  331,  332,   59,   59,   -1,   61,  104,  326,
  327,  328,  329,  330,  331,  332,  262,  263,  264,  265,
  266,  257,   93,   -1,   -1,   -1,   -1,  263,  264,  265,
  266,   -1,  278,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   -1,  328,  329,  330,  331,  332,   -1,  326,  327,  328,
  329,  330,  331,  332,  125,   -1,  326,  327,  328,  329,
  330,  331,  332,   -1,   -1,   -1,   -1,   -1,   -1,  123,
  125,   -1,   -1,   -1,   -1,   -1,   -1,  326,  327,  328,
  329,  330,  331,  332,   -1,   -1,  192,   -1,   -1,   -1,
  186,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  195,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  326,  327,  328,  329,  330,  331,
  332,   -1,   -1,   -1,   -1,   -1,   -1,  328,  329,  330,
  331,  332,   -1,   -1,   -1,  326,  327,  328,  329,  330,
  331,  332,   -1,   -1,   41,   -1,   -1,   -1,   45,   -1,
   -1,  257,   -1,   50,   -1,  326,  327,  328,  329,  330,
  331,  332,  268,  259,   -1,  261,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   71,   72,   -1,   -1,   -1,  285,
   -1,   -1,   -1,  289,   81,  291,  292,   -1,  294,   -1,
   -1,   -1,  288,   -1,  290,  301,   93,  303,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
  264,  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  135,   -1,
   -1,  138,  139,  140,  141,  142,  143,  144,  145,  146,
  147,  148,  149,  150,   -1,   -1,   -1,  328,  329,  330,
  331,  332,  159,   41,   -1,  162,   -1,   45,   47,   -1,
   -1,   -1,   50,   45,   -1,  330,  331,  332,   50,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   71,   72,   -1,   -1,   -1,   -1,   71,
   72,   -1,   -1,   81,   -1,   -1,   -1,   -1,   -1,   81,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   93,   -1,  102,  103,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  231,   -1,  115,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  135,   -1,   -1,
  138,  139,  140,  141,  142,  143,  144,  145,  146,  147,
  148,  149,  150,   -1,   -1,   -1,  148,  149,  150,   -1,
   -1,  159,   -1,   -1,  162,   -1,   -1,  159,   -1,  168,
  162,  170,  171,  172,  173,  174,  175,  176,  177,  178,
  179,  180,  181,  182,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  198,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  231,   -1,   -1,   -1,   -1,   -1,  231,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 338
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
"DIV_ASSIGN","MUL_ASSIGN","INVALIDNUM","ELSE_DUMMY_FOR_CONFLICT",
"illegal-symbol",
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
"labeled_statement : IDENTIFIER ':' statement",
"labeled_statement : CASE logical_or_expression ':' statement",
"labeled_statement : DEFAULT ':' statement",
"jump_statement : CONTINUE ';'",
"jump_statement : BREAK ';'",
"jump_statement : RETURN ';'",
"jump_statement : RETURN expression ';'",
"expression_statement : ';'",
"expression_statement : expression ';'",
"selection_statement : IF '(' expression ')' statement",
"selection_statement : IF '(' expression ')' statement ELSE statement",
"selection_statement : SWITCH '(' expression ')' statement",
"iteration_statement : WHILE '(' expression ')' statement",
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
#line 384 "parser.y"
 
#include <stdio.h>
#include <stdlib.h>

extern int lineCount;
extern int yytext[];
extern char** lineContents;
extern numStrings;
extern wordCount;
extern void freeLineContents();

int main(int argc, char*argv[]){
  ++argv;
  --argc;	/*skip over program name*/

  lineContents = (char**)malloc(sizeof(char*)*numStrings); 

  /*if (0<argc){
  	yyin = fopen(argv[0], "r");
  } else {
  	yyin=stdin;
  }*/
 
	yyparse();
	printf("No syntax error!\n");
	freeLineContents();
	return 0;
}
#line 867 "y.tab.c"

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
