#include<stdio.h>

int add(int a,int b,int c)
{
    return (a+b+c);
}

int main()
{
    int a,b,c,arr[3],sum=0,i,choice;

    printf("1.Using Variables");
    printf("\nEnter three numbers:");
    scanf("%d%d%d",&a,&b,&c);

    arr[0]=a;
    arr[1]=b;
    arr[2]=c;

    printf("\n1.Variables");
    printf("\n2.Arrays");
    printf("\n3.Function:");

    printf("\nEnter Choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\nSum is %d",a+b+c);
            break;
        case 2:
            for(i=0;i<3;i++)
            {
                sum=sum+arr[i];
            }
            printf("\nSum is %d",sum);
            break;
        case 3:
            sum=add(a,b,c);
            printf("\nSum is %d",sum);
            break;
        default:
            printf("\nEnter the correct choice!!!!");
    }


    return 0;
}
