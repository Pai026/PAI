#include<stdio.h>
int fib(int a)
{  if((a==0)||(a==1))
	return 1;

	return fib(a)+fib(a+1);
}
int main()
{    int i,j;
     scanf("%d",&i);
     for(j=0;j<i;j++)
     printf("%d " ,fib(j));
     return 0;
}