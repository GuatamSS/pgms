
%{
	#include "y.tab.h"
%}

%%

[a-zA-Z]			{return LETTER;}
[0-9]					{return NUM;}
\n					{return NL;}
_					{return UNDSC;}

%%

int yywrap()
{

	return(1);
}
