#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX_N 3
/*
typedef struct Cliente{
	int nro;
	char *nome[50];
	char *endereco[50];
	int telefone;
} Cliente;

Cliente* novoCliente(int nro, char *nome, char *endereco, int tel)
*/

typedef struct Ponto{
	int x,y;
} Ponto;

Ponto espelhamento(Ponto *p){
	p->x*=-1;
	p->y*=-1;
	return (*p);
}

void inverter (Ponto *p){
	int aux = (*p).x; // = p->x;
	p->x = p->y;
	p->y = aux;
}

void show(Ponto p, int i){
	printf("Ponto %d => x=%d e y=%d\n",i+1, p.x, p.y);
}

typedef struct Plano{
	Ponto *pontos; //armazena os pontos
	int n; //quantidade de pontos
} Plano;

Plano* criaPlano(int n){
	Plano *p = malloc(sizeof(Plano));
	p->n = n;
	p->pontos = malloc(n*sizeof(Ponto));
	return p;
}

void showPlano(Plano *p){
	puts("---PLANO---");
	int i;
	for(i=0; i<(p->n); i++){
		show(p->pontos[i],i);
	}
}

void addPonto(Plano *p, int x, int y){
	int n= p->n+1;
	p->n=n;
	p->pontos=realloc(p->pontos, n*sizeof(Ponto));
	p->pontos[n-1].x=x;
	p->pontos[n-1].y=y;
}

int main(){
	// sem usar o typedef: struct Ponto pontos[MAX_N];
	/*
	Ponto plano[MAX_N];
	int i;
	for(i=0; i<MAX_N; i++){
		printf("Digite x e y do %d vetor ",i+1);
		scanf("%d %d", &plano->pontos[i].x, &plano->pontos[i].y.y);
	}
	for(i=0; i<MAX_N; i++)
		show(plano[i], i);
	printf("Plano 1 sera espelhado, plano 2 e 3 serao invertidos\n");
	espelhamento(&plano[0]);
	inverter(&plano[1]);
	inverter(&plano[2]);
	for(i=0; i<MAX_N; i++)
		show(plano[i], i);
	*/
	Plano *plano;
	plano = criaPlano(MAX_N);
	plano->pontos[0].x=1;
	plano->pontos[0].y=3;
	plano->pontos[1].x=2;
	plano->pontos[1].y=5;
	plano->pontos[2].x=6;
	plano->pontos[2].y=6;
	addPonto(plano, 97, -11);
	showPlano(plano);
	
		
	
	//Cliente clientes[MAX_N];
	
}
