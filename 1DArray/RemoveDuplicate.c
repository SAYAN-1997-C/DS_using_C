#include<stdio.h>

void showArray(int *,int );

int main()
{
    int n,arr[20],i,j,k;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is : ");
    showArray(arr,n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                for(k=j;k<n;k++)
                    arr[k]=arr[k+1];
                n=n-1;
                j--;
            }
        }
    }
    printf("\nAfter duplicate value deleted  : ");
    showArray(arr,n);
    puts("\n");
    return 0;
}
void showArray(int * arr,int n)
{
    int i=0;
    for(;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
}