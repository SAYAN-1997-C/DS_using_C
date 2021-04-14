#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int *,int );

int main()
{
    int *arr,i,j,n,chk=1;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&(*(arr+i)));
    printf("\nThe Array is : ");
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));
    chk=BinarySearch(arr,n);
    if(chk==0)
        printf("\nElement is not present in the list !!!\n");
    return 0;   
}
int BinarySearch(int *arr,int n)
{
    int lb=0,ub=n-1,mid,val;
    printf("\nEnter the Element you want to search : ");
    scanf("%d",&val);
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(*(arr+mid)==val)
        {
            printf("\nThe position of the element is : %d\n",mid+1);
            return 1;
        }
        if(*(arr+mid)>val)
            ub=mid-1;
        if(*(arr+mid)<val)
            lb=mid+1;
    }
    return 0;
}