#include <stdio.h>
#include <stdlib.h>

int main(){

	int stvalue, ndvalue, eh_igual, manipu;
	int* vetstvalue=NULL;
	int* vetndvalue=NULL;
	int j, i=0;
	int tam1=0;
	int tam2=0;
	

	scanf("%d", &stvalue);
	manipu = stvalue;
	while(manipu > 0){
		vetstvalue = realloc(vetstvalue, (i+1)*sizeof(int));
		vetstvalue[i] = manipu%10;
		manipu = manipu/10;
		i++;
	}// tenho o primeiro valor em um vetor de [0] até [--i], MAS de tras pra frente. (e.g: 35 -> [0]5 [1]3)
//	vetstvalue[i] = '\0';
	tam1 = --i;

	i=0; // Resetando o i para usa-lo novamente.

	scanf("%d", &ndvalue);
	manipu = ndvalue;
	while(manipu > 0){
		vetndvalue = realloc(vetndvalue, (i+1)*sizeof(int));
		vetndvalue[i] = manipu%10;
		manipu = manipu/10;
		i++;
	}// Tenho o segundo valor em um vetor de [0] até [--i], MAS de tras pra frente. (e.g: 354 -> [0]4 [1]5 [2]3)
//	vetndvalue[i] = '\0';
	tam2 = --i;
	manipu = 1;//manipu passara a ser uma variavel de verificação.
		//Farei a comparacao dos valores com o vetor de cada numero. Lembrando que esta de tras pra frente

	if (tam2 > tam1){
		for(i=tam2; i>=0 && manipu!=0; tam2--){
			i=tam2;
			if(vetndvalue[i] == vetstvalue[tam1]){
				eh_igual = 1;
				for(j=(tam1-1); eh_igual && j>=0; j--){
					i--;
					if(vetndvalue[i] == vetstvalue[j]) eh_igual=1;
					else eh_igual = 0;
				}
			if (j < 0) manipu = 1;	// Se j for <= 0 quer dizer que todos os valores de stvalue "cabem" no ndvalue. Portanto um é segmento do outro.
			}
		}
		if(eh_igual) printf("%d %d SIM\n", stvalue, ndvalue);
		else printf("%d %d NAO\n", stvalue, ndvalue);	
	}
	else{
		for(i=tam1; i>=0 && manipu!=0; tam1--){
			i=tam1;
			if(vetstvalue[i] == vetndvalue[tam2]){
				eh_igual = 1;
				for(j=(tam2-1); eh_igual && j>=0; j--){
					i--;
					if(vetstvalue[i] == vetndvalue[j]) eh_igual=1;
					else eh_igual = 0;
				}
			if (j < 0) manipu = 1;	// Se j for <= 0 quer dizer que todos os valores de stvalue "cabem" no ndvalue. Portanto um é segmento do outro.
			}
		}
		if(eh_igual) printf("%d %d SIM\n", ndvalue, stvalue);
		else printf("%d %d NAO\n", ndvalue, stvalue);
	}
	free(vetstvalue);
	free(vetndvalue);
		return 0;
}
