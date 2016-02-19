#include<stdio.h>

void arithProg(int n,int s,int d)
{
    int i,val=s,j;
    for(i=1;i<=n;i++)
    {
        j=1;
        printf("%d,",val);
        val=val+(d*j);
        j++;
    }
}

int main()
{
    int n,s,d;
    printf("Enter the n value:");
    scanf("%d",&n);
    printf("\nEnter the start value:");
    scanf("%d",&s);
    printf("\nEnter the difference value:");
    scanf("%d",&d);

    arithProg(n,s,d);

    return 0;
}
