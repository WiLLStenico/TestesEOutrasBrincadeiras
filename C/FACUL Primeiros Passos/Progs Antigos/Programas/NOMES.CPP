#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>

void main(void)
{
  char *frase,*nova,letra,letra2;
  int tam,i,cont,achou,pos1,pos2;

   clrscr();
   printf("Nome completo: ");
   gets(frase);
   tam=strlen(frase);
   nova = strdup("");
   achou=0;
   i=0;
   while (achou==0)
   {
      letra=frase[i];
      if  (letra!=' ')
	nova[i]=letra;
      else
      {
	nova[i]=letra;
	achou=1;
	pos1=i;
      }
      i=i+1;
   }
   achou=0;  //atribuindo o valor falso
   i=tam;
   while (!achou)
   {
     letra=frase[i];
     if(letra==' ')
     {
       pos2=i;
       achou=1;
     }
     i=i-1;
   }
   cont=pos1+1;
   letra2=frase[cont];
   for (i=pos1+1;i<pos2;i++)
   {
     letra=frase[i];
     if ((letra==' ')||(letra=='\0'))
     {
       nova[cont]=letra2;
       cont=cont+1;
       nova[cont]='.';
       cont=cont+1;
       nova[cont]=' ';
       cont=cont+1;
       letra2=frase[i+1];
     }
   }
   for(i=pos2+1;i<=tam;i++)
   {
     nova[cont]=frase[i];
     cont=cont+1;
   }
   strcat(nova,"\0");
   puts(nova);

   getch();
}