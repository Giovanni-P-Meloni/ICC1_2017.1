#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char Nome[4];
	int Ouro, Prata, Bronze;
} P;


int main(){
	
	int n, e;
	scanf("%d", &n);
	getchar();
	P pais[n];
	
	int i;
	for (i=0; i<n; i++){
		scanf("%s", pais[i].Nome);
		scanf("%d", &pais[i].Ouro);
		scanf("%d", &pais[i].Prata);
		scanf("%d", &pais[i].Bronze);
	}

	do{
		e = 0;
		for (i = 0; i<n-1; i++){
			if (pais[i].Ouro < pais[i+1].Ouro){
			P temp = pais[i];
			pais[i] = pais[i+1];
			pais[i+1] = temp;
			e = 1;				
			}
			else if(pais[i].Ouro == pais[i+1].Ouro){
				if (pais[i].Prata < pais[i+1].Prata){
					P temp = pais[i];
					pais[i] = pais[i+1];
					pais[i+1] = temp;
					e = 1;

				}
				else if(pais[i].Prata == pais[i+1].Prata){
					if(pais[i].Bronze < pais[i+1].Bronze){
						P temp = pais[i];
						pais[i] = pais[i+1];
						pais[i+1] = temp;
						e = 1;
					}
				}
			}
		}
	}while(e);

	for (i=0; i<n; i++){
		printf("%s %d %d %d\n", pais[i].Nome, pais[i].Ouro, pais[i].Prata, pais[i].Bronze);

	}
		
}

	
