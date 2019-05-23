#ifndef CLIENTE_H
#define CLIENTE_H

#include "LDDE.h"

typedef struct { 
    int loca;
    char palavra[30];	
} info;

void flush(FILE *in);
void exibeLista(LDDE *ptr, info *reg);
void menu(LDDE *p,FILE *arv);
void carregaLista(LDDE *ptr);
void verificarArquivo(FILE *saida);
void startArquivo(FILE *arq,LDDE *ptr,info *reg);

#endif
