#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* getNode(int );
node* CreateList(node *);
void Display(node *);

int main()
{
    node *head1=NULL,*head2=NULL,*ptr;
    printf("\nFor 1st List : ");
    head1=CreateList(head1);
    printf("\nFor 2nd List : ");
    head2=CreateList(head2);
    printf("\n1st list : ");
    Display(head1);
    printf("\n2nd list : ");
    Display(head2);
    ptr=head1;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head2;
    printf("\nAfter Added : ");
    Display(head1);
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
    printf("\nThe list is : ");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

node* CreateList(node *head)
{
    node *current,*nw;
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
    return head;
}