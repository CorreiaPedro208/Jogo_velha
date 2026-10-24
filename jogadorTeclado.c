#include <stdio.h>

#include "jogador_teclado.h"
#include "tabuleiro.h"

void jogador_teclado_inicializa(JogadorTeclado *j, int tipo) {
    j->tipo = tipo;
}

void jogador_teclado_joga(JogadorTeclado *j, Tabuleiro *t) {
    int linha, coluna;

    printf("Digite a linha e coluna da sua jogada: ");
    scanf("%d %d", &linha, &coluna);

    tabuleiro_marcaJogada(t, linha, coluna, j->tipo);
}