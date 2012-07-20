#include <stdio.h>
#include <stdlib.h>

int main()
{
int num1,num2,num3,num4,num5,num6,num_jgos,i;
FILE *newfile;

newfile = fopen("numeros_sorteados.txt", "w");

printf("Digite o numero de jogos a serem gerados: ");
scanf("%d", &num_jgos);

fprintf(newfile, "Numeros que me deixara Milionario:\n ");

srand(time(NULL));

for(i=0;i<num_jgos;i++){
//srand(time(NULL));
num1= (rand() % 60)+1;

do{
    //srand(time(NULL));
    num2= (rand() % 60)+1;
}while(num2==num1);

do{
    //srand(time(NULL));
    num3= (rand() % 60)+1;
}while((num3==num1)||(num3==num2));

do{
    //srand(time(NULL));
    num4= (rand() % 60)+1;
}while((num4==num1)||(num4==num2)||(num4==num3));

do{
    //srand(time(NULL));
    num5= (rand() % 60)+1;
}while((num5==num1)||(num5==num2)||(num5==num3)||(num5==num4));

do{
    //srand(time(NULL));
    num6= (rand() % 60)+1;
}while((num6==num1)||(num6==num2)||(num6==num3)||(num6==num4)||(num6==num5));

printf("Numeros:\n \t%d\t%d\t%d\t%d\t%d\t%d\n",num1, num2, num3,num4, num5, num6 );

fprintf(newfile,"%d ",  num1);

fprintf(newfile, "--");

fprintf(newfile,"%d ",  num2);

fprintf(newfile, "--");


fprintf(newfile,"%d ",  num3);

fprintf(newfile, "--");


fprintf(newfile,"%d ",  num4);

fprintf(newfile, "--");


fprintf(newfile, "%d ", num5);

fprintf(newfile, "--");

fprintf(newfile, "%d ", num6);

fprintf(newfile, "\n");

}

fprintf(newfile, "\nDesenvolvido por:\nWiLLiaM Henrique Stenico\nProgramado em: 30/12/2009\n");

fclose(newfile);

system("notepad \"numeros_sorteados.txt\"");

//getch();

return (0);
}




