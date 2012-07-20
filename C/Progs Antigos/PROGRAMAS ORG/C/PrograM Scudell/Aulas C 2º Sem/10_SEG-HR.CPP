#include <stdio.h>
#include <conio.h>

int transforma(int seg,int *hora,int *min)
{
int r;

  *hora=seg/3600;
  r=seg%3600;
  *min=r/60;
  seg=r%60;
  return seg;
}

void main()
{
int hora,min,seg,s;

  clrscr();
  printf("\n\n\t Tempo em segundos: ");
  scanf("%d",&seg);
  s=transforma(seg,&hora,&min);
  printf("\n\n\t Tempo tranformado: %dh %dmin %dseg",hora,min,s);
  getch();
}