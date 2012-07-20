#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define KEY 100

int main()
{
  

   int msqid;
   char *caminho="/home/leandro/Desktop";

   if ((msqid = msgget(ftok(caminho,(key_t)KEY),IPC_CREAT|IPC_EXCL|0666)) == -1) {
      printf("Erro ao criar a fila de mensagem. \n");
      exit(1);
   }
  
   printf("Esta nova fila tem o identificador número: %d\n",msqid);
   exit(0);


}

