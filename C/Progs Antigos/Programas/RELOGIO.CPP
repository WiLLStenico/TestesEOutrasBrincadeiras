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

void main(void)
{  float x0,y0,xo0,yo0;//origens
   float hx,hy,hx0,hy0,ih;//hora
   float mx,my,mx0,my0,im;//minuto
   float sx,sy,sx0,sy0,is;//segundo
   float PI,teta,marcx,marcy,marchora,marcx2,marcy2,marcmin,marcseg;//marcadores
   float RAIO,FI,RO,raio,fi,ro,tecla;//teclas
   float pseg,pmin,phora,pxh,pyh,pxm,pym,pxs,pys;//ponteiros
   int pisca,cont;//fazer nomes piscar;

   time_t now;
   struct tm ts;//strutura hora escrever
   char buf[80];



    time(&now);
    ts=*localtime(&now);

	 PI=3.14159265358979;
	 RAIO=raio=100;
	 x0=xo0=320;
	 y0=yo0=240;
	 ih=im=is=marchora=marcmin=marcseg=-90;
	 FI=RO=-25;
	 fi=ro=0;
	 phora=-90+(30*ts.tm_hour)+(ts.tm_min*60*0.00833333333333)+(ts.tm_sec*0.008333333333333333);
	 pmin=-90+((-6)*ts.tm_min)+(ts.tm_sec*(-0.1));
	 pseg=90+((-6)*ts.tm_sec)-6;
	 pisca=0;
	 cont=1;
   opengraph();


   do{

     setfillstyle(1,BLUE);
     floodfill(0,0,BLUE);

     setcolor(BLACK);
     rectangle(215,y0-RAIO-30,420,y0-RAIO-85);
     setfillstyle(1,BLACK);
     floodfill(230,y0-RAIO-36,BLACK);
     setcolor(WHITE);
     rectangle(215,y0-RAIO-30,420,y0-RAIO-85);//retangulo nomes;

     setcolor(BLACK);
     rectangle(254,y0+RAIO+10,385,y0+RAIO+35);
     setfillstyle(1,BLACK);
     floodfill(275,y0+RAIO+30,BLACK);
     setcolor(WHITE);
     rectangle(254,y0+RAIO+10,385,y0+RAIO+35);//quadrado digital

     setcolor(BLACK);
     rectangle(50,y0-40,96,y0-25);
     setfillstyle(1,BLACK);
     floodfill(51,y0-26,BLACK);
     setcolor(WHITE);
     rectangle(50,y0-40,96,y0-25);
     setcolor(YELLOW);
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(55,y0-35,"HORAS");//legenda hora;

     setcolor(BLACK);
     rectangle(50,y0-15,113,y0);
     setfillstyle(1,BLACK);
     floodfill(51,y0-1,BLACK);
     setcolor(WHITE);
     rectangle(50,y0-15,113,y0);
     setcolor(RED);
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(55,y0-10,"MINUTOS");//legenda hora;

     setcolor(BLACK);
     rectangle(50,y0+10,120,y0+25);
     setfillstyle(1,BLACK);
     floodfill(51,y0+16,BLACK);
     setcolor(WHITE);
     rectangle(50,y0+10,120,y0+25);
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(55,y0+15,"SEGUNDOS");//legenda hora;

     setcolor(BLACK);
     circle(x0,y0,RAIO);
     setfillstyle(1,BLACK);
     floodfill(x0,y0,BLACK);//circulo fora

     setcolor(WHITE);
     circle(x0,y0,RAIO);

     /*setcolor(23);
     circle(x0,y0,(RAIO*20/100));
     setfillstyle(1,23);
     floodfill(x0,y0,23);
     setcolor(BLACK);
     circle(x0,y0,(RAIO*20/100));//circulo meio*/

     setcolor(LIGHTRED);
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(250,y0-RAIO-80,"Desenvolvido por:");
     setcolor(LIGHTGREEN);
     outtextxy(220,y0-RAIO-70,"WiLLiaM Henrique Stenico");
     outtextxy(270,y0-RAIO-60,"RA:300070489");
     setcolor(MAGENTA);
     outtextxy(270,y0-RAIO-50,"GiaNNe Forti");
     outtextxy(270,y0-RAIO-40,"RA:300070510");


  do{

     settextstyle(0,HORIZ_DIR,1);

     if((pisca==1)&&(cont<=2))//desenvolvido por:
     {
      setcolor(BLACK);
      outtextxy(220,y0-RAIO-80,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-70,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-60,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-50,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-40,"лллллллллллллллллллллллл");
      setcolor(LIGHTRED);
      outtextxy(250,y0-RAIO-80,"Desenvolvido por:");
     }
     if((pisca==2)&&(cont<=2))//WiLLiaM RA
     {
      setcolor(BLACK);
      outtextxy(220,y0-RAIO-80,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-50,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-40,"лллллллллллллллллллллллл");
      setcolor(LIGHTGREEN);
      outtextxy(220,y0-RAIO-70,"WiLLiaM Henrique Stenico");
      outtextxy(270,y0-RAIO-60,"RA:300070489");
     }
     if((pisca==3)&&(cont<=2))//GiaNNe RA
     {
      setcolor(BLACK);
      outtextxy(220,y0-RAIO-70,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-60,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-80,"лллллллллллллллллллллллл");
      setcolor(MAGENTA);
      outtextxy(270,y0-RAIO-50,"GiaNNe Forti");
      outtextxy(270,y0-RAIO-40,"RA:300070510");
     }
     if((pisca==4)&&(cont<=2))//limpa
     {
      setcolor(BLACK);
      outtextxy(220,y0-RAIO-80,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-70,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-60,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-50,"лллллллллллллллллллллллл");
      outtextxy(220,y0-RAIO-40,"лллллллллллллллллллллллл");
     }
     if((pisca==5)&&(cont<=2))//tudo
     {
       setcolor(LIGHTRED);
      outtextxy(250,y0-RAIO-80,"Desenvolvido por:");
      setcolor(LIGHTGREEN);
      outtextxy(220,y0-RAIO-70,"WiLLiaM Henrique Stenico");
      outtextxy(270,y0-RAIO-60,"RA:300070489");
      setcolor(MAGENTA);
      outtextxy(270,y0-RAIO-50,"GiaNNe Forti");
      outtextxy(270,y0-RAIO-40,"RA:300070510");
      pisca=0;
      cont=cont+1;
     }
      pisca=pisca+1;


    time(&now);
    ts=*localtime(&now);
    strftime(buf,sizeof(buf),"%H:%M:%S",&ts);
    setcolor(BLACK);
    settextstyle(0,HORIZ_DIR,2);
    outtextxy(257,y0+RAIO+15,"лллллллл");
    setcolor(LIGHTGRAY);
    outtextxy(257,y0+RAIO+15,buf);



   do{
     teta = PI*marcseg/180;
     marcx=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     marcy=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-110)/180);
     marcx2=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-20)/180);
     marcy2=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-110)/180);
     setcolor(GREEN);
     ellipse(x0,y0,0,360,abs((RAIO-1)*cos(PI*(RO-20)/180)),abs((RAIO-1)*cos(PI*(FI-110)/180)));//segundo
     line(marcx2,marcy2,marcx,marcy);//segundo

     teta = PI*marcmin/180;
     marcx=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-110)/180);
     marcy=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     marcx2=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-110)/180);
     marcy2=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(RED);
     line(marcx2,marcy2,marcx,marcy);
     ellipse(x0,y0,0,360,abs((RAIO-1)*cos(PI*(RO-110)/180)),abs((RAIO-1)*cos(PI*(FI-20)/180)));
     //minuto

     teta = PI*marchora/180;
     marcx=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     marcy=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     marcx2=x0+(RAIO-15)*cos(teta)*cos(PI*(RO-20)/180);
     marcy2=y0+(RAIO-15)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(YELLOW);
     line(marcx2,marcy2,marcx,marcy);//hora
     ellipse(x0,y0,0,360,abs((RAIO-1)*cos(PI*(RO-20)/180)),abs((RAIO-1)*cos(PI*(FI-20)/180)));//hora
     //hora

     marchora=marchora+30;
     marcmin=marcmin+6;
     marcseg=marcseg+6;


  }while(marcmin<=270);

     //PONTEIROS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


     teta = PI*pseg/180;
     pxs=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-20)/180);
     pys=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-110)/180);
     setcolor(GREEN);
     line(x0,y0,pxs,pys);//segundo


     teta = PI*pmin/180;
     pxm=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-110)/180);
     pym=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(RED);
     line(x0,y0,pxm,pym);//minuto

     teta = PI*phora/180;
     pxh=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     pyh=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(YELLOW);
     line(x0,y0,pxh,pyh);//hora

     delay(1000);
     setcolor(BLACK);
     line(x0,y0,pxs,pys);//segundo

     pseg=90+((-6)*ts.tm_sec)-6;
     //pseg=pseg-6;

     line(x0,y0,pxm,pym);
     pxh=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     pyh=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     line(x0,y0,pxh,pyh);

     phora=-90+(30*ts.tm_hour)+(ts.tm_min*60*0.00833333333333)+(ts.tm_sec*0.008333333333333333);
     pmin=-90+((-6)*ts.tm_min)+(ts.tm_sec*(-0.1));

    /* pmin=pmin-0.1;
     phora= phora+0.008333333333333333333333333333333333333333;*/


     /*if(pseg<=-270)
     {
      setcolor(BLACK);
      line(x0,y0,pxm,pym);
      pxh=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
      pyh=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
      line(x0,y0,pxh,pyh);
      pmin=pmin-6;
      phora=phora+0.5;
      pseg=90;//minuto
     }*/

     }while(!kbhit());




     tecla=getch();

     if(tecla=='8')
     {
      FI=FI+10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='2')
     {
      FI=FI-10;
      marcmin=-90;
      cleardevice();
     }
       if(tecla=='6')
     {
      RO=RO-10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='4')
     {
      RO=RO+10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='9')
     {
      FI=FI+10;
      RO=RO-10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='7')
     {
      FI=FI+10;
      RO=RO+10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='3')
     {
      FI=FI-10;
      RO=RO-10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='1')
     {
      FI=FI-10;
      RO=RO+10;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='5')
     {
      FI=fi;
      RO=ro;
      RAIO=raio;
      marcmin=-90;
      cleardevice();
     }

      if(tecla=='.')
     {
      FI=fi-25;
      RO=ro-25;
      marcmin=-90;
      cleardevice();
     }

      if(tecla=='+')
     {
      RAIO=RAIO+20;
      marcmin=-90;
      cleardevice();
     }
      if((tecla=='-')&&(RAIO>25))
     {
      RAIO=RAIO-20;
      marcmin=-90;
      cleardevice();
     }
     if(tecla=='*')
     {
      cont=0;
      pisca=0;

     }


   }while(tecla!=27);

}