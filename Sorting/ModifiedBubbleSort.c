#include<stdio.h>

void Display(int *,int );
void BubbleSort(int *,int );

int main()
{
    int n,i,arr[18];
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe Array is : ");
    Display(arr,n);
    printf("\nAfter sorting : ");
    BubbleSort(arr,n);
    Display(arr,n);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void BubbleSort(int *arr,int n)
{
    int i,j,temp,flag=1;
    for(i=0;i<n-1&&flag=1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}