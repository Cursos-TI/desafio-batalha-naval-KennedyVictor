#include <stdio.h>
    int main(){

    // Tamanho do Tabuleiro
    int tabuleiro[10][10] = {0};

    // Navios
    int navio1 = 3;
    int navio2 = 3;

    // Posições dos navios
    int linha_h = 8, coluna_h = 6; // 1º Navio em Horizontal)
    int linha_v = 1, coluna_v = 1; // 2º Navio em Vertical 

    for (int i = 0; i < navio1; i++)
    {
    tabuleiro[linha_h][coluna_h + i] = 3;
    }

    for (int i = 0; i < navio2; i++)
    {
    tabuleiro[linha_v + i][coluna_v] = 3;
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


    