#include <stdio.h>
#include "tabuleiro.h"

void tabuleiro_inicializa(Tabuleiro *t) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t->tabuleiro[i][j] = VAZIO;
        }
    }
}

void tabuleiro_desenha(Tabuleiro *t) {
    printf("\033[2J\033[H");
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            char c = ' ';
            if (t->tabuleiro[i][j] == JOGADOR_O) {
                c = 'O';
            } else if (t->tabuleiro[i][j] == JOGADOR_X) {
                c = 'X';
            }
            printf(" %c ", c);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf(" ---+---+---\n");
        }
    }
    printf("\n");
}

int tabuleiro_temVencedor(Tabuleiro *t) {
    for (int i = 0; i < 3; i++) {
        if (t->tabuleiro[i][0] != VAZIO &&
            t->tabuleiro[i][0] == t->tabuleiro[i][1] &&
            t->tabuleiro[i][1] == t->tabuleiro[i][2]) {
            return t->tabuleiro[i][0];
        }
        if (t->tabuleiro[0][i] != VAZIO &&
            t->tabuleiro[0][i] == t->tabuleiro[1][i] &&
            t->tabuleiro[1][i] == t->tabuleiro[2][i]) {
            return t->tabuleiro[0][i];
        }
    }

    if (t->tabuleiro[0][0] != VAZIO &&
        t->tabuleiro[0][0] == t->tabuleiro[1][1] &&
        t->tabuleiro[1][1] == t->tabuleiro[2][2]) {
        return t->tabuleiro[0][0];
    }

    if (t->tabuleiro[0][2] != VAZIO &&
        t->tabuleiro[0][2] == t->tabuleiro[1][1] &&
        t->tabuleiro[1][1] == t->tabuleiro[2][0]) {
        return t->tabuleiro[0][2];
    }

    return VAZIO;
}

int tabuleiro_marcaJogada(Tabuleiro *t, int linha, int coluna, int jogador) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        return 0;
    }
    if (t->tabuleiro[linha][coluna] != VAZIO) {
        return 0;
    }
    t->tabuleiro[linha][coluna] = jogador;
    return 1;
}