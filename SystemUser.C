#include<stdio.h>
int main()
{
    int bt[20],pid[20],tat[20],wt[20],i,n,j,temp,su[20];
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
    printf("Enter 1 for system process, 0 for user process");
    for(i=0;i<n;i++)
    {
        printf("System/User");
        scanf("%d",&su[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(su[i]<su[j])
            {
                temp=su[i]; su[i]=su[j]; su[j]=temp;
                temp=pid[i]; pid[i]=pid[j]; pid[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }
        }
    }
    wt[0]=0;
    tat[0]=bt[0];
    float wtavg,tatavg;
    wtavg=0;
    tatavg=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        tatavg+=tat[i];
        wtavg+=wt[i];
    }
    printf("Process id        System/User       Burst Time       Waiting time           Turnaround time\n");
    for(i=0;i<n;i++)
    {

    printf("%d                   %d                %d               %d                    %d\n",pid[i],su[i],bt[i],wt[i],tat[i]);
    }
    wtavg=(float)(wtavg/n);
    tatavg=(float)(tatavg/n);
    printf("\nAverage waiting time is %f",wtavg);
    printf("\nAverage turnaround time is %f",tatavg);
    return 0;
}
