#include<stdio.h>

int main()
{
    int arr[20][20],r,c,i,j,Zcount=0,NZcount=0;
    printf("\nEnter the number of rows : ");
    scanf("%d",&r);
    printf("\nEnter the number of columns : ");
    scanf("%d",&c);
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
            if(arr[i][j]==0)
                Zcount++;
            else
                NZcount++;
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    if(Zcount>NZcount)
        printf("\nMatrix is sparse!!\n");
    else
        printf("\nMatrix is not sparse!!\n");
    return 0;
}