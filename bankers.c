#include <stdio.h>
void print(int a[20][20],int n,int m)
{   int i,j;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
    }
}
int main()
{
   int max[20][20],available[20],allocation[20][20],need[20][20],p,r,i,j,count=0,finish[20],s[10],a=0,flag=0,f1[50];
   printf("\nEnter the number of process");
   scanf("%d",&p);
    printf("\nEnter the number of resources");
    scanf("\%d",&r);
    printf("\nEnter the max matrix");
    for(i=0;i<p;i++){
        f1[i]=0;
    finish[i]=0;
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);}
    printf("\nEnter the allocated matrix");
      for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&allocation[i][j]);
    printf("\nEnter the available matrix");
        for(i=0;i<r;i++)
            scanf("%d",&available[i]);
    for(i=0;i<p;i++)
       for(j=0;j<r;j++)
            need[i][j]=max[i][j]-allocation[i][j];
            
    printf("\nMax Matrix");
    print(max,p,r);
    printf("\nNeed Matrix");
    print(need,p,r);
    printf("\nAllocation Matrix");
    print(allocation,p,r);
    while(count>=0)
    {
        for(i=0;i<p;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        break;
                    }
                    available[j]+=allocation[i][j];
                    finish[i]=1;
                    if(f1[i]==0){
                    s[a]=i;
                    a++;
                    f1[i]=1;}
                   
                }
            }
             count=count+1;
        }
        if(count>5)
        {
            break;
        }
    }
    for(i=0;i<p;i++)
    {    if(finish[i]==0)
        {    printf("\nNot in safe state");
            flag=0;
            break;
        }
        else
            flag=1;
    }    
    if(flag==1)
    {   printf("\n");
        for(i=0;i<p;i++)
            printf(" %d",s[i]);
    }
    return 0;
            
    
            
}
