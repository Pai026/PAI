#include<stdio.h>
#include<conio.h>
void read(int a[10],int n)
{  int *p,i;
   p=a;
   for(i=0;i<n;i++)
       scanf("%d",(p+i));
   for(i=0;i<n;i++)
	printf("%d",*(p+i));
}
void sort(int a[10],int n)
{ int *p,i,j,temp;
   p=a;
   for(i=0;i<n;i++)
    {	for(j=i+1;j<n;j++)
	{ if(*(p+j)<*(p+i))
	   { temp=*(p+i);
	     *(p+i)=*(p+j);
	     *(p+j)=temp;
	   }
	 }
     }
}
void print(int a[10],int n)
{	int *p,i;
	p=a;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d",*(p+i));
}
void b_search(int a[10],int n,int item)
{ int beg=0,last=n-1,mid,*p,found=0;
  p=a;
  while(beg<=last)
  {  mid=(beg+last)/2;
     if(*(p+mid)==item)
     { printf("\nElement found at position %d",mid+1);
	found=1;
	break;
     }
     if(*(p+mid)<item)
	beg=mid+1;
     else
	last=mid-1;
  }
  if(found==0)
	printf("\nElement not found");
}

int main()
{   clrscr();
    int a[10],n,item;
    scanf("%d",&n);
    read(a,n);
    sort(a,n);
    print(a,n);
    printf("\n");
    scanf("%d",&item);
    b_search(a,n,item);
    getch();
    return 0;
}