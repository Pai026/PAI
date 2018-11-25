#include<stdio.h>
#include<stdlib.h>
int a[100],n=-1;
void insert(int item)
{	int temp,i,p;
	if(n<99)
	{	n=n+1;
		a[n]=item;
		i=n;
		p=(i-1)/2;
		while((p>=0)&&(a[p]>a[i]))
		{
			temp=a[p];
			a[p]=a[i];
			a[i]=temp;
			i=p;
			p=(i-1)/2;
		}
	}
}
void sort()
{	int flag,key,temp1,temp2,lc,rc,x,y,i;
	if(n<0)
		printf("\nnothing to delete");
	else{
		key=a[0];
		a[0]=a[n];
		n=n-1;
		i=0;
		flag=0;
		while((flag==0)&&(i<n))
		{	lc=(2*i)+1;
			rc=(2*i)+2;
			//printf("\n%d",lc);
			//printf("\n%d",rc);
			if(lc<=n)
				x=a[lc];
			else
				x=-1;
			if(rc<=n)
				y=a[rc];
			else
				y=-1;
			
			if((a[i]<x)&&(a[i]<y))
				flag=1;
			else if((x<y)&&(a[i]>x))
			{	temp1=a[i];
				a[i]=a[lc];
				a[lc]=temp1;
				i=lc;
			}
			else if((y<x)&&(a[i]>y))
			{	temp2=a[i];
				a[i]=a[rc];
				a[rc]=temp2;
				i=rc;
			}
			break;
		}
	}
		printf("\n%d",key);
}
int main()
{	int i;	
	insert(10);
	insert(5);
	insert(3);
	insert(2);
	insert(9);
	insert(8);
	for(i=0;i<=n;i++)
		printf("\n%d",a[i]);
	sort();
	sort();
sort();
sort();
sort();
sort();
return 0;
}
		
