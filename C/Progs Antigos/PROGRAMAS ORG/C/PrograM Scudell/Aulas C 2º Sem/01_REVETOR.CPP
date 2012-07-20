#include <stdio.h>
#include <conio.h>

void main(void)
{
float temp[11];
float media,ttemp,limite;
int i;

   clrscr();
 ttemp=0;
 for(i=0;i<10;i++)
 {
   clrscr();
   printf("Temperatura %d: ",i+1);
    scanf("%f",&temp[i]);
   ttemp=ttemp+temp[i];
 }
 media=ttemp/10;
 limite=media*0.75;
 clrscr();

 gotoxy(15,8);
 for(i=0;i<10;i++)
   if(temp[i]<limite)
     printf("%5.2f",temp[i]);

   getch();
}