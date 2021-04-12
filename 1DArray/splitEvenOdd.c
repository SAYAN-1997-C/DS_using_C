#include<stdio.h>

void showArray(int *,int );

int main()
{
    int arr[20],even[20],odd[20],e=0,o=0,i,n;
    printf("Enter size of the array : ");
    scanf("%d",&n);
    printf("Enter the elemests : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The Array is : ");
    showArray(arr,n);
    for(i=0;i<n;i++)
    {
        if( (arr[i]%2) == 0 )
        {
            even[e++]=arr[i];
        }
        else
        {
            odd[o++]=arr[i];
        }
    }
    printf("\nThe even array is : ");
    showArray(even,e);
    printf("\nThe odd array is : ");
    showArray(odd,o);
    puts("\n");
    return 0;
}

void showArray(int *arr,int n)
{
    int i=0;
    for(i=-0;i<n;i++)
    {
        printf("%d  ",*(arr+i));
    }
    return;
}