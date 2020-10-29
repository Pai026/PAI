#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - y, yc + x, RED);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc - y, yc - x, RED);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
	x++;
	if (d > 0)
	{
	    y--;
	    d = d + 4 * (x - y) + 10;
	}
	else
	    d = d + 4 * x + 6;
	drawCircle(xc, yc, x, y);
	delay(50);
    }
}

int main()
{
    while(1){
    float x,y,r;
    int z;
    cout<<"Enter co-ordinates of center(x and y): ";
    cin>>x>>y;
    cout<<"Enter radius of circle: ";
    cin>>r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    circleBres(x, y, r);
    cout<<"Do you want to continue?(1/0): ";
    cin>>z;
    if(z==0){
	exit(0);
    }
    }
    return 0;
}
