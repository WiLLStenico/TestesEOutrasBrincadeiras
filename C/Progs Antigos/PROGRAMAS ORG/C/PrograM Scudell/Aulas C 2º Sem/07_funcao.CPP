#include <stdio.h>
#include <conio.h>

int soma(int x,int y,int z)
{
  int i,s=0;

  for(i=y;i<=z;i++)
    if(i%x==0)
      s+=i;
   return s;
}


void main()
{
  int a,b,c,resultado;
  do
  {
    clrscr();
    printf("\n\n\t Digite um numero inteiro maior que 1: ");
    scanf("%d",&a);
  }
  while(a<1);

  printf("\n\n\t Digite um outro numero inteiro: ");
  scanf("%d",&b);

  do
  {
    printf("\n\n\t Digite um numero maior que o anterior: ");
    scanf("%d",&c);
  }
  while(c<=b);

  resultado=soma(a,b,c);
  printf("\n\n\t Soma= %d",resultado);
  getch();
}