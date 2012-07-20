#include <stdio.h>
#include <conio.h>

int transforma(int seg,int *hora, int *min)
{
int r;
*hora=seg/3600;
r=seg%3600;
*min=r/60;
seg=r%60;
return seg;
}

void main(void)
{
   int s,seg,hs,min;
   clrscr();
   printf ("\n \n Tempo em segundos: ");
   scanf("%d", &seg);
   s=transforma(seg,&hs,&min);
   printf("\n \n Tempo transformado : %dh %dmin %dseg", hs, min, s);

   

   getch();
}