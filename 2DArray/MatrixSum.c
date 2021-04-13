#include<stdio.h>

int main()
{
    int r,c,i,j,arr[20][20],sum=0;
    printf("Enter the number of rows : ");
    scanf("%d",&r);
    printf("\nEnter the numbrr of columns : ");
    scanf("%d",&c);
    printf("\nEnter the values : " );
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nThe matrix is : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            sum=sum+arr[i][j];
        }
    }
    printf("\nThe sum of matrix is : %d\n",sum);
    return 0;
}