#include<stdio.h>
#include<stdlib.h>
struct node 
{	int data;
	struct node *link;
};
struct node *header,*header1,*ptr,*ptr1,*cur,*prev;
void insert(int d)
{ 	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->link=NULL;
	if(header->link==NULL)
		header->link=temp;
	else
	{	ptr=header;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=temp;
	}
}
void rev()
{
	prev=header;
	cur=prev->link;
	ptr=cur->link;
	cur->link=NULL;
	while(ptr!=NULL)
	{	prev=cur;
		cur=ptr;
		ptr=ptr->link;
		cur->link=prev;
		
	}
	header->link=cur;

}	
void print(struct node *header)
{	ptr1=header->link;	
		while(ptr1!=NULL){
				printf(" %d",ptr1->data);
				ptr1=ptr1->link;}
}
int main()
{	int k,d;
	header=(struct node*)malloc(sizeof(struct node));
	do{
	printf("\n1.insert\n2.reverse\n3.print");
	scanf("%d",&k);
	switch(k)
	{	case 1:scanf("%d",&d);
			insert(d);
			break;
		case 2:rev();
			break;
		case 3:print();
			break;
	}
 	}while(k!=4);
}
