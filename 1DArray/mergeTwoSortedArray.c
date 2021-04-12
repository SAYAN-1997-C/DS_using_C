#include<stdio.h>
#include<stdlib.h>

void showArray(int *,int );
void merge_two_sorted_array(int *,int *,int ,int );

int main()
{
    int arr1[20],arr2[20],*final,i,n,m,f,j,k;
    printf("Enter the size of the first Array(sorted) : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("The first array is : ");
    showArray(arr1,n);
    printf("\nEnter the size of the second Array(sorted) : ");
    scanf("%d",&m);
    printf("Enter the elemets : ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("The second array is : ");
    showArray(arr2,m);
    merge_two_sorted_array(arr1,arr2,n,m);
    return 0;
}
void showArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
    puts("\n");
    return ;
}
void merge_two_sorted_array(int *arr1,int *arr2,int n,int m)
{
    int f,p=0,k=0,l=0,*final;
    f=m+n;
    final=(int *)malloc(f*sizeof(int));
    for(;k<n && l<m;)
    {
        if(arr1[k]>arr2[l])
        {
            *(final+p)=arr2[l];
            l++;
            p++;
        }
        else
        {
            *(final+p)=arr1[k];
            k++;
            p++;
        }
    }
    while(k<n)
    {
        *(final+p)=arr1[k];
        k++;
        p++;
    }
    while(l<n)
    {
        *(final+p)=arr2[l];
        l++;
        p++;
    }
    printf("After merged : ");
    showArray(final,p);
    return;
}