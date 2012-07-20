#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bin;
    do{
    printf("\nNumero a ser Transformado: ");
    scanf("%d",&bin);

    char buffer[13];
    itoa(bin,buffer,2);
    bin=atoi(buffer);

    printf("\nNumero Binario: %d",bin);
    }while(bin!=0);

    return 0;
}
