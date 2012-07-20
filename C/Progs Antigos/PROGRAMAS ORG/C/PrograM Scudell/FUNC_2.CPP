#include <stdio.h>
#include <conio.h>




   int caracteristica(int n);
   void main()
   {
   clrscr();
   int n,c;
   do
   {
   clrscr();
   printf(" Digite um numero de 4 algarismos:");
   scanf("%d",&n);
   }
   while((n<1000)||(n>9999));
   c=caracteristica(n);
   if (c==1)
   printf("o numero possui a caracteristica");
   else
   printf(" O numero naum possui a caracteristca");

   getch();
 }
   int caracteristica ( int n)
   {
   int q,r,s;
   q=n/100;
   r=n%100;
   s=q+r;
   if (s*s==n)
   return 1;
   else
   return 0;
  }