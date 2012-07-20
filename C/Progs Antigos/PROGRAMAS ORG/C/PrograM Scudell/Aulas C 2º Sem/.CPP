#include <stdio.h>
#include <conio.h>

void main(void)
{

  struct aluno
  {
    int numero,ativo;
    char nome[20],curso[15];
    float nota1,nota2;
  };

 FILE *classe;
 aluno a,b;

 classe=fopen("c:\\aluno.dat","a+");
 clrscr();

 if(classe==NULL)
 {
   printf("\n\n\t Erro na abertura/criacao do arquivo");
   getch();
 }
 else
 {
   printf("\n\n\t Numero do aluno a incluir: ");
   scanf("%d",&a.numero);
   while(a.numero>0)
   {
     rewind(classe);
     fread(&b,sizeof(aluno),1,classe);
     while((!feof(classe)) && ((a.numero!=b.numero) || ((a.numero==b.numero) && (b.ativo==0))))
     {
       fread(&b,sizeof(aluno),1,classe);
     }
     if(feof(classe))
     {
       flushall();
       printf("\n\n\t Nome do aluno: ");
       gets(a.nome);
       printf("\n\n\t Curso do aluno: ");
       gets(a.curso);
       printf("\n\n\t Primeira nota: ");
       scanf("%f",&a.nota1);
       printf("\n\n\t Segunda nota: ");
       scanf("%f",&a.nota2);
       a.ativo=1;
       fwrite(&a,sizeof(aluno),1,classe);
       printf("\n\n\t Aluno incluido com sucesso");
     }
     else
     {
       printf("\n\n\t Numero ja cadastrado");
     }
     getch();
     clrscr();
     printf("\n\n\t Numero do aluno a incluir: ");
     scanf("%d",&a.numero);
   }
   fclose(classe);
 }
}