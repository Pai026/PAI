%{

#include<stdio.h>
int valid = 1;
%}

%token DIGIT ID
%left '+' '-'
%left '*' '/'
%%
F :E '+' E
  |E '-' E
  |E '*' E
  |E '/' E 
  |'('E')'
  ;
E :ID 
  |DIGIT
  ;
%%

int main()
{
printf("Enter expresstion\t");
yyparse();
if(valid)
	printf("valid expression\n");
return 0;
}

int yyerror()
{
printf("invalid expression\n");
valid =0;
return 0;
}
