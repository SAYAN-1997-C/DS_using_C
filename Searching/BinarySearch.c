#include<stdio.h>

void Display(int *,int );
void BinarySearch(int *,int ,int);

int main()
{
    int n,i,val,arr[10];
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe array is : ");
    Display(arr,n);
    printf("\nEnter the data do you want to search: ");
    scanf("%d",&val);
    BinarySearch(arr,n,val);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void BinarySearch(int *arr,int n,int val)
{
    int lb,ub,mid;
    lb=0;ub=n-1;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(arr[mid]==val)
        {
            printf("\nThe position of the data is : %d\n",mid+1);
            return;
        }
        if(arr[mid]>val)
            ub=mid-1;
        else
            lb=mid+1;
    }
    printf("\nValue is not present into the array!!!\n");
    return;
}