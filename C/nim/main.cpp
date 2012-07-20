#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define delay 2000

using namespace std;

void tabuleiro(int QtdePilhas, int NroPalitos[9]){

 int i,j;

    for(i=0;i<QtdePilhas;i++){

       puts("\n");
       printf(" %d ->",i+1);

       for(j=0;j<NroPalitos[i];j++){

           //printf("Pilhas %d Palitos %d", QtdePilhas, NroPalitos[i]);
           printf(" | ");

       }

            printf(" Total: %d",NroPalitos[i]);

    }

}

int transIntBin(int bin){

    char buffer[13];

    itoa(bin,buffer,2);
    bin=atoi(buffer);

    return bin;
}

int somaBin(int nroLinhas, int nroPaus[9]){

    int totalBin =0, i;

    for(i=0;i<nroLinhas;i++){

        totalBin=totalBin+transIntBin(nroPaus[i]);
    }

    return totalBin;

}

int jogada(int maxLinha, int maxPaus[9]){

    int linha, paus,jogada,i, par =1,aux, cont=0, tentativas = 0, auxPalitos[9];

    for(i=0;i<maxLinha;i++){

    auxPalitos[i]=maxPaus[i];
    }

    linha=maxLinha;
    paus=maxPaus[linha-1];

  while ((par !=0)&&(tentativas==0)){

    for(i=0;i<=maxLinha;i++){

    auxPalitos[i]=maxPaus[i];
    }

    par = 0;

    auxPalitos[linha-1]=auxPalitos[linha-1]-paus;
    jogada = paus*10 + linha;
    aux = somaBin(maxLinha,auxPalitos);

    while(aux>=1){
            if(aux%2!=0){
                par=1;
            }
            aux=aux/10;
            cont++;
        }

    paus--;
    cont=0;

    if(paus<=0){
      if(maxLinha>1){
        linha--;
      }else {
         par = 0;
         jogada = 0;
       }
     paus = maxPaus[linha-1];
    }

   if(jogada<11){
        tentativas=1;
    }

  }

  if(tentativas !=0){

    srand ( time(NULL) );
    linha=(rand()%maxLinha)+1;
    paus=(rand()%maxPaus[linha-1])+1;
    jogada = paus*10 + linha;
    printf(" JOGADA ALEATORIA : ");
    printf("%d\n", jogada);

  }else{
      printf("%d\n", jogada);
  }
    //printf("\nPaus %d \n linha %d \n confere %d \n", paus, linha, confere);
    //printf("Jogada: %d\n", jogada);
    return jogada;
}

int main(){

    int  i,jogador=1,NroPalitos[9],auxNroPalitos[9],QtdePilhas=0,op,axaPilha,axaQtde,testaJogada, tipojogo=0;
    char nome[2][15];

  do{

      if(tipojogo!=4){
      puts("\n\t\t\t Selecione o Tipo de Jogo\n\t-----------------------------------------------------\n\t(1) - 1 Player\t(2) - 2 Players \t(3) - PC x PC\n");
      scanf("%d",&tipojogo);
      }

//*******Correção de Erro do Scanf(op);
    if(op==1){
    getchar();
    }

    jogador=2;//deve comecar com valor 2 para verificardor de jogador alterar para 1;

    system("cls");

    if((tipojogo!=3)&&(tipojogo!=4)){
    puts("Digite o nome do Jogador 1:");
    scanf("%s",&nome[0]);


    if(tipojogo==2){
    puts("Digite o nome do Jogador 2:");
    scanf("%s",&nome[1]);
    }
    }

    if(tipojogo == 1){

        strcpy(nome[1],"PC");
    }
    if((tipojogo == 3)||(tipojogo==4)){

        strcpy(nome[0],"Player 1");
        strcpy(nome[1] ,"Player 2");
    }


    system("cls");

    srand ( time(NULL) );

    QtdePilhas=(rand()%4)+2;

    for(i=0;i<QtdePilhas;i++){

        NroPalitos[i]=(rand() % 9)+1;
    }

    jogador=2;

    do{

        if(jogador==1){
            jogador=2;
        }else{
            jogador=1;
        }

        system("cls");

        tabuleiro(QtdePilhas, NroPalitos);

        printf("\n\n--> ");
        printf("%s :",nome[jogador-1]);
        printf("\n\nDigite a Qtde de Palitos a serem retirados + o NRO DA LINHA. Ex: 23\nSelecione sua Opcao: ");

       /* if(!scanf("%d", &op)){
            op=0;

        }*/

        if(jogador==1){

            if((tipojogo==1)||(tipojogo==2)){
            if(!scanf("%d",&op)){
                op=0;
            }
            }else{

            op=jogada(QtdePilhas, NroPalitos);
            //printf("%d",op);
            Sleep(delay);
            //      system("PAUSE");

            }

        }else{

            if(tipojogo==2){
            if(!scanf("%d",&op)){
                op=0;
            }
            }else{

            op=jogada(QtdePilhas, NroPalitos);
            //printf("%d",op);
            Sleep(delay);
            //system("PAUSE");
            }

        }

        axaQtde=op/10;
        axaPilha=op-(axaQtde*10);

     if((axaPilha>QtdePilhas)||(axaPilha==0)){
            printf("\nLinha %d Inexistente", axaPilha);
            Sleep(delay);
            if(jogador==1){
                jogador=2;
                }else{
                jogador=1;
            }
        }else{

            if((axaQtde>NroPalitos[axaPilha-1])||(axaQtde==0)){
                printf("\nQuantidade deve ser Maior que 1 e menos que o TOTAL");
                Sleep(delay);
                if(jogador==1){
                    jogador=2;
                    }else{
                    jogador=1;
                }
            }else{
                NroPalitos[axaPilha-1]=NroPalitos[axaPilha-1]-axaQtde;

                if((NroPalitos[axaPilha-1]==0)&&(QtdePilhas>=1)){//Verifica se Linhas = 0

                    for(i=axaPilha;i<QtdePilhas;i++){
                    NroPalitos[i-1]=NroPalitos[i];
                    }
                    QtdePilhas--;
                }
            }
        }

        if(QtdePilhas==0){
            system("cls");
            printf("\n\n\n\n\t\t\t\\o/ %s VENCEU!!! \\o/", nome[jogador-1]);
        }

        }while((QtdePilhas!=0));

        if(tipojogo!=4){
        while((op!=1)&&(op!=2)){

            printf("\n\t\t\t   Novo Jogo? \n\t\t\t(1) Sim \t(2) Nao\n ");
            if(!scanf("%d", &op)){
                op=2;
                exit(0);
                }

        }
        }else{
             op=1;
             Sleep(delay);
        }

}while(op==1);

//puts("\n");

    //cout << "Hello world!" << endl;
    return 0;
}
