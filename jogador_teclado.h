#ifndef JOGADOR_TECLADO_H
#define JOGADOR_TECLADO_H

#include "tabuleiro.h"

typedef struct {
    int tipo;
} JogadorTeclado;

void jogador_teclado_joga(JogadorTeclado *j, Tabuleiro *t);

#endif