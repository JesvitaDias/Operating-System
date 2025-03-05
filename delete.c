#include<stdio.h>
void main()
{
    int a[30],n,i,j,ele,pos;
    printf("Enter number of elements  ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position   ");
    scanf("%d",&pos);
    if(pos>n-1)
    {
        printf("invalid position");
    }
    else
    {
    printf("Deleted d=item is: ", a[pos]);
    for(i=pos;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    printf("After deletion: ");
    for(i=0;i<n-1;i++)
    {
        printf("%d",a[i]);
    }
    }
}
