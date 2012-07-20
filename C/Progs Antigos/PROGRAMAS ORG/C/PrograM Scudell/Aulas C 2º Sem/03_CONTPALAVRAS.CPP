#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(void)
{
char *frase;
int contador,i;
//int tam;

   clrscr();
  gotoxy(1,7);
  printf("Digite uma frase: ");
  gets(frase);
  //tam=strlen(frase);
  contador=0;

  //for(i=0;i>=i;i++)
  for(i=0;frase[i]!='\0';i++)
  {
    if(frase[i]==' ')
      contador++;
  }
  contador++;
  gotoxy(25,10);
  printf("A frase tem %d palavras",contador);

   getch();
}