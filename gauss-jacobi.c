#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int i,j,y,z,w, cont=0;
  bool quadrada=false;
  do{
    printf("Digite o numero de linhas e colunas da matriz A: ");
    scanf("%i %i",&i,&j);
    if(i==j){
      quadrada=true;
    }
    else{
      printf("Matriz nao quadrada, tente novamente\n");
      quadrada=false;
    }
  }while(quadrada==false);

  float x[i][2], a[i][j], b[i][1], temp[i][1], max, aux, erro=0;
	for(z=0;z<i;z++){
		printf("Preencha a linha %i: ",z+1);
		for(y=0;y<j;y++){
			scanf("%f",&a[z][y]);
		}
	}

	printf("Digite os elementos da coluna da matriz b: ");
	for(y=0;y<j;y++){
		scanf("%f",&b[y][0]);
	}

  for(y=0;y<i;y++){
    x[y][0]=b[y][0]/a[y][y];
    x[y][1]=0;
  }


  printf("Sua matriz do tipo A|b:\n");
  for(z=0;z<i;z++){
    printf("|");
    for(y=0;y<j;y++){
      printf("%9.5f ",a[z][y]);
    }
    printf(": %9.5f  |\n",b[z][0]);
  }

  printf("Digite o erro desejado: ");
  scanf("%f",&erro);

  bool parar=false;
  do{
    for(y=0;y<i;y++){
      aux=0;
      for(z=0;z<j;z++){
        if(y!=z){
          aux=aux-(a[y][z]*x[z][0]);
        }
      }
      x[y][1]=(1/a[y][y])*(b[y][0]+aux);
    }

    max=0;
    for(y=0;y<i;y++){
      temp[y][0]=fabs((x[y][1])-(x[y][0]));
      if(temp[y][0]>max){
        max=temp[y][0];
      }
    }
    if(max<=erro){
      parar=true;
    }
    //atualizando a variavel x para proxima iteração:
    for(y=0;y<i;y++){
      x[y][0]=x[y][1];
    }
    cont++;
  }while(parar!=true);
  printf("X com %i iteracoes:\n",cont);

  for(y=0;y<i;y++){
    printf("x%i: %f\n",y,x[y][1]);
  }
  return 0;
}
