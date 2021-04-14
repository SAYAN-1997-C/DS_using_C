#include<stdio.h>

void SelectionSort(int *,int );

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
    SelectionSort(arr,n);
    return 0;
}
void SelectionSort(int *arr,int n)
{
    int min,pos,i,j,temp;
    for(i=0;i<n-1;i++)
    {
        min=*(arr+i);
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(*(arr+j) < min)
            {
                min=*(arr+j);
                pos=j;
            }
        }
        temp=*(arr+i);
        *(arr+i)=min;
        *(arr+pos)=temp;
    }
    printf("\nAfter sorted the array is : ");
    for(i=0;i<n;i++)
       printf("%d  ",*(arr+i));
    puts("\n");
    return;
}