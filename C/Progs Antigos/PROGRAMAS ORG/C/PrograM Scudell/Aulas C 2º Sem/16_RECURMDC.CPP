#include<stdio.h>
#include<conio.h>

int mdc(int p1, int p2)
{
  if(p2==0)
    return p1;
  else
    return(mdc(p2,p1%p2));
}

void main()
{
  int x,y,z;
  clrscr();
  printf("\n\n\t Primeiro valor: ");
  scanf("%d",&x);
  printf("\n\n\t Segundo valor: ");
  scanf("%d",&y);
  z=mdc(x,y);
  printf("\n\n\t M.D.C de %d e %d = %d",x,y,z);
  getch();
}