#include <stdio.h>
#include <conio.h>
#include <math.h>
void main(void)
{

   int a[10],i,n,p,j;

   clrscr();

   for(i=0;i<=9;i++)
   {
    gotoxy(30,10);
    printf("Digite o %d§ elemento: ",i+1);
    scanf("%d",&a[i]);
    gotoxy(30,10);
    clreol();
   }
   clrscr();
   for(i=0;i<10;i++)
   {
    n=(int)sqrt(a[i]);
    p=1;
    for(j=2;j<=n;j++)
     if(a[i]%j==0)
      p=0;
     if(p)
      printf("N£mero %d, na posi‡Æo %d\n", a[i], i+1);
    }
   getch();
}