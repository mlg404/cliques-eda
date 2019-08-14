#include <stdio.h>
#include <stdlib.h>
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
	int num,k,l,achou,conta,pos;
	

	/*
	###### Pega vértices aleatórios ###### 
	######  Em conta < 3 é selecionado  ###### 
	######   o tamanho da clique   ###### 
	*/
/*
	while(conta < 3) {
		int num = (rand() % m);
		int achou = 0;

		for (i = 0; i < 3; i++) {
			if(vet[i] ==num) {
				achou = 1;
				break;
			}
		}

		if(!achou) {
			vet[conta] = num;
			conta++;
		}
	}
	for (k = 0; k < 3; k++){
		printf("%d ", vet[k]);
	}


*/

system("cls");
	int codigo, vet[50], v;
	do{
		achou=0;
		conta=0;
		printf("1 - Tentar clique 3\n");
		printf("2 - Tentar 10\n");
		printf("3 - Tentar 100\n");
		printf("4 - Tentar 1000\n");
		printf("5 - Usar magia negra (1000000 vezes)\n");
		printf("6 - Assumir que não tem clique e desistir\n");
		printf("Informe um numero: ");
		scanf("%d", &codigo);
		switch (codigo){
			case 1 : 
				while(conta < 3) {
					int num = (rand() % m);
					int achou = 0;
					for (i = 0; i < 3; i++) {
						if(vet[i] ==num) {
							achou = 1;
							break;
						}
					}

					if(!achou) {
						vet[conta] = num;
						conta++;
					}
				}
				printf("\nVertices escolhidos: ");
				for (k = 0; k < 3; k++){
					printf("%d ", vet[k]);
				}
				for (i = 0; i < 3; i++){
					for (j = 0; j < 3; j++){
						if(matriz[vet[i]][vet[j]] == 1 && vet[i]!=vet[j]){
							v=1;
						}	
                        else if (matriz[vet[i]][vet[j]] == 0 && vet[i]!=vet[j]){
                            v=0;
                            break;
                        }
                    }
                }
                if(v==1){
					printf("\nEsses vertices formam uma clique!\n\n");
				} else {
					printf("\nEsses vertices nao formam uma clique\n\n");
				}
				
					// if (matriz[vet[0]][vet[1]] == 1 && matriz[vet[0]][vet[2]] == 1 && matriz[vet[1]][vet[2]] == 1){
					// 	printf("\nEsses vertices formam uma clique!\n\n");
					// } else{
					// 	printf("\nEsses vertices nao formam uma clique\n\n");
					// }
				
			break;
		}		
	} while (codigo != 6);
	
	
	// for (i=0;i<3;i++){
	// 	pos = vet[i];
	// 	for(j=0;j<3;j++){
	// 		if (pos == j){ } else {
	// 			if (matriz[pos][j] == 0){
					
	// 			}
	// 		}
	// 	}
	// }
	
}