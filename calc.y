%{
	#include<stdio.h>
	#include<stdlib.h>
	int yyerror(char *a);
%}
%union {int num;}
%token <num> NUM
%left '+' '-'
%left '*' '/'

%%

stmt:expr;
expr:expr'+'expr'		{printf("=%d\n",$$=$1+$2);}
	|expr'-'expr'		{printf("=%d\n",$$=$1-$2);}
	|expr'*'expr'		{printf("=%d\n",$$=$1*$2);}
	|expr'/'expr'		{printf("=%d\n",$$=$1/$2);}
	|'('expr')'		{$$=$2;}
	|NUM			{$$=$1;}
	;
%%

#include "lex.yy.c"
void main()
{
	printf("\nEnter Expression:");
	yyparse();
	printf("\nValid");
	exit(0);
}

int yyerror(char *a)
{	
	printf("\nInvalid");
	return(0);
	exit(0);
}
