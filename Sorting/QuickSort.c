#include<stdio.h>

void Display(int *,int );
void quickSort(int *, int , int );
int partition (int *, int , int );
void swap(int *, int *);

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
    quickSort(arr,0,n-1);
    Display(arr,n);
    return 0;
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}