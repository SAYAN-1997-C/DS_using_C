#include<stdio.h>

void Display(int *,int );
void LinearSearch(int *,int ,int);

int main()
{
    int n,i,val,arr[10];
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nThe array is : ");
    Display(arr,n);
    printf("\nEnter the data do you want to search: ");
    scanf("%d",&val);
    LinearSearch(arr,n,val);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void LinearSearch(int *arr,int n,int val)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            printf("\nThe position of the data is : %d\n",i+1);
            return;
        }
    }
    printf("\nValue is not present into the array!!!\n");
    return;
}