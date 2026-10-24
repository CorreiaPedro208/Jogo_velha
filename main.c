#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jogador_teclado.h"
#include "tabuleiro.h"

int main() {
    JogadorTeclado j1;
    JogadorTeclado j2;
    JogadorTeclado *jogador_atual;
    Tabuleiro tabuleiro;

    tabuleiro_inicializa(&tabuleiro);
    jogador_teclado_inicializa(&j1, JOGADOR_X);
    jogador_teclado_inicializa(&j2, JOGADOR_O);

    srand(time(NULL));
    if (rand() % 2 == 0) {
    jogador_atual = &j1;
    } else {
    jogador_atual = &j2;
    }
    
    while (tabuleiro_temVencedor(&tabuleiro) == VAZIO) {
        tabuleiro_desenha(&tabuleiro);
        
        char simbolo;
        if (jogador_atual->tipo == JOGADOR_X) {
            simbolo = 'X';
        } else {
            simbolo = 'O';
        }

        printf("\nVez do jogador (%c):\n", simbolo);

        jogador_teclado_joga(jogador_atual, &tabuleiro);
        tabuleiro_desenha(&tabuleiro);

        if (jogador_atual == &j1) {
            jogador_atual = &j2;
        } else {
            jogador_atual = &j1;
        }
    }

    int resultado = tabuleiro_temVencedor(&tabuleiro);
    if (resultado == JOGADOR_X){
        printf("Jogador 1 (X) é o vencedor!\n");
    } else if (resultado == JOGADOR_O) {
        printf("Jogador 2 (O) é o vencedor!\n");
    } else {
        printf("Empate! Deu velha!\n");
    }

    return 0;
}

