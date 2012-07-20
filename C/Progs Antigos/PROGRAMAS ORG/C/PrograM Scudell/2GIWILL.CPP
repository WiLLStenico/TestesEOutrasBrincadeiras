#include <stdio.h>
#include <conio.h>

void perfeitos(int *v)
{
int cont,n,i,s;
cont=0;
n=1;
while (cont<=2)
{
s=0;
for (i=1;i<=n-1;i++)
{
  if (n%i==0)

    s=s+i  ;
}
if (s==n)
{
v[cont]=n;
cont=cont+1;
}
n=n+1;
}
}

void main(void)
{
   int v[3];
   int i;
   clrscr();
   perfeitos(v);
   for(i=0;i<=2;i++)
   {
   printf ("%d  ", v[i]);
   }
   getch();
}