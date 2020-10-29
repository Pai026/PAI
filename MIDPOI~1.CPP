#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
void drawmidpointcircle(int x0, int y0, int radius)
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


    } 
} 




// driver function

 main()
{
while(1){
    int xc, yc,z , r2 ,dp,x,y,ch;
    int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
cout<<"\nenter the coordinates= ";
cin>>xc>>yc;
cout<<"\nnow enter the radius =";
cin>>r2;
cout<<"Enter your option:\n1.Mid point algorithm \n2.Bresenham's Algorithm\n";
cin>>ch;
//delay(500000);
switch(ch)
    {
    case 1:
	drawmidpointcircle(xc,yc,r2);
	    break;
	case 2:
	 circleBres(xc, yc, r2);
	 break;
}
cout<<"Do you want to continue?(1/0): ";
	cin>>z;
if(z==0){
		exit(0);
	}
}
closegraph();
return 0;
}