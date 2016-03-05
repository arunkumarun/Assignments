#include<stdio.h>

void swap(int a[],int n,int h,int l,int b[])
{
	int i,j=0;
	for(i=h;i<n;i++)
	{
		b[j]=a[i];	
		j++;
	}
	if(n%2!=0)
	{
		b[l]=a[l];
		j++;
	}
	for(i=0;i<l;i++)
	{		
		b[j]=a[i];
		j++;
	}	
}

int main()
{
	int a[20],n,i,r,b[20],high,low;
	printf("\nEnter The size of array::");
	scanf("%d",&n);
	printf("\nEnter The Array::");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	

	r=n/2;
	if(n%2==0)
	{
		high=r;
		low=r;	
		swap(a,n,high,low,b);
	}
	else
	{
		high=r+1;
		low=r;	
		swap(a,n,high,low,b);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}

	return 0;
}
