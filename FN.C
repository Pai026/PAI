#include<stdio.h>
#include<conio.h>
int add(int a,int b)
{ return a+b;
}
int sub(int a,int b)
{ return a-b;
}
int multiply(int a,int b)
{ return a*b;
}
int div(int a,int b)
{ if(b==0)
   printf("\nDivison not possible");
    return a/b;
}
int main()
{   int (*fn[])(int,int)={add,sub,multiply,div};
    int a,b;
    clrscr();
    scanf("%d %d",&a,&b);
    printf("%d",fn[3](a,b));
    getch();
    return 0;
}