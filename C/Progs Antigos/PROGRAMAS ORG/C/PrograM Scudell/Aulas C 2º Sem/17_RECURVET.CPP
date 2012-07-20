#include <stdio.h>
#include <conio.h>
#include <math.h>

double fat(int n)
{
  if(n==0)
    return 1;
  else
    return(n*fat(n-1));
}

float ex(float x, int n)
{
  if(n==0)
    return 1;
  else
    return(pow(x,n)/fat(n)+ex(x,n-1));
}


void main()
{
  float s,x;
  int n;
  clrscr();
  printf("\n\n\t Numero de termos da serie: ");
  scanf("%d",&n);
  printf("\n\n\t Valor de x: ");
  scanf("%f",&x);
  s=ex(x,n);
  printf("\n\n\t Valor de E elevado a %.2f = %.6f",x,s);
  getch();
}