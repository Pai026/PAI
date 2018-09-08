#include<stdio.h>
#include<conio.h>
int main()
{
clrscr();
int t,s,i,n,j;
printf("enter the limit:");
scanf("%d",&n);
printf("\n the first %d palindrome numbers are:",n);
for(j=1;j<=n;++j)
{s=0;
t=j;
while(t!=0)
{
i=t%10;
s=s*10+i;
t=t/10;
}
if(s==j)
printf("%d\t",s);
}
getch();
return 0;
}