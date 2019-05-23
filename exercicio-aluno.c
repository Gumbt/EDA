#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 3
typedef struct Disciplina {
	char sigla[3];
	char nome[50];
} Disciplina;

typedef struct Registro {
	float freq;
	float nota;
	int anosemestre;
	struct Disciplina *materia;
} Registro;
typedef struct Alunos {
	int matricula;
	char *nome;
	struct Registro *aluno;
} Aluno;
Disciplina* criarDisciplina(char* sigla, char* nome){
	Disciplina *d = malloc( sizeof(Disciplina) );
	d->nome = malloc( strlen(nome) * sizeof(char) );
	d->sigla = malloc( strlen(sigla) * sizeof(char) );
	strcpy( d->nome, nome );
	strcpy( d->sigla, sigla );
	return d;
}
Registro* criarRegistro(Discipina *dis, int semestre, float freq, float nota){
	Registro *r = malloc( sizeof(Registro) );
	r->semestre = semestre;
	r->freq = freq;
	r->nota = nota;
	r->materia = dis;

	return r;
}
Aluno *criarAluno(int matricula, char *nome){
	Aluno *a = malloc( sizeof(Aluno) );
	a->matricula = matricula;
	a->nome = malloc( strlen(nome) * sizeof(char) );
	strcpy( a->nome, nome );

	return a;
}

void showHistorico(Aluno *aluno){
	printf("\n:::REGISTRO:::\n");
	printf("      Aluno: %s\n", aluno->nome);
	printf("     Matricula: %i\n", aluno->matricula);
	int i;
	for(i=0;i<3;i++){
		printf("Materia: %s - Nota: %f - Frequencia: %f%\n",aluno->aluno->nota,aluno->aluno->freq);
	}
}






int main(){
	// como representar pontos (x,y) usando vetores tradicionais
	//    * problema: separação / isolamento dos elementos 
	/*int x[MAX_N], y[MAX_N],i;
	printf("Digite as coordenadas de %d pontos:\n", MAX_N);
	for(i=0; i<MAX_N; i++)
		scanf("%d %d", &x[i], &y[i]);
*/
	// representar registros de clientes
	int nros[MAX_N],i;
	char nomes[MAX_N][50],nomedotop[50];
	char enderecos[MAX_N][50];
	int telefones[MAX_N];
	Cliente *cli[MAX_N];
	for(i=0; i<MAX_N; i++){
		printf("Digite o nro do cliente #%d: ", i);
		scanf("%d", &nros[i]);
		getchar();
		printf("Digite o nome do cliente #%d: ", i);
		fgets( nomes[i] , 50 , stdin );

		printf("Digite o endereco do cliente #%d: ", i);
		fgets( enderecos[i] , 50 , stdin );
		printf("Digite o telefone do cliente #%d: ", i);
		scanf("%d", &telefones[i]);
		puts("");
		if(i==0)
			cli[i] = novoCliente(nros[i], nomes[i], enderecos[i], telefones[i], NULL);	
		else
			cli[i] = novoCliente(nros[i], nomes[i], enderecos[i], telefones[i], cli[i-1]);
	}
	for(i=0; i<MAX_N; i++){
		showCliente( cli[i] );
	}

}



