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
/*Funcao que le o nome do arquivo e aloca numa string (nope)dinamicamente. Run Codes nao aceitava a alocacao dinamica, portanto aloquei estaticamente.*/
void NomeDoArq(char* fileptr){
	fgets(fileptr, 50, stdin);
    int i = 0;
	while (fileptr[i] != '\0' && fileptr[i] != '\n') {
		i++;
	}
	fileptr[i] = '\0';
}
/*Funcao que altera a Imagem conforme a operacao de Log*/
void FuncLog(Imagem* parte){
        //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int PixelMax = parte->max;
    double c = 255/log(1+PixelMax);
    int y = (*parte).YDIM; // facilita se eu passar "parte.YDIM" para uma variavel.
    int x = (*parte).XDIM;
    // Esse for ira pegar o pixel da imagem original e mudar para um novo valor
    for(int i = 0; i < y; i++){
        for(int j=0; j < x; j++){
            int pixel = parte->image[i][j]; // Apenas jogando o valor numa variavel aux, para fica mais legivel
            pixel = c*log(1+pixel);
            (*parte).image[i][j] = pixel;
        }
    }
}
/*Funcao que altera a Imagem conforme a operacao de "Contrast Stretching"*/
void FuncStretching(Imagem* parte){
        //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int PixelMax = parte->max;
    int PixelMin = parte->min;
    int y = (*parte).YDIM;
    int x = (*parte).XDIM;
    // Esse for ira pegar o pixel da imagem original e mudar para um novo valor
    for(int i = 0; i < y; i++){
        for(int j=0; j < x; j++){
            int pixel = parte->image[i][j]; // Apenas jogando o valor numa variavel aux, para fica mais legivel
            pixel = (float)(pixel-PixelMin)/(float)(PixelMax-PixelMin)*255.00;
            (*parte).image[i][j] = pixel;
        }
    }
}
/* Funcao que percorre a matriz para encontrar o pixel de menor/maior valor.*/
void MinMax(Imagem* parte){
    //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int y = (*parte).YDIM;
    int x = (*parte).XDIM;
    unsigned char **p = parte->image;
    int min = (int)p[0][0];
    int max = (int)p[0][0];

    for(int i = 0; i < y; i++){
            for(int j=1; j < x; j++){
                    if ((int)p[i][j] < min) min = (int)p[i][j];
                    if ((int)p[i][j] > max) max = (int)p[i][j];
            }
    }
    parte->min = min;
    parte->max = max;

}
/* Funcao que mostra imagem na saida padrao (stdout)*/
void ShowImage(Imagem* parte, int MaxVal){
    //Declarando variaveis, principalmente da struct para facilitar a manipulacao
    int y = parte->YDIM;
    int x = parte->XDIM;
    unsigned char **p = parte->image;

        // Imprimindo o cabecalho
    printf("P2\n");
    printf("# CREATOR: Image Generator SCC-221 - ICC I\n");
    printf("%d %d\n", x, y);
    printf("%d\n", MaxVal);
        // Imprindo a imagem
    for (int i=0; i < y; i++){
        for (int j=0; j < x; j++){
            printf("%d\n", p[i][j]);
        }
    }
}
/* Funcao que abre o arquivo de imagem, passa as informacoes para a struct, e captura o MaxVal*/
void LoadImage(char* filename, Imagem* parte, int* MaxVal){ // Problemas <<
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

        //Quarta parte do cabecalho me diz o valor do maior pixel encontrado na imagem (normalmente 255).
    fscanf(ImgPtr, "%d", MaxVal);
    // PROBLEMA, o ponteiro nesse instante esta em um '\n', se for ASCII nao tem problema, mas se for binario o fread acaba pegando o '\n'.
    fgetc(ImgPtr); // pegar o '\n'

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
                    fread(parte->image[i], sizeof(unsigned char), x, ImgPtr);
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
    int MaxVal; // NOTE que max e MaxVal sao diferentes. max eh o pixel de maior valor da imagem, enquanto MaxVal eh o tamanho que o pixel PODE vir a atingir.
    char filename[50];
    Imagem parte; // A imagem eh composta por diferentes partes, "parte" sera um ponteiro que aponta para uma delas.
    parte.image = NULL;

        // Primeira entrada e` a Operacao desejada pelo usuario
        //3 possibilidades: 1 -> FuncLog || 2 -> FuncStretching || 3 -> FuncBucket
    scanf("%d\n", &Operacao);

        // Proxima entrada e` o nome do arquivo, portanto alocarei ele numa string.
    NomeDoArq(filename);

        // Abrir a imagem.
    LoadImage(filename, &parte, &MaxVal);

        // Achar o pixel de maior e de menor valor.
    MinMax(&parte);

        // Manipular a imagem.
    if (Operacao == 1) FuncLog(&parte);
    else if (Operacao == 2) FuncStretching(&parte);
//  else if (Operacao == 3) FuncBucket();
        //Mandar a imagem para stdout
        ShowImage(&parte, MaxVal);

        // Liberando a memoria
    LiberaHeap(&parte);
    return 0;
}
