/*  Programa que manipula uma dada imagem (mm binário ou ASCII) dependendo da operação selecionada pelo usuario.

    Giovanni P. Meloni, ICMC 2017.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Definindo uma variavel booleana
typedef enum {
    false,
    true
} bool;
//Definindo uma estrutura com as "partes" da imagem
typedef struct {
    int XDIM, YDIM;
    int max, min;
    bool isAsc; // tipo da imagem
    unsigned char **image;
} Imagem;
/*Funcao que le o nome do arquivo e aloca numa string dinamicamente*/
void NomeDoArq(char** fileptr){
	char c;
	int count=0;

	do {
	c = fgetc(stdin);
	*fileptr = realloc(*fileptr, sizeof(char)*(count+1));
	(*fileptr)[count] = c;
	count++;
	} while (c != '\n');

	(*fileptr)[count-1] = '\0';
}
/*Funcao que altera a Imagem conforme a operacao de Log*/
void FuncLog(Imagem* parte){
        //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int PixelMax = parte->max;
    double c = 255/log(1+PixelMax);
    int y = (*parte).YDIM; // facilita se eu passar "parte.YDIM" para uma variavel.
    int x = (*parte).XDIM;

    // Esse for ira pegar o pixel da imagem original e mudar para um novo valor, depois jogara esse valor n
    for(int i = 0; i < y; i++){
        for(int j=0; j < x; j++){
            int pixel = parte->image[i][j]; // Apenas jogando o valor numa variavel aux, para fica mais legivel
            pixel = c*log(1+pixel);
            (*parte).image[i][j] = pixel;
        }
    }
}
/*Funcao que altera a Imagem conforme a operacao de "Contrast Stretching"*/
void FuncStretching(Imagem* parte){ //Problema??
        //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int PixelMax = parte->max;
    int PixelMin = parte->min;
    int y = (*parte).YDIM;
    int x = (*parte).XDIM;

    for(int i = 0; i < y; i++){
        for(int j=0; j < x; j++){
            int pixel = parte->image[i][j];
            pixel = (pixel-PixelMin)/(PixelMax-PixelMin)*255;
            (*parte).image[i][j] = pixel;
        }
    }
}
/* Funcao que percorre a matriz para encontrar o pixel de menor valor.*/
void Min(Imagem* parte){
    //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int y = (*parte).YDIM;
    int x = (*parte).XDIM;
    unsigned char **p = parte->image;
    int min = (int)p[0][0];

    for(int i = 0; i < y; i++){
            for(int j=1; j < x; j++){
                    if ((int)p[i][j] < min) min = (int)p[i][j];
            }
    }
    (*parte).min = min;
}
/* Funcao que mostra imagem na saida padrao (stdout)*/
void ShowImage(Imagem* parte){
    //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int MaxVal = parte->max;
    int y = parte->YDIM;
    int x = parte->XDIM;
    bool isAsc = parte->isAsc;
    unsigned char **p = parte->image;

        // Imprimindo o cabecalho
    if(isAsc) printf("P2\n");
    else printf("P5\n");
    printf("# CREATOR: Image Generator SCC-221 - ICC I\n"); // comentario
    printf("%d %d\n", x, y); // dimensoes da imagem
    printf("%d\n", MaxVal);// pixel de maior valor
        // Imprindo a imagem
    for (int i=0; i < y; i++){
        for (int j=0; j < x; j++){
            printf("%d\n", p[i][j]);
        }
        //printf("\n");
    }
}
/* Funcao que abre o arquivo de imagem e passa as informacoes para a struct*/
void LoadImage(char* filename, Imagem* parte){ // Problemas <<
    FILE *ImgPtr;
    int tam1;
    char headertype[50];
    char comentario[50]; // comentario da imagem que devo ignorar


    ImgPtr = fopen(filename, "r");
        // Primeira parte do cabecalho me diz COMO a imagem esta armazenada, portanto, em headertype,
        // terei "P<n>".
    fgets(headertype, 50, ImgPtr); //Primeira linha sera composta por 'P', '<n>' e >>'\n'<<
    tam1 = strlen(headertype);
    headertype[tam1-1] = '\0';
        if(!strcmp(headertype, "P2")) (*parte).isAsc = true;
        else (*parte).isAsc = false;

        // Segunda parte do cabecalho consiste do comentario, que pode ser ignorado
    fgets(comentario, 50, ImgPtr);
    tam1 = strlen(comentario);
    comentario[tam1-1] = '\0';

        //Terceira parte do cabecalho me diz quais as DIMENSOES da matriz imagem
    fscanf(ImgPtr, "%d", &((*parte).XDIM));
    fscanf(ImgPtr, "%d", &((*parte).YDIM));
    int y = (*parte).YDIM; // facilita se eu passar "parte.YDIM" para uma variavel.
    int x = (*parte).XDIM; // Analogo a de cima

        //Quarta parte do cabecalho me diz qual o o valor do MAIOR pixel encontrado na imagem.
    fscanf(ImgPtr, "%d", &((*parte).max));
    fgetc(ImgPtr); // pegar o '\n'
    // PROBLEMA, o ponteiro nesse instante esta em um '\n', se for ASCII nao tem problema, mas se for binario o fread acaba pegando o '\n'.

        //Quinta parte. Possuindo as dimensoes da matriz, posso alocar espaco para ela na struct
        //enquanto aloco, ja ponho os respectivos valores dentro, mas antes preciso verificar
        //com qual tipo de arquivo estarei trabalhando
    if((*parte).isAsc){
        (*parte).image = (unsigned char**) malloc(y * sizeof(unsigned char*));
        for(int i = 0; i < y; i++){
            *((*parte).image + i)  = (unsigned char*) malloc(x * sizeof(unsigned char));
            for(int j=0; j < x; j++){
                fscanf(ImgPtr, "%d", (int*)&parte->image[i][j]);
            }
        }
    }
    else{
        parte->image = (unsigned char**) malloc(y * sizeof(unsigned char*));
        for(int i = 0; i < y; i++){
            *((*parte).image + i)  = (unsigned char*) malloc(x * sizeof(unsigned char));
            for(int j=0; j < x; j++){
                    fread(&parte->image[i][j], sizeof(unsigned char), (y*x), ImgPtr);
            }
        }
    }
    fclose(ImgPtr);
}
/*Funcao que libera a memoria Heap*/
void LiberaHeap(Imagem* parte){
        //Declarando variaveis para facilitar uso
    unsigned char*** p = &(*parte).image;
    int y = (*parte).YDIM;

    for (int i=0; i < y; i++){
        free( (*p)[i] );
        (*p)[i] = NULL;
    }
    free(*p);
    *p=NULL;
}

int main(){
        //Declarando variaveis
    int Operacao;
    char *filename = NULL;
    Imagem parte; // A imagem eh composta por diferentes partes, "parte" sera um ponteiro que aponta para uma delas.
    parte.image = NULL;

        // Primeira entrada e` a Operacao desejada pelo usuario
    scanf("%d", &Operacao);// Existem 3 possibilidades: Operacao == 1 -> FuncLog || Operacao == 2 -> FuncStretching || Operacao == 3 -> FuncBucket
    getchar(); // Pegar o '\n' no digitado.

        // Proxima entrada e` o nome do arquivo, portanto alocarei ele numa string.
    NomeDoArq(&filename);

        // Abrir a imagem.
    LoadImage(filename, &parte);

        // Achar o pixel de maior e de menor valor.
    Min(&parte);
/*DEBUGANDO <<<<<<< DELETAR
 printf("MaxVal: %d\nMinVal: %d\nOperacao: %d\nImagem Original:\n", parte.max, parte.min, Operacao);

   for (int i=0; i < parte.YDIM; i++){
        for (int j=0; j<parte.XDIM; j++){
            printf("%d ", parte.image[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");
*/

        // Manipular a imagem.
    if (Operacao == 1) FuncLog(&parte);
    else if (Operacao == 2) FuncStretching(&parte);
//  else if (Operacao == 3) FuncBucket();
        //Mandar a imagem para stdout
        ShowImage(&parte);

/* DEBUGANDO <<<<<<<<<<<<< DELETAR
    printf("Nova imagem: \n");
    for (int i=0; i < parte.YDIM; i++){
            for (int j=0; j<parte.XDIM; j++){
                printf("%d ", parte.image[i][j]);

            }
            printf("\n");
        }
*/
        // Liberando a memoria
    LiberaHeap(&parte);
    free(filename);
    return 0;
}
