#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <GRAPHICS.H>
#include <stdlib.h>
#include <dos.h>
#include <time.h>


//!!!!!!!!!!!!!!!!!!!!!!!!!! MODO GRAFICO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void opengraph()
{
  int driver, mode;
  detectgraph(&driver,&mode);
  initgraph(&driver, &mode, "c:\\borlandc\\bgi");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MIRA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void mira(int x0, int y0)
{
 setcolor(LIGHTGREEN);
 circle(x0,y0,10);
 circle(x0,y0,5);
 line(x0-5,y0,x0+5,y0);
 line(x0,y0+5,x0,y0+10);
 line(x0,y0-5,x0,y0-10);
}

//!!!!!!!!!!!!!!!!!!!!!!!!!! CORPO NAVE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void nave()
{
 setcolor(LIGHTGRAY);
 setfillstyle(1,LIGHTGRAY);
 line(120,400,520,400);
 line(120,400,10,0);
 line(110,410,0,0);
 line(640,0,530,410);
 line(630,0,520,400);
 line(630,0,640,0);
 line(0,0,10,0);
 line(110,410,10,480);
 line(630,480,530,410);
 floodfill(110,405,LIGHTGRAY);

 setcolor(BLACK);
 setfillstyle(1,BLACK);
 line(140,420,500,420);
 line(140,420,50,480);
 line(500,420,600,490);
 floodfill(320,470,BLACK);

 setcolor(GREEN);
 line(140,420,500,420);
 line(140,420,50,480);
 line(500,420,600,490);

 setcolor(BLUE);
 line(120,400,520,400);
 line(120,400,10,0);
 line(110,410,0,0);
 line(640,0,530,410);
 line(630,0,520,400);
 line(630,0,640,0);
 line(0,0,10,0);
 line(110,410,10,480);
 line(630,480,530,410);

}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! PAINEL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void painel()
{
 setcolor(RED);
 circle(150,440,5);
 setcolor(GREEN);
 circle(170,440,5);
 setcolor(YELLOW);
 circle(190,440,5);
 delay(50);
 setfillstyle(1,RED);
 floodfill(151,440,RED);
 if(!kbhit())
 {
 delay(50);

 setcolor(RED);
 circle(150,440,5);
 setcolor(GREEN);
 circle(170,440,5);
 setcolor(YELLOW);
 circle(190,440,5);

 setfillstyle(1,GREEN);
 floodfill(171,440,GREEN);
 delay(50);

 setcolor(RED);
 circle(150,440,5);
 setcolor(GREEN);
 circle(170,440,5);
 setcolor(YELLOW);
 circle(190,440,5);

 setfillstyle(1,YELLOW);
 floodfill(191,440,YELLOW);

 delay(50);

 setfillstyle(1,BLACK);
 floodfill(151,440,BLACK);
 floodfill(171,440,BLACK);
 floodfill(191,440,BLACK);
 setcolor(RED);
 circle(150,440,5);
 setcolor(GREEN);
 circle(170,440,5);
 setcolor(YELLOW);
 circle(190,440,5);

 setcolor(LIGHTBLUE);
 setfillstyle(1,LIGHTBLUE);
 rectangle(450,440,500,470);
 floodfill(452,441,LIGHTBLUE);

 delay(50);

 setcolor(BLACK);
 setfillstyle(1,BLACK);
 rectangle(450,440,500,470);
 floodfill(452,441,BLACK);
 setcolor(LIGHTBLUE);
 rectangle(450,440,500,470);
 }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TIRO DUPLO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void tiro(int x, int y)
{
 int rt=20;
 float xe,xd;
 xe=x;
 xd=x;

  while(rt>=3)
  {
   sound(y*50);

   setcolor(LIGHTCYAN);
   setfillstyle(1,LIGHTCYAN);
   circle(xd+80,y+130,rt);
   floodfill(xd+80,y+130,LIGHTCYAN);
   setfillstyle(1,LIGHTCYAN);
   circle(xe-80,y+130,rt);
   floodfill(xe-80,y+130,LIGHTCYAN);
   delay(2);
   setcolor(BLACK);
   setfillstyle(1,BLACK);
   circle(xd+80,y+130,rt);
   floodfill(xd+80,y+130,BLACK);
   setcolor(BLACK);
   setfillstyle(1,BLACK);
   circle(xe-80,y+130,rt);
   floodfill(xe-80,y+130,BLACK);

   y=y-7.1;
   xd=xd-5;
   xe=xe+5;
   rt=rt-0.05;

  }
  nosound();

}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CENARIO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void cenario(int ex,int ey)
{


    setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
    circle(ex,ey,.1);


}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! INIMIGOS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void inimigos(int ix, int iy)
{
 setcolor(LIGHTGRAY);
 setfillstyle(1,LIGHTGRAY);
 circle(ix,iy,10);
 setcolor(LIGHTBLUE);
 setfillstyle(1,LIGHTBLUE);
 circle(ix,iy,10);
 floodfill(ix,iy,BLUE);
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! FUNCAO PRINCIPAL !!!!!!!!!!!!!!!!!!!!!!!!!

void main(void)
{
   float tecla,ex[101],ey[101],xex[101],xey[101],raiox[101],raioy[101],pi,I,teta;
   int x0,y0,i;

   x0=320;
   y0=240;
   I=-90;
   pi = 3.14159265358979;

   opengraph();

   setbkcolor(BLACK);

   for(i=0;i<=100;i++)
    { ex[i]=rand()%640;
      ey[i]=rand()%480;

      teta = pi*I/180;

      if(i<=50)
       raiox[i]=sqrt((ex[i]-320)*(ex[i]-320)+(ey[i]-240)*(ey[i]-240));
	else
	  raiox[i]=-sqrt((ex[i]-320)*(ex[i]-320)+(ey[i]-240)*(ey[i]-240));

      xex[i] = ex[i] + raiox[i] * cos(teta);
      xey[i] = ey[i] + raiox[i] * sin(teta);

     cenario(xex[i],xey[i]);
    }

   nave();

   do{
    do{


     for(i=0;i<=100;i++)
    {
     teta = pi*I/180;
      xex[i] = ex[i] +raiox[i] *cos(teta);
      xey[i] = ey[i] +raiox[i] *sin(teta);

     cenario(xex[i],xey[i]);
    }

     mira(x0,y0);
     nave();
     painel();



    }while(!kbhit());
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! COMANDOS !!!!!!!!!!!!!!!!!!!!!!!

    tecla=getch();

     if(tecla=='s')//TIRO DUPLO
   {
    tiro(x0,y0);

   }

    if(tecla=='6')
    I=I-5;

    if(tecla=='4')
    I=I+5;





    cleardevice();
   }while(tecla!=27);



   cleardevice();



}