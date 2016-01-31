#include<stdio.h>

int main()
{
	int a=0,b=1,c,i,n;
	printf("Enter the number:");
	scanf("%d",&n);
	
	c=a+b;
	printf("\nThe value is:\n");
	while(n>0)
	{
		a=b;
		b=c;
		c=a+b;
		if(c>n)
		{
			n=n-b;
			printf("%d\t",b);
			a=0;
			b=1;
			c=a+b;
		}
	}
}
