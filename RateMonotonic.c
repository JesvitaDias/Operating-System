#include<stdio.h>
#include<math.h>
int isschedulable(int n,float util)
{
    float bound=(float)n*(pow(2,1/n)-1);
    return(util<=bound);
}

int gcd(int a,int b)
{
    if(b==0)
    {return a;}
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return((a*b)/gcd(a,b));
}
void ratemono(int n,int extime[],int period[])
{
    int hyperperiod;
    hyperperiod=period[0];
    for(int i=1;i<n;i++)
    {
        hyperperiod=lcm(hyperperiod,period[i]);
    }
    int remianingtime[max]={0};
    int time=0;
    printf("Scheduling Timeline");
    while(time<hyperperiod)
    {
        int highestpr=-1;
        for(int i=0;i<n;i++)
        {
            if(time%period[i]==0)
            {
                remainingtime[i]=extime[i];

            }
                if(remainingtime[i]>0 && (highestpr==-1 || period[i]<period[highestpr]))
                {
                    highestpr=i;
                }
            }
        }
    }
}
