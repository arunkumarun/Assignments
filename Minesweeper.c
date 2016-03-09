#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void fill(int,int);

int a[6][6]={0},b[6][6],c[6][6],bomb[6][6]={0},move[6][6]={0},visit[6][6]={0},flag[6][6]={0}; //Initializes with zero
int x,y,count=0,moveKey,n=0,choice,flagKey=0;    //Count for the number of clicks
int Nbomb=5;	//Number of Bombs


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
    //Sleep(1000);
}

void fill(int x,int y)
{
    if(flag[x][y] != 1)
    {
        b[x][y]=c[x][y]=a[x][y];
    }
    else
    {
        b[x][y]=c[x][y]=-2;
    }
    //displayBomb(b);
    //printf("\nX is %d\tY is %d\tN is %d\n",x,y,n);
    if(visit[x][y] != 1)
    {
        if(a[x][y]!=-1 && a[x][y]==0 && flag[x][y] != 1)
        {
            if(flag[x][y] != 1)
            {
                b[x][y]=c[x][y]=a[x][y];
            }
            else
            {
                b[x][y]=c[x][y]=-2;
            }
            if(x!=0)
            {
                visit[x][y]=1;
                fill(x-1,y);
            }
            if(x!=0 && y!=5)
            {
                visit[x][y]=1;
                fill(x-1,y+1);
            }
            if(x!=0 && y!=0)
            {
                visit[x][y]=1;
                fill(x-1,y-1);
            }
            if(x!=5)
            {
                visit[x][y]=1;
                fill(x+1,y);
            }
            if(x!=5 && y!=0)
            {
                visit[x][y]=1;
                fill(x+1,y-1);
            }
            if(x!=5 && y!=5)
            {
                visit[x][y]=1;
                fill(x+1,y+1);
            }
            if(y!=0)
            {
                visit[x][y]=1;
                fill(x,y-1);
            }
            if(y!=5)
            {
                visit[x][y]=1;
                fill(x,y+1);
            }
        }
    }
}

void showMine(int x,int y)	//Stores the Clicked index to B-array
{
    b[x][y] =c[x][y]= a[x][y];
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
            else
            {
                move[i][j]=0;
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
    count=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(b[i][j] != 9 && a[i][j]!=-1 && flag[i][j]!= 1)
            {
                count++;
            }
        }
    }
}

void checkFlag(int x,int y)
{
    if(flag[x][y] == 1)
    {
        flag[x][y]=0;
        b[x][y]=c[x][y];
        printf("\nUNFlagged the Location:::\n");
    }
    else
    {
        flag[x][y]=1;
        b[x][y]=-2;
        printf("\nFlagged the Location:::\n");
    }
}

void win()
{
    system("cls");
    printf("\n!!!!! You Won !!!!!\n");
    printf("\nCongratzzzzzz\n");
    //displayBomb(b);
    displayBomb(bomb);
}

void play()		//Beginning of Game
{
    while(1)
    {
        printf("\nEnter the choice 1.Click 2.Flag::");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("\nEnter the index you wanna click::");
            scanf("%d%d",&x,&y);
            system("cls");	//Clear the screen
            printf("\t\t-----MINESWEEPER GAME-----\t\t\n\n\n");
            moveKey=checkMove(x,y);
            checkCount();
            //printf("\n\n\nCount Before is :% d\n",count);
            if(moveKey == -1)
            {
                printf("\nThis Location is Clicked\n");
                displayBomb(b);
            }
            else
            {
                if(a[x][y] == -1 && flag[x][y] != 1)//Bomb is clicked
                {
                    //printf("\n\n\nCount is :% d",count);
                    displayBomb(bomb);
                    printf("\n**** -_- -_- Game Over -_- -_- ****\n\n");
                    break;
                }
                else if(a[x][y] == 0 && flag[x][y]!=1)//Empty place is clicked
                {
                    fill(x,y);
                    checkCount();
                    displayBomb(b);
                }
                else		//Number is clicked
                {
                    if(flag[x][y]!=1)
                    {
                        showMine(x,y);
                        checkCount();
                        displayBomb(b);
                    }
                    else
                    {
                        printf("\nFlagged Position\n");
                    }
                }
                if(count >= (36-Nbomb))
                {
                    win();
                    break;
                }

            }
        }
        else
        {
            printf("\nEnter the index to flag::");
            scanf("%d%d",&x,&y);
            checkFlag(x,y);
            checkCount();
            if(count >= (36-Nbomb))
            {
                win();
                break;
            }
            displayBomb(b);
        }
        printf("\n\n\nCount is :% d",count);
    }
}

void randomBombLocation()	//Puts bomb in random Location
{
    int k=0,i,j,key;
    srand(time(NULL));
    while(k<Nbomb)
    {
        i=rand()%6;
        j=rand()%6;
        key=checkBomb(i,j);
        if(key==-1)
        {
            Nbomb++;
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
    //displayBomb(a);  //display the bomb array

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            b[i][j] = 9;    //Initializing array to 9 for user
            c[i][j] = 9;
        }
    }
    printf("\t\t-----MINESWEEPER GAME-----\t\t\n\n\n");
    printf("\nInstructions:::\n1.The -1 are the bombs\n");
    printf("2.The 0 are the empty space\n");
    printf("3.The 9 are the unclicked space\n");
    printf("4.The -2 are the flagged area\n");
    printf("********Enjoy Playing*********\n");
    printf("\nEnter The Number of Bombs::\n");
    scanf("%d",&Nbomb);
    randomBombLocation();
    displayBomb(b);
    play();
    return 0;
}
