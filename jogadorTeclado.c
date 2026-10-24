#include <stdio.h>

#include "jogador_teclado.h"
#include "tabuleiro.h"

void jogador_teclado_inicializa(JogadorTeclado *j, int tipo) {
    j->tipo = tipo;
}

void jogador_teclado_joga(JogadorTeclado *j, Tabuleiro *t) {
    int linha, coluna;
    int sucesso;

    do {
        printf("Digite a linha e coluna da sua jogada: ");
        scanf("%d %d", &linha, &coluna);

        sucesso = tabuleiro_marcaJogada(t, linha - 1, coluna - 1, j->tipo);
        if (!sucesso) {
            printf("Jogada invalida! Posicao ocupada ou fora dos limites. Tente novamente.\n");
        }
    } while (!sucesso);
}