#include <stdio.h>
#include <math.h>
int main()
{
   int head,p[50],n,max,i,thm=0,diff;
   printf("\nEnter the disk size");
   scanf("%d",&max);
   max=max-1;
   printf("\nEnter the number of process");
   scanf("%d",&n);
   printf("\nEnter the process");
   for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    printf("\nEnter the head position");
    scanf("%d",&head);
    
    for(i=1;i<n;i++)
    {   diff=abs(p[i]-head);
        thm=thm+diff;
        head=p[i];
    }
    printf("\nTotal Head Movment is %d",thm);
    
            
}
