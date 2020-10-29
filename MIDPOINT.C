#include <stdio.h> 
#include<stdlib.h>
#include <graphics.h> 
void drawCircle(int xc, int yc, int x, int y) 
{ 
    printf("\n\n\n\t\t\t\t");
    putpixel(xc+x, yc+y, RED); 

    putpixel(xc-x, yc+y, RED); 

    putpixel(xc+x, yc-y, RED); 

    putpixel(xc-x, yc-y, RED); 

    putpixel(xc+y, yc+x, RED); 

    putpixel(xc-y, yc+x, RED); 

    putpixel(xc+y, yc-x, RED); 

    putpixel(xc-y, yc-x, RED); 
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

        delay(500); 

    } 
} 




// driver function 

 main() 
{ 

    int xc, yc , r2 ,dp,x,y,ch; 
    int gd = DETECT, gm; 
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
cout<<"\nenter the coordinates= ";
cin>>xc>>yc);
cout<<"\nnow enter the radius =";
cin>>r2);
printf("Enter your option:\n1.Mid point algorithm \n2.Bresenham's Algorithm\n");
cin>>ch;
//delay(500000);
switch(ch)
    {
    case 1:
        x=0;
        y=r2;
        dp=1-r2;
        do
        {
             /*putpixel(xc+x,yc+y,YELLOW);
            putpixel(xc+y,yc+x,YELLOW);
            putpixel(xc-y,yc+x,YELLOW);
            putpixel(xc-x,yc+y,YELLOW);
            putpixel(xc-x,yc-y,YELLOW);
            putpixel(xc-y,yc-x,YELLOW);
            putpixel(xc+y,yc-x,YELLOW);
            putpixel(xc+x,yc-y,YELLOW);*/
     drawCircle( xc,  yc,  x, y) ;
            if(dp<0)
             {
                dp+=(2*x)+1;
             }
            else
            {
                y=y-1;
                dp+=(2*x)-(2*y)+1;
            }
                x=x+1;
        }while(y>x);
            break;
        case 2:
         circleBres(xc, yc, r2);
         break;
}
delay(15000);
closegraph();
return 0;
}