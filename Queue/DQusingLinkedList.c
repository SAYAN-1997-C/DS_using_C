#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next; 
}node;

void QInsertRear(node **,node **,int *,int *,int );
void QInsertFront(node **,node **,int *,int *,int );
void Display(node **,node **,int *,int *);
node* getNode(int );
void QDeleteFront(node **,node **,int *,int *);
void QDeleteRear(node **,node **,int *,int *);

int main()
{
    node *Fhead=NULL,*Rend=NULL;
    int F=-1,R=-1,n,ch;
    printf("\nEnter the size of the queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Insert into Rear\n2.Delete from Front\n3.Insert into Front\n4.Delete from Rear\n5.Display\n6.Exit\nEnter our choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : QInsertRear(&Fhead,&Rend,&F,&R,n);
                     break;
            case 2 : QDeleteFront(&Fhead,&Rend,&F,&R);
                     break;
            case 3 : QInsertFront(&Fhead,&Rend,&F,&R,n);
                     break;
            case 4 : QDeleteRear(&Fhead,&Rend,&F,&R);
                     break;
            case 5 : Display(&Fhead,&Rend,&F,&R);
                     break;
            case 6 : exit(0);
            default: printf("\nEnter a valid input !!\n");
                     break;
        }
    }
    return 0;
}
void QInsertRear(node **Fhead,node **Rend,int *F,int *R,int n)
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
void QInsertFront(node **Fhead,node **Rend,int *F,int *R,int n)
{
    if(*F==0)
    {
        printf("\nNot possible insert into front!!\n");
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
        *F-=1;
        //node *ptr=*Fhead;
        nw->next=*Fhead;
        //ptr->next=nw;
        *Fhead=nw;
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
void QDeleteFront(node **Fhead,node **Rend,int *F,int *R)
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
void QDeleteRear(node **Fhead,node **Rend,int *F,int *R)
{
    if(*R==-1)
    {
        printf("\nQueue is empty!!\n");
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
        *R-=1;
        node *ptr;
        ptr=*Fhead;
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
        *Rend=ptr;
    }
    printf("\nDeleted Successfully!!\n");
    return;
}