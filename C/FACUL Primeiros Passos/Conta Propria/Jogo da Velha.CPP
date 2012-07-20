#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void main(void)
{
   int v[10],rep[10];
   float x,y;
   int jog1,i,jog2,venc,emp;
   char cont;





  do
  {

   //inicio
   clrscr();
   textbackground('BLACK');
   textcolor(WHITE);
   clrscr();
   gotoxy(6,5);
   cprintf("| |");
   gotoxy(5,6);
   cprintf("-|-|-");
   gotoxy(6,7);
   cprintf("| |");
   gotoxy(5,8);
   cprintf("-|-|-");
   gotoxy(6,9);
   cprintf("| |");


   textcolor(LIGHTRED);
   gotoxy(15,5);
   cprintf("7   9");
   gotoxy(15,7);
   textcolor(LIGHTBLUE);
   cprintf("4   6");
   gotoxy(15,9);
   textcolor(LIGHTRED);
   cprintf("1   3");


   textcolor(WHITE);
   gotoxy(16,5);
   cprintf("| |");
   gotoxy(15,6);
   cprintf("-|-|-");
   gotoxy(16,7);
   cprintf("| |");
   gotoxy(15,8);
   cprintf("-|-|-");
   gotoxy(16,9);
   cprintf("| |");

   gotoxy(17,5);
   textcolor(LIGHTBLUE);
   cprintf("8");
   gotoxy(17,9);
   cprintf("2");
   textcolor(LIGHTRED);
   gotoxy(17,7);
   cprintf("5");
   //fim tabuleiros

   x=y=7;

   for(i=1;i<=9;i++)
   {
    v[i]=0;rep[i]=0;
   }

   jog1=0;jog2=0;venc=0;emp=1;

   //zerando matrizes e definindo inicio de variaveis

   gotoxy(1,2);
   textcolor(LIGHTGREEN);
   cprintf("*********** WiLLiaM H. Stenico ********************************Term 26/07/07****");

 do
 {





  while((jog1<=0)||(jog1>9)||(v[jog1]!=0))
  {


   textcolor(LIGHTRED);
   gotoxy(5,15);
   cprintf("Jogador \"X\" selecione sua jogada: ");
   clreol();
   cscanf("%d",&jog1);
   venc=1;
  }


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
     gotoxy(5,15);
     cprintf("Jogador \"O\" selecione sua jogada: ");
     clreol();
     cscanf("%d",&jog2);
     venc=2;
     }
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


  gotoxy(5,15);
  clreol();

  if(((v[1]!=1)||(v[2]!=1)||(v[3]!=1))&&((v[4]!=1)||(v[5]!=1)||(v[6]!=1))&&((v[7]!=1)||(v[8]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[4]!=1)||(v[7]!=1))&&((v[2]!=1)||(v[5]!=1)||(v[8]!=1))&&((v[3]!=1)||(v[6]!=1)||(v[9]!=1))&&((v[1]!=1)||(v[5]!=1)||(v[9]!=1))&&((v[3]!=1)||(v[5]!=1)||(v[7]!=1))&&((v[1]!=2)||(v[2]!=2)||(v[3]!=2))&&((v[4]!=2)||(v[5]!=2)||(v[6]!=2))&&((v[7]!=2)||(v[8]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[4]!=2)||(v[7]!=2))&&((v[2]!=2)||(v[5]!=2)||(v[8]!=2))&&((v[3]!=2)||(v[6]!=2)||(v[9]!=2))&&((v[1]!=2)||(v[5]!=2)||(v[9]!=2))&&((v[3]!=2)||(v[5]!=2)||(v[7]!=2))&&(emp==6))
     {
    textcolor(CYAN);
    cprintf("JOGO EMPATADO!!");clreol();
   }
    else if(venc==1)
	  {
	   textcolor(LIGHTGREEN);
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
	   gotoxy(5,15);
	   textcolor(LIGHTRED);
	   cprintf("Parabens!!!!!!! Jogador \"X\" Venceu!!");clreol();
	  }
	  else
	  {
	   textcolor(LIGHTGREEN);
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
	   gotoxy(5,15);
	   textcolor(LIGHTBLUE);
	   cprintf("Parabens!!!!!!! Jogador \"O\" Venceu!!");clreol();
	  }

     //verifica quem ganhou
  do
  {
  textcolor(CYAN);
  gotoxy(15,17);
  cprintf("Continuar?? S/N: ");clreol();
  toupper;
  cscanf("%c",&cont);
  }while((cont!='S')&&(cont!='N'));
  }while(cont=='S');

 }

