#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[]){

	int N, M;
	int P, Q;
	int i, j, k;		
	
	//printf("Digite o tamanho da 1.a matriz\n");
	scanf("%d %d", &N, &M);
	int** mat1 = (int**) malloc(N*sizeof(int*));
	
	for (i=0; i < N; i++){
		mat1[i] = realloc(mat1[i], M*sizeof(int));
		//printf("Quais os numeros da linha %d?\n",i);
		for (j=0; j < M; j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	
//	printf("Digite o tamanho da 2.a matriz\n");
	scanf("%d %d", &P, &Q);
	int** mat2 = (int**) malloc(P*sizeof(int*));
	
	for (i=0; i < P; i++){
		mat2[i] = realloc(mat2[i], Q*sizeof(int));
//		printf("Quais os numeros da linha %d?\n",i);
		for (j=0; j < Q; j++){
			scanf("%d", &mat2[i][j]);
//			printf("j: %d\n", j);
		}
	}

//	printf("Resposta: \n");
	int matResp[1000][1000]={0};

	for (i=0; i < N; i++){
		for (j=0; j < Q; j++){
			for(k=0; k < M; k++){
				matResp[i][j] = matResp[i][j] + (mat1[i][k]*mat2[k][j]);
			}
			printf("%d ", matResp[i][j]);
		}
	printf("\n");
	}

		return 0;
}
