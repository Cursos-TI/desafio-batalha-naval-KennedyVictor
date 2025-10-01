#include <stdio.h>

#define TAM_LIN 3
#define TAM_COL 5
#define TAB_LIN 10
#define TAB_COL 10

int main() {

    int tabuleiro[TAB_LIN][TAB_COL] = {0};
    int habilidade[TAM_LIN][TAM_COL] = {0};
    int centro_linha = TAM_LIN / 2;
    int centro_coluna = TAM_COL / 2;

    // Navios
    int navio1 = 3, navio2 = 3, navio3 = 3, navio4 = 3;

    // Posições dos navios
    int linha_h = 0, coluna_h = 5; // navio horizontal
    int linha_v = 1, coluna_v = 1; // navio vertical
    int linha_dd = 5, coluna_dd = 3; // navio diagonal direita
    int linha_de = 7, coluna_de = 8; // navio diagonal esquerda

    // Posições das habilidades
    int linha_cone = 4, coluna_cone = 7;
    int linha_cruz = 2, coluna_cruz = 4;
    int linha_octa = 7, coluna_octa = 2;

    // Navio 1 Horizontal
    for (int i = 0; i < navio1; i++)
        if ((linha_h < TAB_LIN) && (coluna_h + i < TAB_COL))
            tabuleiro[linha_h][coluna_h + i] = 3;

    // Navio 2 Vertical
    for (int i = 0; i < navio2; i++)
        if ((linha_v + i < TAB_LIN) && (coluna_v < TAB_COL))
            tabuleiro[linha_v + i][coluna_v] = 3;

    // Navio 3 Diagonal direita
    for (int i = 0; i < navio3; i++)
        if ((linha_dd + i < TAB_LIN) && (coluna_dd + i < TAB_COL))
            tabuleiro[linha_dd + i][coluna_dd + i] = 3;

    // Navio 4 Diagonal esquerda
    if (coluna_de - (navio4 - 1) >= 0) {
        for (int i = 0; i < navio4; i++)
            tabuleiro[linha_de + i][coluna_de - i] = 3;
    }

    // Habilidades

    // Cone
    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            if (j >= centro_coluna - i && j <= centro_coluna + i)
                habilidade[i][j] = 1;

    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            if (habilidade[i][j] == 1) {
                int tab_i = linha_cone + i - centro_linha;
                int tab_j = coluna_cone + j - centro_coluna;
                if (tab_i >= 0 && tab_i < TAB_LIN && tab_j >= 0 && tab_j < TAB_COL)
                    if (tabuleiro[tab_i][tab_j] != 3)
                        tabuleiro[tab_i][tab_j] = 5;
            }

    // Limpar habilidade
    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            habilidade[i][j] = 0;

    // Cruz
    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            if (i == centro_linha || j == centro_coluna)
                habilidade[i][j] = 1;

    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            if (habilidade[i][j] == 1) {
                int tab_i = linha_cruz + i - centro_linha;
                int tab_j = coluna_cruz + j - centro_coluna;
                if (tab_i >= 0 && tab_i < TAB_LIN && tab_j >= 0 && tab_j < TAB_COL)
                    if (tabuleiro[tab_i][tab_j] != 3)
                        tabuleiro[tab_i][tab_j] = 5;
            }

    // Limpar habilidade
    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            habilidade[i][j] = 0;

    // Octaedro
    int raio = 1;
    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++) {
            int di = (i > centro_linha) ? i - centro_linha : centro_linha - i;
            int dj = (j > centro_coluna) ? j - centro_coluna : centro_coluna - j;
            if (di + dj <= raio)
                habilidade[i][j] = 1;
        }

    for (int i = 0; i < TAM_LIN; i++)
        for (int j = 0; j < TAM_COL; j++)
            if (habilidade[i][j] == 1) {
                int tab_i = linha_octa + i - centro_linha;
                int tab_j = coluna_octa + j - centro_coluna;
                if (tab_i >= 0 && tab_i < TAB_LIN && tab_j >= 0 && tab_j < TAB_COL)
                    if (tabuleiro[tab_i][tab_j] != 3)
                        tabuleiro[tab_i][tab_j] = 5;
            }

    // Tabuleiro
    printf("\tBATALHA NAVAL\n\n");
    for (int i = 0; i < TAB_LIN; i++) {
        for (int j = 0; j < TAB_COL; j++)
            printf("%2d ", tabuleiro[i][j]);    
        printf("\n");
    }

    return 0;
}





