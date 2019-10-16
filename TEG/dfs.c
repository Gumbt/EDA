#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100
#define nulo 0
#define infinito max-1

int distancia[max];//vetor das distancias a partir do vertice atual
int distPer=0;//variavel da distancia percaorrida
int marcado[max];//vetor de vertices marcados
int seq[max];//vetor das sequencias de vetores percorridos
int cont=0;//contador auxiliar para vetor de sequencias

int** alocarGrafo(int arestas,int vertices){
	int i,j;
	int **m = (int**)malloc(arestas * sizeof(int*));

	for (i = 0; i < arestas; i++){
		m[i] = (int*) malloc(vertices * sizeof(int));
		for (j = 0; j < vertices; j++){
			m[i][j] = 0;
		}
	}
	return m;
}
void mostra_grafo(int **g,int vertices){
	int i,j;
	for (i=0;i<vertices;i++){
	  for (j=0;j<vertices;j++){
	     if (g[i][j]==0)printf("0 ");
             else printf("1 ");
	  }
	  printf("\n");
	}
}

void ler_grafo(int **g,FILE *grafoarq,int vertices, int arestas){
	int i,j,a,b;
    for (j=0;j<arestas;j++){
	  fscanf(grafoarq,"%d %d",&a,&b);
	  g[a-1][b-1]=1;
	  g[b-1][a-1]=1;
	}
}
/*
int grau(int n){
	int i,ocorrencias;
	for (i=0;i<vertices;i++)
	  if (grafo[n][i]) ocorrencias++;
	return(ocorrencias);
}
*/

void visitaDFS(int n, int **grafo, int vertices){
	int i;
	distancia[n]=distPer;
	for (i=0;i<vertices;i++){
		if ( (grafo[n][i]==1) && (distPer<distancia[i]) && (marcado[i]!=1) ){
			distPer++;
			marcado[i]=1;
			seq[cont]=i+1;
			cont++;
			printf("visitando %d a partir de %d . distPer= %d \n",i+1,n+1,distPer);
			visitaDFS(i,grafo,vertices);
			distPer--;
		}
	}
}

void DFS(int inicial, int **grafo, int vertices){
	int i;
	printf("Iniciando DFS em %d\n",inicial+1);
	for(i=0;i<vertices;i++){
		distancia[i]=infinito;
	}
	distancia[inicial]=0;
	distPer=0;
	for(i=0;i<vertices;i++){
  	if  ( (grafo[inicial][i]==1) && (distPer<distancia[i]) && (marcado[i]!=1) ){
    	distPer++;
			marcado[i]=1;
			seq[cont]=inicial+1;
			cont++;
			seq[cont]=i+1;
			cont++;
    	printf("visitando %d a partir de %d . distPer= %d \n",i+1,inicial+1,distPer);
    	visitaDFS(i,grafo,vertices);
    	distPer--;
  	}
  }
}
void freeGrafo(int **g,int v){
	int i;
	for (i=0; i<v; i++)
		free(g[i]);
	free(g);
}

int main(){
  int v,a;
	FILE *grafoarq = fopen("grafo.txt", "r+");
	if(grafoarq == NULL){
      printf("Nao foi possivel abrir o programa base\n");
      return 0;
  }
  fscanf(grafoarq, "%d %d",&v,&a); //numero de vertices e arestas da primeira linha do .txt
  int **mgrafo = alocarGrafo(v,v);
	ler_grafo(mgrafo,grafoarq,v,a);
	printf("Matriz do grafo:\n\n");
	mostra_grafo(mgrafo,v);
	int i,j,inicial=1;
	printf("\nDigite o vertice de inicio: ");
	scanf("%d",&inicial);
  printf("\n");
  DFS(inicial-1,mgrafo,v);
  printf("\nVetor das distancias:\n\n");
  for (i=0;i<v;i++){
		printf("[%d]",distancia[i]);
	}
	printf("\n\nCaminhos/Arvore:\n");
	for(i=0;i<cont;i++){
		if(seq[i]==inicial){
			printf("\n%d - ",seq[i]);
		}
		else{
			if(i==cont-1 || seq[i+1]==inicial)
				printf("%d  ",seq[i]);
			else
				printf("%d - ",seq[i]);
		}
	}
  freeGrafo(mgrafo, v);
	fclose(grafoarq);
}
