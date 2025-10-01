#include <stdio.h>
    int main(){

    // Tamanho do Tabuleiro
    int tabuleiro[10][10] = {0};

    // Navios
    int navio1 = 3, navio2 = 3, navio3 = 3, navio4 = 3;

    // Posições dos navios
    int linha_h = 0, coluna_h = 5; // 1º Navio em Horizontal)
    int linha_v = 1, coluna_v = 1; // 2º Navio em Vertical
    int linha_d = 4, coluna_d = 3; // 3º Navio Diagonal Direita
    int linha_d2 = 6, coluna_d2 = 8; // 4º Navio Diagonal Esquerda
    
    // Navio Horizontal
    for (int i = 0; i < navio1; i++)
    { if ((linha_h < 10) && (coluna_h + i < 10) && tabuleiro[linha_h][coluna_h + i] == 0) { // Verifica se está dentro do tabuleiro
    tabuleiro[linha_h][coluna_h + i] = 3;
        }
    }

    // Navio Vertical
    for (int i = 0; i < navio2; i++)
    { if ((linha_v + i < 10) && (coluna_v < 10) && tabuleiro[linha_v + i][coluna_v] == 0) { // Verifica se está dentro do tabuleiro
    tabuleiro[linha_v + i][coluna_v] = 3;
        }
    }

    // Navio Diagonal para direita
    for (int i = 0; i < navio3; i++)
    { if ((linha_d + i < 10) && (coluna_d + i < 10) && tabuleiro[linha_d + i][coluna_d + i] == 0) { // Verifica se está dentro do tabuleiro
    tabuleiro[linha_d + i][coluna_d + i] = 3;
        }
    }

    // Navio Diagonal para esquerda
    for (int i = 0; i < navio4; i++)   
    { if ((linha_d2 + i < 10) && (coluna_d2 - i >= 0) && tabuleiro[linha_d2 + i][coluna_d2 - i] == 0) { // Verifica se está dentro do tabuleiro
    tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
        }
    }
    
    
    // Exibição do tabuleiro
    printf("\tBATALHA NAVAL\n\n");
        for (int i = 0; i < 10; i++)
        {        
        for (int j = 0; j < 10; j++)
        {
        printf("%2d ", tabuleiro[i][j]);
        }
    printf("\n");
    }
    
    return 0;
}