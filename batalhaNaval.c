#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SKILL_SIZE 5  // Tamanho das matrizes de habilidade (5x5)

// Função para criar a matriz de habilidade Cone
void createCone(int coneMatrix[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;  // Centro da matriz (2 para 5x5)
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Inicializa a matriz com 0
            coneMatrix[i][j] = 0;
            // Controla a posição para montar o cone corretamente
            if (j >= center - i && j <= center + i) {
                coneMatrix[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade Cruz
void createCross(int crossMatrix[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Inicializar com 0
            crossMatrix[i][j] = 0;
              // Controla a posição para montar o cone corretamente
            if (i == center || j == center) {
                crossMatrix[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade Octaedro (losango)
void createOctahedron(int octaMatrix[SKILL_SIZE][SKILL_SIZE]) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            // Inicializar com 0
            octaMatrix[i][j] = 0;
            // Condicional para losango: distância de Manhattan do centro
            int dist = abs(i - center) + abs(j - center);
            if (dist <= center) {
                octaMatrix[i][j] = 1;
            }
        }
    }
}

// Função para sobrepor a habilidade no tabuleiro
void applySkill(int board[10][10], int skillMatrix[SKILL_SIZE][SKILL_SIZE], int originRow, int originCol) {
    int center = SKILL_SIZE / 2;
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (skillMatrix[i][j] == 1) {
                int boardRow = originRow + (i - center);
                int boardCol = originCol + (j - center);
                // Verificar limites do tabuleiro
                if (boardRow >= 0 && boardRow < 10 && boardCol >= 0 && boardCol < 10) {
                    board[boardRow][boardCol] = 5;  // Marcar área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void displayBoard(int board[10][10]) {
    printf("TABULEIRO DE BATALHA NAVAL COM HABILIDADES\n");
    printf("\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", i);
        for (int j = 0; j < 10; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const int BOARD_SIZE = 10;
    int board[BOARD_SIZE][BOARD_SIZE];

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Posicionar navios (mantido do código original)
    // Navio vertical
    board[3][1] = 3;
    board[4][1] = 3;
    board[5][1] = 3;

    // Navio horizontal
    board[9][7] = 3;
    board[9][8] = 3;
    board[9][9] = 3;

    // Navios na diagonal
    board[0][0] = 3;
    board[1][1] = 3;
    board[2][2] = 3;
    board[4][4] = 3;
    board[5][5] = 3;
    board[6][6] = 3;

    // Definir pontos de origem para as habilidades (fixos no código)
    int coneOriginRow = 2, coneOriginCol = 2;
    int crossOriginRow = 5, crossOriginCol = 5;
    int octaOriginRow = 7, octaOriginCol = 7;

    // Criar matrizes de habilidade
    int coneMatrix[SKILL_SIZE][SKILL_SIZE];
    createCone(coneMatrix);

    int crossMatrix[SKILL_SIZE][SKILL_SIZE];
    createCross(crossMatrix);

    int octaMatrix[SKILL_SIZE][SKILL_SIZE];
    createOctahedron(octaMatrix);

    // Aplicar habilidades ao tabuleiro
    applySkill(board, coneMatrix, coneOriginRow, coneOriginCol);
    applySkill(board, crossMatrix, crossOriginRow, crossOriginCol);
    applySkill(board, octaMatrix, octaOriginRow, octaOriginCol);

    // Exibir tabuleiro final
    displayBoard(board);

    return 0;
}
