#include <stdio.h>
#include <conio.h>
#include <string.h>
void main(void)
{

float tabela[5][2];
struct
{
char identificacao[20];
int mesatraso;
float imposto;
}imovel;
int i,j;
float multa;

for (i=0;i<5;i++)
{
clrscr();
for(j=0;j<2;j++)
{
flushall();
printf("\n \n \t Tabela[%d,%d]=" "",i+1,j+1);
scanf("%f", &tabela[i][j]);
}
clrscr();
flushall();
printf("\n \n \t Identifica‡ao imovel: ");
gets(imovel.identificacao);
while(strcmp(imovel.identificacao,"vazio")!=0)
{
flushall();
printf("\ n\ n \t Valor do imposto:");
scanf("%f",&imovel.imposto);
printf("\n \n \t Meses em atraso:");
scanf("%d",imovel.mesatraso);
i=4;
while((imovel.imposto>=tabela[i][0])&&(i>0))
{
i--;
if(imovel.imposto>=tabela[i][0])
multa=tabela[i][1]/100*imovel.imposto*imovel.mesatraso;
getch();
clrscr();
flushall();
printf("\n \n \t Identificao imovel:");
gets(imovel.identificacao);
}
}
}
}

