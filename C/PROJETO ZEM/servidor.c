#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include<time.h>


// FUNÇÃO ITOA ////////////////////////////////////////////////////////
 size_t strlen(const char *string) {
	const char *s;

	s = string;
	while (*s)
		s++;
	return s - string;
   }

   char *strrev(char *str) {
	char *p1, *p2;

	if (!str || !*str)
		return str;

	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}

	return str;
   }


   char *itoa(int n, char *s, int b) {
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int i=0, sign;
    
	if ((sign = n) < 0)
		n = -n;

	do {
		s[i++] = digits[n % b];
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	return strrev(s);
   }
/////////////////////////////////////////////////////////////////////////////////////////



main() {
 
//var fila
 key_t	key_f;
  int	mid_f, mid_c,n;
  char	msg_fila[200];


//var mem
   key_t key_m;
   int	tamanho=1000, shmid;
   char	msg_mem[200],*shm,*shm_r;


//tratamento de String

   char *PID,*COMANDO,*msg_original;
   char RESPOSTA[200];


//função DATA

	struct tm *ptr;
	time_t ld;
   char data[4];
   
//Armazenamento de USUARIOS

	char user[500];//PID@USER@SENHA#PID@USER@SENHA#.....
  


  system("clear");


//Criando Filas..................

  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0777|IPC_CREAT)) == -1) {
     printf("Nao foi possivel criar uma fila de mensagens na memoria.");
  } else {
     printf("O identificador da fila de mensagens e %d. \n",mid_f);
  }


 //Criando Segmento de MEMORIA Compartilhada.........

  

  //system("clear");

  key_m=ftok(".",'m');
  if ((shmid=shmget(key_m,tamanho,0777|IPC_CREAT)) == -1) {
     printf("Nao foi possivel reservar um segmento de memoria compartilhada.");
  }

  printf("O identificador do segmento de memória compartilhada e %d.\n",shmid);


// system("ipcs");

do{

  

   


//recuperando Mensagem da FILA......


  printf("\nBUSCANDO MENSAGENS DOS CLIENTES...\n",n);

    
  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0)) == -1) {
     printf("Nao foi possivel determinar a identificacao da fila de mensagens.\n");
  } else {
     n=msgrcv(mid_f,msg_fila,sizeof(msg_fila),0,0); 
     printf("Recuperei a mensagem \"%s\" da fila de mensagens de identificador %d.\n",msg_fila,mid_f);
     printf("%d \n",n);

  }

   
//TRATAMENTO DE STRING..................................................................................



                   
       
    msg_original=strdup(msg_fila);//recebe msg aqui
        
    PID = strtok(msg_original, "#");
    printf("%s \n", PID);  
                
                
    COMANDO = strtok(NULL, "#");
    printf("%s \n", COMANDO);

   
      






//************************ SHELL **********************************************************

/*

-LOGIN
-LOGOUT
-WHO AM I *
-WHO
-DATE - OK
-HOSTNAME
-UNAME
-CLEAR*
-CREDITOS - OK

*/


 

if(strcmp(COMANDO , "date")==0)
{
	ld = time(NULL);
	ptr = localtime(&ld);
   
   itoa(ptr->tm_mday, data, 10);

   strcpy(RESPOSTA,data); //DIA

   itoa(ptr->tm_mon+1, data, 10);
   strcat(RESPOSTA, "\\");
   strcat(RESPOSTA, data);//MES

   itoa(ptr->tm_year+1900, data, 10);
   strcat(RESPOSTA, "\\");
   strcat(RESPOSTA, data);//ANO

   itoa(ptr->tm_hour, data, 10);
   strcat(RESPOSTA, " - ");
   strcat(RESPOSTA, data);//HORA

	itoa(ptr->tm_min, data, 10);
   strcat(RESPOSTA, ":");
   strcat(RESPOSTA, data);//MIN

	itoa(ptr->tm_sec, data, 10);
   strcat(RESPOSTA, ":");
   strcat(RESPOSTA, data);//SEG

	printf("DATA: %s \n",RESPOSTA);


}else if(strcmp(COMANDO , "creditos")==0)
{
 strcpy(RESPOSTA,"\n\t CREDITOS \n WiLLiaM Henrique Stenico   RA: 300070489 \n Leandro Maciel Vitti   RA: 300070537 \n Gianne Forti   RA: 300070510\n");

} else if(strcmp(COMANDO , "logout")==0)
				{
 					strcpy(RESPOSTA,"logout");

					} else if(strcmp(COMANDO , "shutdown")==0)
								{
									strcpy(RESPOSTA,"Ate a proxima!!!");
								}else if(strcmp(COMANDO , "clear")==0)
								       {
									     strcpy(RESPOSTA,"clear");
								      }else								
   								   { 
  									     strcpy(RESPOSTA,"COMANDO INVALIDO");
      								}

  
   


//*****************************************************************************************



//TRATAMENTO DE STRING PARA RESPOSTA......................................................



	
	strcpy(msg_mem,PID);
   strcat(msg_mem,"#");
   strcat(msg_mem,RESPOSTA);
   




//ESCREVER MENSAGEM DE RESPOSTA NA MEM COMPARTILHADA!!!!!!!!!!!!!!!!!!!!!!!!!! ===================================================================


 // system("clear");

  key_m=ftok(".",'m');
  if ((shmid=shmget(key_m,tamanho,0)) == -1) {
     printf("Nao foi possivel determinar o identificador do segmento de memoria compartilhada.\n");
  } else {
     shm=shmat(shmid,0,0);
     
     //printf("Digite a mensagem: ");
     //gets(msg_mem);
     
	  //strcat(PID,"#");


	  strcpy(shm,msg_mem);
     printf("Estou armazenando a mensagem \"%s\" na posicao de memoria compartilhada %d.\n",shm,shmid);
     shmdt(shm);
  }

		printf("Aguardando Resposta do Usuario.");
	

   	do{
      
      
		printf(".");

      /*key_m=ftok(".",'m');
		if ((shmid=shmget(key_m,tamanho,0)) == -1)
		{
			printf("Segmento de memória não criado. Favor inicializar o servidor.\n");
		}
		else
		{*/
			shm_r=shmat(shmid,0,0);
//			printf("Recuperei a mensagem \"%s\" do segmento de memoria compartilhada %d.\n",shm,shmid);
         strcpy(RESPOSTA,shm_r);
			shmdt(shm_r);
		//}
      
      sleep(1);

  	 }while(strcmp(RESPOSTA , "0")!=0);



  
	//getchar();
   
   //liberar espaco na variavel
    //free(COMANDO); 
    

	}while(strcmp(COMANDO , "shutdown")!=0);


//apaga Filas........................
    
  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0)) == -1) {
     printf("Nao foi possivel determinar a identidicacao da fila de mensagens.\n");
  } else {
     if (msgctl(mid_f,IPC_RMID,0) == 0) {
        printf("A fila de mensagens %d foi removida.\n",mid_f);
     } else {
        printf("A fila de mensagens %d nao pode ser removida.\n",mid_f);
     }
  }




//apaga Memoria Compartilhada...................



  key_m=ftok(".",'m');
  if ((shmid=shmget(key_m,tamanho,0)) == -1) {
     printf("Nao foi possivel determinar o identificador do segmento de memoria compartilhada.\n");
  } else {
     if (shmctl(shmid,IPC_RMID,0) == 0) {
        printf("O segmento de memória compartilhada %d foi removido.\n",shmid);
     } else {
        printf("O segmento de memória compartilhada %d nao pode ser removido.\n",shmid);
     }
  }





 //system("ipcs");
 
}




