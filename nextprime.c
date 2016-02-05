#include<stdio.h>

int main()
{
	int a,i=2,n;
	
	printf("Enter the Number:");
	scanf("%d",&n);
	a=n+1;
	
	while(i <= a)
	{   
		if(a==i)
		{
			break;
		}
		if(a%i==0)
		{
			i=2;
			a++;
		}
			
		i++;
	}
	
	if(n==0)
	{
		printf("\n%d",2);
	}
	else
	{
		printf("\n%d",a);
	}
	return 0;
}
