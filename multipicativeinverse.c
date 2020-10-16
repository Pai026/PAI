#include<stdio.h>

int multiplicativeinverse(int a,int b)
{
    int t1=0,t2=1,t;
    int q,r;
    int temp =a;
    while(b!=0)
    {
        q=a/b;
        r=a%b;
        t=t1-t2*q;
        t1=t2;
        t2=t;
        a=b;
        b=r;
    }
    printf("Multiplicative Inverse=%d positive value=%d",t1,temp+t1);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    multiplicativeinverse(a,b);
}