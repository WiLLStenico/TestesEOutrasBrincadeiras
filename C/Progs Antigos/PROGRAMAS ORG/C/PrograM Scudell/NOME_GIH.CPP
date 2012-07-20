#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

   int nome(char *frase)
   {
   int n,i,total;

   total=0;
   n=strlen(frase);

    for(i=0;i<=n;i++)
    {
      if(frase!="")
      {
      total=total+1;
      }
    }
    return total;

    }

 void main(void)
{
   int i,total;
   char *frase;

   clrscr();

   printf("Digite a frase: ");
   gets(frase);
   for(i=0;i<=frase[i];i++)
   {
   total=nome(frase);
   }
   printf( "%d total" , total);
}


   getch();