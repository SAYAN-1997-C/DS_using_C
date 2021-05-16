#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}

node* Push(node *,int *,int );
node* getNode(int );
void Display(node *,int );
node* Pop(node *,int *);

int main()
{
    int n,ch,top=-1;
    node *head=NULL;
    printf("\nEnter the size of the stack : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.peek\n4.Display\n5.Exit\nEnter your hoice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : head=Push(head,&top,n);
                     break;
            case 2 : head=Pop(Arr,&top);
                     break;
            case 3 :if(top==-1)
                        printf("\nStack is Empty!!");
                    else 
                        printf("\nThe peek value is : %d\n",head->data);
                     break;
            case 4 : Display(head,top);
                     break;
            case 5 : exit(0);
                     break;
            default: printf("\nEnter a valid input\n");
                     break;
        }
    }
}
node* Push(node *head,int *top,int n)
{
    if(*top == (n-1))
    {
        printf("\nStack is Full!!");
        return;
    }
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    node *nw;
    nw=getNode(val);
    nw->next=head;
    head=nw;
    *top+=1;
    printf("\nPushed Successfully!!");
    return head;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=NULL:
    return nw;
}
void Display(node *head,int top)
{
    if(top==-1)
    {
        printf("\nStack is Empty!!");
        return;
    }
    printf("\nThe stack is : ");
    int i=top;
    node *ptr=head;
    for(;i>=0;i--)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}
node* Pop(node *head,int *top)
{
    if(*top == -1)
    {
        printf("\nStack is already empty!!\n");
        return;
    }
    printf("\nThe poped value is : %d\n",head->data);
    head=head->next;
    *top=*top-1;
    return head;
}