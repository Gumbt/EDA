#include <stdlib.h>
#include <stdio.h>
int verificaPivo(int *mat,int l, int c,int i,int j){//c = coluna q ele esta, l= a partir dessa linha
	int pivo,x,y,z,aux;
	pivo=mat[l][c];
	for(x=l;x<i;x++){
		if(mat[x][c]>pivo){
			pivo=mat[x][c];
			linhaPivo=x;
		}
	}
	for(z=l;z<i;z++){
		aux = mat[z][c];
		mat[y][z]=mat[y+1][z]
	}


}
int main(){
	int i,j,x,y, pivo, linhaPivo, aux, cont;
	printf("Digite o numero de linhas e colunas da matriz A: ");
	scanf("%i %i",&i,&j);
	int mat[i][j], b[i][1];
	for(x=0;x<i;x++){
		printf("Preencha a linha %i: ",x+1);
		for(y=0;y<j;y++){
			scanf("%i",&mat[x][y]);
		}
	}
	printf("Digite os elementos da coluna da matriz b:\n");
	for(y=0;y<j;y++){
		scanf("%i",&b[y][1]);
	}
	
	
}
