#include<stdio.h>

int main()
{
    int arr[20][20],r,c,i,j,determinant=0;
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
    determinant=(arr[0][0]*((arr[1][1]*arr[2][2])-(arr[1][2]*arr[2][1])))-(arr[0][1]*((arr[1][0]*arr[2][2])-(arr[1][2]*arr[2][0])))+(arr[0][2]*((arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0])));
    printf("\nDeterminant is : %d\n",determinant);
    return 0;
}