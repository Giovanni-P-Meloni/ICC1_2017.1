#include <stdio.h>
#include <stdlib.h>


void Labirinto(char endLab[][7]){ // A funcão recebe uma matriz para manipula-lá, portanto não irá retornar nada apenas processará informacões.
    char* matriz=NULL;
	char c;
	int count=0;

    do { // Preciso desse while para ler a matriz em uma unica linha
        c = fgetc(stdin);
        matriz = realloc(matriz, sizeof(char)*(count+1));
        matriz[count] = c;
        count++;

        } while (c != '\n'); // Possuo a matriz labirinto, porem em um vetor de chars com espacos
    count = 0;
	for(int i=0; i < 7; i++){
		for(int j=0; j < 7; j++){

			endLab[i][j] = matriz[count];
            count = count + 2; //depois de cada valor, existe um espaco.
		}
	}
    free(matriz);
}

int main(){
                    // Declarando Variaveis
    //Variaveis de "Entrada"
	char Lab[7][7]={0};//O labirinto


    //Contadores & Outros
    int x=0, y=0, k;//, i, j; //x,y nao sao exatamente contadores, eles sao as coordenadas da atual posicao no labirinto

	//Variaveis de "Saida"
    int caminho[20] = {0}; // Caminho[0] eh o Inicio da labirinto. O vetor aramzena as posicoes em decimal

                    // 1.o: Ler o Labirinto
	Labirinto(Lab); // Preciso passar a matriz para uma funcao, nela a matriz sera preenchida pelo usuario.

                    // 2.o: Ler a entrada do labirinto
	scanf("%d", &caminho[0]);
    x = caminho[0]/7;
    y = caminho[0]%7;

                    // 3.o Percorrer o Labirinto
                    /*
                    0 - Caminho Livre(Maior Prioridade)
                    1 - Obstaculo ou Impedido
                    2 - "Safe Haven", isto eh, ja passei por aqui, mas posso voltar (Menor Prioridade)
                    */
    k=1; // afinal caminho[0] ja esta preenchido
	do{ // A primeira vez que entrar nesse laco, com certeza sera uma entrada.

            if ( x<6 && Lab[x+1][y] == '0'){
                Lab[x][y] = '2';
                x++;
                caminho[k] = (7*x) + y;
            }
            else if (x>0 && Lab[x-1][y] == '0'){
                    Lab[x][y] = '2';
                    x--;
                    caminho[k] = (7*x) + y;
                }
                else if (y<6 && Lab[x][y+1] == '0'){
                        Lab[x][y] = '2';
                        y++;
                        caminho[k] = (7*x) + y;
                    }
                    else  if (y>0 && Lab[x][y-1] == '0'){
                            Lab[x][y] = '2';
                            y--;
                            caminho[k] = (7*x) + y;

                        }
                        else{ // Se chegar nesse ponto, quer dizer que estou num beco sem saida. Irei agora impedir a minha posicao atual e ver as posicoes de menor prioridade.
                            Lab[x][y] = '1'; // Impedindo a posicao atual.
                            k--;           // | Limpando o numero em caminho, afinal ele nao faz parte da resposta.
                            caminho[k] = 0;// | Preciso que essa posicao seja sobreescrita por um valida
                            if(x<6 && Lab[x+1][y] == '2') x++;
                            else if(x>1 && Lab[x-1][y] == '2')x--; // Vendo as posicoes de menor prioridade
                            else if(y<6 && Lab[x][y+1] == '2')y++;
                            else if(y>0 && Lab[x][y-1] == '2')y--;
                            k--; // Preciso diminuir k mais uma vez pois no final irei somar k, dessa maneira a posicao nao sera sobreescrita, isto eh, tera um 0.
                        }
        k++;
	} while ((y != 0) && (x != 0) && (x != 6) && (y != 6)); // Enquanto nao for uma saida, repita o laco.


                // 4.o Imprimir na Tela o caminho
   for(k=0; (k <= 19) && caminho[k] != 0; k++){
        printf("%d ", caminho[k]);
    }

    printf("\n");
	return 0;
}
