%{

#include<stdio.h>
int valid = 1;
%}

%token DIGIT LETTER

%%
stmt :A;
A :LETTER B
  |LETTER
  ;
B :LETTER B
  |DIGIT B
  |LETTER 
  |DIGIT
  ;
%%

int main()
{
printf("Enter variable\t");
yyparse();
if(valid)
	printf("valid variable\n");
return 0;
}

int yyerror()
{
printf("invalid variable\n");
valid =0;
return 0;
}
