#include<stdio.h>

int main()
{
	int arr[50],max,min,n,i;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}	
	printf("The array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	min=max=arr[i];
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	printf("\nThe max value is : %d\nThe min value is : %d\n",max,min);
}
