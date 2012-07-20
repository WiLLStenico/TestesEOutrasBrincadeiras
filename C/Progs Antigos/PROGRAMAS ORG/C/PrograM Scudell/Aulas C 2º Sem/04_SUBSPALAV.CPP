#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(void)
{
char *frase,*frase_nova,*pal_digitada,*pal_frase;
int tam,i,cont,res;

   clrscr();
  gotoxy(10,5);
  printf("Digite uma frase: ");
  gets(frase);
  gotoxy(10,9);
  printf("Palavra para a substituicao: ");
  gets(pal_digitada);
  tam=strlen(frase);
  cont=0;
  strcpy(pal_frase,"\0");
  strcpy(frase_nova,"\0");

  for(i=0;i<tam;i++)
  {
    if ((frase[i]!=' ') && (frase[i]!=',') && (frase[i]!='.') && (frase[i]!='\0'))
    {
      pal_frase[cont]=frase[i];
      cont++;
    }
    else
    {
      pal_frase[cont]='\0';
      cont=0;
      res=strcmp(pal_frase,"ESCOLA");
      if(res==0)
      {
	strcat(frase_nova,pal_digitada);
	strcat(frase_nova," ");
	strcpy(pal_frase,"\0");
      }
      else
      {
	strcat(frase_nova,pal_frase);
	strcat(frase_nova," ");
	strcpy(pal_frase,"\0");
      }
    }
  }

  gotoxy(10,12);
  printf("Nova frase\n\n");
  puts(frase_nova);

   getch();
}