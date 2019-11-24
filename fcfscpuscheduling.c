#include <stdio.h>
int main()
{
    int tat[50],ttat=0,twt=0,wt[50],bt[50],p[20],i,n;
    float atat,awt;
    printf("\nEnter the number of process");
    scanf("%d",&n);
    printf("\nEnter the burst times");
    for(i=0;i<n;i++)
    {
       
        scanf("%d",&bt[i]);
    }
    tat[0]=bt[0];
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=tat[i-1];
        tat[i]=wt[i]+bt[i];
    }
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
