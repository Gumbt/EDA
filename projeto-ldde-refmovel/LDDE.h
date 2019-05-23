#ifndef LDDE_H
#define LDDE_H

#define FRACASSO 0
#define SUCESSO 1

typedef struct LDDE LDDE;

int cria(LDDE **pp, int tamInfo);
int insereNoInicio(LDDE *p, void *novo);
int insereNoFim(LDDE *p, void *novo);
int insereNaPosLog (LDDE *p, void *novo,unsigned int posLog);
int tamanho(LDDE *p);
void reinicia(LDDE *p);
void destroi(LDDE **pp);
int buscaNaPosLog(LDDE *p, void *reg, unsigned int posLog);
int buscaNoFim(LDDE *p, void *reg);
int buscaNoInicio(LDDE *p, void *reg);
int removeDaPosLog(LDDE *p, void *reg, unsigned int posLog);
int removeDoFim(LDDE *p, void *reg);
int removeDoInicio(LDDE *p, void *reg);

#endif
