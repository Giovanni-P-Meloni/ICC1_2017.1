#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//Declarando
	double rd = 0;
	double i ;
	double sen;
	double ultimo ;
	double n = 2;
	//Entrada

	scanf("%lf", &rd);
	ultimo = rd;
	sen = rd;

	//Processamento


	for (i=1; i <= 4; i = i + 1){ // "for" para ficar variando o sinal
       // printf("%lf\n", ultimo);
        ultimo = (ultimo * pow(rd, 2))/(n * (n+1));
     //   printf("%lf\n", ultimo);
        sen = sen + ultimo * pow(-1,i);
        //printf("%lf\n\n", sen);
        n = n + 2;

   	}
	printf("%.6lf\n", sen);

    return 0;
}
