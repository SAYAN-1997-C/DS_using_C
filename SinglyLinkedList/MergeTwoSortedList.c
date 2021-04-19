#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* getNode(int );
void ListDisplay(node *);
node* createList(node *);
void Merge_Two_Sorted_List(node *,node *);

int main()
{
    node *head1=NULL,*head2,*current,*nw;
    printf("\nFor 1st List : ");
    head1=createList(head1);
    printf("\nFor 2nd List : ");
    head2=createList(head2);
    ListDisplay(head1);
    ListDisplay(head2);
    Merge_Two_Sorted_List(head1,head2);
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
node* createList(node *head)
{
    node *current,*nw;
    int val,ch;
    while(1)
    {
        printf("\nEnter the data(Sorted order) : ");
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
void Merge_Two_Sorted_List(node *head1,node *head2)
{
    node *ptr1,*ptr2,*head=NULL,*current,*nw;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data <= ptr2->data)
        {
           nw=getNode(ptr1->data);
           ptr1=ptr1->next; 
        }
        else
        {
            nw=getNode(ptr2->data);
            ptr2=ptr2->next;
        }
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw;
    }
    while(ptr1!=NULL)
    {
        nw=getNode(ptr1->data);
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw; 
        ptr1=ptr1->next;      
    }
    while(ptr2!=NULL)
    {
        nw=getNode(ptr2->data);
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw;
        ptr2=ptr2->next;                
    }
    printf("\nAfter merge ");
    ListDisplay(head);
    return;
}