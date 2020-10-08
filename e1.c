#include<stdio.h>
union x{
    int a,b;
    char c[4];
};
int main() 
{
      char str[] = "PROcoders";

  printf("%s %s %s ", &str[5], &5[str], str+5);

  printf("%c %c %c\n", *(str+6), str[6], 6[str]);

  return 0;
}