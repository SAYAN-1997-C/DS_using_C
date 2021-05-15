#include<stdio.h>
#include<stdlib.h>

void QInsert(int *,int *,int *,int );
void Display(int *,int *,int *);
void QDelete(int *,int *,int *);
 
int main()
{
    int n,*arr,F=-1,R=-1,ch;
    printf("\nEnter the size of the Queue : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : QInsert(arr,&F,&R,n);
                     break;
            case 2 : QDelete(arr,&F,&R);
                     break;
            case 3 : Display(arr,&F,&R);
                     break;
            case 4 : exit(0);
            default: printf("\nEnter a valid input !!");
                     break;
        }
    }
    return 0;
}
void QInsert(int *arr,int *F,int *R,int n)
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
void QDelete(int *arr,int *F,int *R)
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