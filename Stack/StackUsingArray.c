#include<stdio.h>
#include<stdlib.h>

void Push(int *,int *,int );
void Display(int *,int );
void Pop(int *,int *);

int main()
{
    int *Arr,n,top=-1,ch;
    printf("\nEnter the size of the stack : ");
    scanf("%d",&n);
    Arr=(int *)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.peek\n4.Display\n5.Exit\nEnter your hoice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : Push(Arr,&top,n);
                     break;
            case 2 : Pop(Arr,&top);
                     break;
            case 3 :if(top==-1)
                        printf("\nStack is Empty!!");
                    else 
                        printf("\nThe peek value is : %d\n",Arr[top]);
                     break;
            case 4 : Display(Arr,top);
                     break;
            case 5 : exit(0);
                     break;
            default: printf("\nEnter a valid input\n");
                     break;
        }
    }
}
void Push(int *Arr,int *top,int n)
{
    if(*top == (n-1))
    {
        printf("\nStack is Full!!");
        return;
    }
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    Arr[++(*top)]=val;
    printf("\nPushed Successfully!!");
    return;
}
void Pop(int *Arr,int *top)
{
    if(*top == -1)
    {
        printf("\nStack is already empty!!\n");
        return;
    }
    printf("\nThe poped value is : %d\n",Arr[*top]);
    *top=*top-1;
    return;
}
void Display(int *Arr,int top)
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
        printf("\n%d",*(Arr+i));
    }
    printf("\n");
    return;
}