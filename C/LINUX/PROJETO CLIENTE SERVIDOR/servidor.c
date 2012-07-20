#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include<time.h>
#include <sys/utsname.h>



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


//*************************************************** MAIN () ****************************************************************************************
main() {
 
//var fila
 key_t	key_f;
  int	mid_f, mid_c,n;
  char	msg_fila[1000];


//var mem
   key_t key_m;
   int	tamanho=1000, shmid;
   char	msg_mem[1000],*shm,*shm_r;


//tratamento de String

   char *PID,*COMANDO,*msg_original;
   char RESPOSTA[1000];
   char *usuario,*subcomando,*msg_comando,*senha;
   char *copiacomando;


//função DATA

	struct tm *ptr;
	time_t ld;
   char data[4];
   
//Armazenamento de USUARIOS

	char pid_user[10][10],user[10][10],senha_user[10][10],logados[10][10],whoIam[10];
	//pid_user armazena pid de qm esta logado!!!
	//logados armazena o Nome do usuario que esta Logado!!! 
	//user armazena TODOS os usuarios criados!!!
	//pid_user armazena PID de todos os Usuarios LOGADOS!!!

   int cont,status=0,pos_vaga=11,ver_user=0,arm_pos,logado=0,jacadastrado; //status 1=Logado 0=Nao Logado(criar Conta); pos_vaga=posição onde sera armazenado o usuario, senha e PID
   
//Funçao UNAME

  struct utsname u;
   uname(&u);

	char uname_aux[20];

	strcpy(uname_aux,u.sysname);

//LIMPANDO TELA....
  system("clear");


//Criando Filas..................

  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0777|IPC_CREAT)) == -1) {
     printf("Nao foi possivel criar uma fila de mensagens na memoria.");
  } else {
     printf("Criando Fila de Mensagens com Identificador\" %d \". \n",mid_f);
  }


 //Criando Segmento de MEMORIA Compartilhada.........

  

  //system("clear");

  key_m=ftok(".",'m');
  if ((shmid=shmget(key_m,tamanho,0777|IPC_CREAT)) == -1) {
     printf("Nao foi possivel reservar um segmento de memoria compartilhada.");
  }

  printf("\nCriando Segmento de Memoria Compartilhada com Identificador \" %d \".\n",shmid);


// system("ipcs");




//Limpando Strings!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

 printf("\nLimpando Strings Para Armazenamento de Usuarios.");

	

for(cont=0;cont<10;cont++)
{

 printf(".");
 strcpy(user[cont],"0");
 strcpy(pid_user[cont],"0");
 strcpy(logados[cont],"0");
 strcpy(senha_user[cont],"0");

}

	strcpy(user[0],"root");
	strcpy(senha_user[0],"toor");//Armazenando ROOT!!







do{

  

   


//recuperando Mensagem da FILA......


  printf("\n\nBUSCANDO MENSAGENS DOS CLIENTES...\n\n",n);

    
  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0)) == -1) {
     printf("Nao foi possivel determinar a identificacao da fila de mensagens.\n\n");
  } else {
     n=msgrcv(mid_f,msg_fila,sizeof(msg_fila),0,0); 
     //printf("Recuperei a mensagem \"%s\" da fila de mensagens de identificador %d.\n",msg_fila,mid_f);
     //printf("%d \n",n);

  }

   
//TRATAMENTO DE STRING..................................................................................



                   
       
    msg_original=strdup(msg_fila);//recebe msg aqui
        
    PID = strtok(msg_original, "#");
    //printf("%s \n", PID);  
                
                
    COMANDO = strtok(NULL, "#");
    //printf("%s \n", COMANDO);

   
      

	printf("Recebido Comando \"%s\" do Usuario de PID \"%s\".",COMANDO,PID);




//************************ SHELL **********************************************************

/*

-LOGIN - OK
-LOGOUT - OK
-WHO AM I - OK
-WHO - OK
-DATE - OK
-HOSTNAME - OK
-UNAME - OK
-CLEAR - OK
-CREDITOS - OK
-EXIT - OK
-HELP - 

*/



//char *usuario,*subcomando,*msg_comando, *senha;

// char pid_user[10][10],user[10][10],senha_user[10][10],logados[10][10];
// int cont,status=0,pos_vaga=11; //status 1=Logado 0=Nao Logado(criar Conta); pos_vaga=posição onde sera armazenado o usuario, senha e PID
 
        
    msg_comando=strdup(COMANDO);//recebe msg aqui
        
    subcomando = strtok(msg_comando, " ");//Separa Comando do Tipo Login e Create_user para Verificação

	 usuario = strtok(NULL, " ");//Separa Usuario

	 senha = strtok(NULL, "\0");//Separa Senha


    if(strcmp(subcomando,"login")==0)
	  {
		status=1;
      ver_user=0;
      arm_pos=11;

          for(cont=0;cont<10;cont++)
          {
				 
            
				if((pos_vaga==11)&&(strcmp(pid_user[cont],"0")==0))
              {
               
					pos_vaga=cont; 
              }
           }//verifica posição livre para armazenar usuario

		  for(cont=0;cont<10;cont++)
			{
				
				if(strcmp(logados[cont],usuario)==0)
					{
					 strcpy(RESPOSTA,"Usuario em Uso Selecione outro:!!!");
					 status=0;
					}
				if((ver_user==0)&&(strcmp(user[cont],usuario)==0))
					{
					 ver_user=1;
					 arm_pos=cont;
					}     		
			}
       

		  if(((strcmp(senha,senha_user[arm_pos])!=0)||(ver_user==0))&&(status==1))
			{
				strcpy(RESPOSTA,"Usuario ou Senha Invalidos:!!!!");
            status=0;
			}	

         
          for(cont=0;cont<10;cont++)
	       {

	        if(strcmp(pid_user[cont],PID)==0)//verifica se usuario esta logado ou nao!!!
     		  {
			   strcpy(RESPOSTA,"Voce ja esta Logado como: ");
            strcat(RESPOSTA, logados[cont]); 
				status=0;//se já estiver logado status = 0 para evitar entrar em novas verificações

		     }

	       }

        
		  if((status==1)&&(ver_user==1))
			{ 
				 for(cont=0;cont<10;cont++)
				{
				
				//if(strcmp(logados[cont],"0")==0)
					//{           
						//puts(pid_user[pos_vaga]);
            		//puts(user[arm_pos]);
						strcpy(pid_user[arm_pos],PID);//armazenando PID usuario
						strcpy(logados[arm_pos],user[arm_pos]);//armazenando usuario na tabela de quem esta logado
						strcpy(RESPOSTA,"Logado com Sucesso!\n Login:");
						strcat(RESPOSTA,user[arm_pos]);
            		logado=1;
					// }
					}
			}

       

     }else if(strcmp(subcomando,"create_user")==0)
     	{        
        status=1;//Altera status para 1 para Verificar se Usuario é o ROOT!!!!
			jacadastrado=0;


          for(cont=0;cont<10;cont++)
	       {

	        if(strcmp(pid_user[cont],PID)==0)//compara PID do usuario Logado com PID da tabela de Logados
     		  {
			   
             if(strcmp(user[cont],"root")==0) //verifica se o PID logado é do ROOT
					{
									
						status=1;



             for(cont=0;cont<10;cont++) 
             {
					              
          	  if((strcmp(user[cont],"0")==0)&&(pos_vaga!=11))               
					{
						  
  
						pos_vaga=cont;
                  break;
               }
              }//verifica posição livre para armazenar usuario

        
           for(cont=0;cont<10;cont++)
			  {
				if((status==1)&&(strcmp(user[cont],usuario)==0))
				{

					jacadastrado=1;
					status=0;
					strcpy(RESPOSTA,"\n--> Usuario ja Cadastrado Favor Crie Outro com um Nome Diferente!!!");

				}
			  }

			

			

         if(status==1)
         {
			 
	  	
     	
		   strcpy(user[pos_vaga],usuario); //armazenando Usuario em uma posição vaga
     	   	
     	
		   strcpy(senha_user[pos_vaga],senha);//armazena senha na mm posição do user porem em outro vetor
     	    
    	   strcpy(RESPOSTA,"\n         Usuario Criado!!\n UserName: ");
         strcat(RESPOSTA,user[pos_vaga]);
		   strcat(RESPOSTA,"\n Senha: ");
         strcat(RESPOSTA,senha_user[pos_vaga]);

         printf("\n\nCriado Usuario e Armazenado na Posicao: %d \n",pos_vaga);

         
     
        }
       

						
		 }else{ strcpy(RESPOSTA,"Voce não tem Permissao para criar Logins, Entre em Contato com o Administrador!!"); }
				

	 }

	}
         

     }
   logado=0;

    

    for(cont=0;cont<10;cont++)
	 {

	  if(strcmp(pid_user[cont],PID)==0)//verifica se usuario esta logado ou nao!!!
		{	
			strcpy(whoIam,user[cont]);
			logado=1;//logado = 1 equivale a dizer que o usuario esta Logado!!!

		}

	 }

  


if(logado==1)//Entra Aqui quando esta Logado ( Status==1)
{

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
  strcpy(RESPOSTA,"\n\t CREDITOS \n WiLLiaM Henrique Stenico   RA: 300070489 \n Leandro Maciel Vitti       RA: 300070537 \n Gianne Forti               RA: 300070510\n");

 	} else if(strcmp(COMANDO , "logout")==0) 
				{
 								
					for(cont=0;cont<10;cont++)
	       		{

	        		 if(strcmp(pid_user[cont],PID)==0)//verifica se usuario esta logado ou nao!!!
     		  		 {
						strcpy(RESPOSTA, "Usuario \" ");	   		
						strcat(RESPOSTA, logados[cont]); 
						strcat(RESPOSTA, " \" Desconectado!!");
						strcpy(pid_user[cont],"0");//Apaga Registro do Usuario na Tabela de PID_USER
						strcpy(logados[cont],"0");//Apaga Registro da Tabela de Logados
					            					
		     		 }

	       	   }

				}else if(strcmp(COMANDO , "exit")==0) 
				{
 						
					for(cont=0;cont<10;cont++)
	       		{

	        		 if(strcmp(pid_user[cont],PID)==0)//verifica se usuario esta logado ou nao!!!
     		  		 {
						strcpy(RESPOSTA, "exit");	   		
						strcpy(pid_user[cont],"0");//Apaga Registro do Usuario na Tabela de PID_USER
						strcpy(logados[cont],"0");//Apaga Registro da Tabela de Logados          					
		     		 }
	       	   }
				}else if(strcmp(COMANDO , "shutdown")==0)
								{
									strcpy(RESPOSTA,"OFF");

								}else if(strcmp(COMANDO , "uname")==0)
								{
																	
									strcpy(RESPOSTA,uname_aux);
									
								}else if(strcmp(COMANDO , "hostname")==0)
								{
									strcpy(RESPOSTA,u.nodename);
								}else if(strcmp(COMANDO , "who")==0)
								{
									   strcpy(RESPOSTA,"LOGADOS: \n");

          							for(cont=0;cont<10;cont++)
	       							{

	        								if(strcmp(pid_user[cont],"0")!=0)//verifica quem esta logado ou nao!!!
     		 								 {
			   								strcat(RESPOSTA,logados[cont]);
            								strcat(RESPOSTA, "\n"); 
											 }
	      							}							
								}else if(strcmp(COMANDO , "whoami")==0)
								{
									for(cont=0;cont<10;cont++)
	       						{
	        							if(strcmp(pid_user[cont],PID)==0)//verifica se usuario atraves do PID!!!
     		 								 {
			  									strcpy(RESPOSTA, logados[cont]); 
		     								 }
	       						}
								}else if(strcmp(COMANDO , "clear")==0)
								       {
									     strcpy(RESPOSTA,"clear");
								      }else if((strcmp(subcomando,"login")!=0)&&(strcmp(subcomando,"create_user")!=0))								
   								   { 
  									     strcpy(RESPOSTA,"COMANDO INVALIDO");
      								}

  
 status=0;
}else if((strcmp(subcomando,"create_user")!=0)&&(strcmp(subcomando,"login")!=0)){ 
      strcpy(RESPOSTA, "   USUARIO NAO LOGADO!!!!!!!!!\n-->Se ja possui Login digite: \"login <nome_de_usuario> <senha>\"");
     }


	if(strcmp(subcomando,"help")==0)
	{
		strcpy(RESPOSTA,"\nlogin:\n\tLoga no sistema(login user senha)\nlogout:\n\tEfetua logoff do sistema\nwhoami:\n\tExibe nome do cliente que executou o comando\nwho:\n\tExibe uma lista de todos os usuarios logados\ndate:\n\tExibe a data\nhostname:\n\tExibe nome do host onde o servidor esta sendo executado\nuname:\n\tExibe o nome do Sistema Operacional em que o servidor esta sendo executado\nclear:\n\tLimpa tela\ncreditos:\n\tExibe nome dos Desenvolvedores do Sistema(Cliente/Servidor)\nexit:\n\tEfetua logoff e encerra o Cliente\ncreate_user:\n\tCria usuario, Restrito ao \"root\"(create_user user senha)"); 




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
     printf("\n\nEnviando Resposta ao Cliente %s: -> \"%s\".\n",whoIam,shm);
     shmdt(shm);
  }

		printf("\nAguardando Resposta do Usuario.");
	

   	do{
      
      
		printf(".");

      	shm_r=shmat(shmid,0,0);
         strcpy(RESPOSTA,shm_r);
			shmdt(shm_r);
		
      
      sleep(1);

  	 }while(strcmp(RESPOSTA , "0")!=0);



  
	//getchar();
   
   //liberar espaco na variavel
    //free(COMANDO); 
    

	}while((strcmp(COMANDO , "shutdown")!=0)||(logado==0));


//apaga Filas........................
    
  key_f=ftok(".",'f');
  if ((mid_f=msgget(key_f,0)) == -1) {
     printf("Nao foi possivel determinar a identidicacao da fila de mensagens.\n");
  } else {
     if (msgctl(mid_f,IPC_RMID,0) == 0) {
        printf("\n\nApagando a Fila de Mensagens \"%d\" .\n",mid_f);
     } else {
        printf("A fila de mensagens %d nao pode ser removida.\n",mid_f);
     }
  }



//apaga Memoria Compartilhada...................



  key_m=ftok(".",'m');
  if ((shmid=shmget(key_m,tamanho,0)) == -1) {
     printf("Nao foi possivel determinar o identificador do segmento de memoria compartilhada.\n\n");
  } else {
     if (shmctl(shmid,IPC_RMID,0) == 0) {
        printf("\nApagando o Segmento de Memória Compartilhado \" %d \".\n\n",shmid);
     } else {
        printf("O segmento de memória compartilhada %d nao pode ser removido.\n",shmid);
     }
  }





 //system("ipcs");
 
}




