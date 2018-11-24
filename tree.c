#include<stdio.h>
#include<stdlib.h>
struct node
{ 	int data;
	struct node *LC;
	struct node *RC;
};
struct node *temp,*ptr,*parent,*root;
void insert_BST(int key)
{	struct node *temp1;
	int flag;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->data=key;
	temp1->LC=NULL;
	temp1->RC=NULL;
	temp=root;
	if(root==NULL)
		root=temp1;
	else
	{	flag=0;
		while((temp!=NULL)&&(flag==0))
		{	if(key<temp->data)
				{parent=temp;temp=temp->LC;}
			else if(key>temp->data)
				{parent=temp;temp=temp->RC;}
			else
			{	flag=1;
				break;
			}
		}
		if(flag!=1)
		{	if(parent->data>key)
				parent->LC=temp1;
			else
				parent->RC=temp1;
		}
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{	printf("%d\t",root->data);
		preorder(root->LC);
		preorder(root->RC);
	}
}
void preorder1()
{	int s[50],top=0;	
	if(root==NULL)
		printf("EMPTY");
	else
	{		
		s[top]=root->data;
		ptr=root;
		parent=root;
		while(ptr->LC!=NULL)
		{
			top=top+1;
			ptr=ptr->RC;
			s[top]=s[top]+ptr->data;
			if(root!=NULL)
			{	root=root->LC;
				top=top+1;
				s[top]=root->data;
				ptr=root;
			}
			else
				{parent=parent->RC;ptr=parent;}
		
		}
	}
	while(top>-1)
	{	printf("%d\t",s[top]);top--;
	}
}	
int main()
{	
	root=(struct node*)malloc(sizeof(struct node));
	root=NULL;
	insert_BST(50);
	insert_BST(20);
	insert_BST(65);
	insert_BST(10);
	insert_BST(30);
	insert_BST(70);
	insert_BST(60);
	//preorder(root);
	preorder1();
	return 0;
}


