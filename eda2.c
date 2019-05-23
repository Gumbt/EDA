#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 3

void show(Ponto p,int i){
  printf("Ponto[%d]=> x=%d y=%d\n",i+1,p.x,p.y);
}

typedef struct Ponto{
  int x,y;
}Ponto;

Ponto espelhamento( Ponto p){
    p.x *= -1;
    p.y *= -1;
    return p;
}

void inverter (Ponto *p){
    int aux = (*p).x; // = p->x
    p->x = p->y;
    p->y=aux;
}

typedef struct Plano{
  Ponto *pontos; //armazena os pontos
  int n; //quant pontos
}Plano;

Plano* criarPLano(int n){
    Plano *p = malloc(sizeof(Plano));
    p->n = n;
    p->pontos = malloc(n * sizeof(Ponto));
    return p;
}

void showPlano(Plano *p){
  puts("--- Plano ---");
  for(int i=0;i<(p->n);i++){
    printf("Ponto %d: ", i);
    show(p->pontos[i],i);
  }
}

void addPonto( Plano *p, int x, int y){
  int n= p->n + 1;
  p->n = n;
  p->pontos = realloc( p->pontos, n * sizeof(Ponto));
  p->pontos[n-1].x=x;
  p->pontos[n-1].y=y;
}

typedef struct Cliente{
  int nro;
  char nome[50];
  char endereco[50];
  int telefone;
  struct Cliente *responsavel;
}Cliente;

Cliente* novoCliente(int nro, char *nome, char* endereco, int telefone, Cliente *responsavel){
  Cliente *c = malloc(sizeof(Cliente));
  c->nro=nro;
  c->nome = malloc(strlen(nome)*sizeof(char));
  c->endereco= malloc(strlen(endereco)*sizeof(char));
  c->telefone=telefone;
  strcpy(c->nome, nome);
  strcpy(c->endereco, endereco);
  c->responsavel=responsavel;
  return c;
}

void showCliente(Cliente *c){

}

int main(){
  /*int x[MAX_N], y[MAX_N];

  int nros[MAX_N];
  char nome[MAX_N][50];
  char endereco[MAX_N][50];
  int telefone[MAX_N];*/
  ////Ponto plano[MAX_N];
  ////plano[0].x = 5;
  ////plano[0].y = 7;
  Plano *plano;
  plano = criarPlano(MAX_N);
  plano->pontos[0].x=1;
  plano->pontos[0].y=3;
  addPonto(plano, 97, -11);
  addPonto(plano, 13, 7);
  addPonto(plano, -9, 4);
  showPlano(plano);

  Cliente *c1 = novoCliente(1,"farofeiro","praia",4799999999,null);
  Cliente *c2 = novoCliente(2,"arroizeiro","japao",4444444444,c1);
  /*for(int i=0;i<MAX_N;i++){
    scanf("%d %d", &plano[i].x, &plano[i].y);
  }

  Ponto aux = espelhamento( plano[0]);
  inverter(&plano[1]);
  inverter(&plano[2]);

  printf("[0]=> %d / %d\n", plano[0].x,plano[0].y );
  printf("[1]=> %d / %d\n", plano[1].x,plano[1].y );
  printf("[2]=> %d / %d\n", plano[2].x,plano[2].y );
  printf("aux=> %d / %d\n", aux.x,aux.y );
  Cliente clientes[MAX_N];
  */
}
