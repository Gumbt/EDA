#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LDDE_priv.h"
//#include "mem.h"

/*************** CRIA ***************/
int cria(LDDE **pp, int tamInfo)
{   
    int ret = FRACASSO;
    LDDE *desc = (LDDE*) malloc(sizeof(LDDE));

    if( !desc ) {
        ret = FRACASSO;
    }
    else {	
    	desc->PosLogAtual = 0;
        desc->refMovel = NULL;
        desc->tamInfo = tamInfo;      
        desc->tamLista = 0;
        ret = SUCESSO;
    }

    (*pp) = desc;

    return ret;
}

/*************** INSERE NO INICIO ***************/
int insereNoInicio(LDDE *p, void *novo)
{
    NoLDDE *temp;
    int ret = FRACASSO;

    if( (temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL ) {
        if( (temp->dados = (void*) malloc(p->tamInfo)) != NULL ) {
            memcpy(temp->dados, novo, p->tamInfo);
            temp->ant=NULL;
            if(p->refMovel==NULL){ //lista vazia
                p->refMovel=temp;
                temp->prox=NULL;
                p->tamLista++;
                p->PosLogAtual++;
            }
            else{
                while(p->refMovel->ant!=NULL){ //enquanto nao esta na primeira posiÃ§Ã£o
                    p->refMovel=p->refMovel->ant;
                    p->PosLogAtual--;
                }
                temp->prox = p->refMovel; //esta na primeira posicao
                p->refMovel->ant = temp;
                p->refMovel = temp;
                p->tamLista++;
            }
            ret = SUCESSO;
        }
        else {
            free(temp);
        }
    }

    return ret;
}

/*************** INSERE NO FINAL ***************/
int insereNoFim(LDDE *p, void *novo)
{
    NoLDDE *temp, *aux;
    int ret = FRACASSO;

    if( (temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL ) {
        if((temp->dados = (void*) malloc(p->tamInfo)) != NULL ) {
            memcpy(temp->dados, novo, p->tamInfo);
            temp->prox = NULL;
            if(p->refMovel == NULL) { //lista vazia
                p->refMovel = temp;
                temp->ant = NULL;
                p->tamLista++;
                p->PosLogAtual++;
            }
            else {
                while(p->refMovel->prox != NULL){ //chegar na ultima posiÃ§Ã£o
                    p->refMovel = p->refMovel->prox;
                    p->PosLogAtual++;
                }
                p->refMovel->prox = temp; //esta na ultima posicao
                temp->ant = p->refMovel;
                p->refMovel=temp;
                p->PosLogAtual++;
                p->tamLista++;
            }
            ret = SUCESSO;
        }
        else {
            free(temp);
        }
    }

    return ret;
}

/*************** INSERE NA POSICAO LOGICA ***************/
int insereNaPosLog (LDDE *p, void *novo, unsigned int posLog)
{
    NoLDDE *temp,*aux;
    unsigned int ret=FRACASSO;

    if( p->refMovel != NULL && posLog > 0) {
        if( (temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL ) {
            if((temp->dados = (void *) malloc(p->tamInfo)) != NULL) {
                memcpy(temp->dados, novo, p->tamInfo);
                if(posLog == 1){
                    return insereNoInicio(p,novo);
                }
                else{
                	if(posLog < p->tamLista+1){
	                    if(posLog != p->PosLogAtual){
	                        while(posLog!=p->PosLogAtual){ //enquanto nao estiver na posicao
	                            if(posLog<(p->PosLogAtual)){ 
	                                p->refMovel = p->refMovel->ant;
	                                p->PosLogAtual--;
	                            }
	                            if(posLog> p->PosLogAtual){ 
	                                p->refMovel = p->refMovel->prox;
	                                p->PosLogAtual++;
	                            }
	                        }
	                    }
	                    aux = p->refMovel->ant;
	                    temp->prox = p->refMovel;
	                    temp->ant = aux;
	                    p->refMovel->ant = temp;
	                    aux->prox = temp;
	                    p->refMovel = temp;
	                    p->tamLista++;
	                    ret = SUCESSO;
	            	}else{
	            		ret = FRACASSO;
	            	}
                }
            }
            else {
                free(temp);
            }
        }
    }

    return ret;
}

/*************** REMOVE DO INICIO ***************/
int removeDoInicio(LDDE *p, void *reg)
{  	
    int ret = FRACASSO;

    if(p->refMovel != NULL) {
		while(p->refMovel->ant!=NULL){//vai pro inicio
            p->PosLogAtual--;
			p->refMovel = p->refMovel->ant;
        }	
        memcpy(reg, p->refMovel->dados, p->tamInfo);
        free(p->refMovel->dados);
        if(p->refMovel->prox != NULL) {//<=2
			p->refMovel = p->refMovel->prox;
            free(p->refMovel->ant->dados);
            free(p->refMovel->ant);
            p->refMovel->ant = NULL;	
        }
        else {// 1 elemento
            free(p->refMovel);
            p->refMovel = NULL;
        }
        ret = SUCESSO;
        p->tamLista--;
    }
    return ret;
}


/*************** REMOVE DO FINAL ***************/
int removeDoFim(LDDE *p, void *reg)
{	
    NoLDDE *aux;
    int ret = FRACASSO;

    if(p->refMovel != NULL) {	
        while(p->refMovel->prox != NULL) {//vai pro fim
            p->refMovel = p->refMovel->prox;
            p->PosLogAtual++;
        }
        memcpy(reg, p->refMovel->dados, p->tamInfo);
        free(p->refMovel->dados);
        if(p->refMovel->ant != NULL) {//<=2
            aux=p->refMovel->ant;
            aux->prox=NULL;   
            p->refMovel=aux;
        }
        else {//1 elemento
            free(p->refMovel);
            p->refMovel = NULL;
        }
        p->PosLogAtual--;
        p->tamLista--;
        ret = SUCESSO;
    }
    return ret;

}

/*************** REMOVE DA POSIÇÃO LÓGICA ***************/
int removeDaPosLog(LDDE *p, void *reg, unsigned int posLog)
{	
     NoLDDE *temp, *pos;
    unsigned int cont=0, ret=FRACASSO;

    if( p->refMovel != NULL && posLog > 0 ) { 
        if(posLog <= p->tamLista+1){//a posicao pedida tem q ser menor ou igual ao tamanho da lista
		    if(posLog == 1) {/*PosLog == 1: inserção de um novo primeiro elemento*/
                return removeDoInicio(p,reg);//insere no inicio
            }
            else {                         /* posLog >= 2, no minimo igual a dois */
                while(posLog != p->PosLogAtual){ //"busca binaria"
                    if(posLog < p->PosLogAtual){ //esta antes do refmovel
                        p->refMovel = p->refMovel->ant;
                        p->PosLogAtual--;
                    }
                    if(posLog > p->PosLogAtual){ //esta depois do refmovel
                        p->refMovel = p->refMovel->prox;
                        p->PosLogAtual++;
                    }
                }
                pos = p->refMovel;//encontrou a posicao para remover
	            memcpy(reg,pos->dados,p->tamInfo);
	            free(p->refMovel->dados);
	            pos->ant->prox = pos->prox;
	            pos->prox->ant = pos->ant;
	            pos=pos->prox;
	            free(p->refMovel);
	            p->refMovel=pos;
	            p->tamLista--;
	            ret = SUCESSO;
            }
    	}else{
    		ret = FRACASSO;
    	}

    }
    return ret;
}

/*************** BUSCA NO INICIO ***************/
int buscaNoInicio(LDDE *p, void *reg)
{  
    int ret = FRACASSO;

    if(p->refMovel != NULL) { 	
   		 while(p->refMovel->ant!=NULL){//vai pro inicio
          	p->PosLogAtual--;
		    p->refMovel=p->refMovel->ant;          
        }
        memcpy(reg, p->refMovel->dados, p->tamInfo);
        ret = SUCESSO;
    }

    return ret;
}

/*************** BUSCA NO FINAL ***************/
int buscaNoFim(LDDE *p, void *reg)
{	
    NoLDDE *aux;
    int ret = FRACASSO;
    if(p->refMovel != NULL) {
        while(p->refMovel->prox!=NULL) {//vai pro fim
            p->refMovel = p->refMovel->prox;
            p->PosLogAtual++;
        }
        memcpy(reg, p->refMovel->dados, p->tamInfo);
        ret = SUCESSO;
    }

    return ret;
}

/*************** BUSCA NA POSIÇÃO LÓGICA ***************/
int buscaNaPosLog(LDDE *p, void *reg, unsigned int posLog)
{	
    int cont, ret = FRACASSO;
    NoLDDE *pos;

    if(p->refMovel != NULL && posLog > 0) {	
        if(posLog == 1) {/*PosLog == 1: inserção de um novo primeiro elemento*/
            return buscaNoInicio(p,reg);//insere no inicio
        }
        else {                         /* posLog >= 2, no minimo igual a dois */
            if(posLog<=p->tamLista){
				while(posLog != p->PosLogAtual){ //"busca binaria"
	                if(posLog < p->PosLogAtual){ //esta antes do refmovel
	                    p->refMovel = p->refMovel->ant;
	                    p->PosLogAtual--;
	                }
	                if(posLog > p->PosLogAtual){ //esta depois do refmovel
	                    p->refMovel = p->refMovel->prox;
	                    p->PosLogAtual++;
	                }
	            }
	            memcpy(reg,p->refMovel->dados,p->tamInfo);
	            ret = SUCESSO;
        	}
		}
    }
    return ret;
}

/*************** TAMANHO ***************/
int tamanho(LDDE *p)
{ 
    return p->tamLista;
}

/*************** PURGA ***************/
void reinicia(LDDE *p)
{	
    if(p->refMovel != NULL) {
        while(p->refMovel->ant!=NULL){
            p->refMovel=p->refMovel->ant;
        }
        while(p->refMovel->prox != NULL) {
            p->refMovel = p->refMovel->prox;
            free(p->refMovel->ant->dados);
            free(p->refMovel->ant);
        }
        free(p->refMovel->dados);
        free(p->refMovel);
        p->refMovel = NULL;
        p->tamLista=0;
        p->PosLogAtual=0;        
    }
}

/*************** DESTROI ***************/
void destroi(LDDE **pp)
{
    reinicia(*pp);
    free(*pp);
    (*pp) = NULL;
}
