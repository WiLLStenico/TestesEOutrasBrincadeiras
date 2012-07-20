#include <stdio.h>
#include <conio.h>

char pilha[100];
int pos=0;

void push(char dado) {
  if (pos<100) {
    pilha[pos++]=dado;
  } else {
    printf("Stack overflow!");
  }
}

void pop() {
  if (pos>0) {
    pos--;
  } else {
    printf("Stack underflow!\n");
  }
}

void main() {
  clrscr();
  push('a');
  push('b');
  push('c');
  pop();
  pop();
  printf("Tamanho: %d\n",pos);
  getch();
}