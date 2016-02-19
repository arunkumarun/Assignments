#include<stdio.h>

int main()
{
    int n,s,d,ch,i,ap,gp;
    printf("Enter the n value:");
    scanf("%d",&n);
    printf("\nEnter the start value:");
    scanf("%d",&s);
    printf("\nEnter the difference value:");
    scanf("%d",&d);
    printf("\n1.AP\n2.GP\nEnter your Choice:");
    scanf("%d",&ch);
    ap=gp=s;
    switch(ch)
    {
        case 1:
            for(i=0;i<n;i++)
            {
                    printf("%d,",ap);
                    ap=ap+d;
            }
            break;
        case 2:
            for(i=0;i<n;i++)
            {
                printf("%d,",gp);
                gp=gp*d;
            }
            break;
        default:
            printf("Enter from the choice alone!!");
    }
    return 0;
}
