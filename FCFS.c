#include<stdio.h>
void main()
{
    int bt[20],tat[20],wt[20],i,n;
    printf("Enter the number of processes ");
    scanf("%d",&n);
    printf("Enter the burst times of processes ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    float wtavg,tatavg;
    wtavg=0;
    wt[0]=0;
    tatavg=bt[0];
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("\nPROCESS  BURSTTIME WAITINGTIME TURNAROUNDTIME");
    for(i=0;i<n;i++)
    {
       printf("\n%d         %d           %d              %d",(i+1),bt[i],wt[i],tat[i]);
    }
    wtavg=(float)(wtavg/n);
    tatavg=(float)(tatavg/n);
    printf("\nAverage waiting time is %f",wtavg);
    printf("\nAverage turnaround time is %f",tatavg);
}
