#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(void)
{
  float tabela[5][2];
  struct
  {
    char identific[20];
    float imposto;
    int mesesat;
  }imovel;

int i,j;
float multa;

  for(i=0; i<5; i++)
  {
    clrscr();
    for(j=0; j<2; j++)
    {
      flushall();
      printf("\n\n\t Tabela[%d][%d]= ",i+1,j+1);
      scanf("%f",&tabela[i][j]);
    }
  }
  clrscr();
  flushall();
  printf("\n\n\t Identificao do imovel: ");
  gets(imovel.identific);

  while(strcmp(imovel.identific,"vazio")!=0)
  {
    flushall();
    printf("\n\n\t Valor do imposto: ");
    scanf("%f",&imovel.imposto);
    printf("\n\n\t Meses em atraso: ");
    scanf("%d",&imovel.mesesat);
    i=4;

    while((imovel.imposto>=tabela[i][0]) && (i>0))
      i--;

    if(imovel.imposto>=tabela[i][0])
      multa=tabela[i][1]/100*imovel.imposto*imovel.mesesat;

    getch();

    clrscr();
    flushall();

    printf("\n\n\t Identificado imovel: ");
    gets(imovel.identific);

    printf("Multa: %f",multa);
    getch();
  }

}