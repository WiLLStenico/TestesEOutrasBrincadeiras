#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

size_t strlen(const char *);
char *strrev(char *);
char *itoa(int, char *, int);


main() 
{

	key_t key;
   int	mid;
   int nPID;
	char cPID[200];  
   char cmd[200];
   char comando[200];  

	//variaveis pega resposta do servidor no segmento memoria
	key_t	key_m;
	int shmid, tamanho=1000;
	char *shm;
   char resp_serv[200];  //variavel auxiliar



	//variaveis separa PID e MENSAGEM ba resposta do servidor
   char *msg_original;// = strdup("Separe#Isso");
   char *pid_resp, *msg_resp;
   char msg[200];



	int exe;

	exe = 0;

system("clear");


do
{

	///////////////////////////////////////////
   nPID = getpid();

   printf("Comando -> ");
   gets(cmd);

   // Converte nPID para string em comandos
   itoa(nPID, comando, 10);
	itoa(nPID, cPID, 10);

   strcat(comando,"#");
   strcat(comando, cmd);


   key=ftok(".",'f');
   if ((mid=msgget(key,0)) == -1) 
   {
      printf("Nao foi possivel determinar a identificacao da fila de mensagens.\n");
   }
   else
   {
      //Armazena mensagem na Fila
      msgsnd(mid,comando,sizeof(comando),1);
   }
/////////////////////////////////////////////////////



	do
	{
		key=ftok(".",'m');
		if ((shmid=shmget(key,tamanho,0)) == -1)
		{
			printf("Segmento de memória não criado. Favor inicializar o servidor.\n");
		}
		else
		{
			shm=shmat(shmid,0,0);
//			printf("Recuperei a mensagem \"%s\" do segmento de memoria compartilhada %d.\n",shm,shmid);
         strcpy(resp_serv,shm);
			shmdt(shm);
		}

      msg_original=strdup(resp_serv);//PID + Resposta retornada pelo servidor
      pid_resp = strtok(msg_original, "#");  //pid_resp
      msg_resp = strtok(NULL, "#");          //msg_resp

		//fprintf(stdout, "%s - %s \n", pid_resp,msg_resp);


//		printf("cPID: %s",cPID);
//		printf("pid_resp: %s",pid_resp);


		if (strcmp(cPID , pid_resp) == 0)
		{
			//Se for logout fecha o cliente			
			if (strcmp(msg_resp,"logout") == 0)
			{
				exe = 1;						
			}
			else
			{
				printf("%s \n\n",msg_resp);
			}
		}
		else
		{
			//Não faz nada
		}


	}while(strcmp(cPID , pid_resp) != 0);

	//Atribui 0 a memória compartilhada dps de ler a resposta	
	key=ftok(".",'m');
	if ((shmid=shmget(key,tamanho,0)) == -1)
	{
   	//Não faz nada
   }
	else
	{
   	shm=shmat(shmid,0,0);
      strcpy(shm,"0");
      shmdt(shm);
	}


}while(exe == 0);




}




//Funções para converter INT para String
/////////////////////////////////////////////////////////////////////////////////////////
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
