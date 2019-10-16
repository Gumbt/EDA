#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100
#define nulo 0
#define infinito 1000000

int marcado[max];//vetor de vertices marcados
int seq[max];//vetor das sequencias de vetores percorridos
int cont=0;//contador auxiliar para vetor de sequencias
int peso[max];//peso das arestas
int estimativa[max];
int vertice[max];
int precedente[max];

int** alocarGrafo(int vertices, int arestas){
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

void ler_grafo(int **g,FILE *grafoarq,int vertices, int arestas){
	int i,j,a,b,c;
	for (j=0;j<arestas;j++){
	  fscanf(grafoarq,"%d %d %d",&a,&b,&c);
	  g[j][a-1]=1;
	  g[j][c-1]=2;
    peso[j]=b;
	}
}

void mostra_grafo(int **g, int vertices, int arestas){
	int i,j;
	for (i=0;i<arestas;i++){
    for (j=0;j<vertices;j++){
      printf("%d ",g[i][j]);
    }
    printf(" =  %d\n",peso[i]);
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
void tabelinha(int v){
	int i;
	printf("\n\nVertices:    ");
	for(i=0;i<v;i++){
		printf("%3d ",vertice[i]+1);
	}
	printf("\nEstimativas: ");
		for(i=0;i<v;i++){
	printf("%3d ",estimativa[i]);
	}
	printf("\nPrecedentes: ");
		for(i=0;i<v;i++){
	printf("%3d ",precedente[i]+1);
	}
}

bool todosMarcados(int v){
	int i;
	bool aux=true;
	for(i=0;i<v;i++){
    	if(marcado[i]==0){
      		aux=false;
    	}
	}
	return aux;
}
void dijkstra(int **g, int atual, int vertices, int arestas){
	marcado[atual]=1;
	seq[cont]=atual;
	cont++;
	bool todos_marcados = todosMarcados(vertices);
	int i,j,menor_estimativa=infinito,posi_menor_es;
	for(i=0;i<arestas;i++){
		if(g[i][atual]==1){//busca na matriz de arestas o vertice atual
		  for(j=0;j<vertices;j++){
		    if(g[i][j]==2 && marcado[j]!=1){//busca os vizinhos em que saem arestas do atual para o novo vertice (vizinho)
		      estimativa[j]=peso[i]+estimativa[atual];
		      if(estimativa[j]>infinito)
		        estimativa[j]=estimativa[j]-infinito;
		      precedente[j]=atual;
		    }
		  }
		}
	}
	for(i=0;i<vertices;i++){
		if(estimativa[i]<menor_estimativa && estimativa[i]!=0 && marcado[i]!=1){
		    menor_estimativa=estimativa[i];
		    posi_menor_es=i;
		}
	}
	tabelinha(vertices);
	if(todos_marcados==false){
		printf("\nselecionou o vertice  %d",posi_menor_es+1);
		dijkstra(g,posi_menor_es,vertices,arestas);
	}
}

void printCaminho(int v){
	int i;
	printf("\n\nCaminho com menor pesos: ");
	for(i=0;i<v;i++)
		printf("%d ",seq[i]+1);
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
	int **mgrafo = alocarGrafo(v,a);
	ler_grafo(mgrafo,grafoarq,v,a);
	printf("Matriz do grafo:\n\n");
	mostra_grafo(mgrafo,v,a);
	int i,j,inicial=1;
	printf("\nDigite o vertice de inicio: ");
	scanf("%d",&inicial);
	for(i=0;i<v;i++){
	    vertice[i]=i;
	    estimativa[i]=infinito;
	    marcado[i]=0;
	}
	estimativa[inicial-1]=0;
	precedente[inicial-1]=-1;
	tabelinha(v);
	dijkstra(mgrafo,inicial-1,v,a);
	printCaminho(v);
	freeGrafo(mgrafo, v);
	fclose(grafoarq);
	return 0;
}
