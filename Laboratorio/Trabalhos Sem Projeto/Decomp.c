#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]){

	int a;
	int eh_primo;
	int n;
	int d;
	int count[100] = {0};
	int i=0;

	scanf("%d", &a);
	int check = sqrt(a);
	int Res = a;

	for (n=2; (n <= a); n++){
		eh_primo = 1;
		for(d = 2; (d <= check) && (eh_primo == 1) ; d++){
			if ((n%d == 0) && (d != n)){
				eh_primo=0;
			}
		}
		if (eh_primo == 1){
			while ((Res%n == 0) && (Res != 0)){
			count[i]++;
			Res = Res/n;
		//	printf("%d\n", count[i]);
		//	printf("%d\n", Res);

			}
			if (count[i] != 0){
                printf("%d %d\n", n, count[i]);
                i++;
			}
		}

	//printf("%d %d\n", n, count[i-1]);

	}



























		  return 0;
}

