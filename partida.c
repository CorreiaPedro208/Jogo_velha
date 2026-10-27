#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"
#include "partida.h"

void configuraJogadores(Partida *p) {
    jogador_teclado_inicializa(&(p->j1), JOGADOR_X);
    jogador_teclado_inicializa(&(p->j2), JOGADOR_O);

    srand(time(NULL));
    if (rand() % 2 == 0) {
    p->jogador_atual = &(p->j1);
    } else {
    p->jogador_atual = &(p->j2);
    }
}

void inicia(Partida *p) {
    tabuleiro_inicializa(&(p->tabuleiro));
    
    for (int i = 0; i < 9; i++) {
        tabuleiro_desenha(&(p->tabuleiro));
        
        char simbolo[2];
        if (p->jogador_atual->tipo == JOGADOR_X) {
            simbolo[0] = '1';
            simbolo[1] = 'X';
        } else {
            simbolo[0] = '2';
            simbolo[1] = 'O';
        }

        printf("\nVez do jogador %c (%c):\n", simbolo[0], simbolo[1]);

        jogador_teclado_joga(p->jogador_atual, &(p->tabuleiro));
        tabuleiro_desenha(&(p->tabuleiro));

        if (p->jogador_atual == &(p->j1)) {
            p->jogador_atual = &(p->j2);
        } else {
            p->jogador_atual = &(p->j1);
        }

        if (tabuleiro_temVencedor(&(p->tabuleiro)) != VAZIO) {
            break;
        }
    }

    int resultado = tabuleiro_temVencedor(&(p->tabuleiro));
    if (resultado == JOGADOR_X){
        printf("Jogador 1 (X) é o vencedor!\n");
    } else if (resultado == JOGADOR_O) {
        printf("Jogador 2 (O) é o vencedor!\n");
    } else {
        printf("Empate, deu velha!\n");
    }
}
