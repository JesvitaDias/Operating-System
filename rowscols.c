#include<stdio.h>
void main()
{
    int a[30][30],n,i,j,rs,cs,m;
    printf("Enter the order ");
    scanf("%d%d",&m,&n);
    printf("Enter the elements ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
    }
    printf("\nsum of rows is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
    {
        rs+=a[i][j];
    }
    printf("Row %d sum is %d\n", i+1,rs);
    rs=0;
    }
    cs=0;
    printf("sum of columns is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
    {
        cs+=a[j][i];
    }
    printf("Row %d sum is %d\n", i+1,cs);
    cs=0;
    }
}
