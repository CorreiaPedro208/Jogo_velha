#ifndef TABULEIRO_H
#define TABULEIRO_H

enum {VAZIO = 0, JOGADOR_O = 1, JOGADOR_X = 4};
typedef struct {
    int tabuleiro[3][3];
} Tabuleiro;
void tabuleiro_inicializa(Tabuleiro *t);
void tabuleiro_desenha(Tabuleiro *t);
int tabuleiro_temVencedor(Tabuleiro *t);
int tabuleiro_marcaJogada(Tabuleiro *t, int linha, int coluna, int jogador);
#endif

