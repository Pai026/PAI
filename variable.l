%{
#include<stdio.h>
#include"y.tab.h"
%}


%%
[0-9] {return DIGIT;}
[a-zA-Z]+ {return LETTER;}
.	{return yytext[0];}
\n	{return 0;}
%%

int yywrap()
{
return 1;
}
