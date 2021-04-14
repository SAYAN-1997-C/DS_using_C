#include<stdio.h>
int LinearSearch(int *,int );


int main()
{
    int arr[20],i,n,flag;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe Array is : ");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    flag=LinearSearch(arr,n);
    if(flag==0)
        printf("\nElement is not present in the array!!\n");
    else
        printf("\nElement is present at position : %d\n",flag);
    return 0;
}
int LinearSearch(int *arr,int n)
{
    int i,val;
    printf("\nEnter the element you want to search : ");
    scanf("%d",&val);
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
            return i+1;
    }
    return 0;
}