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
   int nPID,nPIDF;
   char cPID[1000];
   char cmd[1000];
   char comando[1000];  

	//variaveis pega resposta do servidor no segmento memoria
   key_t key_m;
   int shmid, tamanho=1000;
   char *shm;
   char resp_serv[1000];  //variavel auxiliar


	//variaveis separa PID e MENSAGEM ba resposta do servidor
   char *msg_original;// = strdup("Separe#Isso");
   char *pid_resp, *msg_resp;
   char msg[1000];

   int exe;

   //Variáveis que separa apenas o usuário do comando login
	char *login_user;// = strdup("Separe#Isso");
   char *nada, *usuario;

	char cmdaux[1000],cmdaux2[1000],msg_respaux[1000],msg_respaux2[1000],user[1000];

int loop;

loop = 1;


   //Zerando String
   strcpy(user,"");

   exe = 0;

   system("clear");

	nPID = getpid();

	//processo q verifica se o servidor esta ativo
	if(fork() == 0)
	{
	   nPIDF = getpid();
		do
		{
		   key=ftok(".",'m');
			if ((shmid=shmget(key,tamanho,0)) == -1)
			{
				system("clear");						
				kill(nPID);
				printf("O servidor foi desligado!!!");
	         loop = 0;
			}
			else
			{
				//Não faz nada
			}
		}while(loop==1);

		sleep(1);
	   kill(nPIDF);
		exit(0);
	}


do
{

   key=ftok(".",'f');
   if ((mid=msgget(key,0)) == -1) 
   {
      printf("O servidor esta desligado!!!.\n Encerrando Cliente. \n\n");
      sleep(2);
      exit(0);
   }
   else
   {
      printf("%sComando -> ",user);
      gets(cmd);


		if (strcmp(cmd,"logout") == 0)
		{
		   //Zerando String
		   strcpy(user,"");
		}

		strcpy(cmdaux,cmd);
		strtok(cmdaux," ");


      // Converte nPID para string em comandos
      itoa(nPID, comando, 10);
      itoa(nPID, cPID, 10);

      strcat(comando,"#");
      strcat(comando, cmd);

      //Armazena mensagem na Fila
      msgsnd(mid,comando,sizeof(comando),1);
   }
/////////////////////////////////////////////////////

	do
	{
	   sleep(1);
		key=ftok(".",'m');
		if ((shmid=shmget(key,tamanho,0)) == -1)
		{
         printf("O servidor esta desligado!!!.\n Encerrando Cliente. \n\n");
		   sleep(2);
		   exit(0);		   
		}
		else
		{
		   shm=shmat(shmid,0,0);
//		   printf("Recuperei a mensagem \"%s\" do segmento de memoria compartilhada %d.\n",shm,shmid);
         strcpy(resp_serv,shm);
		   shmdt(shm);
		}

      msg_original=strdup(resp_serv);//PID + Resposta retornada pelo servidor
      pid_resp = strtok(msg_original, "#");  //pid_resp
      msg_resp = strtok(NULL, "#");          //msg_resp

		strcpy(msg_respaux,msg_resp);
		strcpy(msg_respaux2,msg_resp);

	
		if (strcmp(cPID , pid_resp) == 0)
		{	

			//Escreve o nome do usuário antes da linha comando
			if (strcmp(cmdaux,"login") == 0)
			{
	      	
				login_user=strdup(msg_respaux2);
      		nada = strtok(login_user, ":");
		      usuario = strtok(NULL, "\0");    //atribui o nome de usuario na variavel usuario

		      strcat(usuario,"@");

   			strtok(msg_respaux," ");
				if (strcmp(msg_respaux,"Logado") == 0)
				{									
					strcpy(user,usuario);
				}
			}

			
			//Retorna resultados
			if (strcmp(msg_resp,"exit") == 0)
			{
				exe = 1;
				printf("Encerrando Cliente!!! \n\n");
		   	sleep(2);
			}
			else if (strcmp(msg_resp,"OFF") == 0)
			{
				exe = 1;
				printf("Ate a proxima!!!.\n Encerrando Cliente!!! \n\n");
		   	sleep(2);
			}
			else if (strcmp(msg_resp,"clear") == 0)
			{
				system("clear");						
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

printf("\n Cliente Finalizado!!! \n\n\n");


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
