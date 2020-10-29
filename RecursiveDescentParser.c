//E->(E')
//E'->[a-zA-Z]+a
#include<stdio.h>
#include<ctype.h>
char *ip,expression[50];
int Edash();
int E()
{
    if(*ip=='(')
    {
        printf("\n%s \t E->(E')",ip);
        ip++;
        if(Edash())
        {
            if(*ip==')'){
                printf("\n%s \t E->(E')",ip);
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
        else
            return 0;
    }
    else
    {
        return 0;
    }
    
}
int Edash()
{
    if(isalpha(*ip))
    {
        printf("\n%s \t E'->[a-zA-Z]+a",ip);
        ip++;
        if(*ip=='+')
        {
            printf("\n%s \t E'->[a-zA-Z]+a",ip);
            ip++;
            if(*ip=='a')
            {
                printf("\n%s \t E'->[a-zA-Z]+a",ip);
                ip++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
        
            
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    printf("\nEnter the expresssion to be evaluated:");
    scanf("%s",expression);
    ip=expression;
    printf("\ninput \t production");
    if(E())
    {
        printf("\nExpression is Valid");
    }
    else
    {
        printf("\nExpression is Invalid");
    }
}