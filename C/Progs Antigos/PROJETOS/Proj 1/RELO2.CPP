#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <GRAPHICS.H>
#include <stdlib.h>
#include <dos.h>

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

	 PI=3.14159265358979;
	 RAIO=raio=150;
	 x0=xo0=320;
	 y0=yo0=240;
	 ih=im=is=marchora=marcmin=marcseg=-90;
	 FI=RO=fi=ro=0;
	 pmin=phora=-90;pseg=96;

   opengraph();


   do{

     /*setcolor(LIGHTBLUE);
     circle(x0,y0,RAIO);
     setfillstyle(1,LIGHTBLUE);
     floodfill(x0,y0,LIGHTBLUE);//circulo fora

     setcolor(WHITE);
     circle(x0,y0,RAIO);*/

     /*setcolor(23);
     circle(x0,y0,(RAIO*20/100));
     setfillstyle(1,23);
     floodfill(x0,y0,23);
     setcolor(BLACK);
     circle(x0,y0,(RAIO*20/100));//circulo meio*/




  do{
   do{
     teta = PI*marcseg/180;
     marcx=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     marcy=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-110)/180);
     marcx2=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-20)/180);
     marcy2=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-110)/180);
     setcolor(LIGHTGREEN);
     ellipse(x0,y0,0,360,abs((RAIO-1)*cos(PI*(RO-20)/180)),abs((RAIO-1)*cos(PI*(FI-110)/180)));//segundo
     line(marcx2,marcy2,marcx,marcy);//segundo

     teta = PI*marcmin/180;
     marcx=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-110)/180);
     marcy=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     marcx2=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-110)/180);
     marcy2=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(LIGHTRED);
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
     setcolor(LIGHTGREEN);
     line(x0,y0,pxs,pys);//segundo
     delay(100);
     setcolor(BLACK);
     line(x0,y0,pxs,pys);//segundo

     teta = PI*pmin/180;
     pxm=x0+(RAIO-8)*cos(teta)*cos(PI*(RO-110)/180);
     pym=y0+(RAIO-8)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(LIGHTRED);
     line(x0,y0,pxm,pym);//minuto

     teta = PI*phora/180;
     pxh=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
     pyh=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
     setcolor(YELLOW);
     line(x0,y0,pxh,pyh);//hora

     pseg=pseg-6;

     if(pseg<=-270)
     {
      setcolor(BLACK);
      line(x0,y0,pxm,pym);
      pxh=x0+(RAIO-2)*cos(teta)*cos(PI*(RO-20)/180);
      pyh=y0+(RAIO-2)*sin(teta)*cos(PI*(FI-20)/180);
      line(x0,y0,pxh,pyh);
      pmin=pmin-6;
      phora=phora+0.5;
      pseg=90;//minuto
     }

     }while(!kbhit());




     tecla=getch();

     if(tecla=='8')
     {
      FI=FI+5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='2')
     {
      FI=FI-5;
      marcmin=-90;
      cleardevice();
     }
       if(tecla=='6')
     {
      RO=RO-5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='4')
     {
      RO=RO+5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='9')
     {
      FI=FI+5;
      RO=RO-5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='7')
     {
      FI=FI+5;
      RO=RO+5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='3')
     {
      FI=FI-5;
      RO=RO-5;
      marcmin=-90;
      cleardevice();
     }
      if(tecla=='1')
     {
      FI=FI-5;
      RO=RO+5;
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
      if(tecla=='+')
     {
      RAIO=RAIO+5;
      marcmin=-90;
      cleardevice();
     }
      if((tecla=='-')&&(RAIO>25))
     {
      RAIO=RAIO-5;
      marcmin=-90;
      cleardevice();
     }


   }while(tecla!=27);

}