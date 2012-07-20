#include <stdio.h>
#include <conio.h>

int mdc( int g, int w)
{
if (w==0)
return g;
else
return (mdc(g,w%g));
}





void main(void)
{

  int g,w,resto;
  printf("Primeiro Numero");
  scanf("%d", g);
  printf("Segundo Valor");
  scanf("%d", w);
  resto=mdc(g,w);
  printf("\n \n MDC de %d e %d = %d", g,w,resto);



  clrscr();

  getch ();
}
