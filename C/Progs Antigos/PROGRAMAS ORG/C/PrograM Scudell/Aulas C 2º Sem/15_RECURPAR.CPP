#include <stdio.h>
#include <conio.h>

int somapar(int n)
{
   if(n==1)
     return 2;
   else
     return (2*n+somapar(n-1));
}

void main()
{
int sp,n;

  clrscr();

  printf("\n\n\t Quantidade de pares a somar: ");
  scanf("%d",&n);

  sp=somapar(n);

  printf("\n\n\t Soma dos %d primeitos pares= %d",n,sp);

  getch();
}