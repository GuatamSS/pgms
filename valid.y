%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror(char *a);
%}

%token LETTER NUM UNDSC NL


%%

variable:LETTER exchar NL	{printf("\nValid Variable Name");exit(0);}
exchar: exchar LETTER
	|exchar NUM
	|LETTER
	|NUM
	|UNDSC
	;
%%

void main()
{
	printf("\nEnter Variable Name:");
	yyparse();
	
}

int yyerror(char *a)
{	
	printf("\nInvalid");
	return(0);
	exit(0);
}
