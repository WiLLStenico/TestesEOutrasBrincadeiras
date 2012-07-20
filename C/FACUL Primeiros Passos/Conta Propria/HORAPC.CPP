#include   <stdio.h>
#include   <dos.h>
#include <conio.h>
int main(void)
{
   struct  time t;

   gettime(&t);
   printf("The current time is: %2d:%02d:%02d.%02d\n",
	  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
	  getch();
   return 0;
}
