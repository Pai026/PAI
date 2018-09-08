#include<stdio.h>
int and(int a,int b)
{  if((a&&b)==0)
	return 0;
	else
		return 1;
}
int or(int a,int b)
{	if((a||b)==0)
		return 0;
		else
			return 1;
}
int not(int a)
{   if((!a)==0)
	return 0;
	else
		return 1;
}
int main()
{
	int a,b,c,d,f,g,h,i;
	scanf("%d %d %d",&a,&b,&c);
	d=and(a,b);
	f=not(a);
	g=or(a,f);
	h=and(c,g);
	i=or(d,h);
	if(i==1)
	printf("\nresult is TRUE");
	else
	printf("\nresult is FALSE");
	printf("\n");
	return 0;
}