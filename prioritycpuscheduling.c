#include <stdio.h>
void sort(int a[],int b[],int n)
{
    int temp=0,i,j,temp1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(b[j]>b[j+1])
            {temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            temp1=b[j];
            b[j]=b[j+1];
            b[j+1]=temp1;
            }
        }
    }
        
    
}
int main()
{
    int tat[50],ttat=0,twt=0,wt[50],bt[50],p[20],p1[20],i,n;
    float atat,awt;
    printf("\nEnter the number of process");
    scanf("%d",&n);
    printf("\nEnter the burst times and priority");
    for(i=0;i<n;i++)
    {
       
        scanf("%d %d",&bt[i],&p1[i]);
    }
    sort(bt,p1,n);
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
