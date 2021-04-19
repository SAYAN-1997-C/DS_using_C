#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* getNode(int );
void ListDisplay(node *);
void splitEvenOdd(node *);

int main()
{
    node *head=NULL,*current,*nw;
    int ch,val;
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
    splitEvenOdd(head);
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
    return ;
}
void splitEvenOdd(node *head)
{
    node *even=NULL,*odd=NULL,*ptr,*nw,*current1,*current2;
    ptr=head;
    while(ptr!=NULL)
    {
        nw=getNode(ptr->data);
        if((ptr->data%2)==0)
        {
            if(even==NULL)
                even=nw;
            else
                current1->next=nw;
            current1=nw;       
        }
        else
        {
            if(odd==NULL)
                odd=nw;
            else
                current2->next=nw;
            current2=nw;
        }
        ptr=ptr->next;
    }
    printf("\nEVEN : ");
    ListDisplay(even);
    printf("\nODD : ");
    ListDisplay(odd);
    return;
}