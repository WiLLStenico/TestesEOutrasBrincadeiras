#include <stdio.h>
#include <conio.h>


int pares (int n)
{
if (n==1)
return 2;
else
return (2*n+pares(n-1));
}

void main(void)
{
  int sp,n;
  clrscr();
  printf("\n \n Quantidade de pares a somar:");
  scanf("%d", &n);
  sp=pares(n);
  printf("\n \n Soma dos %d primeros pares= %d", n, sp);

  getch ();
}
