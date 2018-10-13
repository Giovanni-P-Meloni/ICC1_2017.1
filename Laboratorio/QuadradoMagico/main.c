#include <stdio.h>
#include <stdlib.h>
/*
Funcao que preenche a matriz
Parametros:
n -> Recebe o numero de linhas e colunas da matriz
*/

int** PreencherMat(int n){
    int** p = NULL; // guarda o endereco da matriz na heap

    p = (int**) malloc(n*sizeof(int*)); // Alocando as Linhas da Matriz

    for (int i=0; i < n; i++){
        p[i] = (int*) malloc(n*sizeof(int));
        for (int j=0; j < n; j++){
            scanf("%d", &p[i][j]);
        }
    }

    // ao fim desse for terei a matriz preenchida, entao vou retornar para a main o endereco dessa matriz
        return p;
}
/*
    Essa Funcao tem como objeivo verificar se a soma de cada linha tem mesmo valor, se tiver ela ira retornar o valor 1 para a main, (1 = sim, 0 = nao)
Parametros:
mat -> recebe o endereco da matriz da heap
n -> recebe o numero de Linhas e Colunas da matriz
*/
int SumLin(int** mat, int n){
    int i=0;
    int LinComp = 0;
    int Lin = 0;


    for (int j=0; j < n; j++){
        LinComp = LinComp + mat[i][j]; // LinComp eh a primeira Linha da matriz, compararei ela com as demais.
    }
    for (int i=1; i < n; i++){
        for (int j=0; j < n; j++){ // Ao final desse for terei o valor da linha correspondente a i.
            Lin = Lin + mat[i][j];
        }
        if (LinComp != Lin) return 0;
        Lin = 0;
    }
    return 1;
}


int main(){
    int n;
    int** mat = NULL;
    int L = 0;
    int C = 0;


    scanf("%d", &n);
    mat = PreencherMat(n);
    L = SumLin(mat, n);
    return 0;
}
