//Leandro Maciel Vitti  RA: 70537

#include <stdio.h>
#include <conio.h>


int sub(int n[], int *ne, int *qntm, float *media)
{
 int i,maior,soma;

    soma=0;

    for(i=1; i<=*ne; i++)
    {
      soma=soma+n[i];
    }

    *media=soma/(*ne);

    *qntm=0;
    for(i=0; i<=*ne; i++)
    {
      if(*media>n[i])
      {
	(*qntm)++;
      }
    }
    return maior;
}

void main()
{
  int n[20];
  int i,maior,ne,qntm,qnte;
  float media;

    clrscr();

    ne=0;
    qnte=0;

    printf("\t\t\t :: Programa em C ::");
    printf("\n\n\n\n >>Digite 0 para sair<< \n\n\n");

    for(i=0; i<=19; i++)
    {
      n[i]=0;
    }

    for(i=0; i<=19; i++)
    {
      printf("Digite N%d:",i+1);
      scanf("%d",&n[i]);
      printf("\n");

      if(n[i]==0)
	break;

      ne++;
      qnte=qnte+1;
    }

    maior=sub(n,&ne,&qntm,&media);

    clrscr();

    printf("\t\t\t :: Programa em C ::");
    printf("\n\n\n\n >>Vetor Digitado<< \n");

    for(i=0; i<=ne; i++)
    {
      if(n[i]!=0)
      printf("N%d: %d \n",i+1,n[i]);
    }

    printf("\nMedia: %.2f",media);
    printf("\nQuantidade de elementos acima da media: %d",qntm);
    printf("\nTotal de elementos digitados: %d",qnte);

    getch();
}


