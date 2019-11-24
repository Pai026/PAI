#include <stdio.h>
#include <math.h>
void sort(int a[],int n)
{   int i,j,temp=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
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
            thm=abs(head-max)+abs(max-0);
            for(i=0;i<n;i++)
            {    if(p[i]>head)
                {    thm+=abs(0-p[i-1]);
                    break;
                }
            }
            
        }
        else
        {
           thm=abs(head-0)+abs(max-0);
            for(i=n-1;i>=0;i--)
            {    if(p[i]<head)
                {    thm+=abs(max-p[i+1]);
                    break;
                }
            }
        }

    printf("\nTotal Head Movment is %d %d",thm,p[0]);
    
            
}
