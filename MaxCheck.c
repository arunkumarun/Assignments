#include<stdio.h>

int main()
{
	int a[20],i,n,x,key=-1;
	printf("\nEnter The size of array::");
	scanf("%d",&n);
	printf("\nEnter The Sorted Array::");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	printf("\nEnter The X value::");
	scanf("%d",&x);

	for(i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			if(a[i]<a[i+1])
			{
				key=i;
				break;
			}
			else if(a[i] == a[i+1])
			{
				key=i+1;
				break;
			}	
		}
	}

	printf("\nThe Index is: %d",key);
	
	return 0;
}
