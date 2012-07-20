#include <stdio.h>
#include <conio.h>

   int prova(int v[],int *maior,float *media)
   {
   int i,menor,soma;

   soma=0;
   menor=v[1];
   *maior=v[1];

   for(i=1;i<=3;i++)
   {
    if(v[i]>*maior)
   {
    *maior=v[i];
   }
    if(v[i]<menor)
   {
    menor=v[i];
   }
   soma=soma+v[i];
   *media=(soma/3);
   }

   return menor;
   }


   void main (void)

   {

   int v[3];
   int i,maior,menor;
   float media;

   clrscr();

   printf("Digite 3 numeros:\n ");

   for (i=1;i<=3;i++)

   {
   scanf("%d", &v[i]);
   menor=prova(v, &maior,&media);
   }
   printf("\n %d maior""\n %d menor""\n %5.2fmedia", maior, menor, media);

    getch();

    }