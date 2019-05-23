#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//exercicio 3:
void requisitos (int *software, int n, int s){
	//nao tem pre requsito de instalacao:
	if(software[s]==-1){
		printf(" %d",s);
		return;
	}
	requisitos(software, n, software[s]);
	printf(" %d",s);
}
//exercicio 4:
int compara( int *a, int n, int *b, int m){
	int i;
	if(n>m)
		return +1;
	if(m>n)
		return -1;
	//if(m==n)
	for (i=0; i<n; i++){
		if(a[i] > b[i])
			return +1;
		else if(b[i] > a[i])
			return -1;
	}
	return 0;
}
int main (){
	//começo exercicio 3 v
	int soft[6] = {1,4,0,1,-1,4};
	requisitos(soft, 6, 2);
	puts("");
	//fim exercicio 3 ^
	//começo eercicio 4 v
	int m,n;
	printf("\nDigite o numero de digitos de n e m: ");
	scanf("%d %d", &n, &m);
	printf("\nDigite o primeiro numero grande:");
	int na[n], i;
	for(i=0; i<n; i++)
		scanf("%d",&na[i]);
	printf("\nDigite o segundo numero grande:");
	int nb[m];
	for(i=0; i<m; i++)
		scanf("%d",&nb[i]);
	int resposta = compara(na,n,nb,m);
	printf("\n+1 = a eh maior\n-1 = b eh maior\nResposta: %d", resposta);
	//fim exercico 4 ^
	return 0;
}
