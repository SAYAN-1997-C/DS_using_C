#include<stdio.h>
#include<stdlib.h>

void Push(int *,int *,int );
void Display(int *,int );
int Pop(int **,int ,int );

int main()
{
    int *q1,top=-1,n,ch;
    printf("\nEnter the size of the stack : ");
    scanf("%d",&n);
    q1=(int *)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : Push(q1,&top,n);
                     break;
            case 2 : top=Pop(&q1,top,n);
                     break;
            case 4 : Display(q1,top);
                     break;
            case 5 : exit(0);
            default: printf("\nEnter a valid input!!\n");
                     break;

        }
    }
    return 0;
}
void Push(int *q1,int *top,int n)
{
    if(*top == n-1)
    {
        printf("\nStack is full!!\n");
        return;
    }
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    *top+=1;
    *(q1+*(top))=val;
    printf("\nInserted Successfully!!");
    return;
}
void Display(int *q1,int top)
{
    if(top==-1)
    {
        printf("\nStack is Empty!!");
        return;
    }
    printf("\nThe stack is : ");
    int i=top;
    for(;i>=0;i--)
    {
        printf("\n%d",*(q1+i));
    }
    printf("\n");
    return;
}
int Pop(int **q1,int top,int n)
{
    int f=0;
    int *q2;
    if(top == -1)
    {
        printf("\nStack is empty!!\n");
        return top;
    }
    q2=(int *)malloc(top*sizeof(int));
    for(;f<top;f++)
    {
        q2[f]=*(*q1+f);
    }
    printf("\nPoped data element is : %d",*(*q1+top));
    top-=1;
    *q1=q2;
    printf("\nPoped Successfully!!\n");
    return top;
}