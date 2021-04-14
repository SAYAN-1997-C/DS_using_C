#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr,r,c,i,j;
    printf("\nEnter the number of row : ");
    scanf("%d",&r);
    printf("\nEnter the number of column : ");
    scanf("%d",&c);
    arr=(int *)malloc(r*c*sizeof(int));
    printf("\nEnter the elements : ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&*(arr+i*c+j));
        }
    }
    printf("\nThe matrix is : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",*(arr+i*c+j));
        }
        printf("\n");
    }
    printf("\nThe upper triangular matrix is : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i>j)
                printf("0\t");
            else
                printf("%d\t",*(arr+i*c+j));
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}