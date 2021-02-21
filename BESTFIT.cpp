#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *alocaVetor(int N) {
	int *v;
	v = (int *) malloc(N*sizeof(int));
	if (v==NULL){
		printf("Erro ao alocar memoria\n");
		exit(-1);    // sai do programa
	}
	printf("Vetor alocado com sucesso\n");
	return v; 
}

void preencheAleatoriamente(int *v, int N) {
	srand(time(NULL));
	int i;
	printf("Inicializando o vetor\n");
	for(i=0; i<N; i++){
		v[i]=rand()%2;
	}
}

void printaVetor(int *v, int N){
	int i;
	printf("\n\n Valores no vetor: \n");
	for(i=0; i<N; i++){ 
	   printf("%d ", v[i]); 
	}
}

void limpaMemoria(int *v) {
	if (v!=NULL){
		free(v);
	}
	printf("\nMemoria liberada \n");
}

int calculaBestFit(int *v, int n, int tamMemoria){
	int espaco=0;
	for(int i=0; i<n;i++){
		if(v[i]==0){
			espaco=0;
			for(v[i]; v[i]==0;i++){
				espaco++;
			}
		}
		if(espaco==tamMemoria){
			printf("Tamanho de memoria encontrado: %d\n",espaco);
			return i - (espaco);
		}	
	}
	return -1;
} 

int bestFit(int *v, int n, int tamMemoria){
	int indice;
	for(tamMemoria; tamMemoria<n ;tamMemoria++){
		indice = calculaBestFit(v,n,tamMemoria);
		if(indice!=-1){
			return indice;
		}
	}
//	printf("nao existem espacos na memoria com tamanho %d", tamMemoria);
	return -1;
}

int main() {
	int *x;
	int tam;
	int indice;
	int tamanhoMemoria;
	printf("Qual tamanho do vetor? ");
	scanf("%d", &tam);
	x= alocaVetor(tam);
	preencheAleatoriamente(x, tam);
	printaVetor(x, tam);
	printf("\nDigite o tamanho de memoria que quer encontrar  ");
	scanf("%d", &tamanhoMemoria);
	indice = bestFit(x, tam, tamanhoMemoria);
	if(indice!=-1){
		printf("Best_fit: Esta memoria comeca no indice %d do vetor", indice);
	}else{
		printf("\nImpossivel localizar este tamanho de memoria");
	}
	limpaMemoria(x);
	return 0;
}