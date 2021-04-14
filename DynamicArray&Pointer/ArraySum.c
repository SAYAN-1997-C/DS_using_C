#include<stdio.h>

int sum(int *,int );

int main()
{
    int arr[20],n,rslt=0,i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe Array is : ");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    rslt=sum(arr,n);
    printf("\nThe sum of the array is : %d\n",rslt);
    return 0;
}
int sum(int *arr,int n)
{
    int rslt=0,i;
    for(i=0;i<n;i++)
        rslt +=*(arr+i);
    return rslt;
}