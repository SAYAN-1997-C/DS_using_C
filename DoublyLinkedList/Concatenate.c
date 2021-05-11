#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *next,*prev;
}node;

node* getNode(int );
node* CreateList(node *);
void Display(node *);
node* ConcatenateTwoList(node *,node *);

int main()
{
    node *head1=NULL,*head2=NULL;
    printf("\nFor 1st List : ");
    head1=CreateList(head1);
    printf("\nFor 2nd List : ");
    head2=CreateList(head2);
    printf("\n1st List : ");
    Display(head1);
    printf("\n2nd List : ");
    Display(head2);
    printf("\nAfter Conatenate  : ");
    head1=ConcatenateTwoList(head1,head2);
    Display(head1);
    return 0;
}
node* CreateList(node *head)
{
    node *nw,*current;
    int ch,val;
    while(1)
    {
        printf("\nEnter the data : ");
        scanf("%d",&val);
        nw=getNode(val);
        if(head==NULL)
            head=nw;
        else
        {
            current->next=nw;
            nw->prev=current;
        }
        current=nw;
        printf("\nYou want to continue press 1 otherwise 0 : ");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    return head;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=NULL;
    nw->prev=NULL;
    return nw;
}
void Display(node *head)
{
    node *ptr,*temp;
    ptr=head;
    printf("\nThe list is : ");
    while(ptr!=NULL)
    {
        printf("%d --> ",ptr->data);
        temp=ptr;
        ptr=ptr->next;
    }
    printf("\n");
    printf("\nThe Reverse list is : ");
    while(temp!=NULL)
    {
        printf("%d --> ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
node* ConcatenateTwoList(node *head1,node *head2)
{
    node *ptr;
    if(head1==NULL)
    {
        head1=head2;
        return head1;
    }
    ptr=head1;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head2;
    head2->prev=ptr;
    return head1;
}