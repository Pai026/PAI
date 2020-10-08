#include<stdio.h>
#include<stdlib.h>
int transtable[20][20],noOfTransition,c,r;
int ans[10];
void calculate(int x)
{
    
    ans[c++]=x;
    for(int i=0;i<=noOfTransition;i++)
        if(transtable[x][i])
            calculate(i);
}
void main()
{
    int i,j;
    char s;
    FILE *fp;
    fp=fopen("input1.txt","r");
    fscanf(fp,"%d",&noOfTransition); 
    printf("\nTotal number of transitions are %d",noOfTransition);
    printf("\nThe Transitions are\n");
    while(!feof(fp))
    {
        fscanf(fp,"%d %c %D",&r,&s,&c);
        printf("\n%d %c %d\n",r,s,c);
        if(s=='e')
            transtable[r][c]=1;
    }

    for(int j=1;j<=r;j++)
    {
        c=0;
        calculate(j);
        printf("\ne-closure of state %d is {",j);
        for(i=0;i<c-1;i++){
            printf("%d,",ans[i]);
        }
        printf("%d}\n\n",ans[i]);
    }
    fclose(fp);
}