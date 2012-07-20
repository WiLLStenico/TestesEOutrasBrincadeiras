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
      int I,face,cor;
      float FI, PI, RAIO, RO, TETA, X0, Y0, XL, YL,teste,Mi,Mo,Ni,No;
      char tecla;

      clrscr();
      printf("Tecle <ESC> para sair do programa");
      printf("\n\nDigite o valor inicial do raio do c¡rculo ");
      scanf("%f",&RAIO);
      printf("Raio digitado = %f",RAIO);
      printf("\n Pressione a ou d ou w ou s para movimentar o circulo");
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
		  Mi = X0 + RAIO*cos(TETA)*cos(PI*(RO+90)/180);
		  Mo = Y0 + RAIO*sin(TETA)*cos(PI*(FI+90)/180);
		  Ni = X0 + RAIO*cos(TETA)*cos(PI*(RO+45)/180);
		  No = Y0 + RAIO*sin(TETA)*cos(PI*(FI+45)/180);
		  setcolor(5);
		  line(X0,Y0,XL,YL);
		  setcolor(BROWN);
		  line(X0,Y0,Mi,Mo);
		  setcolor(BLUE);
		  line(X0,Y0,Ni,No);
		  delay(5);
		  setcolor(WHITE);
		  circle(X0,Y0,RAIO+2);
		  setcolor(18);
		  circle(X0,Y0,RAIO);
		  setfillstyle(SOLID_FILL,18);
		  floodfill(X0,Y0,18);
		  delay(5);
		  line(X0,Y0,XL,YL);

		  line(X0,Y0,Mi,Mo);

		  line(X0,Y0,Ni,No);

		  if(abs(FI)>=360)
		   FI=0;
		  if(abs(RO)>=360)
		   RO=0;
		  I += 1;



	       }
	    while (!kbhit()); /* do nothing */
	    tecla = getch(); /*scanf("%c", tecla);*/
	    if ( (int)(tecla)==72 /* seta para cima */)
	      FI += 5;

	    if ( (int)(tecla)==80 /* seta para baixo */)
		FI -= 5;

	    if ( (int)(tecla)==75 /* seta para esquerda */)
	     RO -= 5;

	    if ( (int)(tecla)==77 /* seta para direita */)
	      RO += 5;

	    if ( (int)(tecla)==43 /* tecla <+> */)
	      RAIO += 5;
	      teste=RAIO;
	    if ( (int)(tecla)==45 /* tecla <-> */)
	       RAIO -= 5;
	       teste=RAIO;
	    if ( tecla=='w')
	    {
	      Y0=Y0-1;
	    }
	    if(tecla=='s')
	    {
	     Y0=Y0+1;
	    }
	    if(tecla=='d')
	     X0=X0+1;
	    if(tecla=='a')
	    X0=X0-1;


	    cleardevice();  /* clrscr();*/
	 }
      while((int)(tecla) != 27 /* tecla <ESC> */);
      closegraph();
//      printf("%c", tecla);
//      getch();
   }
	      //William H Stenico e Gianne Forti