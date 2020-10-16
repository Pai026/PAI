#include<stdio.h>

int findgcdandsandr(int a,int b)
{
    int s1=1,s2=0,s,t1=0,t2=1,t;
    int q,r;
    while(b!=0)
    {
        q=a/b;
        r=a%b;
        s=s1-s2*q;
        t=t1-t2*q;
        t1=t2;
        t2=t;
        s1=s2;
        s2=s;
        a=b;
        b=r;
    }
    printf("GCD of a and b=%d\ns=%d\nt=%d",a,s1,t1);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    findgcdandsandr(a,b);
}