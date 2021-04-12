#include<stdio.h>
void showArray(int *,int );
int main()
{
    int arr[20],n,i,j,pos,val;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is : ");
    showArray(arr,n);
    printf("\nEnter the position do you want to insert : ");
    scanf("%d",&pos);
    printf("\nEnter the values : ");
    scanf("%d",&val);
    if(pos>n+1 || pos<1)
    {
        printf("\nPosition is not available..");
        return 0;
    }
    for(i=n;i>=pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=val;
    printf("After inserted the array is : ");
    showArray(arr,n+1);
    puts("\n");
    return 0;
}
void showArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return;
}