//
// Lista Duplamente Encadeada
//

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct reg {
  int id;
  struct reg *prox;
  struct reg *ant;
};

struct reg *primeiro = NULL;

struct reg * busca_id(int bid) {
  struct reg *pos;
  pos=primeiro;
  while (pos!=NULL) {
    if (pos->id==bid) break;
    pos=pos->prox;
  }
  return pos;
}

int rmv_in(int id) {
  struct reg *pos = busca_id(id);
  if (pos!=NULL) {
    if (pos->ant!=NULL) {
      pos->ant->prox=pos->prox;
    } else {
      primeiro=pos->prox;
    }
    if (pos->prox!=NULL) {
      pos->prox->ant=pos->ant;
    }
    free(pos);
  } else {
    return 0;
  }
  return 1;
}

void add_start(int id) {
  struct reg *novo = (struct reg*) malloc(sizeof(reg));
  if (primeiro==NULL) {
    novo->id=id;
    novo->prox=NULL;
    novo->ant=NULL;
    primeiro=novo;
  } else {
    novo->id=id;
    novo->ant=NULL;
    novo->prox=primeiro;
    primeiro->ant=novo;
    primeiro=novo;
  }
}

int add_after(int id, int bid) {
  struct reg *pos = busca_id(bid);
  if (pos!=NULL) {
     struct reg *novo = (struct reg*) malloc(sizeof(reg));
     novo->id=id;
     novo->ant=pos;
     if (pos->prox!=NULL) {
       novo->prox=pos->prox;
       pos->prox->ant=novo;
     } else {
       novo->prox=NULL;
     }
     pos->prox=novo;
  } else {
    return 0;
  }
  return 1;
}

void lista() {
  struct reg *pos = primeiro;
  while (pos!=NULL) {
    printf("%d\n",pos->id);
    pos=pos->prox;
  }
}

void main() {
  clrscr();
  add_start(1);
  add_start(2);
  add_start(3);
  lista();
  getch();
  clrscr();
  add_after(10,3);
  lista();
  getch();
  clrscr();
  rmv_in(2);
  lista();
  getch();
}