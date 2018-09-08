//CP Assignment Done By Abhiram R Pai   !
//S2 CSE Roll NO 03                     !
//Program to excecute Binary search in  !
//a 1D array and the print the array    !
//using pointers........................!
#include<stdio.h>
#include<conio.h>
void sort(int a[10],int n)
{     int i,j,temp;
      for(i=0;i<n;i++)
      {
	for(j=i+1;j<n;j++)
	      {	if(a[i]>a[j])
		 {	temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		  }
	       }
       }
}
void print(int a[10],int n)
{      int *p,i;
       p=a;
       printf("\t");
       for(i=0;i<n;i++)
	printf("%d ",*(p+i));
       printf("\n");

}
void bsearch(int a[10],int n,int item)
{	int beg,last,mid,found;
	beg=0;
	last=n-1;
	found=0;
	while(beg<=last)
	{ mid=(beg+last)/2;
	  if(a[mid]==item)
	  {
	   printf("\nElement found at %d position",mid+1);
	   found=1;
	   break;
	  }
	  else
		if(a[mid]<item)
			beg=mid+1;
			else
				last=mid-1;
	}
	if(found==0)
		printf("\nElement not found");
}
int main()
{ int a[10],n,i,item;
	clrscr();
  printf("\nEnter the size of the array");
  scanf("%d",&n);
  printf("\nEnter the elements");
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  printf("\nArray before sorting");
  print(a,n);
  sort(a,n);
  printf("\nArray after sorting");
  print(a,n);
  printf("\nEnter the element to be searched for");
  scanf("%d",&item);
  bsearch(a,n,item);
  getch();
  return 0;
}