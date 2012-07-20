
/* WiLLiaM Henrique Stenico R.A.: 300070489 */

#include <stdio.h>
#include <conio.h>



void main(void)

{
 textbackground(WHITE);
 textcolor(BLUE);
 int codigo[6];
 int col,lin,i;
 float salm;
 float venda[6], pagamento[6];
 clrscr();

 col=2;

 while(col<=79)
 {
  gotoxy(col,1);
  printf("* ");
  gotoxy(col,24);
  printf("*");
  col=col+2;
 }
 lin=2;

 while(lin<=23)
 {
  gotoxy(1,lin);
  printf("*");
  gotoxy(80,lin);
  printf("*");
  lin=lin+1;
 }

  gotoxy(20,10);
  printf("Digite o Valor do Salario M¡nimo:  ");
  scanf("%f",&salm);
  clrscr();

   col=2;

 while(col<=79)
 {
  gotoxy(col,1);
  printf("* ");
  gotoxy(col,24);
  printf("*");
  col=col+2;
 }
 lin=2;

 while(lin<=23)
 {
  gotoxy(1,lin);
  printf("*");
  gotoxy(80,lin);
  printf("*");
  lin=lin+1;
 }




  for(i=1;i<6;i++)
  {
   gotoxy(12,10);
   printf("Digite o C¢digo do Vendedor:  ");
   scanf("%d",&codigo[i]);
   gotoxy(12,12);
   printf("Digite o Total das Vendas deste Funcionario:  ");
   scanf("%f",&venda[i]);
    pagamento[i]=salm+venda[i]*0.05;
   gotoxy(12,10);
   clreol();
   gotoxy(12,12);
   clreol();
 }

  clrscr();

  col=2;

 while(col<=79)
 {
  gotoxy(col,1);
  printf("* ");
  gotoxy(col,24);
  printf("*");
  col=col+2;
 }
 lin=2;

 while(lin<=23)
 {
  gotoxy(1,lin);
  printf("*");
  gotoxy(80,lin);
  printf("*");
  lin=lin+1;
 }

 gotoxy(5,8);
 printf("Funcion rio");
 gotoxy(25,8);
 printf("Total das Vendas(R$)");
 gotoxy(55,8);
 printf("Sal rio a Receber(R%)");
 lin=10;
 for(i=1;i<6;i++)
 {
  gotoxy(8,lin);
  printf("%d",codigo[i]);
  gotoxy(32,lin);
  printf("%5.2f",venda[i]);
  gotoxy(64,lin);
  printf("%5.2f",pagamento[i]);
  lin=lin+2;
 }

  col=2;

 while(col<=79)
 {
  gotoxy(col,1);
  printf("* ");
  gotoxy(col,24);
  printf("*");
  col=col+2;
 }
 lin=2;

 while(lin<=23)
 {
  gotoxy(1,lin);
  printf("*");
  gotoxy(80,lin);
  printf("*");
  lin=lin+1;
 }
  printf("Nome: WiLLiaM Henrique Stenico\nR.A.: 300070489");



  getch();

}











