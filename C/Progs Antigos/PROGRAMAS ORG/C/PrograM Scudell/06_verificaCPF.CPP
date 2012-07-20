#include <conio.h>
#include <stdio.h>
#include <string.h>

void main()
{
  char cpfs[9];
  int cpfd[11];
  int i,mult=2,dv,soma=0;

  clrscr();
  gotoxy(20,7);
  printf("CPF: ");
  gets(cpfs);

  for(i=0;i<9;i++)
    cpfd[i]=(int)cpfs[i]-'0';

  for(i=8;i>=0;i--)
  {
    soma+=cpfd[i]*mult;
    mult++;
  }

  dv=soma%11;
  if(dv<=1)
    cpfd[9]=0;
  else
    cpfd[9]=11-dv;
  mult=2;
  soma=0;

  for(i=9;i>=0;i--)
  {
    soma+=cpfd[i]*mult;
    mult++;
  }
  dv=soma%11;

  if(dv<=1)
    cpfd[10]=0;
  else
    cpfd[10]=11-dv;
  gotoxy(20,9);
  printf("Digito verificador: %d %d", cpfd[9],cpfd[10]);
  getch();
}
