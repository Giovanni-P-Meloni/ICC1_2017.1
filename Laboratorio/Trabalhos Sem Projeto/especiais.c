#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int Numero=1000;
	
	do{
		int Numerouno, Numerodos;	
		float Raiz;
		
		Numerouno = Numero/100;
		Numerodos = Numero%100; 
		Raiz = sqrt(Numero);

		if (Raiz == Numerouno + Numerodos){
			printf("%d\n", Numero);
		}
		Numero++;
	}while(Numero != 9999);


		return 0;
}
