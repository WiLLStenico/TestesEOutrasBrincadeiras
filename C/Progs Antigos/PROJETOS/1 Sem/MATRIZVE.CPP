#include <stdio.h>
#include <conio.h>

void main(void)
{ textbackground(RED);
  textcolor(GREEN);
   clrscr();
 int a [4][3], sl[4],sc[3];
 int i,j,c,l;
 for(i=0;i<4;i++)
 for(j=0;j<3;j++)
  {
   clrscr();
   gotoxy(30,10);
   printf("Elemento da linha %d coluna %d ",i+1,j+1);
   scanf("%d", &a[i][j]);
  }
  for(i=0;i<4;i++)
  {
   sl[i]=0;
   for (j=0;j<3;j++)
    sl[i]+=a[i][j];
   }
   for (j=0;j<3;j++)
   {
    sc[j]=0;
    for(i=0;i<4;i++)
     sc[j]+=a[i][j];
    }
    clrscr();

    c=30; l=10;
    for(i=0;i<4;i++)
    {
     for(j=0;j<3;j++)
     {
      gotoxy(c,l);
      printf("%d",a[i][j]);
      c+=5;
     }
     c+=5;
      gotoxy(c,l);
      printf("%d",sl[i]);
      l+=2;
      l+2;c=30;
      }
      for(j=0;j<3;j++)
      {
       gotoxy(c,l);
       printf("%d",sc[j]);
       c+=5;
       }
       getch();
}