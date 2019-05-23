#ifndef LDDE_PRIV_H
#define LDDE_PRIV_H

#include "LDDE.h"

typedef struct noLDDE {
    void *dados;
    struct noLDDE *prox;
    struct noLDDE *ant;
} NoLDDE;

typedef struct LDDE { 
    int tamInfo;
    int PosLogAtual;
    int tamLista;
    NoLDDE *refMovel;   
} LDDE;

#endif
