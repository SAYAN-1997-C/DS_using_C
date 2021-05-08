#include<stdio.h>

void Display(int *,int );
void HeapSort(int *,int );
void Heapify(int *,int ,int );
void Swap(int *,int *);

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
    HeapSort(arr,n);
    Display(arr,n);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void HeapSort(int *arr,int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)//create Heap
        Heapify(arr,n,i);

    for(i=n-1;i>0;i--)
    {
        Swap(&arr[0],&arr[i]);
        Heapify(arr,i,0);
    }
}
void Heapify(int *arr,int n,int i)
{
    int largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if( l<n && arr[l]>arr[largest])
        largest=l;
    if( r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        Swap(&arr[i],&arr[largest]);
        Heapify(arr,n,largest);
    }
}
void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}