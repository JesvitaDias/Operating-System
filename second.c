#include<stdio.h>
void main()
{
    int a[30],n,i,j,large,pos,se;
    printf("Enter number of elements");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    large=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
            pos=i;
        }
    }
    se=0;
    for(i=0;i<n;i++)
    {
        if(i!=pos && a[i]>se)
        {
            se=a[i];
        }
    }

    printf("Second largest element is : %d",se);

}
