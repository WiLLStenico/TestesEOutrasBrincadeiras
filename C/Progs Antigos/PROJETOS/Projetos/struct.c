#include <stdio.h>
#include <stdlib.h>




void main(){



int count =10,*temp, sum=0;


temp=&count;
printf("count = %d, temp= %d, sum = %d \n",count,*temp, sum);
getch();
*temp=20;
printf("count = %d, temp= %d, sum = %d \n",count,*temp, sum);
getch();
temp=&sum;
getch();
*temp=count;
printf("count = %d, temp= %d, sum = %d \n",count,*temp, sum);
*temp=11;
printf("count = %d, temp= %d, sum = %d \n",count,*temp, sum);
*temp=40;
getch();
printf("count = %d, temp= %d, sum = %d \n",count,*temp, sum);
getch();


}
