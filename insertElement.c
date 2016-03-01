#include<stdio.h>

int insert(int a[],int n,int num,int index)
{
    int i,j;
    j=n;
    n++;

    for(i=n;i>index;i--)
    {
        a[i]=a[j];
        j--;
    }
    a[index] = num;
    return n;
}

int main()
{
    int i,arr1[20],n,num,index;
    printf("\nEnter the size:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("\nEnter the Number to be Inserted:");
    scanf("%d",&num);
    printf("\nEnter the Index:");
    scanf("%d",&index);

    n=insert(arr1,n,num,index);
    printf("\nAfter Insert:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
    return 0;
}
