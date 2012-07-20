#include <stdio.h>
#include <conio.h>

void main(void)
{
   char nome[50], telefone[20];
   FILE *fp; //criar o aqruivo para arquivo
   clrscr();
   printf("Digite seu nome:");
   gets(nome);
   printf("Digite seu telfone:");
   gets(telefone);

   fp=fopen("c:\\Dados.htm","w"); //abrindo o arquivo

   fprintf(fp,"\nNome: %s",nome); //escrevendo o arquivo
   fprintf(fp,"\nTelefone: %s",telefone);

   fclose(fp); //fechando o arquivo

}