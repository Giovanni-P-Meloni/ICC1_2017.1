#include <stdio.h>
#include <stdlib.h>

void VetorCrescente(char* VET, int tam){

	int  i, k;
	int temp, Maior;
	
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


int main(){
	char* VetCar=NULL;
	int k;
	int i=0;
	char c;
	
	do {
		c = fgetc(stdin);
		if (c != '\n'){
			VetCar = realloc(VetCar, sizeof(char)*(i+1));
			VetCar[i] = c;
			i++;	
		}
	} while (c != 'x');

	VetCar[i] = '\0';
	i--;
	VetorCrescente(VetCar, i);
	int* printar;
	int max;

	printar = (int*)VetCar;

	max = i/4;
	
	for (k=0; k<=max; k++){
		printf("%d\n", printar[k]);
	}

	return 0;
}
