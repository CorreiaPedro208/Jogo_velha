#ifndef JOGADOR_IA_H
#define JOGADOR_IA_H

#include "tabuleiro.h"

typedef struct {
    int tipo;
} JogadorIA;

void ia_joga(JogadorIA *j, Tabuleiro *t);

#endif