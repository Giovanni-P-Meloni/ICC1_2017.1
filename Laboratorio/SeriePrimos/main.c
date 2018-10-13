#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    //Declaring
    int N;
    int n;
    int d;
    int eh_primo;
    int check;
    float Res;
    int i = 1;



    //Input
    scanf("%d", &N);
    check = sqrt(N);
    Res = 1.0/2.0;

    //Processing
    if (N == 1){
     Res = 0;
     printf("%.7f", Res);
    }
    else {
        for (n = 3; n <= N; n++){ // Going through all numbers until N
            eh_primo = 1;
            for (d = 2; (d <= check) && (eh_primo = 1) ; d++){ //Testing to see if the number is prime
                if (n%d == 0 && d != n) {
                    eh_primo = 0;
                }
            }
            if (eh_primo == 1){ // If the number is indeed prime, then Add to the Result
                Res = Res + (1/(float)n * pow(-1, i));
                i++;// Change the operator for the next Result (- to +, or + to -)
            }
        }
        printf("%.7f", Res);
    }
    return 0;
}
