// Listas Encadeadas - Exemplo 1

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

#define numreg 10

struct reg {
  int info;
  struct reg *prox;
};

struct reg *inicio = NULL;
struct reg *ultimo = NULL;

struct reg *anterior = NULL;
struct reg *atual = NULL;

void adiciona(int info) {
  struct reg *novo;
  novo=(reg *) malloc(sizeof(reg));
  if (inicio==NULL) {
    inicio=novo;
  } else {
    ultimo->prox=novo;
  }
  novo->info=info;
  novo->prox=NULL;
  ultimo=novo;
}

void apaga() {
  struct reg *atual;
  atual=inicio;
  if (inicio==ultimo) {
    free(ultimo);
    inicio=NULL;
    ultimo=NULL;
  } else {
    while (atual->prox!=ultimo) {
      atual=atual->prox;
    }
    free(ultimo);
    ultimo=atual;
    ultimo->prox=NULL;
  }
}

void limpar() {
  while (inicio!=NULL) {
    apaga();
  }
}

void lista() {
  struct reg *atual;
  atual=inicio;
  while (atual!=NULL) {
    printf("%d\n",atual->info);
    atual=atual->prox;
  }
}

void busca_id(int id) {
  anterior=inicio;
  if (anterior->info==id) {
    atual=anterior;
    anterior=NULL;
    return;
  }
  atual=anterior->prox;
  while (atual!=NULL) {
    if (atual->info==id) {
      break;
    }
    anterior=atual;
    atual=atual->prox;
  }
}

int rmv_in(int id) {
  busca_id(id);
  if (atual==NULL) {
    return 0;
  } else {
    if (anterior!=NULL) {
      anterior->prox=atual->prox;
    }
    free(atual);
    return 1;
  }
}

void add_in(int id, int nid) {
  busca_id(id);
  if (atual==NULL) {
    adiciona(id);
  } else {
    struct reg *novo;
    novo=(reg *) malloc(sizeof(reg));
    novo->info=nid;
    novo->prox=atual->prox;
    atual->prox=novo;
  }
}

void main() {
  int op;
  do {
    clrscr();
    printf("MENU - LISTA ENCADEADA\n");
    printf("----------------------\n");
    printf("1. Adicionar\n");
    printf("2. Remover\n");
    printf("3. Listar\n");
    printf("4. Limpar\n");
    printf("5. Remove In\n");
    printf("6. Add In\n");
    printf("7. Sair\n\n");
    printf("Opcao: "); scanf("%d",&op);
    clrscr();
    switch (op) {
      case 1: {
	printf("Digite o dado: ");
	int dado;
	scanf("%d",&dado);
	adiciona(dado);
	break;
      }
      case 2: {
	if (inicio!=NULL) {
	  printf("Removendo... ");
	  apaga();
	  getch();
	}
	break;
      }
      case 3: {
	lista();
	getch();
	break;
      }
      case 4: {
	printf("Limpando...");
	limpar();
	getch();
	break;
      }
      case 5: {
	printf("Remove Id: ");
	int id;
	scanf("%d",&id);
	if (rmv_in(id)) {
	  printf("Elemento removido!");
	} else {
	  printf("Elemento nao existe!");
	}
	getch();
	break;
      }
      case 6: {
	printf("Digite o Id de referencia: ");
	int id;
	scanf("%d",&id);
	printf("Digite o dado: ");
	int dado;
	scanf("%d",&dado);
	add_in(id,dado);
	break;
      }
    }
  } while (op!=7);
  limpar();
}