#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    //Inicializando o tabuleiro com 10 posições e usando um for loop para acessar cada posição e atribuir 0
    const int  BOARD_SIZE = 10;
    int board[BOARD_SIZE][BOARD_SIZE];

    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = 0;
        }
    }

    //DECLARAÇÃO DOS NAVIOS
    const int SHIP_SIZE = 3;
    int verticalShip[] = {3, 3, 3}; 
    int horizontalShip[] = {3, 3, 3};

    //Posicionando manualmente os navios no tabuleiro
    //POSIÇÃO DO NAVIO VERTICAL
    if(board[2][1] == 0 && board[3][1] == 0 && board[4][1] == 0 ){
        board[3][1] = 3;
        board[4][1] = 3;
        board[5][1] = 3;
    }

    //POSIÇÃO DO NAVIO VERTICAL
    if(board[9][7] == 0 && board[9][8] == 0 && board[9][9] == 0) {
        board[9][7] = 3;
        board[9][8] = 3;
        board[9][9] = 3;
    }

    /*
    *   Implementando mais dois návios horizontais.
    *   Uso de uma variável contadora para controlar quantos navios foram posicionados
    *   e uma variável para controlar se um navio foi inteiramente posicionado.
    *   Posicionando na diagonal principal da matriz
    */
    int shipsToInsert = 2;
    int shipCounter;

    do {
        shipCounter = 0;
       for(int i=0; i<BOARD_SIZE; i++) {

            if(shipCounter == 3)  {
                shipsToInsert--;
                break; //Quebra o laço se as três peças forem posicionadas
            }

            for(int j=0; j<BOARD_SIZE; j++) {

                if(i == 3 && j == 3) continue; // PULANDO UM ESPAÇO NA DIAGONAL PARA FACILITAR A VISUALIZAÇÃO
                if (i == j && board[i][j] == 0) {
                    board[i][j] = 3;
                    shipCounter++;
                }

            }
       }

    } while(shipsToInsert > 0);

        //EXIBIÇÃO DO TABULEIRO
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%d\t",board[i][j]);
        }
        printf("\n");
    }


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
