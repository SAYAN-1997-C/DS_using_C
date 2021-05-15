#include<stdio.h>
#include<stdlib.h>

void QInsertRear(int *,int *,int *,int );
void Display(int *,int *,int *);
void QDeleteFront(int *,int *,int *);
void QInsertFront(int *,int *,int *,int );
void QDeleteRear(int *,int *,int *);

int main()
{
    int n,*arr,F=-1,R=-1,ch;
    printf("\nEnter the size of the Queue : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n1.Insert into Rear\n2.Delete from Front\n3.Insert into Front\n4.Delete from Rear\n5.Display\n6.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : QInsertRear(arr,&F,&R,n);
                     break;
            case 2 : QDeleteFront(arr,&F,&R);
                     break;
            case 3 : QInsertFront(arr,&F,&R,n);
                     break;
            case 4 : QDeleteRear(arr,&F,&R);
                     break;
            case 5 : Display(arr,&F,&R);
                     break;
            case 6 : exit(0);
            default: printf("\nEnter a valid input !!");
                     break;
        }
    }
    return 0;
}
void QInsertRear(int *arr,int *F,int *R,int n)
{
    if(*R==n-1)
    {
        printf("\nQueue is Full!!\n");
        return;
    }
    printf("\nEnter the element : ");
    int val;
    scanf("%d",&val);
    if(*F==-1 && *R==-1)
    {
        *F=*R=0;
        *(arr+*R)=val;
    }
    else
    {
        *R+=1;
        *(arr+*R)=val;
    }
    printf("\nInserted Successfully!!!\n");
    return;
}
void QInsertFront(int *arr,int *F,int *R,int n)
{
    if(*F==0)
    {
        printf("\nNot Possible insert into front!!\n");
        return;
    }
    printf("\nEnter the element : ");
    int val;
    scanf("%d",&val);
    if(*F==-1 && *R==-1)
    {
        *F=*R=0;
        *(arr+*R)=val;
    }
    else
    {
        *F-=1;
        *(arr+*F)=val;
    }
    printf("\nInserted Successfully!!!\n");
    return;
}

void Display(int *arr,int *F,int *R)
{
    if(*F==-1 && *R==-1)
    {
        printf("\nQueue is Empty!!\n");
        return;
    }
    printf("\nThe Queue is : ");
    int i=*F;
    for(;i<=*R;i++)
        printf("%d --> ",*(arr+i));
    printf("\n");
}
void QDeleteFront(int *arr,int *F,int *R)
{
    if(*F==-1)
    {
        printf("\nQueue is already empty!!\n");
        return;
    }
    if(*F==*R)
        *F=*R=-1;
    else
        *F+=1;
    printf("\nDeleted Successfully!!\n");
    return;
}
void QDeleteRear(int *arr,int *F,int *R)
{
    if(*F==-1)
    {
        printf("\nQueue is already empty!!\n");
        return;
    }
    if(*F==*R)
        *F=*R=-1;
    else
        *R-=1;
    printf("\nDeleted Successfully!!\n");
    return;
}