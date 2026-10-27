#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogador_teclado.h"
#include "tabuleiro.h"

typedef struct {
    JogadorTeclado j1;
    JogadorTeclado j2;
    JogadorTeclado *jogador_atual;
    int vs_ia;
    Tabuleiro tabuleiro;
} Partida;

void configuraJogadores(Partida *p);
void inicia(Partida *p);

#endif