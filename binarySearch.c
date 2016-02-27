#include<stdio.h>

int midPoint(int min,int max)
{
    int mid;
    mid = (min+max)/2;
    return mid;
}

int binSearch(int a[],int key,int min,int max)
{
    int mid;
    if(max<min)
    {
        return -1;  //If Array is empty
    }
    else
    {
        mid = midPoint(min,max);
        if(a[mid]<key)
        {
            binSearch(a,key,min,mid-1);
        }
        else if(a[mid]>key)
        {
            binSearch(a,key,mid+1,max);
        }
        else
        {
            return mid;
        }
    }

}

int main()
{
    int a[30],n,k,i,min,max,res;

    printf("Enter the size of array::");
    scanf("%d",&n);
    printf("\nEnter the Sorted array::");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to be found::");
    scanf("%d",&k);

    res = binSearch(a,k,0,n-1);

    if(res == -1)
    {
        printf("\nThe Value is not found");
    }
    else
    {
        printf("\nThe Value %d is at index %d",k,res);
    }

    return 0;
}
