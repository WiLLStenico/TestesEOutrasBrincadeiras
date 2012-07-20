#include <stdio.h>
#include <conio.h>

int sub(int n[], int *menor, int *soma, int *dif, float *media)
{
  int i,j;
  int maior=n[0];

  *menor=n[0];
  *soma=0;

  for(i=0; i<=7; i++)
    if(n[i]>maior)
       maior=n[i];

  for(i=0; i<=7; i++)
    if(n[i]<*menor)
       *menor=n[i];

  for(i=0; i<=7; i++)
    *soma=*soma+n[i];

  *dif=maior-*menor;

  *media=*soma/8;


  return maior;
}

void main()
{
   int n[8],c[8];
   int maior, menor, soma, dif;
   float media;

   clrscr();

   for(int i=0; i<=7; i++)
   {
     printf("N-%d:",i+1);
     scanf("%d",&n[i]);
     printf("\n");
   }

   maior=sub(n,&menor,&soma,&dif,&media);

   printf("O Maior numero ‚: %d",maior);
   printf("\nO Menor numero ‚: %d",menor);
   printf("\nA Soma dos numeros ‚: %d",soma);
   printf("\nA diferenca entre o maior e menor ‚: %d",dif);
   printf("\nA Media dos numeros ‚: %f",media);


   getch();
}