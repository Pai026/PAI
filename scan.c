#include <stdio.h>
#include <math.h>
void sort(int a[],int n)
{   int i,j,temp=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
   int head,p[50],n,max,i,thm=0,diff,prevhead;
   printf("\nEnter the disk size");
   scanf("%d",&max);
   max=max-1;
   printf("\nEnter the number of process");
   scanf("%d",&n);
   printf("\nEnter the process");
   for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    sort(p,n);
    printf("\nEnter the head position");
    scanf("%d",&head);
    printf("\nEnter the previous head position");
    scanf("%d",&prevhead);
        if(head>prevhead)
        {
            thm=abs((head-max)+(max-p[0]));
            
        }
        else
        {
            thm=abs(head+p[n-1]);
        }

    printf("\nTotal Head Movment is %d",thm);
    
            
}
