#include<stdio.h>
int main()
{
    int bt[20],sbt[20],ubt[20],pid[20],sid[20],uid[20],tat[20],wt[20],i,n,j=0,k=0,su[20],syscount=0,uscount=0;
    printf("Enter the number of processes ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
    }
    printf("Enter the burst times of processes ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    printf("Enter 1 for system process, 0 for user process\n");
    for(i=0;i<n;i++)
    {
        printf("System/User");
         scanf("%d",&su[i]);
    }
    for(i=0;i<n;i++)
    {
        if(su[i]==0)
        {
            ubt[j]=bt[i];
            uid[j]=pid[i];
            j++;
            syscount++;
        }
        else
        {
            sbt[k]=bt[i];
            sid[k]=pid[i];
            k++;
            uscount++;
        }
    }
    float wtavg,tatavg;
    wtavg=0;
    tatavg=sbt[0];
    tat[0]=sbt[0];
    wt[0]=0;
    i=1;
    while(i<syscount)
    {
        wt[i]=wt[i-1]+sbt[i-1];
        tat[i]=tat[i-1]+sbt[i];
        tatavg+=tat[i];
        wtavg+=wt[i];
        i++;
    }
    wt[i]=wt[i-1]+sbt[i-1];
    tat[i]=tat[i-1]+ubt[0];
    i++;
    for(j=0;j<uscount-1;j++)
    {
        wt[i]=wt[i-1]+ubt[j];
        tat[i]=tat[i-1]+ubt[j+1];
        tatavg+=tat[i];
        wtavg+=wt[i];
    }
    printf("Process id        System/User       Burst Time       Waiting time           Turnaround time\n");
    for(i=0;i<syscount;i++)
    {

    printf("%d                     1                   %d                 %d                        %d\n",sid[i],sbt[i],wt[i],tat[i]);
    }
    for(i=0;i<uscount;i++)
    {

    printf("%d                     0                  %d                  %d                        %d\n",uid[i],ubt[i],wt[syscount+i],tat[syscount+i]);
    }

    wtavg=(float)(wtavg/n);
    tatavg=(float)(tatavg/n);
    printf("\nAverage waiting time is %f",wtavg);
    printf("\nAverage turnaround time is %f",tatavg);
    return 0;
}


