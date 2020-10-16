#include<stdio.h>
int gcd(int a,int b)
{
    int temp=0;
    while(b!=0)
    {
        temp = b;
        b=a%b;
        a=temp;

    }
    return a;
}

int lcm (int a,int b)
{
    return ((a*b)/gcd(a,b));
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("GCD of a and b is %d",gcd(a,b));
    printf("\nLCM of a and b is %d",lcm(a,b));
    return 0;

}