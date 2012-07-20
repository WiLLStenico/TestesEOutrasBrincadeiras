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

void nave(int x, int y)
{
 setcolor(LIGHTGRAY);
 setfillstyle(1,LIGHTGRAY);
 line(x,y-15,x-5,y);
 line(x,y-15,x+5,y);
 line(x-5,y,x,y-5);
 line(x+5,y,x,y-5);
 floodfill(x,y-6,LIGHTGRAY);
}

void apaganave(int x, int y)
{
 setcolor(BLACK);
 setfillstyle(1,BLACK);
 line(x,y-15,x-5,y);
 line(x,y-15,x+5,y);
 line(x-5,y,x,y-5);
 line(x+5,y,x,y-5);
 floodfill(x,y-6,BLACK);

}

void inimigo(int x, int y)
{
 setcolor(LIGHTRED);
 setfillstyle(1,LIGHTRED);
 rectangle(x-7,y-2,x+7,y);
 line(x-2,y+1,x,y+10);
 line(x+2,y+1,x,y+10);
 line(x-2,y-2,x-3,y-5);
 line(x+2,y-2,x+3,y-5);
 floodfill(x,y-1,LIGHTRED);
 floodfill(x,y+5,LIGHTRED);
}

void apainimigo(int x, int y)
{
 setcolor(BLACK);
 setfillstyle(1,BLACK);
 rectangle(x-7,y-2,x+7,y);
 line(x-2,y,x,y+10);
 line(x+2,y,x,y+10);
 line(x-2,y,x-3,y-5);
 line(x+2,y,x+3,y-5);
 line(x-7,y-1,x+7,y-1);
 rectangle(x-8,y-3,x+8,y+11);
 line(x-2,y+3,x+2,y+3);
 floodfill(x,y-2,BLACK);
 floodfill(x,y+5,BLACK);
 setcolor(BLACK);
 outtextxy(x-2,y,"лл");
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

void tiro(int x, int y)
{
 setcolor(LIGHTGREEN);
 line(x-2,y,x-2,y+10);
 line(x+2,y,x+2,y+10);
 line(x-2,y,x-2,y+10);
 line(x+2,y,x+2,y+10);
 line(x-2,y,x-2,y+10);
 line(x+2,y,x+2,y+10);
 delay(0.5);
 setcolor(BLACK);
 line(x-2,y,x-2,y+10);
 line(x+2,y,x+2,y+10);
}

void explosao(int inix,int iniy)
{
 setcolor(YELLOW);
 line(inix+5,iniy+5,inix+10,iniy+10);
 line(inix-5,iniy-5,inix-10,iniy-10);
 line(inix+5,iniy-5,inix+10,iniy-10);
 line(inix-5,iniy+5,inix-10,iniy+10);
 delay(15);
 setcolor(BLACK);
 line(inix+5,iniy+5,inix+10,iniy+10);
 line(inix-5,iniy-5,inix-10,iniy-10);
 line(inix+5,iniy-5,inix+10,iniy-10);
 line(inix-5,iniy+5,inix-10,iniy+10);


}


void main(void)
{

   int tecla;
   int x,y,i,desce,dir,c;
   int inix[100],iniy[100];

   opengraph();
   cleardevice();

   x=320;y=240;

   for(c=0;c<=99;c++)
   {
    inix[c]=0;iniy[c]=0;
   }
  do{

    do{

     for(c=0;c<=99;c++)
     {
      if((inix[c]==0)&&(iniy[c]==0))
      {
       do{
	inix[c]=rand()%620;
      }while(inix[c]%15!=0);
       inix[c]=inix[c]+5;
       iniy[c]=5;

       inimigo(inix[c],iniy[c]);
      }
     }
     if(desce>=100)
     {
      for(c=0;c<=99;c++)
      {
       apainimigo(inix[c],iniy[c]);
       iniy[c]=iniy[c]+10;
       dir=rand();
       if((dir%4==0)&&(inix[c]+15<=610))
	inix[c]=inix[c]+15;
	else if((dir%4==1)&&(inix[c]-15>=10))
	inix[c]=inix[c]-15;


	inimigo(inix[c],iniy[c]);
       }
       desce=0;
     }
     for(c=0;c<=99;c++)
     {
      if((x==inix[c])&&(y>iniy[c])&&(tecla=='l'))
      {
       apainimigo(inix[c],iniy[c]);
       explosao(inix[c],iniy[c]);
       inix[c]=0;iniy[c]=0;
      }
      if(iniy[c]>=480)
      {inix[c]=0;iniy[c]=0;}
     }
      desce=desce+1;

     nave(x,y);
     setcolor(BLACK);
     line(0,477,640,477);
     hora();
    }while(!kbhit());

     tecla=getch();
     if((tecla=='a')&&(x>5))
     {
      apaganave(x,y);
      x=x-15;
     }
     if((tecla=='d')&&(x<610))
     {
      apaganave(x,y);
      x=x+15;
     }
     if((tecla=='w')&&(y>20))
     {
      apaganave(x,y);
      y=y-15;
     }
     if((tecla=='s')&&(y<480))
     {
      apaganave(x,y);
      y=y+15;
     }
     if(tecla=='l')
     {
      for(i=y-25;i>=1;i=i-1)
       tiro(x,i);
      }




   }while(tecla!=27);
    cleardevice();

}