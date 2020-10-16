#include<stdio.h>
#include<malloc.h>
struct node
{
    int value;
    struct node* next;
};

void insert(struct node** a,int item)
{
    struct node * head = *a;
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->value = item;
    temp->next = NULL;
    if(*a == NULL)
    {
        *a = temp;
        return;
    }
    while(head->next != NULL)
    {
        head=head->next;
    }
    head->next = temp;
    return;

}

int print(struct node* a)
{
    struct node* head = a;
    while(head->next != NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
    printf("%d ",head->value);
}
int main()
{
    struct node* a=NULL;
    insert(&a,5);
    insert(&a,6);
    insert(&a,7);
    insert(&a,8);
    insert(&a,9);
    print(a);
    return 0;

}