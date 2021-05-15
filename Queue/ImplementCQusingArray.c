#include<stdio.h>
#include<stdlib.h>

void CQinsert(int *,int ,int *,int *);
void CQdisplay(int *,int ,int ,int );
void CQdelete(int *,int ,int *,int *);

int main()
{
    int n,*arr,F=-1,R=-1,ch;
    printf("\nEnter the size of the queue : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter tour choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : CQinsert(arr,n,&F,&R);
                     break;
            case 2 : CQdelete(arr,n,&F,&R);
                     break;
            case 3 : CQdisplay(arr,n,F,R);
                     break; 
            case 4 : exit(0);
            default: printf("\nEnter a valid input !!!");
                     break;
        }
    }
    return 0;
}
void CQinsert(int *arr,int n,int *F,int *R)
{
    int f,r,val;
    f=*F;
    r=*R;
    if(f==(r+1)%n){
        printf("\nQueue is full!!\n");
        return ;
    }
    printf("\nEnter the data : ");
    scanf("%d",&val);
    if(f==-1 && r==-1){
        f=r=0;
        arr[f]=val;
    }
    else{
        r=(r+1)%n;
        arr[r]=val;
    }
    *F=f;*R=r;
    printf("\nInserted successfully!!!!\n");
    return;
}
void CQdelete(int *arr,int n,int *F,int *R)
{
    int f,r;
    f=*F;r=*R;
    if(f==-1 && r==-1)
    {
        printf("\nQueue is already empty!!");
        return;
    }
    if(f==r)
        f=r=-1;
    else
        f=(f+1)%n;
    *F=f;*R=r;
    printf("\nDeleted Successfully!!!!");
    return;
}
void CQdisplay(int *arr,int n,int f,int r)
{
    if(f==-1 && r==-1)
    {
        printf("\nQueue is empty!!!");
        return;
    }
    printf("\nThe Queue is : ");
    while(f != r)
    {
        printf("%d  ",*(arr+f));
        f=(f+1)%n;
    }
    printf("%d",*(arr+r));
    printf("\n");
}