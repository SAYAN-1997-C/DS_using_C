#include<stdio.h>

int main()
{
    int a[20],*b[20],n,rslt=0,i,x;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nThe Array is : ");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    for(i=0;i<n;i++)
    {
        b[i]=&a[i];
    }
    for(i=0;i<n;i++)
    {
        rslt+=*(*(b+i));
    }
    printf("\nThe sum of elements is : %d\n",rslt);
    return 0;
}