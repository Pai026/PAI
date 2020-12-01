#include <stdio.h>

int main()
{
     int i,r,c,T;
    int t;
     scanf("%d",&T);
     for(i=0;i<T;++i)
     {
         t=0;
         scanf("%d %d",&r,&c);
         if(c<r){
             t=r;
             r=c;
             c=t;
         }
             printf(" Case #%d: %d",i+1,r*(r+1)*(2*r+1)/6+(c-r)*(r+1)/2);
         
     }
     return 0;
}