#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void nome()
{
int w;
textcolor(LIGHTGREEN);
 gotoxy(1,24);
 cprintf("----------------------     ----------------------     --------------------------");
 gotoxy(1,22);
 cprintf("   -------------------     ----------------------     -------------------");
 gotoxy(2,23);
 cprintf("  W  i  L  L  i  a  M     H  e  n  r  i  q  u  e     S  t  e  n  i  c  o     ");
 gotoxy(1,1);
 cprintf("*************************** J O G O   D A  V E L H A ***************************");
 gotoxy(1,2);
 cprintf("--------------------------------------------------------------------------------");
 for(w=3;w<=23;w++)
 {
  gotoxy(1,w);
  cprintf("I");
  gotoxy(80,w);
  cprintf("I");
 }
return;
}

void main(void)
{
   int v[10],rep[10];
   float x,y;
   int jog1,i,jog2,venc,emp,tpo,total;
   char cont;





  do
  {
   clrscr();
   nome();
   gotoxy(30,10);
   textcolor(YELLOW);
   cprintf("1- 1 Player Vs PC");
   gotoxy(30,12);
   cprintf("2- 2 Players");
   gotoxy(25,15);
   cprintf("Digite o N£mero de Jogadores: ");
   cscanf("%d",&tpo);





   total=0;


   //inicio
   clrscr();
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   gotoxy(31,10);
   cprintf("| |");
   gotoxy(30,11);
   cprintf("-|-|-");
   gotoxy(31,12);
   cprintf("| |");
   gotoxy(30,13);
   cprintf("-|-|-");
   gotoxy(31,14);
   cprintf("| |");


   textcolor(LIGHTRED);
   gotoxy(47,10);
   cprintf("7   9");
   gotoxy(47,12);
   textcolor(LIGHTBLUE);
   cprintf("4   6");
   gotoxy(47,14);
   textcolor(LIGHTRED);
   cprintf("1   3");


   textcolor(WHITE);
   gotoxy(48,10);
   cprintf("| |");
   gotoxy(47,11);
   cprintf("-|-|-");
   gotoxy(48,12);
   cprintf("| |");
   gotoxy(47,13);
   cprintf("-|-|-");
   gotoxy(48,14);
   cprintf("| |");

   gotoxy(49,10);
   textcolor(LIGHTBLUE);
   cprintf("8");
   gotoxy(49,14);
   cprintf("2");
   textcolor(LIGHTRED);
   gotoxy(49,12);
   cprintf("5");
   //fim tabuleiros

   x=32;y=12;

   for(i=1;i<=9;i++)
   {
    v[i]=0;rep[i]=0;
   }

   jog1=0;jog2=0;venc=0;emp=1;

   //zerando matrizes e definindo inicio de variaveis

  nome();

 do
 {





  while((jog1<=0)||(jog1>9)||(v[jog1]!=0))
  {


   textcolor(LIGHTRED);
   gotoxy(5,20);
   cprintf("Jogador \"X\" selecione sua jogada: ");
   clreol();
   cscanf("%d",&jog1);
   venc=1;
  }
    total=total+1;

    switch(jog1)
    {

    case 1:
     {
      gotoxy(x-2,y+2);
      cprintf("X");
      v[1]=1;
      break;
     }
    case 2:
    {
     gotoxy(x,y+2);
     cprintf("X");
     v[2]=1;
     break;
    }

    case 3:
    {
     gotoxy(x+2,y+2);
     cprintf("X");
     v[3]=1;
     break;
    }

    case 4:
    {
     gotoxy(x-2,y);
     cprintf("X");
     v[4]=1;
     break;
    }

    case 5:
    {
     gotoxy(x,y);
     cprintf("X");
     v[5]=1;
     break;
    }

    case 6:
    {
     gotoxy(x+2,y);
     cprintf("X");
     v[6]=1;
     break;
    }

    case 7:
    {
     gotoxy(x-2,y-2);
     cprintf("X");
     v[7]=1;
     break;
    }

    case 8:
    {
     gotoxy(x,y-2);
     cprintf("X");
     v[8]=1;
     break;
    }

    case 9:
    {
     gotoxy(x+2,y-2);
     cprintf("X");
     v[9]=1;
     break;
    }
   }


    //jogador X


    if(((v[1]!=1)||(v[2]!=1)||(v[3]!=1))&&((v[1]!=1)||(v[4]!=1)||(v[7]!=1))&&((v[2]!=1)||(v[5]!=1)||(v[8]!=1))&&((v[3]!=1)||(v[6]!=1)||(v[9]!=1))&&((v[4]!=1)||(v[5]!=1)||(v[6]!=1))&&((v[7]!=1)||(v[8]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[5]!=1)||(v[9]!=1))&&((v[3]!=1)||(v[5]!=1)||(v[7]!=1))&&(emp<5))
    {
     //verifica se X ganhou ou se nao esta empatado para continuar o jogo
     while((jog2<=0)||(jog2>9)||(v[jog2]!=0))
     {
     textcolor(LIGHTBLUE);
     gotoxy(5,20);
     cprintf("Jogador \"O\" selecione sua jogada: ");
     clreol();
     if(tpo==1)
     {
      jog2=rand()%9;
     }
      else
      {
       cscanf("%d",&jog2);
      }
     venc=2;
     }
     total=total+1;
     switch(jog2)
     {

      case 1:
      {
      gotoxy(x-2,y+2);
      cprintf("O");
      v[1]=2;
      break;
      }
      case 2:
      {
       gotoxy(x,y+2);
      cprintf("O");
      v[2]=2;
      break;
      }

     case 3:
     {
     gotoxy(x+2,y+2);
     cprintf("O");
     v[3]=2;
     break;
     }

    case 4:
    {
     gotoxy(x-2,y);
     cprintf("O");
     v[4]=2;
     break;
    }

    case 5:
    {
     gotoxy(x,y);
     cprintf("O");
     v[5]=2;
     break;
    }

    case 6:
    {
     gotoxy(x+2,y);
     cprintf("O");
     v[6]=2;
     break;
    }

    case 7:
    {
     gotoxy(x-2,y-2);
     cprintf("O");
     v[7]=2;
     break;
    }

    case 8:
    {
     gotoxy(x,y-2);
     cprintf("O");
     v[8]=2;
     break;
    }

    case 9:
    {
     gotoxy(x+2,y-2);
     cprintf("O");
     v[9]=2;
     break;
    }
   }


   }

   emp=emp+1;//variavel para verificar empate


 } while(((v[1]!=1)||(v[2]!=1)||(v[3]!=1))&&((v[4]!=1)||(v[5]!=1)||(v[6]!=1))&&((v[7]!=1)||(v[8]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[4]!=1)||(v[7]!=1))&&((v[2]!=1)||(v[5]!=1)||(v[8]!=1))&&((v[3]!=1)||(v[6]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[5]!=1)||(v[9]!=1))&&((v[3]!=1)||(v[5]!=1)||(v[7]!=1))&&((v[1]!=2)||(v[2]!=2)||(v[3]!=2))&&((v[4]!=2)||(v[5]!=2)||(v[6]!=2))&&((v[7]!=2)||(v[8]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[4]!=2)||(v[7]!=2))&&((v[2]!=2)||(v[5]!=2)||(v[8]!=2))&&((v[3]!=2)||(v[6]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[5]!=2)||(v[9]!=2))&&((v[3]!=2)||(v[5]!=2)||(v[7]!=2))&&(emp<=5));


  //fim jogadas


  gotoxy(5,16);
  clreol();

  if(((v[1]!=1)||(v[2]!=1)||(v[3]!=1))&&((v[4]!=1)||(v[5]!=1)||(v[6]!=1))&&((v[7]!=1)||(v[8]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[4]!=1)||(v[7]!=1))&&((v[2]!=1)||(v[5]!=1)||(v[8]!=1))&&((v[3]!=1)||(v[6]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[5]!=1)||(v[9]!=1))&&((v[3]!=1)||(v[5]!=1)||(v[7]!=1))&&((v[1]!=2)||(v[2]!=2)||(v[3]!=2))&&((v[4]!=2)||(v[5]!=2)||(v[6]!=2))&&((v[7]!=2)||(v[8]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[4]!=2)||(v[7]!=2))&&((v[2]!=2)||(v[5]!=2)||(v[8]!=2))&&((v[3]!=2)||(v[6]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[5]!=2)||(v[9]!=2))&&((v[3]!=2)||(v[5]!=2)||(v[7]!=2))&&(emp==6))
     {
    textcolor(CYAN);
    cprintf("JOGO EMPATADO!!");clreol();
   }
    else if(venc==1)
	  {
	   textcolor(LIGHTGREEN+BLINK);
	   if((v[1]==v[2])&&(v[2]==v[3])&&(v[1]==1))
	    {

	     gotoxy(x-2,y+2);
	     cprintf("X");
	     gotoxy(x,y+2);
	     cprintf("X");
	     gotoxy(x+2,y+2);
	     cprintf("X");
	    } else if((v[4]==v[5])&&(v[5]==v[6])&&(v[4]==1))
		    {gotoxy(x-2,y);
		     cprintf("X");
		     gotoxy(x,y);
		     cprintf("X");
		     gotoxy(x+2,y);
		     cprintf("X");
		    }
		    else if((v[7]==v[8])&&(v[8]==v[9])&&(v[7]==1))
			 {
			  gotoxy(x-2,y-2);
			  cprintf("X");
			  gotoxy(x,y-2);
			  cprintf("X");
			  gotoxy(x+2,y-2);
			  cprintf("X");
			 }
			  else if((v[1]==v[4])&&(v[4]==v[7])&&(v[1]==1))
				 {
				  gotoxy(x-2,y+2);
				  cprintf("X");
				  gotoxy(x-2,y);
				  cprintf("X");
				  gotoxy(x-2,y-2);
				  cprintf("X");
				 }
				 else if((v[2]==v[5])&&(v[5]==v[8])&&(v[2]==1))
				 {
				  gotoxy(x,y+2);
				  cprintf("X");
				  gotoxy(x,y);
				  cprintf("X");
				  gotoxy(x,y-2);
				  cprintf("X");
				 }
				 else if((v[3]==v[6])&&(v[6]==v[9])&&(v[3]==1))
				 {
				  gotoxy(x+2,y+2);
				  cprintf("X");
				  gotoxy(x+2,y);
				  cprintf("X");
				  gotoxy(x+2,y-2);
				  cprintf("X");
				 }
				  else if((v[7]==v[5])&&(v[5]==v[3])&&(v[7]==1))
				 {
				  gotoxy(x-2,y-2);
				  cprintf("X");
				  gotoxy(x,y);
				  cprintf("X");
				  gotoxy(x+2,y+2);
				  cprintf("X");
				 }
				 else if((v[1]==v[5])&&(v[5]==v[9])&&(v[1]==1))
				 {
				  gotoxy(x-2,y+2);
				  cprintf("X");
				  gotoxy(x,y);
				  cprintf("X");
				  gotoxy(x+2,y-2);
				  cprintf("X");
				 }
	   gotoxy(32,16);
	   textcolor(LIGHTRED);
	   cprintf("Jogador \"X\" Venceu!!");clreol();
	  }
	  else
	  {
	   textcolor(LIGHTGREEN+BLINK);
	   if((v[1]==v[2])&&(v[2]==v[3])&&(v[1]==2))
	    {

	     gotoxy(x-2,y+2);
	     cprintf("O");
	     gotoxy(x,y+2);
	     cprintf("O");
	     gotoxy(x+2,y+2);
	     cprintf("O");
	    } else if((v[4]==v[5])&&(v[5]==v[6])&&(v[4]==2))
		    {gotoxy(x-2,y);
		     cprintf("O");
		     gotoxy(x,y);
		     cprintf("O");
		     gotoxy(x+2,y);
		     cprintf("O");
		    }
		    else if((v[7]==v[8])&&(v[8]==v[9])&&(v[7]==2))
			 {
			  gotoxy(x-2,y-2);
			  cprintf("O");
			  gotoxy(x,y-2);
			  cprintf("O");
			  gotoxy(x+2,y-2);
			  cprintf("O");
			 }
			  else if((v[1]==v[4])&&(v[4]==v[7])&&(v[1]==2))
				 {
				  gotoxy(x-2,y+2);
				  cprintf("O");
				  gotoxy(x-2,y);
				  cprintf("O");
				  gotoxy(x-2,y-2);
				  cprintf("O");
				 }
				 else if((v[2]==v[5])&&(v[5]==v[8])&&(v[2]==2))
				 {
				  gotoxy(x,y+2);
				  cprintf("O");
				  gotoxy(x,y);
				  cprintf("O");
				  gotoxy(x,y-2);
				  cprintf("O");
				 }
				 else if((v[3]==v[6])&&(v[6]==v[9])&&(v[3]==2))
				 {
				  gotoxy(x+2,y+2);
				  cprintf("O");
				  gotoxy(x+2,y);
				  cprintf("O");
				  gotoxy(x+2,y-2);
				  cprintf("O");
				 }
				  else if((v[7]==v[5])&&(v[5]==v[3])&&(v[7]==2))
				 {
				  gotoxy(x-2,y-2);
				  cprintf("O");
				  gotoxy(x,y);
				  cprintf("O");
				  gotoxy(x+2,y+2);
				  cprintf("O");
				 }
				 else if((v[1]==v[5])&&(v[5]==v[9])&&(v[1]==2))
				 {
				  gotoxy(x-2,y+2);
				  cprintf("O");
				  gotoxy(x,y);
				  cprintf("O");
				  gotoxy(x+2,y-2);
				  cprintf("O");
				 }
	   gotoxy(32,16);
	   textcolor(LIGHTBLUE);
	   cprintf("Jogador \"O\" Venceu!!");clreol();
	  }

     //verifica quem ganhou
     textcolor(YELLOW);
     gotoxy(29,18);
     cprintf("Jogo Finalizado em %d Jogadas",total);
     gotoxy(2,20);
     clreol();
  do
  {
  textcolor(CYAN);
  gotoxy(33,20);
  cprintf("Continuar?? S/N: ");clreol();
  toupper;
  cscanf("%c",&cont);
  }while((cont!='S')&&(cont!='N')&&(cont!='s')&&(cont!='n'));
  }while((cont=='S')||(cont=='s'));

 }

