#include <stdio.h>
#include <conio.h>




void main()
{
  int op_menu,col,lin;

  textcolor(LIGHTCYAN);

  col=5; lin=7;

  do{
   clrscr();
     //===========================MENU PRINCIPAL=================
     printf("*******************************************************************************\n");
     printf("\t\t\tSimulador de Escalonamento de CPU\n");
     printf("*******************************************************************************\n");
     gotoxy(col,lin);
     printf("1) Gerenciamento da Tabela de Processos\n");
     gotoxy(col,lin+2);
     printf("2) Execucao dos Algoritmos\n");
     gotoxy(col,lin+4);
     printf("3) Outros\n");
     gotoxy(col,lin+6);
     printf("4) Sair\n");

     gotoxy(col,lin+10);
     printf("Digite a Opcao: ");
     clreol();
     scanf("%d",&op_menu);

     switch(op_menu)
     {
      case 1:
       //==================================1.1) GERENCIAMENTO TABELA==============
      break;
      case 2:
      {
       printf("====EXECUCAO ALGORITMOS====");
       getch();break;
      }
      case 3:
      {
       printf("===========OUTROS========");
       getch();break;
      }

     }


   }while(op_menu!=4);


  }


/*









Opção: 1




1) Inserir Processos
2) Remover Processos
3) Alterar Processos
4) Listar  Processos
5) Voltar
---------------------------------------
Opção:
*/
