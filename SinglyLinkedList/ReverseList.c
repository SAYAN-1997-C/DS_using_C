#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* getNode(int );
void ListDisplay(node *);
void ReverseList(node *);

int main()
{
    node *head=NULL,*current,*nw;
    int val,ch;
    while(1)
    {
        printf("\nEnter the data : ");
        scanf("%d",&val);
        nw=getNode(val);
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw;
        printf("\nYou want to continue press 1 otherwise 0 : ");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    ListDisplay(head);
    ReverseList(head);
    return 0;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=NULL;
    return nw;
}
void ListDisplay(node *head)
{
    node *ptr;
    ptr=head;
    printf("\nThe list is : ");
    while(ptr!=NULL)
    {
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}
void ReverseList(node *head)
{
    node *ptr1,*ptr2,*ptr3;
    ptr1=head;
    ptr2=ptr1->next;
    ptr1->next=NULL;
    while(ptr2!=NULL)
    {
        ptr3=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr3;
    }
    head=ptr1;
    printf("\nAfter reverse " );
    ListDisplay(head);
    return;
}