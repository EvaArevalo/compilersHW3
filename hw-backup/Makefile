# makefile
# creates "scanner" from "scanner.l" and "test.c"

CC=gcc
LEX=flex
PARS=byacc

parser: lex.yy.c y.tab.c
		$(CC) -o codegen lex.yy.c y.tab.c

y.tab.c: parser.y
		 $(PARS) -d --verbose parser.y

lex.yy.c: scanner.l
		$(LEX) --header-file=scanner.h scanner.l 

clean:
		$(RM) *.o scanner.o lex.yy.c y.tab.c



parser: scanner.l parser.y
	flex --header-file=scanner.h scanner.l
	byacc  -d  parser.y
	g++  -o  codegen lex.yy.c y.tab.c
clean:
	rm -f codegen
	rm -f lex.yy.c
