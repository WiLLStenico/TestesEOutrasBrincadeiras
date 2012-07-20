#include <stdio.h>
#include <conio.h>
#include <string.h>
void main(void)
{

   char *frase;
   int i,contador;
   clrscr();

   printf("Digite uma frase:\n ");
   gets(frase);
   contador=0;

   for(i=0;frase[i]!='\0';i++)
   {
   if (frase[i]==' ')
   contador=contador+1;
   }
   contador=contador +1;
   printf(" A frase tem ""%d",contador);
   getch();
}
