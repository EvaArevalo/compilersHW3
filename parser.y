%{
//includes
#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.hpp"
#include "scanner.h"
#include "y.tab.h"

int yylex();
int yyerror(char* msg);

//variables
SymbolTable* table;
FILE* file;
int scope = 0;
int top = 0;
int function_main_flag = 0;
int if_label_count = 0;
int finish_label_count = 0;
int and_label_count = 0;
int or_label_count = 0;
int while_label_count = 0;
%}

%token IDENTIFIER NUMBER_SCI NUMBER_DOUBLE NUMBER_INTEGER CHARACTER
%token VOID INT DOUBLE BOOL CHAR STRING K_NULL FOR WHILE DO IF ELSE SWITCH RETURN BREAK 
%token CONTINUE CONST TRUE FALSE STRUCT CASE DEFAULT
%token FCLOSE CLEARERR FERROR FFLUSH FGETPOS FOPEN FREAD FREOPEN FSEEK FTELL FWRITE
%token REMOVE RENAME REWIND SETBUF SETVBUF TMPFILE TMPNAM FPRINTF PRINTF SPRINTF 
%token VFPRINTF VPRINTF VSPRINTF FSCANF SCANF SSCANF FGETC FGETS FPUTC FPUTS GETC
%TOKEN GETCHAR GETS PUTC PUTCHAR PUTS UNGETC PERROR FFPRINTF
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP POINTER_OP
%token ADD_ASSIGN SUB_ASSIGN DIV_ASSIGN MUL_ASSIGN
%token INVALIDNUM

%token DELAY DIGITALWRITE HIGH LOW

%nonassoc ELSE_DUMMY_FOR_CONFLICT
%nonassoc ELSE

%start valid_structure
%%

valid_structure
	: global_declarations function_definition {function_main_flag = 1;}
	;

global_declarations
	: /* empty */
	| global_declarations external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

declaration
	: declaration_const 
	| declaration_array 
	;

declaration_const
	: declaration_specifiers_const ';'
	| declaration_specifiers_const init_declarator_list_const ';'
	;

declaration_specifiers_const
	: CONST scalar_type_specifier
	;

scalar_type_specifier
	: INT 
	| DOUBLE 
	| BOOL 
	| CHAR
	;

init_declarator_list_const
	: init_declarator_const
	| init_declarator_list_const ',' init_declarator_const
	;

init_declarator_const
	: declarator_const '=' initializer
	| declarator_const
	;

declarator_const
	: direct_declarator_const
	;

direct_declarator_const
	: IDENTIFIER
	| '(' declarator_const ')'
	| direct_declarator_const '[' ']'
	| direct_declarator_const '[' logical_or_expression']'
	| direct_declarator_const '(' parameter_list ')'
	| direct_declarator_const '(' identifier_list ')'
	;

declaration_array
	: declaration_specifiers_array ';'
	| declaration_specifiers_array init_declarator_list_array ';'
	;

declaration_specifiers_array
	: scalar_type_specifier
	| scalar_type_specifier declaration_specifiers_array

init_declarator_list_array
	: init_declarator_array
	| init_declarator_list_array ',' init_declarator_array

init_declarator_array
	: declarator_array '=' initializer
	| declarator_array
	;

declarator_array
	: direct_declarator_array
	;

direct_declarator_array
	: IDENTIFIER
	| '(' declarator_array ')'
	| direct_declarator_array '(' ')'
	| direct_declarator_array '[' ']'
	| direct_declarator_array '[' logical_or_expression_no_function']'
	| direct_declarator_array '(' parameter_list ')'
	| direct_declarator_array '(' identifier_list ')'
	;

function_definition
	: declaration_specifiers_array declarator_array declaration_list compound_statement
	| declaration_specifiers_array declarator_array compound_statement
	| VOID declarator_array declaration_list compound_statement
	| VOID declarator_array compound_statement
	;

initializer
	: '{' '}'
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression_no_function
	;

initializer_list
	: designator_list_and_equal_op  initializer
	| initializer
	| initializer_list ',' designator_list_and_equal_op
	| initializer_list ',' initializer
	;

designator_list_and_equal_op
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '.' IDENTIFIER
	;	

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers_array declarator_array
	| declaration_specifiers_array
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

compound_statement
	: '{' statements_within_function '}'
	;

statements_within_function
	: global_declarations statement_group
	;

statement_group
	: /*empty*/
	| statement_group statement
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| labeled_statement
	| jump_statement
	| delay_statement
	| digital_write_statement
	;

high_or_low
	: HIGH{ 
		$$ = 1;
	}
	| LOW{
		$$ = 0;
	}
	;

delay_statement
	: DELAY '(' expression ')' {
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "bal delay\n");
	}
    ;

digital_write_statement
	: DIGITALWRITE '(' NUMBER_INTEGER ',' high_or_low ')' {
		fprintf(file, "movi $r0, %d\n", $3);
		fprintf(file, "movi $r1, %d\n", $5);
		fprintf(file, "bal digitalWrite\n");
    }
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE logical_or_expression ':' statement
	| DEFAULT ':' statement
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement %prec ELSE_DUMMY_FOR_CONFLICT
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

assignment_expression
	: logical_or_expression
	| unary_expression '=' assignment_expression
	;

assignment_expression_no_function
	: logical_or_expression_no_function
	| unary_expression_no_function '=' assignment_expression_no_function
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

logical_and_expression
	: and_expression
	| logical_and_expression AND_OP and_expression
	;

and_expression
	: equality_expression
	| and_expression POINTER_OP equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

relational_expression
	: additive_expression
	| relational_expression '>' additive_expression
	| relational_expression '<' additive_expression
	| relational_expression GE_OP additive_expression
	| relational_expression LE_OP additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator unary_expression
	;

logical_or_expression_no_function
	: logical_and_expression_no_function
	| logical_or_expression_no_function OR_OP logical_and_expression_no_function
	;

logical_and_expression_no_function
	: and_expression_no_function
	| logical_and_expression_no_function AND_OP and_expression_no_function
	;

and_expression_no_function
	: equality_expression_no_function
	| and_expression_no_function POINTER_OP equality_expression_no_function
	;

equality_expression_no_function
	: relational_expression_no_function
	| equality_expression_no_function EQ_OP relational_expression_no_function
	| equality_expression_no_function NE_OP relational_expression_no_function
	;

relational_expression_no_function
	: additive_expression_no_function
	| relational_expression_no_function '>' additive_expression_no_function
	| relational_expression_no_function '<' additive_expression_no_function
	| relational_expression_no_function GE_OP additive_expression_no_function
	| relational_expression_no_function LE_OP additive_expression_no_function
	;

additive_expression_no_function
	: multiplicative_expression_no_function
	| additive_expression_no_function '+' multiplicative_expression_no_function
	| additive_expression_no_function '-' multiplicative_expression_no_function
	;

multiplicative_expression_no_function
	: unary_expression_no_function
	| multiplicative_expression_no_function '*' unary_expression_no_function
	| multiplicative_expression_no_function '/' unary_expression_no_function
	| multiplicative_expression_no_function '%' unary_expression_no_function
	;

unary_expression_no_function
	: postfix_expression_no_function
	| INC_OP unary_expression_no_function
	| DEC_OP unary_expression_no_function
	| unary_operator unary_expression_no_function
	;

postfix_expression_no_function
	: primary_expression_no_function
	| postfix_expression_no_function  '[' ']'
	| postfix_expression_no_function '.' IDENTIFIER
	| postfix_expression_no_function INC_OP
	| postfix_expression_no_function DEC_OP
	;

primary_expression_no_function
	: IDENTIFIER
	| number
	| STRING
	| '(' expression ')'
	;

unary_operator
	: '&'
	| '+'
	| '-'
	| '!'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

primary_expression
	: IDENTIFIER
	| number
	| STRING
	| '(' expression ')'
	;

number
	: NUMBER_INTEGER{
		fprintf(file, "movi $r0, %d\n", $1);
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;
	}
	| NUMBER_DOUBLE
	| NUMBER_SCI
	| CHARACTER
	; 

%% 
#include <stdio.h>
#include <stdlib.h>

extern int lineCount;
extern int yytext[];
extern char** lineContents;
extern numStrings;
extern wordCount;
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
		fprintf(file, "beqz $r0, .AND%d\n", and_label_count);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .AND%d\n", and_label_count);

		fprintf(file, "movi $r0, 1\n");
		fprintf(file, "j .AND%d\n", and_label_count+1);
		fprintf(file, ".AND%d:\n", and_label_count);
		and_label_count++;
		fprintf(file, "movi $r0, 0\n");
		fprintf(file, ".AND%d:\n", and_label_count);
		and_label_count++;
		fprintf(file, "swi $r0, [$sp + %d]\n", top*4);
		top++;

	}else if(!strcmp(op, "||")){
		top--;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
		fprintf(file, "beqz $r0, .OR%d\n", or_label_count+1);
		top --;
		fprintf(file, "lwi $r0, [$sp + %d]\n", top*4);
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
