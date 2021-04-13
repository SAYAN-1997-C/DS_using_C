#include<stdio.h>

int main()
{
    int arr[20][20],r,c,i,j,x,y,temp;
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
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the two rows : ");
    scanf("%d%d",&x,&y);
    x=x-1;
    y=y-1;
    for(i=0;i<c;i++)
    {
        temp=arr[x][i];
        arr[x][i]=arr[y][i];
        arr[y][i]=temp;
    }
    printf("\nAfter interchange the matrix is  : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}