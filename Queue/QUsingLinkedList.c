#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next; 
}node;

void QInsert(node **,node **,int *,int *,int );
void Display(node **,node **,int *,int *);
node* getNode(int );
void QDelete(node **,node **,int *,int *);


int main()
{
    node *Fhead=NULL,*Rend=NULL;
    int F=-1,R=-1,n,ch;
    printf("\nEnter the size of the queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter our choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : QInsert(&Fhead,&Rend,&F,&R,n);
                     break;
            case 2 : QDelete(&Fhead,&Rend,&F,&R);
                     break;
            case 3 : Display(&Fhead,&Rend,&F,&R);
                     break;
            case 4 : exit(0);
            default: printf("\nEnter a valid input !!\n");
                     break;
        }
    }
    return 0;
}
void QInsert(node **Fhead,node **Rend,int *F,int *R,int n)
{
    if(*R==n-1)
    {
        printf("\nQueue is full!!\n");
        return;
    }
    node *nw;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(*R==-1)
    {
        *F=*R=0;
        *Fhead=nw;
        *Rend=nw;
    }
    else
    {
        *R+=1;
        node *ptr=*Rend;
        ptr->next=nw;
        *Rend=nw;
    }
    printf("\nInserted Successfully!!\n");
    return;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=NULL;
    return nw;
}
void Display(node **Fhead,node **Rend,int *F,int *R)
{
    if(*R==-1)
    {
        printf("\nThe queue is empty!!\n");
        return;
    }
    printf("\nThe queue is : ");
    int i=*F;
    node *ptr=*Fhead;
    for(;i<=*R;i++)
    {
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}
void QDelete(node **Fhead,node **Rend,int *F,int *R)
{
    if(*F==-1)
    {
        printf("\nQueue is Empty!!\n");
        return;
    }
    if(*F==*R)
    {
        *F=*R=-1;
        *Fhead=NULL;
        *Rend=NULL;
    }
    else
    {
        *F+=1;
        node *ptr;
        ptr=*Fhead;
        ptr=ptr->next;
        *Fhead=ptr;
    }
    printf("\nDeleted Successfully!!\n");
    return;
}