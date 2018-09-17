%{
	#include<stdio.h>
	int yyerror(char *a);
%}

%token ID NUM
%left '+' '-'
%left '*' '/'

%%

stmt:expr;
expr:expr'+'expr
	|expr'-'expr
	|expr'*'expr
	|expr'/'expr
	|'('expr')'
	|ID
	|NUM
	;
%%

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
