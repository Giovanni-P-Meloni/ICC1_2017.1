#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    //float Res;
    double Vet[1000]={0};
    double entry[1000] = {0};
    double Somatorio;
    float coisa;
    int k;
    int n;
    int N;


    scanf("%d", &N);

    for(n=0; n <= N-1; n++){
    scanf("%lf", &entry[n]);

    }

    for(k=0; k <= N-1 ; k++){ // Os valores que serao printados na tela
        Somatorio=0;
         for(n=0; n <= N-1; n++){ //Calcular o Somatorio de Xn e a "coisa"

            coisa = (M_PI/N)*(n + 0.5)*k;
           // printf("%f\n", coisa);

            Somatorio = Somatorio + entry[n]*cos(coisa);

         }
        Vet[k] = Somatorio;
        printf("%lf\n", Vet[k]);
    }



























        return 0;
}
