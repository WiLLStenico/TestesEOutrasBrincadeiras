#include <stdio.h>
#include <conio.h>

void multiplica(int n)
{
int i,j;
clrscr();
for(i=1;i<=n;i++);
{
printf ("\n \n \t \t");
for (j=1;j<=i;j++)
printf("%5d", i*j);
}
}




void main(void)
{
   int n;
   do
   {
     clrscr();
     printf("Digite um numero entre 1 e 9: ");
     scanf("%d",&n);
     }
     while((n<1)||(n>9));
     multiplica(n);
     getch();
     }