#include <stdio.h>
#include <conio.h>
#include<string.h>

void main(void)
{
   clrscr();

   struct{

   int numero,cod;
   char nome[10];}WiLL[5];

   int i,cod;

       gotoxy(10,5);

   for(i=0;i<5;i++)
   {

    printf("\nDigite o Codigo: ");
    scanf("%d",&WiLL[i].cod);
    flushall();
    printf("\nDigite o nome: ");
    gets(WiLL[i].nome);
    printf("\nDigite o numero: ");
    scanf("%d",&WiLL[i].numero);

   }
    clrscr();
    printf("Digite o Codigo a Pesquisar: ");
    scanf("%d",&cod);

    i=0;

    while((cod!=WiLL[i].cod)||(i>=7))
    {
     i++;
    }

    if(cod==WiLL[i].cod)
    {
     flushall();
     printf("O Codigo procurado eh %d",WiLL[i].cod);
     printf("\nO Nome procurado eh ");
     puts(WiLL[i].nome);
     printf("O Numero procurado eh %d",WiLL[i].numero);
     }
     else
      {
      printf("O Codigo procurado nao existe");



    }




   getch();
}