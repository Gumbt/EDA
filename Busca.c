#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdint.h>
#define MAX 500000

int buscaBinaria(long buscado,long *vet, long total){
	long temp,inicio=0,fim=total-1,meio,niteracoes=0;
	do{
		meio = (inicio+fim)/2;
		if(buscado==vet[meio]){
			temp=vet[meio];
		}else if(buscado>vet[meio]){
			inicio=meio+1;
			temp=vet[meio];
		}else if(buscado<vet[meio]){
			fim=meio-1;
			temp=vet[meio];
		}
		niteracoes++;
	}while(buscado!=temp);
	//printf("Numero de iteracoes %ld busca binaria\n",niteracoes);
	return meio+1;
}
int buscaSequencial(long buscado, long *vet){
	int i=0,temp;
	do{
		if(vet[i]==buscado){
			temp = vet [i];
		}
		i++;
	}while(buscado!=temp);
	//printf("Numero de iteracoes %ld busca sequencial\n",i);
	return temp;
}

int main(){
	long vet[MAX],i,retorno1,retorno2;
	double somams = 0,somams2 = 0;
	for(i=0;i<MAX;i++){
		vet[i]=i+1;
	}
	for(i=0;i<200;i++){
		long buscado = rand() % MAX +1;
		if(buscado<=MAX){
			clock_t Ticks[2], Ticks2[2];
			Ticks[0] = clock();
			retorno1 = buscaBinaria(buscado,vet,MAX);
			Ticks[1] = clock();
			Ticks2[0] = clock();
			retorno2 = buscaSequencial(buscado,vet);
			Ticks2[1] = clock();
			//printf("%ld\n",retorno1);
			//printf("%ld\n",retorno2);
			double Tempo = (Ticks[1] - Ticks[0]) * 1000 / (double) CLOCKS_PER_SEC;
			double Tempo2 = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
			somams = somams + Tempo;
			somams2 = somams2 + Tempo2;
			printf("%d ms\n",retorno1);
		}
	}
	printf("Tempo medio busca binaria %0.20lf ms\n",somams/200);
	printf("Tempo medio busca sequencial %0.20lf ms\n",somams2/200);
}
