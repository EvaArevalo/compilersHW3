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
extern YYSTYPE yylval;
