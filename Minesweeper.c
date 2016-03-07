#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void fill(int,int);
void fillup(int,int);
void fillupleft(int,int);
void fillupright(int,int);
void filldown(int,int);
void filldownleft(int,int);
void filldownright(int,int);
void fillleft(int,int);
void fillright(int,int);

int a[6][6]={0},b[6][6],bomb[6][6]={0},move[6][6]={0}; //Initializes with zero
int x,y,count=1,moveKey,n=0;    //Count for the number of clicks
int Nbomb=1;	//Number of Bombs


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
    b[x][y]=a[x][y];
    if(x!=0)
    {
        fillup(x-1,y);
    }
    if(x!=0 && y!=0)
    {
        fillupleft(x-1,y-1);
    }
    if(x!=0 && y!=5)
    {
        fillupright(x-1,y+1);
    }
    if(x!=5)
    {
        filldown(x+1,y);
    }
    if(x!=5 && y!=0)
    {
        filldownleft(x+1,y-1);
    }
    if(x!=5 && y!=5)
    {
        filldownright(x+1,y+1);
    }
    if(y!=0)
    {
        fillleft(x,y-1);
    }
    if(y!=5)
    {
        fillright(x,y+1);
    }
}

void fillup(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN Top is %d\n",x,y,n);
    if(n<1000)
    {

    if(a[x][y]!=-1 && a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=0)
        {
            n++;
            fillup(x-1,y);
        }
        if(x!=0 && y!=5)
        {
            n++;
            fillupright(x-1,y+1);
        }
        if(x!=0 && y!=0)
        {
            n++;
            fillupleft(x-1,y-1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void fillupleft(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN TopLeft is %d\n",x,y,n);
    if(n<1000)
    {

    if(a[x][y]!=-1 && a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=0 && y!=0)
        {
            n++;
            fillupleft(x-1,y-1);
        }

        if(x!=0)
        {
            n++;
            fillup(x-1,y);
        }
        if(x!=0 && y!=5)
        {
            n++;
            fillupright(x-1,y+1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void fillupright(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN TopRight is %d\n",x,y,n);
    if(n<1000)
    {

    if(a[x][y]!=-1 && a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=0 && y!=5)
        {
            n++;
            fillupright(x-1,y+1);
        }
        if(x!=0)
        {
            n++;
            fillup(x-1,y);
        }
        if(x!=0 && y!=0)
        {
            n++;
            fillupleft(x-1,y-1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void filldown(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN Down is %d\n",x,y,n);
    if(n<1000){
    if(a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=5)
        {
            n++;
            filldown(x+1,y);
        }
        if(x!=5 && y!=0)
        {
            n++;
            filldownleft(x+1,y-1);
        }
        if(x!=5 && y!=5)
        {
            n++;
            filldownright(x+1,y+1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void filldownleft(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN DownLeft is %d\n",x,y,n);
    if(n<1000){
    if(a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=5 && y!=0)
        {
            n++;
            filldownleft(x+1,y-1);
        }
        if(x!=5)
        {
            n++;
            filldown(x+1,y);
        }
        if(x!=5 && y!=5)
        {
            n++;
            filldownright(x+1,y+1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void filldownright(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(a);
    //printf("\nX is %d\tY is %d\tN DownRight is %d\n",x,y,n);
    if(n<1000){
    if(a[x][y]==0)
    {
        b[x][y]=a[x][y];
        if(x!=5 && y!=5)
        {
            n++;
            filldownright(x+1,y+1);
        }
        if(x!=5)
        {
            n++;
            filldown(x+1,y);
        }
        if(x!=5 && y!=0)
        {
            n++;
            filldownleft(x+1,y-1);
        }
        if(y!=0)
        {
            n++;
            fillleft(x,y-1);
        }
        if(y!=5)
        {
            n++;
            fillright(x,y+1);
        }
    }
    }
}

void fillleft(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(b);
    //printf("\nX is %d\tY is %d\n",x,y);
    if(n<1000){
        if(a[x][y]!=-1 && a[x][y]==0)
        {
            b[x][y]=a[x][y];
            if(y!=0)
            {
                n++;
                fillleft(x,y-1);
            }
            if(x!=0)
            {
                n++;
                fillup(x-1,y);
            }
            if(x!=5)
            {
                n++;
                filldown(x+1,y);
            }
        }
    }
}

void fillright(int x,int y)
{
    b[x][y]=a[x][y];
    //displayBomb(b);
    //printf("\nX is %d\tY is %d\n",x,y);
    if(n<1000){
        if(a[x][y]!=-1&& a[x][y]==0)
        {
            b[x][y]=a[x][y];
            if(y!=5)
            {
                n++;
                fillright(x,y+1);
            }
            if(x!=0)
            {
                n++;
                fillup(x-1,y);
            }
            if(x!=5)
            {
                n++;
                filldown(x+1,y);
            }
        }
    }
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
            if(b[i][j] != 9 && a[i][j]!=-1)
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
        printf("\t\t-----MINESWEEPER GAME-----\t\t\n\n\n");
        moveKey=checkMove(x,y);
        checkCount();
        printf("\n\n\nCount Before is :% d\n",count);
        if(count >= (36-Nbomb))
        {
            printf("\n!!!!! You Won !!!!!\n");
            printf("\nCongratzzzzzz\n");
            displayBomb(bomb);
            break;
        }
        else if(moveKey == -1)
        {
            printf("\nThis Location is Clicked\n");
            displayBomb(b);
        }
        else
        {
            if(a[x][y] == -1)//Bomb is clicked
            {
                printf("\n\n\nCount is :% d",count);
                printf("\n**** -_- -_- Game Over -_- -_- ****\n\n");
                displayBomb(bomb);
                printf("\n**** -_- -_- Game Over -_- -_- ****\n\n");
                break;
            }
            else if(a[x][y] == 0)//Empty place is clicked
            {
                fill(x,y);
                checkCount();
                displayBomb(b);
            }
            else		//Number is clicked
            {
                showMine(x,y);
                checkCount();
                displayBomb(b);
            }

            printf("\n\n\nCount is :% d",count);
        }
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
    randomBombLocation();
    displayBomb(a);  //display the bomb array

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            b[i][j] = 9;       //Initializing array to 9 for user
        }
    }
    printf("\t\t-----MINESWEEPER GAME-----\t\t\n\n\n");

    displayBomb(b);
    play();
    return 0;
}
