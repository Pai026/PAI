%{
#include<stdio.h>
int lc=0;
%}
letter [A-Za-z]
digit [0-9]


%%
#.* {printf("%s is a preproccessor directive\n",yytext);}
;* {printf("%s is a delimiter\n",yytext);}
"int"|"float"|"auto"|"double"|"struct"|"enum"|"else"|"typedef"|"char"|"register"|"return"|"void"|"long"|"case"|"switch"|"if"|"else"|"break" {printf("%s is a keyword\n",yytext);}
{letter}({letter}|{digit})* {printf("%s is an identifier\n",yytext);}
{digit}* {printf("%s is a Number\n",yytext);}
"("|")"|"{"|"}" 
"=" {printf("%s assign operator\n",yytext);}
"," 
" "
"\n"
"+"|"-"|"*"|"/" {printf("%s arithemetic operators\n",yytext);}
"!"|"@"|"#"|"$"|"%"|"^"|"&" {printf("%s special characters\n",yytext); }
%%

int yywrap(){}

int main(){
FILE *fp;
fp=fopen("input.c","r");
yyin=fp;
yylex();
printf("\n");
fclose(fp);
return 0;
}
