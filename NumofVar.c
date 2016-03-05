#include<stdio.h>
#include<ctype.h>
#include<string.h>

int charCheck(char b[],int n)
{
	int i,j,k,count=0;
	for(i=0;i<n;i++)		//Removes The Same Element
	{
		for(j=i+1;j<n;)
		{
			if(b[i] == b[j])
			{
				for(k=j;k<n;k++)
				{
					b[k]=b[k+1];
				}
				n--;
			}
			else
			{
				j++;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		count++;
	}

	return count;
}


int main()
{
	char a[20],b[20],count;
	int len,i,j=0;
	printf("\nEnter The Equation::");
	scanf("%s",a);
	len=strlen(a);
	
	for(i=0;i<len;i++)
	{
		if(isalpha(a[i]))
		{
			b[j]=a[i];
			j++;
		}
	}

	count = charCheck(b,j);	
	
	printf("\nThe Number of Variable is :%d\n",count);

	return 0;
}
