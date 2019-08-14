#include <stdio.h>
#include <stdlib.h>
int main(){
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
		return 0;
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
	
	do{
		printf("\n\nDigite o tamanho K da clique que deseja encontrar: ");
		scanf("%d", &k);
	
		if(k>m){
			printf("Tamanho de clique maior que a clique maximal possivel.");
		}else if(k==m){
			printf("Tamanho da clique nao pode ser igual ao numero de vertices (deve ser um subgrafo).");
		}else if(k<1){
			printf("Tamanho da clique nao pode ser menor que 0");
		}
	}while(k>=m || k<1);	
	int vet[k],achou2 = 0,q;
	
	

	system("cls");
	int codigo, v;
	do{
		achou=0;
		conta=0;
		printf("1 - Tentar clique\n");
		printf("1 - Tentar 100\n");
		printf("Informe um numero: ");
		scanf("%d", &codigo);
		switch (codigo){
			/* caso 1 */
			case 1 : 
				while(conta < k) {
					int num = (rand() % m - 1) + 1;
					int achou = 0;
					for (i = 0; i < k; i++) {
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
				for (i = 0; i < k; i++){
					printf("%d ", vet[i]);
				}
				if(k==1){
					printf("\nEsse vertice forma uma clique!");
				}else if(k==2){
					if(matriz[vet[0]][vet[1]]==1)printf("\nEsses vertices formam uma clique!");
					else printf("\nEsses vertices nao formam uma clique!");
				}else{
					for(i=0;i<k;i++){
						for(j=0;j<k;j++){
							if(matriz[vet[i]][vet[j]] == 1 && vet[i]!=vet[j])v=1;
							else if (matriz[vet[i]][vet[j]] == 0 && vet[i]!=vet[j]){
								v=0;
								break;
							}
						}
					}
					if(v==1)printf("\nEsses vertices formam uma clique!\n\n");
					else printf("\nEsses vertices nao formam uma clique\n\n");
				}	
			break;
			/* fim caso 1 */
			
			/* CASO DOOOOOOOOOOOOOIS */
			case 2:
				conta=0;
				for (q = 0; q < 10; q++){
					while(conta < k) {
						int num = (rand() % m - 1) + 1;
						int achou = 0;
						for (i = 0; i < k; i++) {
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
					for (i = 0; i < k; i++){
						printf("%d ", vet[i]);
					}
					if(k==1){
						achou2 = 1;
					}else if(k==2){
						if(matriz[vet[0]][vet[1]]==1){
							achou2 = 1;
						}
					}else{
						for(i=0;i<k;i++){
							for(j=0;j<k;j++){
								if(matriz[vet[i]][vet[j]] == 1 && vet[i]!=vet[j])v=1;
								else if (matriz[vet[i]][vet[j]] == 0 && vet[i]!=vet[j]){
									v=0;
									break;
								}
							}
						}
						if(v==1){
							achou2 = 1;
						}
					}
					if (achou2){
						printf("\nEsses vertices formam uma clique!");
						break;
					}
				}
			break;	
			/* fim caso 2 */				
		}		
	} while (codigo != 6);
	
	
}
