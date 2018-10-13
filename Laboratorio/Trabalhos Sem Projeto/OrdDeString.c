#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	int N, i; // NUmero de strings a serem lidas.
	
	scanf("%d", &N);
		
	char String[N][10000];
	for (i=0; i<N; i++){
		scanf("%s", String[i]);
	}
	
	char *temp, *Maior;
	int tam, j, k; 
	temp = (char*) malloc(10000);
	Maior = (char*) malloc(10000);
	tam = --i;
	while (tam > 0){
//		for (i=0; i<N; i++){
//		printf("%s\n", String[i]);
//	}	
//		printf("\n");
		strcpy(temp, String[tam]);
//		printf("temporaria: %s\n", temp);
		strcpy(Maior, String[0]);
		for (j=0; j<= tam; j++){
			if(strcmp(String[j], Maior) >= 0){
				strcpy(Maior, String[j]);
				k=j;
			}
		} 
//		printf("tamanho: %d\n", tam);
//		printf("Maior: %s\n", Maior);
		strcpy(String[tam], Maior);
		strcpy(String[k], temp);
		tam--;
//	printf("\n\n\n");
	}

	for (i=0; i<N; i++){
		printf("%s\n", String[i]);
	}

}
