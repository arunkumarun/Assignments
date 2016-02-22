#include<stdio.h>

int inArray(int a[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[20],n,i,index,key;

    printf("\nEnter the size:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the key element:");
    scanf("%d",&key);

    index = inArray(a,n,key);

    printf("\nThe index is %d",index);

    return 0;
}
