#include <stdio.h>
#include <stdlib.h>

int main(){
    int N; // Number of values to be compared
    int n;
    int num1;
    int num2;
    int Maior;
    int Menor;
    int novo;
    // ------------------------------------------ //

    scanf("%d", &N);
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 >= num2){
        Maior = num1;
        Menor = num2;
    }
    else {
        Maior = num2;
        Menor = num1;
    }
    for (n = 2; n < N; n++){
        scanf("%d", &novo);

        if(novo >= Maior){
            Maior = novo;
        }
        else {
            if(novo < Menor) {
                Menor = novo;
            }
        }
    }
    printf("max: %d\n", Maior);
    printf("min: %d", Menor);


    return 0;
}
