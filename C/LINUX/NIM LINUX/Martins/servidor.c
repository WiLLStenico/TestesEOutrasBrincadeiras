/* 
 * 			servidorTCP_threads.c
 *
 * Este programa foi desenvolvido para simular uma aplicacao servidora
 * multithread
 * 
 * Funcao:     Receber e retornar streams compostos de caracteres de
 *             multiplas conexoes de clientes
 * Plataforma: Linux (Unix) ou Windows com CygWin
 * Compilar:   gcc -Wall -lpthread servidorTCP_threads.c -o servidorTCP_threads
 * Uso:        ./servidorTCP_threads [porta_do_servidor]
 *
 * Autor:      Jose Martins Junior - 12/08/2005
 * 	
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define QUEUE_LENGTH 5      //Tamanho maximo da fila de conexoes de clientes
#define MAX_FLOW_SIZE 1000  //Tamanho maximo do buffer de caracteres

#define MAX_ATIVOS 100

pthread_mutex_t mut1;  //Semaforo global para uso das threads
int threadId;          //Id das threads - variavel global - condicao de disputa
int ativos, conexoes[MAX_ATIVOS];


void *servThread(int *msgsock) { //Inicio da funcao que cada thread executarah
	int Id, s_val, r_val, buf_len, n = 0;
	char buf[MAX_FLOW_SIZE];
	pthread_mutex_lock(&mut1);   //Inicio de uma regiao critica
	ativos++;
	while(conexoes[n] != 0) n++;
	conexoes[n] = (int)msgsock;
	Id = ++threadId;
	pthread_mutex_unlock(&mut1); //Final de uma regiao critica
	printf("Thread %d - abrindo conexao\n", Id);
	do {

/*
 *******************************************************************************
               Recebendo as mensagens do cliente
 *******************************************************************************
 */
		memset(buf,0,sizeof(buf));
		r_val = recv((int)msgsock, buf, MAX_FLOW_SIZE*(sizeof(char)), 0);
		if (r_val <= 0) {
			if (r_val < 0) 
				fprintf(stderr, "Ocorreu um erro na aplicacao\n");
			else 
				printf("Thread %d - Encerrando a conexao do cliente\n", Id);
		}
/*----------------------------------------------------------------------------*/

		else {

/*
 *******************************************************************************
               Enviando as mensagens para o cliente
 *******************************************************************************
 */
			buf_len = strlen(buf);
			pthread_mutex_lock(&mut1);   //Inicio de uma regiao critica
			n = 0;
			while(n < MAX_ATIVOS) {
				if(conexoes[n] != 0) {
					s_val = send(conexoes[n], buf, buf_len*(sizeof(char)), 0);
				}
				n++;
			}
			pthread_mutex_unlock(&mut1); //Final de uma regiao critica
			if (s_val < 0) {
				fprintf(stderr, "Thread %d - A conexao foi perdida\n", Id);
				r_val=0;
			}
			else {
				printf(	"Thread %d - Mensagem enviada: [%s]\n", Id, buf);
			}
/*----------------------------------------------------------------------------*/

		}
	} while (r_val > 0);
	pthread_mutex_lock(&mut1);
	ativos--;
	n = 0;
	while(conexoes[n] != (int)msgsock) n++;
	conexoes[n] = 0;
	pthread_mutex_unlock(&mut1);
	close((int)msgsock);
	pthread_exit(0);  //Encerramento da thread
} //Final da funcao que cada thread executarah


int main(int argc, char *argv[]){
	int sock, length, b_val, g_val, msgsock, server_port;
	struct sockaddr_in server;

/*
 *******************************************************************************
               Abrindo um socket do tipo stream (TCP)
 *******************************************************************************
 */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		fprintf(stderr, "Stream socket nao pode ser aberto\n");
		return(1);
	}
/*----------------------------------------------------------------------------*/

/*
 *******************************************************************************
               Setando os atributos da estrutura do socket
 *******************************************************************************
 */
	server.sin_family	= AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	if (argc == 2) {
		server_port	= atoi(argv[1]);
		if (server_port <= 0) {
			fprintf(stderr, "Porta Invalida: %s\n", argv[1]);
			close(sock);
			return(1);
		}
		else server.sin_port	= htons(server_port);
	}
	else server.sin_port = 0;
/*----------------------------------------------------------------------------*/

/*
 *******************************************************************************
               Fazendo o bind para o stream socket aberto
 *******************************************************************************
 */
	b_val = bind(sock, (struct sockaddr *)&server, sizeof(server));
	if (b_val < 0) {
		fprintf(stderr, "O bind para o stream socket falhou\n");
		close(sock);
		return(1);
	}
/*----------------------------------------------------------------------------*/

/*
 *******************************************************************************
               Obtendo o nome do socket
 *******************************************************************************
 */
	length = sizeof(server);
	g_val	= getsockname(sock, (struct sockaddr *)&server, &length);
	if (g_val < 0) {
		fprintf(stderr, "Nao foi possivel obter o nome do socket\n");
		close(sock);
		return(1);
	}
/*----------------------------------------------------------------------------*/

	printf("Porta do servidor: %d\n", ntohs(server.sin_port));

/*
 *******************************************************************************
               Colocando o servidor em modo listening
 *******************************************************************************
 */
	listen(sock, QUEUE_LENGTH);
/*----------------------------------------------------------------------------*/
	memset(conexoes,0,MAX_ATIVOS*sizeof(int));
	do {

/*
 *******************************************************************************
               Habilitando o servidor de receber conexoes
 *******************************************************************************
 */
		msgsock = accept(sock, (struct sockaddr *) 0, (int*) 0);
		if (msgsock < 0) 
			fprintf(stderr, "O socket nao pode aceitar conexoes\n");
/*----------------------------------------------------------------------------*/

		else {  //Criacao de um thread para atender cada cliente
			if(ativos < MAX_ATIVOS) {
				pthread_t newThread;
				pthread_create(&newThread, 0, (void *)servThread, (void *)msgsock);
			}
			else {
				read(msgsock, 0, 0);
				write(msgsock, "Limite maximo de clientes excedido", sizeof("Limite maximo de clientes excedido"));
				close(msgsock);
			}
		}
	} while (1);
	close(sock);
	return(0);
}
