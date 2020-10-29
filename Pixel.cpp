#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iostream.h>
int main()
{
   while(1){
   int gd = DETECT, gm, color=0;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   float x,y,r;
   int z;
   cout<<"Enter co-ordinates of center(x and y): ";
   cin>>x>>y;
   while(color<16){
   	putpixel(x, y, color);
	x=x+3;color=color+1;
   }
   cout<<"Do you want to continue?(1/0): ";
   cin>>z;
   if(z==0){
	exit(0);
   }
   }
   return 0;
}