#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int Turma;
	int k;
	int cM=0; // Um contador que ira contar o numero de mulheres
	int cH=0; // UM contador que ira contar o numero de homens
	int bit;


	 scanf("%d", &k);	// numero da panelinha que Pablo deseja estudar.
	 scanf("%d", &Turma);

	//Caso o usuário digite 0, ele esta querendo saber qual a primeira panelinha. Ou seja, a saída deve ser a sequencia invertida de 1's e 0's da primeira linha
	//da variavel Turma
	//
	if ( (k >= 0) && (k <= 3) && (Turma >= 0) && (Turma <= 1000000000)){
	   Turma = Turma >> 8*k;
		printf("%d",bit = Turma & 1); // nessa conta, bit sempre permanecera entre 0 e 1
	         cM = cM + bit; // mulher é representado como o bit "1". Dessa maneira se bit = 1, somara no contador mulher, ou seja quer dizer que existe uma mulher naquela panela.
			       // Em contrapartida homem é representado como bit "0". Dessa maneira se bit = 0 ele ainda somara no contador mulher, porém somara 0, ou seja não contabilizar

		printf("%d", bit = (Turma & 2)/2);
 	         cM = cM + bit;

		printf("%d", bit = (Turma & 4)/4);
	         cM = cM + bit;

		printf("%d", bit = (Turma & 8)/8);
	         cM = cM + bit;

		printf("%d", bit = (Turma & 16)/16);
	         cM = cM + bit;

		printf("%d", bit = (Turma & 32)/32);
	         cM = cM + bit;

		printf("%d", bit = (Turma & 64)/64);
	         cM = cM + bit;

		printf("%d\n", bit = (Turma & 128)/128);
	         cM = cM + bit;

	 printf("%d\n", cH = 8 - cM); // numa panelinha (um byte), existem 8 pessoas(8 bits) . Subtraindo as mulheres (cM) de 8, teremos o numero de homens (cH)
	 printf("%d\n", cM);

       }
       else {
		printf("Invalid input");
       }
}
