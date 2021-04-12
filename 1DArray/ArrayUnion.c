#include<stdio.h>

void showArray(int *,int );

int main()
{
    int arr1[20],arr2[20],m,n,i,j,k;
    printf("Enter the size of the first array : ");
    scanf("%d",&m);
    printf("Enter the elements : ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the size of the second array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("The 1st array : ");
    showArray(arr1,m);
    printf("\nThe 2nd array : ");
    showArray(arr2,n);
    puts("\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr1[i]==arr2[j])
            {
                for(k=j;k<n;k++)
                    arr2[k]=arr2[k+1];
                j--;
                n--;
            }
        }
    }
    printf("\nAfter Union : ");
    showArray(arr1,m);
    showArray(arr2,n);
    puts("\n");
    return 0;
}
void showArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",*(arr+i));
    }
    return ;
}