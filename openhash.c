#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *link;
};
int a[50];
struct node *chain[50];
int init(int n)
{	int i;
	for(i=0;i<n;i++)
	{ chain[i]=(struct node*)malloc(sizeof(struct node));
	  chain[i]=NULL;
	}
}
void hash(int key,int n)
{	int val;
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	val=key%n;
	temp->data=key;
	temp->link=NULL;
	if(chain[val]==NULL)
		chain[val]=temp;
	else
	{	ptr=chain[val];
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=temp;
	}
}
void display(int n)
{	int i;
	struct node *ptr;
	for(i=0;i<n;i++)
	{	ptr=chain[i];
		printf("\nChain[%d]",i);
		while(ptr!=NULL){
			printf("->%d",ptr->data);
			ptr=ptr->link;}
	}
}
void search(int key,int n)
{
	int pos=key%n,flag=0;
	struct node *ptr;
	ptr=chain[pos];
	while(ptr!=NULL)
	{	if(ptr->data==key)
		{	printf("\nElement found at index %d",pos);
			flag=1;
			break;
		}
		else
			ptr=ptr->link;
	}
	if(flag==0)
		printf("\nElement Not Found");
}
int main()
{
	int size,i,k;
	printf("\nEnter the size of the array");
	scanf("%d",&size);
	init(size);
	for(i=0;i<size;i++)
		{scanf("%d",&a[i]);}
	for(i=0;i<size;i++)
		hash(a[i],size);
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

	
