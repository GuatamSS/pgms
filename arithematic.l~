%{
	#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9_]*			{return ID;}
[0-9]+					{return NUM;}
\n					{return 0;}
.					{return yytext[0];}

%%

int yywrap()
{

	return(1);
}
