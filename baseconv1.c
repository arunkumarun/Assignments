#include<stdio.h>

void baseconv(int num,int base)
{
	int count=0,rem,i;
	char val[40];
	while(num > 0)
	{
		rem = num % base;
		val[++count] = rem;
		num = num / base;
	}
	
	for(i =count; i>0 ; i--)
	{
		if(val[i]<10)
		{
			printf("%c",val[i]+'0');
		}
		else
		{
			printf("%c", val[i]+55);
		}
	}
}

int main()
{
	int num,base;
	
	printf("Enter the Number :");
	scanf("%d",&num);
	printf("Enter the base :");
	scanf("%d",&base);
	
	baseconv( num , base );
	
}
