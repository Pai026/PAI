#include <stdio.h>
#include <math.h>
int isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return 0; 
    if (n <= 3)  return 1; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return 0; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return 0; 
  
    return 1; 
} 
int is_palindrome(int n)
{
   
    int digit = n;
    int r=0;
    int check =0;
    while(n!=0)
    {
        r=n%10;
        check=check*10+r;
        n=n/10;
    }
   
    if(check==digit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int count=0;
    for(int i=1000000000;i>0;i--)
    {
        if(is_palindrome(i)==1)
        {
            
            
            if(isPrime(i)==1)
            {
                printf("%d ",i);
                count+=1;
                if(count==3)
                {
                    break;
                }
            }
        }
    }
    return 0;
}
