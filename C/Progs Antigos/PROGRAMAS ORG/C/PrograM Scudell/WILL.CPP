#include <stdio.h>
#include <conio.h>
#include <string.h>
int a(char *frase)
{
int i,letra,n;
n=strlen(frase);

letra=0;

for(i=0;i<=n;i++)
{
if ((frase[i]='a')||(frase[i]='A'))
{
letra=letra+1;
}
}
}

void main(void)
{

   char *frase;
   int letra;

   printf("Digite uma frase:");
   gets(frase);
   //letra

   clrscr();

   getch();
}