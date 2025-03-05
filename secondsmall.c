#include<stdio.h>
void main()
{
    int a[30],b[30],n,i,j,temp,se;
    printf("Enter number of elements  ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    if(n==1)
    {
        printf("Cant find second smallest,enter more than 1 element");
    }
   else{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
        if(b[i]<b[j])
        {
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
        }
        }
    }
    se=b[n-2];
    printf("Second smallest element is : %d  ", se);
   }

}
