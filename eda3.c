#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encontraClique(int **matriz, int k, int m){
	int num,achou=0,conta=0,i,vet[k],j,v;
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
	printf("\nVertice(s) escolhido(s): ");
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
			if(v==0)break;
		}
		if(v==1)printf("\nEsses vertices formam uma clique!\n\n");
		else printf("\nEsses vertices nao formam uma clique\n\n");
	}	
}

int main(){
	FILE *entrada;
	int m,n,i,j,aux, **matriz;

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
	matriz= (int**)malloc(sizeof(int*)*m);
   
    for(i=0;i<m;i++){
		matriz[i]=(int*)malloc(sizeof(int)*m);
    }

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

	srand((unsigned)time(NULL)); 
	int k;
	
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
	
	

	system("cls");
	int codigo, v;
	do{
		printf("\n1 - Tentar clique\n");
		printf("2 - Fechar\n");
		printf("Informe um numero: ");
		scanf("%d", &codigo);
		switch (codigo){
			/* caso 1 */
			case 1 : 
				encontraClique(matriz, k, m);
			break;
			/* fim caso 1 */				
		}		
	} while (codigo != 2);
	
	
}
