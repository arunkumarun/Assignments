#include<stdio.h>

float Babylonian(int n,float y,float acc)
{
	float x=n;
	while(x-y>acc)
	{
		x=(x+y)/2;
		y=n/x;
	}
	return x;
}

int main()
{
	int n;
	float x,y=1,acc,root;
	acc=0.000001;  //For more accuracy
	
	printf("Enter the Number:");
	scanf("%d",&n);
	
	root=Babylonian(n,y,acc);
	
	printf("The root value is: %f",root);
	
	return 0;
}
