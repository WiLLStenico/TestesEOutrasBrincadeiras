#include<stdio.h>     /* Para scanf() e printf()  */
#include<conio.h>     /* Para getch()             */
//#include<stdlib.h>    /* Para comandos gen‚ricos? */
#include <graphics.h> /* Para comandos gr ficos   */
#include <math.h>     /* Para sqrt() e outras...  */
#include <dos.h>      /* Para delay e outras...   */

void opengraph(void)
   {
      int driver, mode;

      detectgraph(&driver, &mode);
      initgraph(&driver, &mode, "c:\\borlandc\\bgi");
   }

sqr(float y)
   {
      float z;
      z = y*y;
      return z;
   }

void main(void)
   {
      int I;
      float FI, PI, RAIO, RO, TETA, X0, Y0, XL, YL;
      char tecla;

      clrscr();
      printf("Tecle <ESC> para sair do programa");
      printf("\n\nDigite o valor inicial do raio do c¡rculo ");
      scanf("%f",&RAIO);
      printf("Raio digitado = %f",RAIO);
      getch();

      opengraph();
      setbkcolor(BLACK);
//      textcolor(LIGHTMAGENTA);
//      textcolor(BLACK);

//      cleardevice();
      clrscr;   /* O uso dos parˆnteses ‚ opcional... */

      PI = 3.14159265358979;
      X0 = 320;
      Y0 = 240;
      I = -90;
      RO = 0;
      FI = 0;

      do
	 {
	    do
	       {
		  TETA = PI*I/180;
		  XL = X0 + RAIO*cos(TETA)*cos(PI*RO/180);
		  YL = Y0 + RAIO*sin(TETA)*cos(PI*FI/180);
		  setcolor(BROWN);
		  line(X0,Y0,XL,YL);
		  delay(5);
		  setcolor(14/*YELLOW*/);
		  ellipse(X0,Y0,0,360,abs(RAIO*cos(PI*RO/180)),abs(RAIO*cos(PI*FI/180)));
		  setfillstyle(SOLID_FILL,14);
		  floodfill(X0,Y0,14);
		  line(X0,Y0,XL,YL);
		  I += 1;
	       }
	    while (!kbhit()); /* do nothing */
	    tecla = getch(); /*scanf("%c", tecla);*/
	    if ( (int)(tecla)==72 /* seta para cima */)     FI += 5;
	    if ( (int)(tecla)==80 /* seta para baixo */)    FI -= 5;
	    if ( (int)(tecla)==75 /* seta para esquerda */) RO -= 5;
	    if ( (int)(tecla)==77 /* seta para direita */)  RO += 5;
	    if ( (int)(tecla)==43 /* tecla <+> */)          RAIO += 5;
	    if ( (int)(tecla)==45 /* tecla <-> */)          RAIO -= 5;
	    if ( (int)(tecla)==46)/*tecla <.>*/
	    {
	      if((X0<550)&&(RAIO>=1))
	      {
	       RAIO=RAIO-1;
	       X0=X0+3;Y0=Y0-1;
	       delay(8);
	      }



	    }




	    cleardevice();  /* clrscr();*/
	 }
      while((int)(tecla) != 27 /* tecla <ESC> */);
      closegraph();
//      printf("%c", tecla);
//      getch();
   }
