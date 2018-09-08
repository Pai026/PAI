#include<stdio.h>
#include<stdlib.h>
void del_beg(int A[],int *n)
{
	int i,d;
	if(n>0){
	d=A[0];

	for(i=0;i<*n;i++)
	      A[i]=A[i+1];
	*n=*n-1;
	printf("deleted value is %d",d);}
	else
	 printf("\ndeletion not possible");
}
void del_end(int A[],int *n)
{
	int i,d;
	if(*n>0)

	{d=A[*n-1];
		*n=*n-1;
		printf("deleted value %d",d);}
	else
		printf("not possible");
}
void del_loc(int A[],int *n,int pos)
{
	int i,d;
	if(*n>0)
	{
	d=A[pos];
	   for(i=pos;i<*n;i++)
		   A[i]=A[i+1];
		*n=*n-1;
		printf("Element deleted %d ",d);
	}
	else
		printf("element can't br del");

}
void Aprint(int A[],int n)
{
	int i=0;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
}
int main()
{
	int pos=0,n,key,A[10],ch;
	int i;
	char d;
	printf("enter the size");
	scanf("%d",&n);
	 for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	 do
	{
	 printf("\n 1.DEL at beg 2.DEL at end 3.DEL at location 4.Print");
	printf("enter your choice\n");
	scanf("%d",&ch);

	 switch(ch)
	 {
		 case 1:del_beg(A,&n);
			Aprint(A,n);
			break;
		case 2 :del_end(A,&n);
			Aprint(A,n);
			break;
		case 3 :printf("ENTER THE POS");
			scanf("%d",&pos);
			del_loc(A,&n,pos);
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


