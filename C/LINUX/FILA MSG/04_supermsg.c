#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TAMANHO_MENSAGEM 80

struct minhastruct {
   long mtype;
   char mtext[MAX_TAMANHO_MENSAGEM];
};

void enviar_mensagem(int fila_id, struct minhastruct *msgponteiro, long tipomensagem, char *mensagem);
void ler_mensagem(int fila_id, struct minhastruct *msgponteiro, long tipomensagem);
void remove_queue(int file_id);
void mudar_permissoes(int fila_id, char *permissoes);
void ajuda(void);

int main(int argc, char *argv[])
{
   key_t key;
   int msgqueue_id;
   struct minhastruct msgponteiro;

   if(argc ==1)
   {
      ajuda();
   }

   key = ftok(".", 'm');

   if((msgqueue_id = msgget(key, IPC_CREAT|0660)) == -1)
   {
      perror("msgget");
      exit(1);
   }

   switch(tolower(argv[1][0]))
   {
      case 'e': enviar_mensagem(msgqueue_id, (struct minhastruct*)&msgponteiro, atol(argv[2]), argv[3]);
         break;;

      case 'r': ler_mensagem(msgqueue_id, &msgponteiro, atol(argv[2]));
         break;

      case 'a': remove_queue(msgqueue_id);
         break;

      case 'm': mudar_permissoes(msgqueue_id, argv[2]);
         break;

      default: ajuda();
   }
   return(0);

}


void enviar_mensagem(int fila_id, struct minhastruct *msgponteiro, long tipomensagem, char *mensagem)
{
   printf("Enviando uma mensagem ... \n");
   msgponteiro->mtype=tipomensagem;
   strcpy(msgponteiro->mtext, mensagem);
   if ((msgsnd(fila_id, (struct msgbuf *)msgponteiro, strlen(msgponteiro->mtext)+1, 0)) == -1)
   {
      perror("msgsnd");
      exit(1);
   }
}


void ler_mensagem(int fila_id, struct minhastruct  *msgponteiro, long tipomensagem)
{
   printf("Lendo uma mensagem ...\n");
   msgponteiro->mtype = tipomensagem;
   msgrcv(fila_id, (struct msgbuf *)msgponteiro, MAX_TAMANHO_MENSAGEM, tipomensagem, 0);
   printf("Tipo: %ld; mensagem: %s\n", msgponteiro->mtype, msgponteiro->mtext);
}


void remove_queue(int fila_id)
{
   msgctl(fila_id, IPC_RMID, 0);
}


void mudar_permissoes(int fila_id, char *permissoes)
{
   struct msqid_ds minhafila_ds;
   msgctl(fila_id, IPC_STAT, &minhafila_ds);
   sscanf(permissoes, "%ho", &minhafila_ds.msg_perm.mode);
   msgctl(fila_id, IPC_SET, &minhafila_ds);
}


void ajuda(void)
{
   fprintf(stderr, "\nsupermmsg - Ferramenta para ler e enviar mensagens em uma fila. \n\n");
   fprintf(stderr, "\nUSO: supermsg comando\n");
   fprintf(stderr, "\n(e)nviar <identificação> <mensagem>\n");
   fprintf(stderr, "\n(r)eceber <tipo>\n");
   fprintf(stderr, "\n(a)pagar\n");
   fprintf(stderr, "\n(m)odo <octal>\n");
   exit(1);
}
