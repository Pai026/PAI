#include<stdio.h>
int rear=-1,front=-1,q[100],a[50][50],v[50];
void enqueue(int n)
{
	if(rear==-1)
	{	rear=0;
		front=0;
		q[rear++]=n;
	}
	else
		q[rear++]=n;
}
int  dequeue()
{
	if(front==-1)
		return -1;
	else
		return q[front++];
}
void bfs(int s, int n)
{	int p,i;
	enqueue(s);
	v[s]=1;
	p=dequeue();
	if(p!=-1)
	{	
		while(p!=-1)
		{	i=1;
			while(i<n)
			{	if((a[p][i]==1)&&(v[i]==0))
				{	enqueue(i);
					v[i]=1;
				}
				i=i+1;
			}
		p=dequeue();
		if(p!=-1)
			printf("%d",p);
		}
	}
	i=1;
	while(i<=n)	
	{	if(v[i]==0)
			bfs(i,n);
	}
}
int main()
{	int n,i,j;
	printf("\nEnter the nos of vertices");
	scanf("\n%d",&n);
	for(i=1;i<=n;i++)
	{	v[i]=0;
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);}
	for(i=1;i<=n;i++){printf("\n");
	for(j=1;j<=n;j++)printf(" %d",a[i][j]);}
	bfs(1,n);
}
