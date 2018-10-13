#include <stdio.h>
#include <stdlib.h>




void VetorCrescente(float* VET, int tam){

	int  i, k;
	float temp, Maior;
	
	while(tam > 0){
		temp = VET[tam]; 
//		printf("temp: %f\n", temp);
		Maior = VET[0];
//		printf("Primeiro Maior: %f\n", Maior);
		for(i=0; i <= tam; i++){ // Preciso do maior valor
			if(VET[i] >= Maior){
				Maior = VET[i];
				k=i;
//					printf("k: %d\n", k);
			}
		}
//	printf("tamanho: %d\n", tam);	
	VET[tam] = Maior;
	VET[k] = temp;
//	printf("Vet[tam]: %f\n", VET[tam]);
//	printf("Vet[k]: %f\n", VET[k]);
//	printf("\n\n");
		tam--;
	}

}	

int main(int argc, char* argv[]){

	int N, i, j, k;
	float* Vet=NULL;
	int* count=NULL;	
	scanf("%d", &N);//Alocando o valor dinamicamente num vetor
	for (i=0; i < N; i++){
		Vet = realloc(Vet, (i+1)*sizeof(float) );
		scanf("%f", (Vet+i));


	}
	i--;
	VetorCrescente (Vet, i);	

	for (j=0; j <= i; j++){ //Ler os numeors e contar suas repetições
		count = realloc(count, (j+1)*sizeof(int) );
		count[j] = 1;
		for(k=j+1; k!=0 && k<=i; k++){
			if(Vet[j] == Vet[k]){			
			count[j]++;
			Vet[k] =0;
			}
		}
		if(Vet[j]!= 0) printf("%.1f %d\n", Vet[j], count[j]);
	}
	j--;
	free(Vet);
//	printf("\n\n");
	return 0;
}
