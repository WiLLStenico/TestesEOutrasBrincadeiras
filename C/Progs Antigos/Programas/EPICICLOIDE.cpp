#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

void opengraph(void)
   {
      int driver, mode;

      detectgraph(&driver, &mode);
      initgraph(&driver, &mode, "c:\\borlandc\\bgi");
   }
void main(void)
   {
      int I;
      float FI, PI, RAIO, VELOCIDADE, RO, TETA2, TETA, X0, Y0, XL, YL, XK, YK,
      J, LOOP, RASTRO, LADO, OPC, MENU;
      char tecla;
      int driver, mode;



      clrscr();
      gotoxy(10,7);
      printf("Sistema desenvolvido por:");
      gotoxy(10,8);
      printf("Adilson Perecin");
      gotoxy(10,9);
      printf("Cristiano Benato");
      gotoxy(10,11);
      printf("Professor orientador: Odahyr Cavallini");
      gotoxy(10,13);
      printf("Ciencia da Computa‡ao");
      gotoxy(10,15);
      printf("Escola de Engenharia de Piracicaba");
      gotoxy(10,18);
      printf("Pressione qualquer tecla para continuar...");
      getch();


      /*
      Entrada de dados
      */


      do
      {
	      clrscr();
	      gotoxy(10,3);
	      printf("Menu Principal");
	      printf("\nPressione 1 para usuario normal.");
	      printf("\nPressione 2 para teste de giro da elipse 3.");
	      printf("\n\n\n\nDigite a op‡ao desejada: ");
	      scanf("%f",&OPC);
      }
      while(OPC<1||OPC>2);

      if(OPC==1)
      {
	      do
		{
			clrscr();
			gotoxy(1,4);
			printf("\nDigite o valor inicial do raio da elipse(1) (fixa)\n(50 at‚ 200): ");
			scanf("%f",&RAIO);
		}
	      while(RAIO<50||RAIO>200);
	      do
		{
			clrscr();
			gotoxy(1,4);
			printf("\nDigite a velocidade de giro da elipse(2) (girat¢ria)\n(1 at‚ 3): ");
			scanf("%f",&VELOCIDADE);
		}
	      while(VELOCIDADE<1||VELOCIDADE>3);

	      do
		{
			clrscr();
			gotoxy(1,4);
			printf("\nDigite a velocidade de giro da elipse(3) (girat¢ria)\n(1 at‚ 3): ");
			scanf("%f",&LOOP);
		}
	      while(LOOP<1||LOOP>3);

	      do
		{
			clrscr();
			gotoxy(1,4);
			printf("\nGostaria que a elipse(3) possua rastro\n(1-sim 0-nao): ");
			scanf("%f",&RASTRO);
		}
	      while(RASTRO<0||RASTRO>1);

	      do
		{
			clrscr();
			gotoxy(1,4);
			printf("\nGostaria que a roda externa(2) gire internamente a roda fixa(1)?\n(1-sim 0-nao): ");
			scanf("%f",&LADO);
		}
	      while(LADO<0||LADO>1);
	      clrscr();
	      gotoxy(5,1);
	      printf("Informa‡oes gerais.");
	      gotoxy(1,2);
	      printf("\nRaio da elipse 1: %f",RAIO);
	      printf("\nRaio da elipse 2: 40.000000");
	      printf("\nRaio da elipse 3: 10.000000");
	      printf("\nVelocidade de giro da elipse 1: %f",VELOCIDADE);
	      printf("\nVelocidade de giro da elipse 2: %f",LOOP);
	      if(RASTRO==1)
		printf("\nVoce escolheu que a elipse 3 possua rastro.");
	      else
		printf("\nVoce escolheu que a elipse 3 nao possua rastro.");
	      if(LADO==1)
		printf("\nVoce escolheu que a elipse 2 gire internamente a elipse 1.");
	      else
	      printf("\nVoce escolheu que a elipse 2 nao gire internamente a elipse 1.");
	      printf("\n\nA qualque momento voce pode pressionar 0 para exibir o Menu de Comandos.");
	      printf("\n\nPressione qualquer tecla para continuar...");
	      getch();
	      clrscr();
	      gotoxy(5,1);
	      printf("Menu de Comandos: ");
	      printf("\n\n\ntecla 5: adciona rastro");
	      printf("\n\nTecla 1: Move todo o conjunto para a diagonal inferior esquerda.");
	      printf("\nTecla 2: Move todo o conjunto para baixo.");
	      printf("\nTecla 3: Move todo o conjunto para a diagonal inferior direita.");
	      printf("\nTecla 4: Move todo o conjunto para a esquerda.");
	      printf("\n\nTecla 6: Move todo o conjunto para a direita.");
	      printf("\nTecla 7: Move todo o conjunto para a diagonal superior esquerda.");
	      printf("\nTecla 8: Move todo o conjunto para cima.");
	      printf("\nTecla 9: Move todo o conjunto para a diagonal superior direita.");
	      printf("\n\n\n\nPressione qualquer tecla para continuar...");
	      getch();
      }
      else
      {
      RAIO=100;
      VELOCIDADE=0;
      LOOP=3;
      RASTRO=0;
      LADO=0;
      }


      /*
      inicia a proje‡ao gr fica
      */


      opengraph();
      clrscr();
      LOOP = LOOP + 3;
      PI = 3.14159265358979;
      X0 = 320;
      Y0 = 240;
      I  = -90;
      J  = 0;
      RO = 0;
      if(LADO==1)
	  RAIO = -RAIO;
      MENU=0;
      FI = 0;
      int posx = 320;
      int posy = 240;
      cleardevice();
      setbkcolor(GREEN);
      if(MENU==1)
	  {
		  gotoxy(1,1);
		  printf("tecla 5: adciona rastro.");
		  printf("\ntecla 1: move todo o conjunto para a diagonal inferior esquerda.");
		  printf("\ntecla 2: move todo o conjunto para baixo.");
		  printf("\ntecla 3: move todo o conjunto para a diagonal inferior direita.");
		  printf("\ntecla 4: move todo o conjunto para a esquerda.");
		  printf("\ntecla 5: move todo o conjunto para a direita.");
		  printf("\ntecla 7: move todo o conjunto para a diagonal superior esquerda.");
		  printf("\ntecla 8: move todo o conjunto para cima.");
		  printf("\ntecla 9: move todo o conjunto para a diagonal superior direita.");
		  printf("\ntecla X: Aumenta a velocidade da elipse 3.");
		  printf("\ntecla Z: Diminui a velocidade da elipse 3.");
		  printf("\ntecla A: Aumenta a velocidade da elipse 2.");
		  printf("\ntecla S: Diminui a velocidade da elipse 2.");
	  }
      do
	 {
	    do
	       {
		  if(MENU==1)
		  {
			  gotoxy(1,1);
			  printf("Tecla 5: adciona rastro");
			  printf("\nTecla 1: Move todo o conjunto para a diagonal inferior esquerda.");
			  printf("\nTecla 2: Move todo o conjunto para baixo.");
			  printf("\nTecla 3: Move todo o conjunto para a diagonal inferior direita.");
			  printf("\nTecla 4: Move todo o conjunto para a esquerda.");
			  printf("\nTecla 5: Move todo o conjunto para a direita.");
			  printf("\nTecla 7: Move todo o conjunto para a diagonal superior esquerda.");
			  printf("\nTecla 8: Move todo o conjunto para cima.");
			  printf("\nTecla 9: Move todo o conjunto para a diagonal superior direita.");
			  printf("\nTecla 0: Esconde este menu.");
			  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTecla X: Aumenta a velocidade da elipse 3.");
			  printf("\nTecla Z: Diminui a velocidade da elipse 3.");
			  printf("\nTecla A: Aumenta a velocidade da elipse 2.");
			  printf("\nTecla S: Diminui a velocidade da elipse 2.");
		  }
		  setcolor(7);
		  TETA = PI*I/180;
		  TETA2 = PI*J/180;
		  XL = X0 + (RAIO+40)*cos(TETA)*cos(PI*RO/180);
		  YL = Y0 + (RAIO+40)*sin(TETA)*cos(PI*FI/180);
		  XK = XL + (35)*cos(TETA2)*cos(PI*RO/180);
		  YK = YL + (35)*sin(TETA2)*cos(PI*FI/180);
		  setcolor(RED);
		  ellipse(posx,posy,0,360,abs(RAIO*cos(PI*RO/180)),abs(RAIO*cos(PI*FI/180)));
		  ellipse(XL,YL,0,360,abs(40*(cos(PI*RO/180))),abs(40*(cos(PI*FI/180))));
		  delay(10);
		  setcolor(GREEN);
		  ellipse(XL,YL,0,360,abs(40*(cos(PI*RO/180))),abs(40*(cos(PI*FI/180))));
		  I = I + VELOCIDADE;
		  setcolor(RED);
		  ellipse(XK,YK,0,360,abs(5*(cos(PI*RO/180))),abs(5*(cos(PI*FI/180))));
		  J = J + LOOP;

		  if(RASTRO==0)
		     {
			delay(10);
			setcolor(GREEN);
			ellipse(XK,YK,0,360,abs(5*(cos(PI*RO/180))),abs(5*(cos(PI*FI/180))));
		     }

	       }

	    while (!kbhit());
	    clrscr();

	    /*
	    Capta as teclas pressionadas
	    */

	    tecla = getch();
	    if ( (int)(tecla)==72) /*seta para cima*/
	    {
		if((FI += 5)>=360)
			FI = 0;
		else
			FI += 5;
	    }
	    if ( (int)(tecla)==80 /* seta para baixo */)
	    {
		if((FI -= 5)<=0)
		   FI=360;
		else
		   FI -= 5;
	    }
	    if ( (int)(tecla)==75 /* seta para esquerda */)
	    {
		if((RO -= 5)<=0)
		   RO=360;
		else
		   RO -= 5;
	    }
	    if ( (int)(tecla)==77 /* seta para direita */)
	    {
	      if((RO += 5)>=360)
		RO = 0;
	      else
		RO += 5;
	    }
	    if ( (int)(tecla)==43 /* tecla <+> */)
	    RAIO += 5;
	    if ( (int)(tecla)==45 /* tecla <+> */)
	    RAIO -= 5;
	    if ( (int)(tecla)==54 /* tecla 6   */)
	    {
		posx += 5;
		X0 += 5;
	    }
	    if ( (int)(tecla)==52 /* tecla 4   */)
	    {
		posx -=5;
		X0 -= 5;

	    }

	    if ((int)(tecla)==56 /* tecla 8  */)
	    {
		posy -=5;

		Y0-=5;
	    }

	    if ((int)(tecla)==50 /* tecla 2 */)
	    {
		posy +=5;
		Y0+=5;
	    }
	    if ((int)(tecla)==49 /* tecla 1 */)
	    {
		posy +=5;
		Y0+=5;
		posx -=5;
		X0 -= 5;
	    }
	    if ((int)(tecla)==51 /* tecla 3 */)
	    {
		posy +=5;
		Y0+=5;
		posx += 5;
		X0 += 5;
	    }
	    if ( (int)(tecla)==55 /* tecla 7   */)
	    {
		posx -=5;
		X0 -= 5;
		posy -=5;
		Y0-=5;

	    }
	    if ((int)(tecla)==57 /* tecla 9  */)
	    {
		posy -=5;
		Y0-=5;
		posx += 5;
		X0 += 5;
	    }
	    if ((int)(tecla)==53 /* tecla 5  */)
	    {
		if(RASTRO==1)
			RASTRO=0;
		else
			RASTRO=1;
	    }
	    if ((int)(tecla)==48 /* tecla 0  */)
	    {
		if(MENU==1)
			MENU=0;
		else
			MENU=1;
	    }
	    if ( (int)(tecla)==120 /* tecla x   */)
	    {
		LOOP++;
	    }
	    if ( (int)(tecla)==122 /* tecla z   */)
	    {
		LOOP--;
	    }
	    if ( (int)(tecla)==97 /* tecla a   */)
	    {
		VELOCIDADE++;
	    }
	    if ( (int)(tecla)==115 /* tecla s   */)
	    {
		VELOCIDADE--;
	    }
	     cleardevice();  /* clrscr();*/

	 }
      while((int)(tecla) != 27 /* tecla <ESC> */);
      closegraph();
   }

