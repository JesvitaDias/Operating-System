#include<stdio.h>
void main()
{
    int a[30],n,i,j,freq;
    int count,dup,k,ele;
    printf("Enter number of elements  ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            freq=0;
        for(j=i+1;j<n;j++)
        {
                 if(a[i]==a[j])
                  {
                   freq=1;
                   a[j]=-1;
                  }
        }
        if(freq)
        {
            count++;
        }

        }
    }

    printf("The number of duplicate elements is %d",count);


}

