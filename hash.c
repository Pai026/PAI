#include<stdio.h>
#include<stdlib.h>
int a[50],h[100];
void closed_hash(int val,int n)
{ 
	int pos,k,flag=0,flag1=0;
	pos=val%n;
	while(h[pos]!=-1)
	{	if(h[pos]==val)
			flag=1;
		pos=pos+1;
		k=k+1;
		if((k==n)&&(flag1!=1))
			{pos=0;flag1=1;}
	}
		if(k==n)
			printf("\n Hash table is full");
		else if(flag==0)
			h[pos]=val;
}
void search(int key,int n)
{	
	int pos,k=0,flag1=0;
	pos=0;
	while(flag1!=1)
	{	if(h[pos]==key)
		{	printf("\nElement Found at index %d\n",pos);
			break;}
		else
		{	if(h[pos]!=-1)
				pos=pos+1; 
			
		}	
	}
	if(--k==n)
		printf("\nElement not found in the table");
}
void display(int n)
{	int i;
	for(i=0;i<n;i++)
	{	printf("\nIndex[%d]=%d",i,h[i]);}


}
int main()
{
	int size,i,k;
	printf("\nEnter the size of the array");
	scanf("%d",&size);
	for(i=0;i<size;i++)
		{scanf("%d",&a[i]);h[i]=-1;}
	for(i=0;i<size;i++)
		closed_hash(a[i],size);
	do{
		printf("\n1.Search\n2.Display\n3.Exit\nEnter Your choice");
		scanf("%d",&k);
		switch(k){
			case 1:	printf("\nEnter the element to search");
				scanf("%d",&k);
				search(k,size);
				break;
			case 2: display(size);
				break;
			case 3: exit(0);
		}
	}while(k!=3);
	return 0;
}


