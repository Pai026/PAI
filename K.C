#include<stdio.h>
#include<conio.h>
int main()
{ char a[20],*ptr;
  int i,j,n;
  clrscr();
  scanf("%d",&n);
  for(i=0;i<n;i++)
  { a[i]=(char*)malloc(20*sizeof(char));
    scanf("%s",a[i]);
  }
  for(i=0;i<n;i++)
    for(j=n-1;j>=0;j--)
	a[i]=a[j];
  for(i=0;i<n;i++)
    printf("%s",a[i]);
    printf("\n");
    getch();
    return 0;
 }
