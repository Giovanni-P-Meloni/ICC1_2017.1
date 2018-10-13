#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

/* S�rie de jogadas, ENQUANTO os pontos de vida n�o chegarem a zero.
   Jogar dados AT� que o ataque supere a defesa.
   DADO DE DETERMINA��O (DDA), ele define SE um ataque ser� autorizado ou nao
   DDO DE ATAQUE - (DA), determina o dano causado pelo ataque no oponente, ou seja quantos pontos de vida ele perdera pelo ataqu   e
   LUTA:
	1 - Ordem: Para definir quem come�a, Drizzt e Artemis lan�am dado NESSA ORDEM, o DDA. Come�a aquele que tirar
	o MAIOR numero. CASO seja IGUAL Drizzt come�a
	2 - Autoriza��o de Ataque: Para poder atacar, primeiro passo � lan�ar o DDA. Se o resultado obtido for estritamente MAIOR do           que a CLASSE DE ARMADURA.
	3 - Ataque: a arma � representada pela nota��o NdP, em que N simboliza o numero de dados de ataque da arma (ou seja o numero de 	ataques possiveis em um turno) e P simboliza a FOR�A DE ATAQUE (FA), que indica o numero de faces do DA. EX: uma arma 2d8
	 permite que sejam sorteados dois DA's com 8 faces. POr outro lado uma arma 1d5 permie que apenas 1 DA com 5 faces seja
	 sorteado.
	4 -  Dano do Oponente: Em cada ataque AUTORIZADO, o resultado no DA � o NUMERO DE VIDA que deve ser DESCONTADO.QUANDO a arma
	permitir jogar mais que um DA (N > 1), a soma dos N resultados obtidos � DESCONTADO da vida do rival
		Eventos Especiais:
			EXTRA DAMAGE: QUANDO o valor obtido na arma � o m�ximo possivel, o numero de pontos a ser subtraido
						 � aumentado em 50%.
			MISS: QUANDO o valor obtido � o M�NIMO POSS�VEL. o atacante errou o golpe.
	5 - Resolu��o da Luta: Assim que um aatque � finalizado (autorizado ou n�o), a vez de atacar passa para o oponente, e eles
	continuam ALTERNANDO AT� que um deles n�o possua mais PONTOS DE VIDA.

  BATALHA: consiste em uma disputa de "Melhor de m lutas", em que m � um n�mero �mpar e o personagem que vencer a maioria das lutas �
	   declarado vencedor da baralha. ENquanto nenhum dos personagens obter as vit�rias necess�rias para vencer a batalha,
	   come�a uma nova luta. retomando a vida inicial de ambos. QUANDO um dos personagens conseguir (m/2] + 1, o declaramos vence
	   dor da batalha e finalizamos o jogo.

*/


	// Declarando as variaveis

	   // Artemis
	int DDAA;
	int VidaA;
	int VidaOrA;
	int CAA = 7;
	int VitA = 0;
 	int NDAA[2]; //Numero de Dados da Arma de Artemis


	   // Drizzt
	int VidaD;
	int VidaOrD;
	int DDAD;
	int CAD = 10;
	int VitD = 0;

	   // Gerais
	int FacesDDA;
	int Lutas;
	int FIMDABATALHA = 0;


	  // Contadores
	int l = 1;
	int Alternar;

	// Entradas

	scanf("%d", &Lutas);
	scanf("%d", &VidaOrD);
	scanf("%d", &VidaOrA);
	scanf("%d", &FacesDDA);

	srand(pow(FacesDDA,2));

		for (l=1; (l <= Lutas) && (FIMDABATALHA == 0); l++){ //Contando a Luta em que se encontra.
			printf("Luta %d\n", l); //retorna para o jogador a luta em qual luta ele se encontra.
            VidaA = VidaOrA;    // } A vida de ambos deve ser resetada antes de come�ar a proxima luta
            VidaD = VidaOrD;    // }
			DDAD = (rand()%FacesDDA) + 1;
			DDAA = (rand()%FacesDDA) + 1;
			Alternar = 0;
			while ((VidaD > 0) && (VidaA > 0)){

				if (((DDAA > DDAD) && (Alternar == 0)) || (Alternar == 1)){  // SE a Artemis possuir uma determina��o MAIOR, ela come�a. (DDAA1 > DDAD1)
					DDAA = (rand()%FacesDDA) + 1; //Novo dado para ver se passa a defesa (DDAA2)
					int DanoA = 0; //Dano que Artemis dara em Dritzz. Deve ser resatado apos o Damage Step
					if (DDAA > CAD){ //Se DDAA2 for maior que a defesa de Drittz, entra no Damage Step
						for (int i=0; i <= 1; i++){ //A arma de Artemis � um 2d7, o jogador deve rolar 2 dados de 7 faces
							NDAA[i] = (rand()%7) + 1; // um dado de 1 a 7 e armazena o valor
							DanoA = DanoA + NDAA[i];
						} //Existem 3 situa��es, ou ED, ou Miss ou Procedimento Normal
						if (DanoA == 14){ // Evento Especial: "EXTRA DAMAGE"
							VidaD = VidaD - 21;
							printf("Artemis %d\n", (DanoA + 7) );
						}
						else{
							if(DanoA == 2){ // Evento Especial: "Miss"
							}
							else{
							VidaD = VidaD - DanoA;
							printf("Artemis %d\n", DanoA);
							}
						}
					}
                    Alternar = -1;
                }
				else { // CASO CONTRARIO, Drizzt possuir uma determina��o MAIOR ou  IGUAL, ele come�a.(DDAD1 >= DDAA1)
					DDAD = (rand()%FacesDDA) + 1;
					int DanoD = 0; //Dano que Drittz dara em Artemis. Deve ser resatado apos o Damage Step
						if (DDAD > CAA){//Se o novo dado for maior que a defesa de Artemis, entra no Damage Step (DDAD3)
							DanoD = (rand()%9) + 1;
							//Existem 3 situa��es, ou ED, ou Miss ou Procedimento Normal
							if (DanoD == 9){ // Evento Especial: "EXTRA DAMAGE"
								VidaA = VidaA - 13;//arredondado para cima ou para baixo??? <<<<<<<<<<<<<<<<<<< WARNING
								printf("Drizzt %d\n", (DanoD + 4));
							}
							else{
								if(DanoD == 1){ // Evento Especial: "Miss"
								}
								else {
								VidaA = VidaA - DanoD;
								printf("Drizzt %d\n", DanoD);
								}

							}
						}

                    Alternar = 1;
                }
            } // Verificando quem perdeu a luta
            if (VidaD <= 0){
                printf("Fim da luta. Vencedor: Artemis\n");
                VitA++;
            }
            else {
                if(VidaA <= 0){
                    printf("Fim da luta. Vencedor: Drizzt\n");
                    VitD++;
                }
            }
            if ((VitA >= (Lutas/2) +1) || (VitD >= (Lutas/2) + 1)){
            FIMDABATALHA = 1;
            }
        }
        if (VitA >= (Lutas/2) + 1) {
                printf("Fim da batalha. Vencedor: ARTEMIS\n");
        }
        else {
            if(VitD >= (Lutas/2) + 1){
                printf("Fim da batalha. Vencedor: DRIZZT\n");
            }
        }

		  return 0;
}
