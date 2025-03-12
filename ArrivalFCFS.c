#include<stdio.h>
void main()
{
    int bt[20],tat[20],wt[20],i,j,temp,n,at[20],ct[20],pid[20];
    printf("Enter the number of processes ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
    }
    printf("Enter the arrival times of processes ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst times of processes ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
     for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]==at[j])
            {
                if(bt[i]>bt[j])
                {
                   temp=at[i];
                   at[i]=at[j];
                   at[j]=temp;
                   temp=bt[i];
                   bt[i]=bt[j];
                   bt[j]=temp;
                   temp=pid[i];
                   pid[i]=pid[j];
                   pid[j]=temp;


                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
              temp=at[i];
                   at[i]=at[j];
                   at[j]=temp;
                   temp=bt[i];
                   bt[i]=bt[j];
                   bt[j]=temp;
                   temp=pid[i];
                   pid[i]=pid[j];
                   pid[j]=temp;
            }
        }
    }
    float wtavg,tatavg;
    wtavg=tatavg=0;

    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
     for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("\nPROCESS  ARRIVALTIME BURSTTIME COMPLETION WAITINGTIME TURNAROUNDTIME");
    for(i=0;i<n;i++)
    {
       printf("\n%d         %d           %d              %d            %d             %d",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    wtavg=(float)(wtavg/n);
    tatavg=(float)(tatavg/n);
    printf("\nAverage waiting time is %f",wtavg);
    printf("\nAverage turnaround time is %f",tatavg);
}




