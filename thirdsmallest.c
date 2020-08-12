#include <stdio.h>
#include <string.h>
#define MAX 100000 
int main()
{
    int a[10],n,min=MAX,count=0,min1=MAX,min2=MAX;
    printf("Enter the length of array");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        
    }
   
    for(int i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min2=min1;
            min1=min;
            min=a[i];
        }
        else if(min1>a[i])
        {
            min2=min1;
            min1=a[i];
        }
        else if(min2>a[i])
        {
            min2=a[i];
        }
    }
    printf("Third Minimum=%d\n",min2);
    for (int i =0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}
