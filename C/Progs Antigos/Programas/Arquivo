#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(void)
{
   struct aluno
   {
   int numero,ativo,nota1,nota2;
   char curso[15],nome[20];
   };
   FILE *classe;// arquivo sempre ponteiro.
   aluno a,b;
   classe=fopen("c:\\alunos.dat","a+");// testar classe.

   clrscr();

   if(classe==NULL)
   {
   printf("\n \n \t Erro na abertura/cria‡Æo de arquivo");
   getch();
   }
   else
   {
   printf("\n \n \t Numero do aluno a incluir:");
   scanf("%d", &a.numero);
   while(a.numero>0)
   {
   fread(&b,sizeof(aluno),1,classe);
   while((!feof(classe))&&((a.numero!=b.numero)||((a.numero==b.numero)&&(b.ativo==0))))
   fread(&b,sizeof(aluno),1,classe);
   if(feof(classe))
   {
   flushall();
   printf("\n \n \t Nome do Aluno: ");
   gets(a.nome);
   printf(" \n \n \t Curso do aluno: ");
   gets(a.curso);
   printf("\n \n \t Primeira nota: ");
   scanf("%d",&a.nota1);
   printf("\n \n \t segunda nota: ");
   scanf("%d",&a.nota2);
   a.ativo=1;
   fwrite(&a,sizeof(aluno),1,classe);
   printf("\n \n \t Aluno incluido com sucesso");
   }
   else
   printf("\n \n \t Numero ja cadastrado");

   getch();
   clrscr();
   printf("\n \n \t Numero do aluno a incluir:");
   scanf("%d",&a.numero);
   }
   fclose(classe);

   }




}