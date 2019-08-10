#include <stdio.h>
void main(){
	FILE *entrada;
	int m,n,i,j,aux;

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
	int matriz[m][m];

	/*

	###### Preenche a matriz com o grafo ###### 
	######     do arquivo Grafo.txt      ###### 
	######    Lê-se linha por linha,     ###### 
	######     inteiro por inteiro       ###### 

	*/
	for (i = 0; i < m; i++){
        for (j = 0; j < m; j++){
            fscanf(entrada, "%d", &aux);
            if (i != j){
                matriz[i][j]= aux;
            } else {
                matriz[i][j] = 0;
            }
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

	// ###### Seleciona números aleatoriamente ###### 
	srand(time(0)); 
	int num,k,l,vet[3];
	// for (k = 0; k < m; k++){
	// 	num = (rand() % m);
	// 	printf("%d - ", num); 
	// }	

	for (k = 0; k < 3; k++){
		printf("k fora: %d\n",k);
		if (k == 0){
			vet[k] = (rand() % m);
		} else {
			num = (rand() % m);
			printf("\nnumero: %d\n",num);
			l = k;
			for (i = 0; i < l; i++){ //ARRUMAR ISSO, N TÁ PEGANDO
				if (vet[i] == num){
					k--;
				}
			}
			vet[k] = (rand() % m);
			printf("k dentro: %d\n",k);
		}
	}
	for (k = 0; k < 3; k++){
		printf("%d ", vet[k]);
	}
}