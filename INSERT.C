#include<stdio.h>
#include<stdlib.h>
void in_beg(int A[],int *n,int key,int max)
{
	int i;
	if(*n<max)
	{	for(i=*n;i>=0;i--)
			A[i+1]=A[i];
	A[0]=key;
	*n=*n+1;}
	else
		printf("insertion is not possible");
}
void in_end(int A[],int *n,int key,int max)
{
	int i;
	if(*n<max)

	{	A[*n]=key;
		*n=*n+1;
	}
	else
		printf("INSERTION IS NOT POSSIBLE");
}
void in_loc(int A[],int *n,int key,int max,int pos)
{
	int i;
	if(*n<max)
	{
		if(pos<=*n-1)
		{	for(i=*n;i>=pos;i--)
				A[i+1]=A[i];
		}
	A[pos]=key;
	*n=*n+1;
	}

	else
		printf("Insertion not possible");
}
void Aprint(int A[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
}
int main()
{
	int pos=0,n,key,max,A[10],ch;
	int i;
	char d;
	max=10;
	printf("enter the size");
	scanf("%d",&n);
	printf("Enter the elemnets");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	do
	{
	 printf("\n 1.insert at beg 2.Insert at end 3.Insert at location 4.Print");
	printf("enter your choice\n");
	scanf("%d",&ch);
	printf("Enter the element to be added");
	scanf("%d",&key);
	 switch(ch)
	 {
		 case 1:in_beg(A,&n,key,max);
			Aprint(A,n);
			break;
		case 2 :in_end(A,&n,key,max);
			Aprint(A,n);
			break;
		case 3 :printf("ENTER THE POS");
			scanf("%d",&pos);
			in_loc(A,&n,key,max,pos);
			Aprint(A,n);
			break;
		case 4 :Aprint(A,n);
			break;
		default : printf("wrong choice");
			  exit(0);

	}
	 printf("\n do u want to continue\n  type y for yes and n for no ");
	scanf(" %c",&d);

	}while(d=='y'||d=='Y');
return 0;

}

