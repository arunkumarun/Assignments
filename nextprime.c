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
	
	if(a == i )
	{
		printf("\n%d",a);
	}
	
	return 0;
}
