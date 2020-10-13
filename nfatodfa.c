#include<stdio.h>
#include<stdlib.h>
int transtable[20][20][20],noOfTransition,c,r;
int ans[10],t=0;
void calculate(int x)
{
    int k=0;
    printf("q%d",x);
    for(int i=1;i<=2;i++){
        k=0;
        
        if(transtable[x][i][k]>0)
        {printf("\t{");
        int flag=0;
            while(transtable[x][i][k]!=0)
            {
                if(flag==0)
                    printf("q%d",transtable[x][i][k]);
                else
                {
                    printf(",q%d",transtable[x][i][k]);
                    ans[t++]=transtable[x][i][k-1];
                    ans[t++]=transtable[x][i][k];
                    ans[t]=0;
                }
               flag=1;
                k++;
            }
            printf("}");
        }
        else{
            printf("\t0");
        }
        
    }
}
void main()
{
    int i,j,k=0;
    int s;
    FILE *fp;
    fp=fopen("input1.txt","r");
    fscanf(fp,"%d",&noOfTransition); 
    printf("\nTotal number of transitions are %d",noOfTransition);
    printf("\nThe Transitions are\n");
    while(!feof(fp))
    {
        k=0;
        fscanf(fp,"%d %d %d",&r,&s,&c);
        printf("\n%d %d %d\n",r,s,c);
        if(transtable[r][s][k]!=0)
        {
            transtable[r][s][++k]=c;
        }
        transtable[r][s][k]=c;
    }
   calculate(1);
   printf("\n");
       printf("\n{q%d,q%d}",ans[0],ans[1]);
       i=0;
       for(int z=1;z<=2;z++)
       {    i=0;
       printf("\t{");
       int flag=0;
            while(ans[i]!=0){
           
        k=0;   
        
            while(transtable[ans[i]][z][k]!=0)
            {
                if(flag==0)
                    printf("q%d",transtable[ans[i]][z][k]);
                else
                    printf(",q%d",transtable[ans[i]][z][k]);
               flag=1;
                k++;
            }
            i=i+1;
           
            }
            printf("}");
   }
    fclose(fp);
}