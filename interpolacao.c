#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int n,i,j;
  printf("Digite o grau do polinomio: ");
  scanf("%i",&n);
  float x[n+1],y[n+1], mat[n+1][n+1];
  printf("Digite os ponto x,y separados por espaco\n");
  for(i=0;i<n+1;i++){
    printf("Digite o %i par de pontos: ",i+1);
    scanf("%f",&x[i]);
    scanf("%f",&y[i]);
  }
  for(i=0;i<n+1;i++){
  	for(j=0;j<n+1;j++){
  		if(j==0){
  			mat[i][j]=1;
		    }
		  else{
			  mat[i][j]=(pow(x[i],j));
		  }
	  }
  }

  int z,u,w;
  float result[n+1],b[n+1];
  for(i=0;i<n+1;i++){
    b[i]=y[i];
  }
  float k, temp, aux;
	for(w=0;w<n+1;w++){
		for(z=w;z<n+1;z++){
			k=mat[z+1][w]/mat[w][w];
			if(z+1<n+1){
				for(u=0;u<n+1;u++){
        mat[z+1][u]=(mat[z+1][u])-(k*mat[w][u]);
				}
				b[z+1]=(b[z+1])-(k*b[w]);
			}
		}
	}
	for(w=n+1-1;w>=0;w--){
		temp=0;
		for(u=n-1;u>=w;u--){
			temp = temp - mat[w][u+1]*result[u+1];
		}
		temp = temp + b[w];
		result[w]=temp/mat[w][w];
	}
  printf("\n");
  for(i=0;i<n+1;i++){
    printf("a%i = %f\n",i,result[i]);
  }
  printf("\n");
  for(i=0;i<n+1;i++){
    if(i==0){
      printf("f(x) = %.5f",result[i]);
    }
    else{
      if(i==n){
        if(result[i]>=0){
          printf(" +%.5fx^%i",result[i],i);
        }
        else{
          printf(" %.5fx^%i",result[i],i);
        }
      }
      else{
        if(result[i]>=0){
          printf(" +%.5fx^%i",result[i],i);
        }
        else{
          printf( "%.5fx^%i",result[i],i);
        }
      }
    }
  }

  return 0;
}
