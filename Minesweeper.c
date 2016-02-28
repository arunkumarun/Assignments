#include <stdio.h>
#include<stdlib.h>

int a[6][6]={0},b[6][6]={0}; //Initializes with zero
int x,y;
void display()
{
    int i,j;
    for(i=0;i<6;i++)
    {
        printf("-------------------------------\n");
        for(j=0;j<6;j++)
        {
            printf("| %d |",a[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}
void displayBomb()
{
    int i,j;
    for(i=0;i<6;i++)
    {
        printf("-------------------------------\n");
        for(j=0;j<6;j++)
        {
            printf("| %d |",b[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

void showMine(int x,int y)
{
    b[x][y] = a[x][y];
}


void showField(int x,int y)
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;//position of Y coordinate

    b[x][y]=a[x][y];
    if((a[up][l]!= -1)&&(x!=0)&&(y!=0))
    {
        b[up][l]=a[up][l];
        if(a[up][l] == 0)
        {
            showField(up,l);
        }
    }
    if((a[up][eq]!= -1)&&(x!=0))
    {
        b[up][eq]=a[up][eq];
        if(a[up][eq] == 0)
        {
            showField(up,eq);
        }
    }
    if((a[up][r]!= -1)&&(y!=5)&&(x!=0))
    {
        b[up][r]=a[up][r];
        if(a[up][r] == 0)
        {
            showField(up,r);
        }
    }
    if((a[equ][l]!= -1)&&(y!=0))
    {
        b[equ][l]=a[equ][l];
    }
    if((a[equ][r]!= -1)&&(y!=5))
    {
        b[equ][r]=a[equ][r];
    }
    if((a[low][l]!= -1)&&(y!=0)&&(x!=5))
    {
        b[low][l]=a[low][l];
    }
    if((a[low][eq]!= -1)&&(x!=5))
    {
        b[low][eq]=a[low][eq];
    }
    if((a[low][r]!= -1)&&(y!=5)&&(x!=5))
    {
        b[low][r]=a[low][r];
    }
}

void bombLocation()
{
    int k=1,i,j,n=8,key;
    while(k<n)
    {
        i=rand()%6;
        j=rand()%6;
        key=checkBomb(i,j);
        if(key==-1)
        {
            n++;
        }
        k++;
    }
}

int checkBomb(int x,int y)
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;      //position of Y coordinate

    if(a[x][y]==-1)
    {
        return -1;
    }
    else
    {
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
}

int main(void)
{
    int i,j;
	bombLocation();
    display();  //display the bomb array

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            b[i][j] = 9;       //Initializing array to 9
        }
    }

    while(1)
    {
        printf("\nEn ter the index you wanna click::");
        scanf("%d%d",&x,&y);
        system("cls");                              //Clear the screen
        if(a[x][y] == -1)//Bomb is clicked
        {
            printf("\nGame Over -_- -_-\n");
            display();
            break;
        }
        else if(a[x][y] == 0)//Empty place is clicked
        {
            showField(x,y);
            displayBomb();
        }
        else
        {
            showMine(x,y);
            displayBomb();
        }

    }
    return 0;
}
