#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogador_teclado.h"
#include "tabuleiro.h"

typedef struct {
    JogadorTeclado j1;
    JogadorTeclado j2;
    JogadorTeclado *jogador_atual;
    Tabuleiro tabuleiro;
} Partida;

void configuraJogadores(Partida *p);
void inicia(Partida *p);

#endif