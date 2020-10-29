#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
void main(){
int gd=DETECT,gm,n,i,j,k,dx,dy;
int x,y,temp;
int p[20][2],xi[20];
float slope[20];
cout << "Enter the number of vertices  of polygon : " ;
cin >> n;
cout << "Enter the coordinates of the polygon :";
for(i=0;i<n;i++)
{
	cout<<"( X"<<i<<", Y"<<i<<" ) : ";
	cin>>p[i][0]>>p[i][1];
}
p[i][0]=p[0][0];
p[i][1]=p[0][1];
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
for(i=0;i<n;i++)
{
	line(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);
}
getch();
for(i=0;i<n;i++)
{
	dy=p[i+1][1]-p[i][1];
	dx=p[i+1][0]-p[i][0];
	if(dy==0) slope[i]=1;
	if(dx==0) slope[i]=0;
	if((dy != 0) && (dx != 0))
	{
		slope[i] = (float)(dx/dy);
	}
}
for(y=0;y<480;y++)
{
	k=0;
	for(i=0;i<n;i++)
	{
		if(((p[i][1]<=y)&&(p[i+1][1]>y))||((p[i][1]>y)&&(p[i+1][1]<=y)))
		{
			xi[k] = (int)(p[i][0]+slope[i]*(y-p[i][1]));
			k++;
		}
	}
	for(j=0;j<k-1;j++)
	{
		for(i=0;i<k-1;i++)
		{
			if(xi[i]>xi[i+1])
			{
				temp = xi[i];
				xi[i] = xi[i+1];
				xi[i+1] = temp;
			}
		}
		setcolor(5);
		for(i=0;i<k;i+=2)
		{
			line(xi[i],y,xi[i+1],y);
			delay(15);
		}
	}
}
getch();
closegraph();
}

