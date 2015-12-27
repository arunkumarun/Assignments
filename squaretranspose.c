#include<stdio.h>

int main()
{
		int arr[10][10],i,j,order,temp;
		
		//Getting matrix order
		printf("\nEnter the matrix Order:");
		scanf("%d",&order);
		
		//Getting Square Matrix Value
		printf("Enter the %d x %d matrix value:\n",order,order);
		for(i = 0;i < order;i++)
		{
			for(j = 0;j < order;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		
		//Self Transposal of Square Matrix
		for(i = 0;i < order;i++)
		{
			for(j = 0;j < i;j++)
			{
				if(i!=j)
				{
					temp = arr[i][j];
					arr[i][j] = arr[j][i];
					arr[j][i] = temp;
				}
			}
		}
		
		//Displaying Transposed Matrix
		printf("\nThe Transposed matrix is:\n");
		for(i = 0;i < order;i++)
		{
			for(j = 0;j < order;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		
		return 0;
}
