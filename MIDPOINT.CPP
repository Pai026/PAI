#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
 
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, RED);
	putpixel(x0 + y, y0 + x, RED);
	putpixel(x0 - y, y0 + x, RED);
	putpixel(x0 - x, y0 + y, RED);
	putpixel(x0 - x, y0 - y, RED);
	putpixel(x0 - y, y0 - x, RED);
	putpixel(x0 + y, y0 - x, RED);
	putpixel(x0 + x, y0 - y, RED);
 
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}
 
	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
	delay(50);
    }
}
 
int main()
{
	while(1){
	int gdriver=DETECT, gmode, error, x, y, r,z;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 	cout<<"Enter co-ordinates of center(x and y): ";
	cin>>x>>y;
	cout<<"Enter radius of circle: ";
	cin>>r;
	drawcircle(x, y, r);
	cout<<"Do you want to continue?(1/0): ";
	cin>>z;
	if(z==0){
		exit(0);
	}
	}
	return 0;
}  