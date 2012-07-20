#include <stdio.h>
#include <conio.h>

void main(void)
{
   clrscr();
  int i,j,m,l;
  float k;
  float a[10][10];
  gotoxy(35,5);
  printf("Dimensao da matriz: ");
  scanf("%d",&m);
  gotoxy(35,5);
  printf("Elemnetos da matriz");
  for(i=0;i<m;i++)
   for(j=0;j<m;j++)
   {
    gotoxy(35,10);clreol();
    printf("Elemento[%d,%d]= ",i+1,j+1);
    scanf("%f",&a[i][j]);
   }

   gotoxy(35,12);
   printf("Valor da constante= ");
   scanf("%f",&k);
   for(i=0;i<m;i++)
    a[i][i]*=k;
   clrscr();
   l=10;
   for(i=0;i<m;i++)
    {
     gotoxy(35,l);
     for(j=0;j<m;j++)
      
       printf("%3.1f  ",a[i][j]);
       l+=2;

     }

   getch();
}