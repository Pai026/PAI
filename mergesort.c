#include<stdio.h>
void mergesort(int,int);
void merge(int, int,int ,int);
int a[20];
void main()
{
	int n,i;
	printf("\nn:");
	scanf("%d",&n);
	printf("\nEnter %d elements:",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(0,n-1);
	for(i=0;i<n;i++)
		printf("  %d",a[i]);
	printf("\n");
	
}
void mergesort(int l,int h)
{int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(l,mid);
		mergesort(mid+1,h);
		merge(l,mid,mid+1,h);
	}
}
void merge(int l,int m,int m1,int h)
{
	int temp[20],i,j,k;
	i=l;
	j=m1;
	k=0;
	while((i<=m) && (j<=h))
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=m)
	{
		temp[k++]=a[i++];
	}
	while(j<=h)
	{
		temp[k++]=a[j++];
	}
	for(i=l,j=0;i<=h;i++,j++)
		a[i]=temp[j];
		
}




