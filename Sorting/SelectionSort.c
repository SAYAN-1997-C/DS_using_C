#include<stdio.h>

void Display(int *,int );
void SelectionSort(int *,int );

int main()
{
    int n,i,arr[18];
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe Array is : ");
    Display(arr,n);
    printf("\nAfter sorting : ");
    SelectionSort(arr,n);
    Display(arr,n);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void SelectionSort(int *arr,int n)
{
    int i,j,min,pos,temp;
    for(i=0;i<n;i++)
    {
        min=arr[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(min > arr[j])
            {
                min=arr[j];
                pos=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
}