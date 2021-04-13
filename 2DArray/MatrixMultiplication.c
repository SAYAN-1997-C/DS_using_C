#include<stdio.h>

int main()
{
    int arr1[10][10],arr2[10][10],r1,c1,r2,c2,i,j,k,sum;
    printf("\nEnter the number of rows(1st Matrix): ");
    scanf("%d",&r1);
    printf("\nEnter the number of columns(1st Matrix): ");
    scanf("%d",&c1);
    printf("\nEnter the elements : ");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\nEnter the number of rows(2nd Matrix): ");
    scanf("%d",&r2);
    printf("\nEnter the number of columns(2nd Matrix): ");
    scanf("%d",&c2);
    while((c1!=r2))
    {
        printf("\nRe-Enter!!If column1 and row2  are same then multiplication is possible..");
        printf("\nEnter the number of rows(2nd Matrix): ");
        scanf("%d",&r2);
        printf("\nEnter the number of columns(2nd Matrix): ");
        scanf("%d",&c2);
    }
    printf("\nEnter the elements : ");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\n1st Matrix is : \n");
    for ( i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n2nd Matrix is : \n");
    for ( i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    printf("\nThe resultant matrix is : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            sum=0;
            for(k=0;k<r2;k++)
            {
                sum+=arr1[i][k]*arr2[k][j];
            }
            printf("%d\t",sum);
        }
        printf("\n");
    }
    return 0;
}