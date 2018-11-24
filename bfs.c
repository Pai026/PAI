#include<stdio.h>
#include<stdlib.h>
int s[100],a[50][50],v[50],r[50],rear=-1,front=0;
void bfs(int b,int n) {
	int i;	
	for(i = 1; i <= n; i++)
	{	if(a[b][i] && !v[i])
			s[++rear] = i;
	}
	if(front <= rear) {
		if(!v[s[front]])
			printf(" %d",s[front]);
		v[s[front]] = 1;
		bfs(s[front++],n);
	}
	
}
void dfs(int s,int n)
{
 int i=s;
 r[s]=1;
printf(" %d",i);
 for(i=1;i<=n;i++)
  if(a[s][i] && !r[i])
  {
   
   dfs(i,n);
  }
}
int main()
{	int n,i,j,key,k;
	printf("\nEnter the nos of vertices");
	scanf("\n%d",&n);
	for(i=1;i<=n;i++)
	{	v[i]=0;
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);}
	do{
		for(i=1;i<=n;i++)
			{v[i]=0;r[i]=0;}
		printf("\nEnter the traversal technique\n1.BFS\n2.DFS\n3.Exit\nEnter the choice");
		scanf("%d",&k);
		switch(k){
			case 1:printf("\nEnter the starting vertex");
				scanf("%d",&key);
				s[++rear]=key;
				bfs(key,n);
				break;
			case 2:printf("\nEnter the starting vertex");
				scanf("%d",&key);	
				dfs(key,n);
				break;
			case 3:exit(0);
		}
	}while(k!=3);
	return 0;
}	


