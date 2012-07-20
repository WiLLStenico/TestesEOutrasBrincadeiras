#include <stdio.h>
#include <conio.h>
void main(void)
{
  struct
  {
    int codigo;
    char nome[30];
  }tabela[5];

  int coddesejado,i;

  for(i=0; i<5; i++)
  {
    clrscr();
    printf("\n\n\t Codigo da profissao: ");
    scanf("%d",&tabela[i].codigo);
    flushall();
    printf("\n\n\t Nome da profissao: ");
    gets(tabela[i].nome);
  }

  printf("\n\n\t Codigo a pesquisar: ");
  scanf("%d",&coddesejado);

  while(coddesejado>0)
  {
    i=0;
    while((coddesejado!=tabela[i].codigo) && (i<4))
    {
      i++;
    }

    if(coddesejado==tabela[i].codigo)
    {
      printf("\n\n\t Profissao: %s",tabela[i].nome);
    }
    else
    {
      printf("\n\n\t Codigo nao encontrado");
    }
    getch();
    clrscr();

    printf("\n\n\t Codigo a pesquisar: ");
    scanf("%d",&coddesejado);
  }
}