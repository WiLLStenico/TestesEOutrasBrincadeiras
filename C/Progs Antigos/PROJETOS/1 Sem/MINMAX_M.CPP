#include <stdio.h>
#include <conio.h>

void main(void)
{
   clrscr();
   int i,j,m,n,l,menor,c,maior,linha;
   int a[10][10];
   gotoxy(35,5);printf("Numero de linhas: ");
   scanf("%d",&m);

   gotoxy(35,7);
   printf("Digite o numero de colunas: ");
   scanf("%d",&n);
   gotoxy(35,9);printf("Elementos da matriz");
   for(i=0;i<m;i++)
    for(j=0;j<n;j++)
     {
      gotoxy(3,11);clreol();
      printf("Elemento[%d,%d]= ",i+1,j+1);
      scanf("%d",a[i][j]);
     }
     menor=a[0][0];l=0;
     for(i=0;i<m;i++)
      for(j=0;j<n;j++)
	if(a[i][j]<menor)
	{
	 menor=a[i][j];
	 l=i;
	}
      maior=a[l][0];c=0;
      for(j=0;j<n;j++)
       if(a[l][j]>maior)
       {
	maior=a[l][j];
	c=j;
       }
       clrscr();linha=8;
       gotoxy(35,5);
       printf("Elemento MINMAX= %d",maior);
       gotoxy(35,7);
       printf("Linha= %d  Coluna= %d",l+1,c+1);
       linha=10;
       for(i=0;i<m;i++)
       {
	gotoxy(30,linha);
	for(j=0;j<n;j++)
	  printf("%d   ",a[i][j]);
	linha+=2;
       }


   getch();
}
