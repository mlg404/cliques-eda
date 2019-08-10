#include <stdio.h>
void main(){
    FILE *entrada;
	int m,n,i,j,aux;

	entrada = fopen("Grafo.txt","r");
    fscanf(entrada, "%d %d", &m, &n);
    int a[m][m];
    
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++){
            fscanf(entrada, "%d", &aux);
            if (i != j){
                a[i][j]= aux;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

}