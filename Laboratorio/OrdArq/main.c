#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
    false,
    true,
} bool;

typedef struct {
	char CPF[16];
	char Nome[200];
	int idade;
} pessoa;

//Funcao que le o arquivo, passando as informacoes para a struct, e retorna quantas structs foram alocadas.
int LerArq(pessoa **p, char* filename, int i){
    FILE* fp = fopen(filename, "r");
	do{
	*p = realloc(*p, sizeof(pessoa)*(i+1));
	fscanf(fp, "%s ", (*p)[i].CPF);
	fscanf(fp, "%[^\n] ", (*p)[i].Nome);
	fscanf(fp, "%d ", &(*p)[i].idade);
	i++;
	}while(!feof(fp));
    fclose(fp);
    return i;
}

int main (){
	char filename1[30];
	char filename2[30];
	int i=0;
	pessoa *p=NULL;
	bool Ver;

	scanf("%s %s", filename1, filename2);
	i = LerArq(&p, filename1, i);
    i = LerArq(&p, filename2, i); //i eh o numero de structs que existem.
    do{
        Ver = false;
        for (int j=0; j<i-1; j++){
            if (strcmp(p[j].CPF, p[j+1].CPF)>0){
                pessoa temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                Ver=true;
            }
        }
    } while(Ver);

    for (int j=0; j<i; j++){
        printf("%s\n%s\n%d\n", p[j].CPF, p[j].Nome, p[j].idade);
    }

	return 0;
}
