#include <stdio.h>
#include <conio.h>
#include <string.h>
void main(void)
{

   char *frase,*frase_nova,*pal_digitada,*pal_frase;
   int i,cont,tam,res;
   clrscr();

   printf("Digite uma frase:\n ");
   gets(frase);
   printf("Digite a palavra para substitui‡Æo:\n");
   gets(pal_digitada);
   tam=strlen(frase);
   strcpy(pal_digitada,'\0');
   strcpy(frase_nova,'\0');

   for(i=0;i<tam;i++)
   {
   if ((frase[i]!=' ')&&(frase[i]!='.')&&(frase[i]!=',')&&(frase[i]!='\0'))
   {
   pal_frase[cont]=frase[i];
   cont=cont+1;
   }
   else
   {
   cont=0;
   res=strcmp(pal_frase,"ESCOLA");
   }
   if res(==0)
   {
   strcat(frase_nova,pal_digitada);
   strcat(frase_nova,' ');
   strcpy(pal_frase,'\0');
   }
   else
   {
   strcat(frase_nova,pal_frase);
   strcat(frase_nova,' ');
   strcpy(pal_frase,'\0');
   }
   printf("Nova frase \n");
   puts(frase_nova);
   

   //printf(" A frase tem ""%d",contador);
   getch();
}
