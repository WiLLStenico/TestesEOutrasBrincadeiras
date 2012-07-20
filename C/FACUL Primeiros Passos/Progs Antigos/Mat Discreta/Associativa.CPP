#include <stdio.h>
#include <conio.h>

void main(void)
{
char c[100],m[100][100];
int n,i,j,k,x,y,w,p,ass,h;
char comp1,comp2;

   clrscr();

   printf("Digite a quantidade de parametros: ");
   scanf("%d",&n);

   for(i=1; i<=n ;i++)
   {
     printf("Conjunto: ");
     scanf("%s",&c[i]);
     printf("\n");
   }

   clrscr();
   for(i=1; i<=n; i++)
   {
     for(j=1; j<=n; j++)
     {
       printf("Conjunto %c,%c: ",c[i],c[j]);
       scanf("%s",&m[i][j]);
     }

   }

   ass=0;
   k=1;
   w=2;

   for(i=1; i<=n; i++)
   {
     for(j=1; j<=n; j++)
     {
       for(w=2; w<=n; w++)
       {
	 h=1;
	 while(m[i][j]!=c[k])
	 {
	   k=k+1;
	 }
	 while((m[j][w]!=c[h]) && (h<=n))
	 {
	   h=h+1;
	 }
	 comp1=m[w][k];
	 comp2=m[h][i];

	 if(comp1!=comp2)
	 {
	   ass=1; //nao e assiciativa
	 }
       }
     }
   }

   if(ass==0)
     printf("E associativa");
   else
     printf("Nao e associativa");

    getch();
    getch();
}