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

	srand(time(0)); 
	int num,k,l,vet[3],pos;
	vet[0] = -1;
	vet[1] = -1;
	vet[2] = -1;
	/*
	###### Pega vértices aleatórios ###### 
	######  Em k < 3 é selecionado  ###### 
	######   o tamanho da clique    ###### 
	*/
	for (k = 0; k < 3; k++){
		if (k == 0){
			vet[k] = (rand() % m);
			printf("\n%d ", vet[0]);
		} else {
			num = (rand() % m);
			printf("%d ", num);
			for (i = 0; i < 3; i++){
				if (vet[i] == num){	
					printf(" eh igual ");
					num = (rand() % m);	
					printf("\n novo num %d", num);
					i--;
				}
			}
			printf("\n num inserido %d\n", num);
			vet[k] = num;
		}
	}
	for (k = 0; k < 3; k++){
		printf("%d ", vet[k]);
	}


	for (i=0;i<3;i++){
		pos = vet[i];
		for(j=0;j<3;j++){
			if (pos == j){ } else {
				if (matriz[pos][j] == 0){
					return 0;
				}
			}
		}
	}
	
}