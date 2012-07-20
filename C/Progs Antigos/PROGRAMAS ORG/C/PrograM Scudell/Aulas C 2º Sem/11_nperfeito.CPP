#include<stdio.h>
#include<conio.h>

void perfeitos(int v[])
{
int cont,num,i,s;

cont=0;
num=1;

  while(cont<=2)
  {
    s=0;
    for(i=1;i<=num-1;i++)
    {
      if(num%i==0)
      {
	s=s+i;
      }
    }

    if(s==num)
    {
      v[cont]=num;
      cont=cont+1;
    }
    num=num+1;
  }
}

void main()
{
int vet[3];
int i;

clrscr();

  perfeitos(vet);

  printf("\n\n\t");

  for(i=0;i<=2;i++)
  {
    printf("%5d",vet[i]);
  }

    getch();
}