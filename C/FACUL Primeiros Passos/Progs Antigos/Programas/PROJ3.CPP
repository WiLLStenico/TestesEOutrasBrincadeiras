#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>


   void main(void)
   {

   int graphmode, graphdriver;
   int curr_mode;

   int posx, posy, dest, x, y;
   int cx, cy, cr;
   float FI, PI, RAIO, RO, TETA,TETA2, X0, Y0, XL, YL, XL1, YL1;
   char tecla;
   int a, b,I;


   detectgraph (&graphdriver, &graphmode);

   initgraph (&graphdriver, &graphmode, "c:\\borlandc\\bgi");


  do{

   PI = 3.14159265358979;
   X0 = 130;
   Y0 = 250;
   I = -90;
   RO = 0;
   FI = 0;
   RAIO=8;

   setfillstyle(1,LIGHTBLUE);
   floodfill(0,0,LIGHTBLUE);

   setcolor(GREEN);
   rectangle(0,280,700,600);
   setfillstyle(1,GREEN);
   floodfill(15,295,GREEN);
   // Arvore
   /*   setcolor(BROWN);
   rectangle(420,320,485,120);
   setfillstyle(1,BROWN);
   floodfill(420,320,BROWN); */
   setcolor(BROWN);
   outtextxy(425,110,"ЫЫЫЫЫЫЫ");
   outtextxy(425,118,"ЫЫЫЫЫЫЫ");
   outtextxy(425,126,"ЫЫЫЫЫЫЫ");
   outtextxy(425,134,"ЫЫЫЫЫЫЫ");
   outtextxy(425,142,"ЫЫЫЫЫЫЫ");
   outtextxy(425,150,"ЫЫЫЫЫЫЫ");
   outtextxy(425,158,"ЫЫЫЫЫЫЫ");
   outtextxy(425,166,"ЫЫЫЫЫЫЫ");
   outtextxy(425,174,"ЫЫЫЫЫЫЫ");
   outtextxy(425,152,"ЫЫЫЫЫЫЫ");
   outtextxy(425,160,"ЫЫЫЫЫЫЫ");
   outtextxy(425,168,"ЫЫЫЫЫЫЫ");
   outtextxy(425,176,"ЫЫЫЫЫЫЫ");
   outtextxy(425,184,"ЫЫЫЫЫЫЫ");
   outtextxy(425,192,"ЫЫЫЫЫЫЫ");
   outtextxy(425,200,"ЫЫЫЫЫЫЫ");
   outtextxy(425,208,"ЫЫЫЫЫЫЫ");
   outtextxy(425,216,"ЫЫЫЫЫЫЫ");
   outtextxy(425,224,"ЫЫЫЫЫЫЫ");
   outtextxy(425,232,"ЫЫЫЫЫЫЫ");
   outtextxy(425,240,"ЫЫЫЫЫЫЫ");
   outtextxy(425,248,"ЫЫЫЫЫЫЫ");
   outtextxy(425,256,"ЫЫЫЫЫЫЫ");
   outtextxy(425,264,"ЫЫЫЫЫЫЫ");
   outtextxy(425,272,"ЫЫЫЫЫЫЫ");
   outtextxy(425,280,"ЫЫЫЫЫЫЫ");
   outtextxy(425,288,"ЫЫЫЫЫЫЫ");
   outtextxy(425,296,"ЫЫЫЫЫЫЫ");
   outtextxy(425,304,"ЫЫЫЫЫЫЫ");
   outtextxy(425,312,"ЫЫЫЫЫЫЫ");

   setfillstyle(1,GREEN);
   setcolor(GREEN);
   circle(410,100,50);
   floodfill(410,100,GREEN);
   setfillstyle(1,GREEN);

   setcolor(GREEN);
   circle(490,100,50);
   floodfill(490,100,GREEN);
   setfillstyle(1,GREEN);

   setcolor(GREEN);
   circle(455,140,40);
   floodfill(455,140,GREEN);
   setfillstyle(1,GREEN);

   setcolor(GREEN);
   circle(455,60,40);
   floodfill(455,60,GREEN);
   setfillstyle(1,GREEN);

   //Alvo
   cx=450;
   cy=250;
   cr=50;



   setfillstyle(1,WHITE);

   //Nuvens
   setcolor(WHITE);
   circle(100,100,cr-40);
   floodfill(100,100,WHITE);
   setfillstyle(1,WHITE);

   setcolor(WHITE);
   circle(120,100,cr-35);
   floodfill(120,100,WHITE);
   setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(140,100,cr-40);
    floodfill(140,100,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(260,50,cr-35);
    floodfill(260,50,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(280,50,cr-30);
    floodfill(280,50,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(305,50,cr-30);
    floodfill(305,50,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(330,50,cr-35);
    floodfill(330,50,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(540,150,cr-45);
    floodfill(540,150,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(550,150,cr-42);
    floodfill(550,150,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(560,150,cr-42);
    floodfill(560,150,WHITE);
    setfillstyle(1,WHITE);

    setcolor(WHITE);
    circle(570,150,cr-45);
    floodfill(570,150,WHITE);
    setfillstyle(1,YELLOW);
    //Sol
    setcolor(YELLOW);
    circle(570,40,40);
    floodfill(570,40,YELLOW);
    setfillstyle(1,YELLOW);
    //Faca

    do{
    if(X0<=440)
    {
    if(X0==440)
    {
    setfillstyle(1,LIGHTBLUE);
    setcolor(LIGHTBLUE);
    setfillstyle(1,LIGHTBLUE);
    circle(cx,cy,cr);
    floodfill(cx,cy,LIGHTBLUE);
   }
   if((X0>405)&&(X0<420))
    {
    setfillstyle(1,RED);
    setcolor(RED);
    setfillstyle(1,RED);
    circle(cx,cy,cr);
    floodfill(cx,cy,RED);
   }

   if((X0<=135)||(X0==440))
   {setfillstyle(1,RED);
    setcolor(RED);
    circle(cx,cy,cr);
    floodfill(cx,cy,RED);
    setfillstyle(1,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    circle(cx,cy,cr-10);
    floodfill(cx,cy,LIGHTGRAY);
    setfillstyle(1,RED);

   setcolor(RED);
   circle(cx,cy,cr-20);
   floodfill(cx,cy,RED);
   setfillstyle(1,LIGHTGRAY);

   setcolor(LIGHTGRAY);
   circle(cx,cy,cr-30);
   floodfill(cx,cy,LIGHTGRAY);
   setfillstyle(1,RED);

   setcolor(RED);
   circle(cx,cy,cr-40);
   floodfill(cx,cy,RED);
   }
    TETA = PI*I/180;
    XL = X0 + RAIO*cos(TETA)*cos(PI*RO/180);
    YL = Y0 + RAIO*sin(TETA)*cos(PI*FI/180);
    XL1 = X0 - RAIO*cos(TETA)*cos(PI*RO/180);
    YL1 = Y0 - RAIO*sin(TETA)*cos(PI*FI/180);
    /* setcolor(BLUE);
    line(X0,Y0,XL,YL);
    setcolor(BLUE);
    line(X0,Y0,XL1,YL1);*/

    setcolor(WHITE);
    line(X0,Y0,XL,YL);
    setcolor(BROWN);
    line(X0,Y0,XL1,YL1);

    //while (X0>=440);
    //if(X0>=440);

    if(X0<405)
    {
    TETA2 = PI*(I-3)/180;
    XL = X0-2 + RAIO*cos(TETA2)*cos(PI*RO/180);
    YL = Y0 + RAIO*sin(TETA2)*cos(PI*FI/180);
    XL1 = X0-2 - RAIO*cos(TETA2)*cos(PI*RO/180);
    YL1 = Y0 - RAIO*sin(TETA2)*cos(PI*FI/180);
    setcolor(LIGHTBLUE);
    line(X0-2,Y0,XL,YL);
    //setcolor(BROWN);
    line(X0-2,Y0,XL1,YL1);
    }
     if((X0>405) &&(X0<430))
    {
    TETA2 = PI*(I-3)/180;
    XL = X0-2 + RAIO*cos(TETA2)*cos(PI*RO/180);
    YL = Y0 + RAIO*sin(TETA2)*cos(PI*FI/180);
    XL1 = X0-2 - RAIO*cos(TETA2)*cos(PI*RO/180);
    YL1 = Y0 - RAIO*sin(TETA2)*cos(PI*FI/180);
    setcolor(RED);
    line(X0-2,Y0,XL,YL);
    line(X0-2,Y0,XL1,YL1);
    }
    }

   // cleardevice();
    I+=3;
    X0+=2;

    //Homem
    posx=150;
    posy=250;
    dest=10;
    setcolor(14);

    //Tronco
    setcolor(YELLOW);
    line(posx, posy+10, posx, posy+40);

    //Pernas
    line(posx, posy+40, posx+10, (posy+70));
    line(posx, posy+40, posx-10, (posy+70));

    //Bra‡os
    line(posx, posy+18, posx+20, posy+15);
    line(posx, posy+18, posx-15, posy+35);

    //Bra‡o mexendo
    if(X0<=200)
    {
    setcolor(LIGHTBLUE);
    a = (int)( posx+10 + 20*cos(TETA2)*cos(PI*0/180));
    b = (int)( posy+10 + 20*sin(TETA2)*cos(PI*0/180));
    line(posx+20, posy+15, a, b);

    setcolor(YELLOW);
    a = (int)( posx+10 + 20*cos(TETA)*cos(PI*0/180));
    b = (int)( posy+10 + 20*sin(TETA)*cos(PI*0/180));
    line(posx+20, posy+15, a, b);

    }
    line(posx+20,posy+15,a,b);
    delay(10);

    if(X0<200)
    {
    //Cabeca
    setcolor(LIGHTBLUE);
    setfillstyle(1,LIGHTBLUE);
    circle(posx, posy, dest);
    floodfill(posx,posy,LIGHTBLUE);

    }


    //Cabeca
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    circle(posx, posy, dest);
    floodfill(posx,posy,YELLOW);



    }while (!kbhit());
    tecla=getch();
    cleardevice();
    }while(tecla!=27);

    closegraph();

    }

