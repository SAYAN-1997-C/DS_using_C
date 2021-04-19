#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;

node* getNode(int );
void Display(node *);
node* AlternateDelete(node *);

int main()
{
    node *head=NULL,*current,*nw;
    int val,ch;
    while(1)
    {
        printf("\nEnter the value : ");
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
    Display(head);
    printf("\nAfter Alternate delete 1th,3rd....");
    head=AlternateDelete(head);
    Display(head);
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
void Display(node *head)
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
node *AlternateDelete(node *head)
{
    node *prev,*ptr;
    if(head==NULL)
    {
        printf("\nList is already empty!!");
        return head;
    }
    if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
    head=head->next;
    ptr=head;
    prev=ptr;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        if(ptr==NULL)
            return head;
        prev->next=ptr->next;
        ptr=ptr->next;
        prev=ptr;
    }
    return head;
}