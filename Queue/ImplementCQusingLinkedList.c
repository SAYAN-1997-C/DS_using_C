#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *next;
}node;
void CQinsert(node **,node **,int *,int *,int );
node* getNode(int );
void Display(node **,node **,int *,int *,int );
void CQdelete(node **,node **,int *,int *,int );

int main()
{
    int n,F=-1,R=-1,ch;
    node *Fhead=NULL,*Rend=NULL;
    printf("\nEnter the size of the queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : CQinsert(&Fhead,&Rend,&F,&R,n);
                     break;
            case 2 : CQdelete(&Fhead,&Rend,&F,&R,n);
                     break;
            case 3 : Display(&Fhead,&Rend,&F,&R,n);
                     break;
            case 4 : exit(0);
            default: printf("\nEnter a valid input!!");
                     break; 
        }
    }
    return 0;
}
void CQinsert(node **Fhead,node **Rend,int *F,int *R,int n)
{
    node *fh,*re,*nw;
    int f,r,val;      
    f=*F;r=*R;fh=*Fhead;re=*Rend;
    if(f==(r+1)%n)
    {
        printf("\nQueue is full!!\n");
        return;
    }
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(f==-1 && r==-1)
    {
        f=r=0;
        fh=nw;
        re=nw;
    }
    else
    {
        r=(r+1)%n;
        re->next=nw;
        re=nw;
    }
    *Fhead=fh;*Rend=re;*F=f;*R=r;
    printf("\nInserted Successfully!!\n");
    return ;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=NULL;
    return nw;
}
void Display(node **Fhead,node **Rend,int *F,int *R,int n)
{
    node *fh,*re;
    int f,r;
    fh=*Fhead;re=*Rend;f=*F;r=*R;
    if(f==-1 && r==-1)
    {
        printf("\nQueue is already empty!!");
        return;
    }
    printf("\nThe queue is : ");
    while(f!=r)
    {
        printf("%d --> ",fh->data);
        fh=fh->next;
        f=(f+1)%n;
    }
    printf("%d\n",re->data);
    return;   
}
void CQdelete(node **Fhead,node **Rend,int *F,int *R,int n)
{
    node *fh,*re;
    int f,r;
    fh=*Fhead,re=*Rend,f=*F,r=*R;
    if(f==-1 && r==-1)
    {
        printf("\nQueue is already is empty!!");
        return;
    }
    if(f==r)
    {
        fh=NULL;re=NULL;
        f=r=-1;
    }
    else
    {
        fh=fh->next;
        f=(f+1)%n;
    }
    *Fhead=fh;*Rend=re;*F=f;*R=r;
    printf("\nDeleted Successfully!!");
    return;
}