#include <stdio.h>
#include <stdlib.h>

int main(){


    int N; //Numero de Trabalhos Realizados
    float T[1000] = {0}; // Armazenar a Nota de cada Trabalho
    float MAH; //Media Harmonica
    float Denom = 0;
    int i;


    scanf("%d", &N);

    for (i=0 ; i <= N-1 ; i++){
        scanf("%f", &T[i]);
        Denom = Denom + 1/(T[i]+1);
    }

    MAH = N/Denom - 1;
    printf("%.2f\n", MAH);




















                return 0;
}
