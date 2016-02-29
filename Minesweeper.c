#include <stdio.h>
#include <stdlib.h>

int a[6][6]={0},b[6][6],bomb[6][6]={0},move[6][6]={0}; //Initializes with zero
int x,y,count=1,moveKey;	//Count for the number of clicks
				
void zeroCheckUp(int x,int y)	//This function checks top of x,y for zero
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;//position of Y coordinate
    if((a[up][l]!= -1)&&(x!=0)&&(y!=0))
    {
        b[up][l]=a[up][l];
        if(a[up][l] == 0)
        {
            zeroCheckUp(up,l);
        }
    }
    if((a[up][eq]!= -1)&&(x!=0))
    {
        b[up][eq]=a[up][eq];
        if(a[up][eq] == 0)
        {
            zeroCheckUp(up,eq);
        }
    }
    if((a[up][r]!= -1)&&(y!=5)&&(x!=0))
    {
        b[up][r]=a[up][r];
        if(a[up][r] == 0)
        {
            zeroCheckUp(up,r);
        }
    }
}

void zeroCheckEqu(int x,int y)	//This function checks left and right of x,y for zero
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;//position of Y coordinate
    if((a[equ][l]!= -1)&&(y!=0))
    {
        b[equ][l]=a[equ][l];
        if(a[equ][l] == 0)
        {
            zeroCheckEqu(equ,l);
        }
    }
    if((a[equ][r]!= -1)&&(y!=5))
    {
        b[equ][r]=a[equ][r];
        if(a[equ][r] == 0)
        {
            zeroCheckEqu(equ,r);
        }
    }
}

void zeroCheckDown(int x,int y)	//This function checks down of x,y for zero
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;//position of Y coordinate
    if((a[low][l]!= -1)&&(y!=0)&&(x!=5))
    {
        b[low][l]=a[low][l];
        if(a[low][l] == 0)
        {
            zeroCheckDown(low,l);
        }
    }
    if((a[low][eq]!= -1)&&(x!=5))
    {
        b[low][eq]=a[low][eq];
        if(a[low][eq] == 0)
        {
            zeroCheckDown(low,eq);
        }
    }
    if((a[low][r]!= -1)&&(y!=5)&&(x!=5))
    {
        b[low][r]=a[low][r];
        if(a[low][r] == 0)
        {
            zeroCheckDown(low,r);
        }
    }
}

void displayBomb(int disp[][6])		//Display the MineField to the User
{
    int i,j;
    for(i=0;i<6;i++)
    {
        printf("-------------------------------\n");
        for(j=0;j<6;j++)
        {
            printf("| %d |",disp[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

void showZero(int x,int y)		//Checks the zero condition
{
    b[x][y]=a[x][y];
    
    zeroCheckUp(x,y);
    zeroCheckEqu(x,y);
    zeroCheckDown(x,y);
}

void showMine(int x,int y)	//Stores the Clicked index to B-array
{
    b[x][y] = a[x][y];
}

int checkMove()		//Checks whether the position is already clicked
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(b[i][j] != 9)
            {
                move[i][j]=1;
            }
        }
    }
    if(move[x][y]==1)
    {
        return -1;
    }
}

void checkCount()	//Check the count for winning condition
{
    int i,j;
    count=1;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(b[i][j] != 9)
            {
                count++;
            }
        }
    }
}

void play()		//Beginning of Game
{
    while(1)
    {
        printf("\nEnter the index you wanna click::");
        scanf("%d%d",&x,&y);
        system("cls");	//Clear the screen
        moveKey=checkMove(x,y);
        if(moveKey == -1)
        {
            printf("\nThis Location is Clicked\n");
            displayBomb(b);
        }
        else
        {
            checkCount();
            if(count < 26)	//Here 26 means the number of free spaces (6*6-10(mines)=26)
            {
                if(a[x][y] == -1)//Bomb is clicked
                {
                    printf("\n**** -_- -_- Game Over -_- -_- ****\n\n");
                    displayBomb(bomb);
                    printf("\n**** -_- -_- Game Over -_- -_- ****\n\n");
                    break;
                }
                else if(a[x][y] == 0)//Empty place is clicked
                {
                    showZero(x,y);
                    displayBomb(b);
                }
                else		//Number is clicked
                {
                    showMine(x,y);
                    displayBomb(b);
                }

                //printf("\n\n\nCount is :% d",count);
            }
            else
            {
                printf("\n!!!!! You Won !!!!!");
                displayBomb(bomb);
                break;
            }

        }
    }
}

void randomBombLocation()	//Puts bomb in random Location
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

int checkBomb(int x,int y)	//Checks the surrounding of bomb
{
    int up=x-1,low=x+1,equ=x;  //position of X coordinate
    int l=y-1,eq=y,r=y+1;      //position of Y coordinate

    if(a[x][y]==-1)
    {
        return -1;
    }
    else
    {
        bomb[x][y]=-1;
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
    int i,j,k=0;
    randomBombLocation();
    //displayBomb(a);  //display the bomb array

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            b[i][j] = 9;       //Initializing array to 9 for user
        }
    }
    printf("\t\tMINESWEEPER GAME\t\t\n");
    displayBomb(b);
    play();
    return 0;
}
