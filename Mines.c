#include <stdio.h>

int a[6][6]={0}; //Initializes with zero
int i,j,x,y;

void displayBomb()
{
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%d   ",a[i][j]);
        }
        printf("\n");
    }
}


void checkBomb()
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;      //position of Y coordinate

    a[x][y]=-1;

    if((a[up][l]!= -1)&&(x!=0)&&(y!=0))
    {
        a[up][l]++;
    }
    if((a[up][eq]!= -1)&&(x!=0))
    {
        a[up][eq]++;
    }
    if((a[up][r]!= -1)&&(y!=5)&&(x!=0))
    {
        a[up][r]++;
    }
    if((a[equ][l]!= -1)&&(y!=0))
    {
        a[equ][l]++;
    }
    if((a[equ][r]!= -1)&&(y!=5))
    {
        a[equ][r]++;
    }
    if((a[low][l]!= -1)&&(y!=0)&&(x!=5))
    {
        a[low][l]++;
    }
    if((a[low][eq]!= -1)&&(x!=5))
    {
        a[low][eq]++;
    }
    if((a[low][r]!= -1)&&(y!=5)&&(x!=5))
    {
        a[low][r]++;
    }
}

int main(void)
{
	int n;
	printf("\nEnter the Number of Bomb");
	scanf("%d",&n);
	printf("\nEnter the Bomb Location:\n");
	for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        checkBomb();
    }

	displayBomb();

	return 0;
}
