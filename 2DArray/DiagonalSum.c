#include<stdio.h>

int main()
{
    int arr[20][20],r,c,i,j,pSum,sSum;
    printf("\nEnter the number of rows : ");
    scanf("%d",&r);
    printf("\nEnter the number of columns : ");
    scanf("%d",&c);
    while(r!=c)
    {
        printf("\nMatrix should be square..So Re-Enter");
        printf("\nEnter the number of rows : ");
        scanf("%d",&r);
        printf("\nEnter the number of columns : ");
        scanf("%d",&c);
    }
    printf("\nEnter the elements : ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nThe matrix is  : \n");
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
            if(i==j)
                pSum+=arr[i][j];
            if((i+j)==(r-1))
                sSum+=arr[i][j];
        }
    }
    printf("\nPrimary Diagonal sum is : %d",pSum);
    printf("\nSecondary Diagonal sum is : %d\n",sSum);
    return 0;
}