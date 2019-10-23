#include <stdio.h>

int main(void) {
	int n,i,m,cont;
	int v[10];

	for (i=0; i<10; i++) {
	    scanf("%d",&n);
	    v[i]=n;
	}

	scanf("%d",&m);

	for (i=0; i<10; i++) {
	    if(v[i]==m) cont++;
	}
	printf("Número de vezes %\n",cont);
	return 0;
}
