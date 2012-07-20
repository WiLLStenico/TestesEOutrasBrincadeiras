#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <GRAPHICS.H>
#include <stdlib.h>
#include <dos.h>
#include <time.h>

void opengraph()
{
  int driver, mode;
  detectgraph(&driver,&mode);
  initgraph(&driver, &mode, "c:\\borlandc\\bgi");
}


void hora()
{
     time_t now;
   struct tm ts;//strutura escrever hora
   char buf[80];

     time(&now);
     ts=*localtime(&now);
     strftime(buf,sizeof(buf),"%H:%M:%S",&ts);
     setcolor(BLACK);
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(570,470,"лллллллл");
     setcolor(LIGHTGRAY);
     outtextxy(570,470,buf);
}

void matriz()
{
 setcolor(WHITE);
 line(0,240,640,240);
 line(320,0,320,480);

}

void desenha(int op,float xi,float xf)
{ float y,d,yp,dp,inverte;

     setcolor(CYAN);

     if(xi>xf)//para numeros invertidos

     {
      inverte=xf;
      xf=xi;
      xi=inverte;
     }


  if(op==1)
  {
   outtextxy((xi*10)+317,235-(xf*10),".");//ponto
  }

  if(op==2)
 { for(d=xi;d<=xf;d=d+0.2)//x ao quadrado
  {

   y=d*d;
   dp=d+1;
   yp=(dp)*(dp);
   outtextxy((d*5)+317,235-y,".");

   //line(d+320,y-240,d+320,y-240);*/
  }
  }


}


void main(void)
{

   int tecla;
   float xi,y,xf,d,op;
   int nova;

   opengraph();
   cleardevice();

   nova=0;
   xi=320;

    do{
       if(nova==0)
	 {
	  scanf("%f",&xi);
	  scanf("%f",&xf);
	  nova=1;
	  cleardevice();
	 }

     do{


	matriz();
	desenha(2,xi,xf);
	hora();

	}while(!kbhit);

	 tecla=getch();

   }while(tecla!=27);



    cleardevice();

}