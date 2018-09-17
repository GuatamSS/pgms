%{
	int com=0;
%}

identifier	[a-zA-Z][_a-zA-Z0-9]*
number		[0-9]+	
%%

#.*		{printf("\n\t%s is a preprocessor directive",yytext);}
int|float|char|while|
for|struct|typedef|do|
if|break|continue|
void|switch|return|else|
goto 		{printf("\n\t%s is a keyword",yytext);}
"/*"		{COMMENT=1;}{printf("\n\t MULTILINE COMMENT BEGINS");}
{identifier}\( {if(!COMMENT) printf("\nFUNCTION %s", yytext);}
\{              {if(!COMMENT) printf("\n BLOCK BEGINS");}
\}		{if(!COMMENT) printf("\n BLOCK ENDS");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n\%sIDENTIFIER",yytext);}
\".*\" 		{if(!COMMENT) printf("\n\t%s is a STRING",yytext);}
{number}        {if(!COMMENT) printf("\n%s is a NUMBER",yytext);}
{number}\.{number} {if(!COMMENT) printf("\n%s is a DECIMAL NUMBER", yytext);}
\)(\:)(\;)?	;
\(		;
=		{if(!COMMENT) printf("\n\t %s is an ASSIGNMENT OPERATOR", yytext);}
\<=|\>=|\<|\!=|
==|\> 		{if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR", yytext);}
"*/"		{COMMENT=0;} {printf("\n\t MULTILINE COMMENT ENDS");}
\|\||\!|\&\& 	{if(!COMMENT) printf("\n\t%s is a LOGICAL OPERATOR", yytext);}
\/\/.* 		{if(!COMMENT) printf("\n\t SINGLE LINE COMMENT");}
%%
int main(int argc, char**argv)
{
	FILE * file;
	file=fopen("yar.c","r");
	if(!file)
	{
		printf("\n\t could not open file");
		exit(0);
	}
	yyin=file;
	yylex();
	printf("\n");
	return(0);
}
int yywrap()
{
return(1);
}


