#include <stdio.h>

int recurs=1,rev=0;

int power(int x,int y)
{
    int squ=1;
    while(y>0)
    {
        squ=squ*x;
        y--;
    }
    return squ;
}

int reverse(int a,int m)
{
    int rem,i=0,temp=0,r;
    if(recurs<=2)
    {
        rev=0;
        while(i<m)
        {
            rem=a%10;
            rev=rev*10+rem;
            a=a/10;
            i++;
        }
        recurs++;
        r=rev;
        reverse(r,m);
    }
    return rev;
}

int front(int a,int m)
{
    int i=0,rem;
    while(i<m)
    {
        rem=a%10;
        rev=rev*10+rem;
        a=a/10;
        i++;
    }
    return a;
}

int midd(int a,int m)
{
    int i=0,middle,rem;
    while(i<m)
    {
        rem=a%10;
        middle=rem;
        a=a/10;
        i++;
    }
    return middle;
}

int main()
{
	int mid,num,rem,range,rev=0,temp,temp1,i=0,count=0,mul,first,cent;
	printf("\nEnter a number::::");
	scanf("%d",&num);
	temp=temp1=num;
	while(temp1>0)
	{
	    temp1=temp1/10;
	    count++;
	}
    mid=count/2;
    if(count%2==0)
    {
        rev=reverse(temp,mid);
        first=front(temp,mid);
        range=(count-mid);
        mul=power(10,range);
        rev=rev*mul;
        rev=rev+first;
    }
    else
    {
        rev=reverse(temp,mid);
        first=front(temp,mid+1);
        cent=midd(temp,mid+1);
        range=(count-mid);
        mul=power(10,range);
        rev=rev*mul;
        mul=power(10,range-1);
        cent=cent*mul;
        rev=rev+cent+first;
    }
    printf("\nBefore Swap is:: %d",num);
	printf("\nAfter Swap  is:: %d",rev);
	return 0;
}
