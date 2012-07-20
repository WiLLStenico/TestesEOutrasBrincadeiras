#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
   clrscr();

  int i;
  int cx,cy, cr, cf = 0, dr;

  int max_try;
  int graphmode, graphdriver;

  int curr_mode;

  int xasp, yasp, maxx, maxy;

  textmode(MONO);
  directvideo=0;

  detectgraph(&graphdriver,&graphmode);

  initgraph(&graphdriver, &graphmode, "C:\\borlandc\\bgi");

  #if 0
   curr_mode=graphicmode;
   maxx=getmaxx(); maxy=getmaxy();

   getaspectratio(&xasp,&yasp);
   #endif





    cx=300;
    cy=150;
    cr=2;
    dr=150;


    circle(cx,cy,cr+dr);
    circle(cx,cy,cr);

    setfillstyle(cf,BLUE);
    floodfill(cx,cy,WHITE);
    setfillstyle(0,WHITE);
    floodfill((cx+cr+2),cy,WHITE);

    moveto(50,1);

    getch();
    cleardevice();

    closegraph();
}