#include<stdio.h>
#include<ctype.h>
#include<string.h>

char a[30],b[30],d[30][30]={' '},e[30],dup[30][30]={' '};
int r=0,c=0,i,j=0,k,len,count,size;

void check()
{
	int i,j,k=0;
	count=r;
	for(i=0;i<r;i++)
	{
		strcpy(dup[i],d[i]);
		for(j=i+1;j<r;j++)
		{
			if(!strcmp(d[i],d[j]))
			{
				count--;
				break;
			}
			else
			{
				strcpy(dup[i],d[i]);
			}
		}
	}
}

int main()
{	
	printf("\nEnter The Equation::");
	scanf("%s",a);
	len=strlen(a);
	
	for(i=0;i<len;i++)
	{
		if(isalpha(a[i]) || isdigit(a[i]))
		{
				b[j]=a[i];
				j++;
		}
		else
		{
			b[j]='_';
			j++;
		}
	}
	b[j]='\0';

	for(i=0;b[i]!='\0';i++)
	{
		if(isalpha(b[i]))
		{
			d[r][0]=b[i];
			for(k=0;(b[i]!='_')&&(b[i]!='\0');k++)
			{
				d[r][k]=b[i];
				i++;
			}
			d[r][k]='\0';
			r++;
		}
	}
	check();
	/*printf("\n%s\n",b);

	for(i=0;i<r;i++)
	{
		for(k=0;k<30;k++)
		{
			printf("%c ",d[i][k]);		
		}
		printf("\n");
	}
	*/
	/*printf("\nAfter Removal::\n");
	for(i=0;i<count;i++)
	{
		for(k=0;k<30;k++)
		{
			printf("%c ",dup[i][k]);		
		}
		printf("\n");
	}*/
	printf("\nNumber Of Variable is::%d\n",count);

	return 0;
}
