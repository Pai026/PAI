#include <stdio.h>

int main()
{
    int tat[50],ttat=0,twt=0,wt[50],bt[50],p[20],p1[20],i,n,bt_rem[100],t=0;
    float atat,awt;
    printf("\nEnter the number of process");
    scanf("%d",&n);
    printf("\nEnter the burst times");
    for(i=0;i<n;i++)
    {
       
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        bt_rem[i]=bt[i];
        wt[i]=0;
    }
    while(1)
    {
        int done=1;
        for(i=0;i<n;i++)
        {
            if(bt_rem[i]>0)
            {
                done=0;
                if(bt_rem[i]>2)
                {
                    t=t+2;
                    bt_rem[i]-=2;
                }
                else
                {
                    t=t+bt_rem[i];
                    wt[i]=t-bt[i];
                    bt_rem[i]=0;
                }
            }
        
        }
        if(done==1)
        {break;}
    }
    for(i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];
    for(i=0;i<n;i++)
    {
        ttat+=tat[i];
        twt+=wt[i];
    }
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("\n%0.2f",awt);
    printf("\n%0.2f",atat);
    
    return 0;
}
