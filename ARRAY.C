#include<stdio.h>
#include<conio.h>
int main()
{ 	int n,*i,**j;
	scanf("%d",&n);
	i=&n;
	j=&i;
	printf("Address=%d value=%d",i,*i);
	printf("\nAddress=%d Value=%d",j,*j);
	printf("\n");
	getch();
	return 0;
}