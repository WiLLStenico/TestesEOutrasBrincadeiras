#include <stdio.h>
#include <conio.h>

int valor(int a, int b, int c)
{

int menor;
printf("Digite 3 valores: ");
scanf("\n %d""\n %d""\n %d",&a,&b,&c);
if((a<b)&&(b<c))
{
menor=a;
}
else
if((b<a)&&(b<c))
{
menor=b;
}
else
if((c<a)&&(c<b))
{
menor=c;
}
return menor;

}


void main(void)
{
   int menor,a,b,c;

   clrscr();
   menor=valor(a,b,c);
   printf("O valor menor ‚:" "%d", menor);

   getch();
}