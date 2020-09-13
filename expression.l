%{
#include<stdio.h>
#include"y.tab.h"
%}


%%
[0-9]+(\.[0-9]+)? {return DIGIT;}
[a-zA-Z_][_a-zA-Z0-9]* {return ID;}
.	{return yytext[0];}
\n	{return 0;}
%%

int yywrap()
{
return 1;
}
