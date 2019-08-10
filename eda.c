#include <stdio.h>
void main(){
	FILE *entrada;
	int m,n,i,j;

	// ###### Recebe o arquivo com o grafo ###### 
	entrada = fopen("Grafo.txt","r");

	/* 
	###### Verifica se ele consegue ler o arquivo ###### 
	######     e se o arquivo não está vazio      ######
	*/
	if (entrada == NULL){
		printf("Arquivo vazio ou nao encontrado");
	}

	// ###### Armazena os valores de vértices e arestas em 'm' e 'n' ###### 
	fscanf(entrada, "%d %d", &m, &n);
	int matriz[m][m], aux[m];

	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++)		{
			matriz[i][j]
		}
	}

	// ###### Fecha o arquivo e exibe a matriz ###### 
	fclose(entrada);
	for (i=0; i<m; i++){
		for (j=0; j<m; j++){
			printf("%d\t",matriz[i][j]);
		}	
		printf("\n");
	}

	srand(time(0)); 
	int num,k;
	for (k = 0; k < 20; k++){
		num = (rand() % m);
		printf("%d - ", num); 
	}	
}