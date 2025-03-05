#include<stdio.h>
void main()
{
    int a[30][30],n,i,j,sum;
    printf("Enter the order ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(j==n-1-i)
            {
                sum+=a[i][j];
            }

        }
    }
    printf("Sum is %d ", sum);
}
