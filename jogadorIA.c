#include <stdio.h>
#include "jogadorIA.h"

int regra1(JogadorIA *j, Tabuleiro *t) {
    int pecas[2] = {JOGADOR_O, JOGADOR_X};

    for (int p = 0; p < 2; p++) {
        int peca_alvo = pecas[p];

        for (int i = 0; i < 3; i++) {
            if (t->tabuleiro[i][0] == peca_alvo && t->tabuleiro[i][0] == t->tabuleiro[i][1] && t->tabuleiro[i][2] == VAZIO) {
                tabuleiro_marcaJogada(t, i, 2, j->tipo);
                return 1;
            }
            if (t->tabuleiro[i][0] == peca_alvo && t->tabuleiro[i][0] == t->tabuleiro[i][2] && t->tabuleiro[i][1] == VAZIO) {
                tabuleiro_marcaJogada(t, i, 1, j->tipo);
                return 1;
            }
            if (t->tabuleiro[i][1] == peca_alvo && t->tabuleiro[i][1] == t->tabuleiro[i][2] && t->tabuleiro[i][0] == VAZIO) {
                tabuleiro_marcaJogada(t, i, 0, j->tipo);
                return 1;
            }

            if (t->tabuleiro[0][i] == peca_alvo && t->tabuleiro[0][i] == t->tabuleiro[1][i] && t->tabuleiro[2][i] == VAZIO) {
                tabuleiro_marcaJogada(t, 2, i, j->tipo);
                return 1;
            }
            if (t->tabuleiro[0][i] == peca_alvo && t->tabuleiro[0][i] == t->tabuleiro[2][i] && t->tabuleiro[1][i] == VAZIO) {
                tabuleiro_marcaJogada(t, 1, i, j->tipo);
                return 1;
            }
            if (t->tabuleiro[1][i] == peca_alvo && t->tabuleiro[1][i] == t->tabuleiro[2][i] && t->tabuleiro[0][i] == VAZIO) {
                tabuleiro_marcaJogada(t, 0, i, j->tipo);
                return 1;
            }
        }

        if (t->tabuleiro[0][0] == peca_alvo && t->tabuleiro[0][0] == t->tabuleiro[1][1] && t->tabuleiro[2][2] == VAZIO) {
            tabuleiro_marcaJogada(t, 2, 2, j->tipo);
            return 1;
        }
        if (t->tabuleiro[0][0] == peca_alvo && t->tabuleiro[0][0] == t->tabuleiro[2][2] && t->tabuleiro[1][1] == VAZIO) {
            tabuleiro_marcaJogada(t, 1, 1, j->tipo);
            return 1;
        }
        if (t->tabuleiro[1][1] == peca_alvo && t->tabuleiro[1][1] == t->tabuleiro[2][2] && t->tabuleiro[0][0] == VAZIO) {
            tabuleiro_marcaJogada(t, 0, 0, j->tipo);
            return 1;
        }

        if (t->tabuleiro[0][2] == peca_alvo && t->tabuleiro[0][2] == t->tabuleiro[1][1] && t->tabuleiro[2][0] == VAZIO) {
            tabuleiro_marcaJogada(t, 2, 0, j->tipo);
            return 1;
        }
        if (t->tabuleiro[0][2] == peca_alvo && t->tabuleiro[0][2] == t->tabuleiro[2][0] && t->tabuleiro[1][1] == VAZIO) {
            tabuleiro_marcaJogada(t, 1, 1, j->tipo);
            return 1;
        }
        if (t->tabuleiro[1][1] == peca_alvo && t->tabuleiro[1][1] == t->tabuleiro[2][0] && t->tabuleiro[0][2] == VAZIO) {
            tabuleiro_marcaJogada(t, 0, 2, j->tipo);
            return 1;
        }   
    }
    return 0;
}


int regra2(JogadorIA *j, Tabuleiro *t) {
    int soma_linha, soma_coluna, soma_diagonal;

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (t->tabuleiro[i][k] != VAZIO) {
                continue;
            }

            int qtd_marcacoes = 0;
            
            soma_linha = t->tabuleiro[i][0] + t->tabuleiro[i][1] + t->tabuleiro[i][2];
            soma_coluna = t->tabuleiro[0][k] + t->tabuleiro[1][k] + t->tabuleiro[2][k];

            if (soma_linha == JOGADOR_O) {
                qtd_marcacoes++;
            }
            if (soma_coluna == JOGADOR_O) {
                qtd_marcacoes++;    
            }
            
            if (i == k) {
                soma_diagonal = t->tabuleiro[0][0] + t->tabuleiro[1][1] + t->tabuleiro[2][2];
                if (soma_diagonal == JOGADOR_O) {
                    qtd_marcacoes++;
                }
            }
            else if (i + k == 2) {
                soma_diagonal = t->tabuleiro[2][0] + t->tabuleiro[1][1] + t->tabuleiro[0][2];
                if (soma_diagonal == JOGADOR_O) {
                    qtd_marcacoes++;
                }
            }

            if (qtd_marcacoes >= 2){
                tabuleiro_marcaJogada(t, i, k, j->tipo);
                return 1;
            }
        }
    }
    return 0;
}

int regra3(JogadorIA *j, Tabuleiro *t) {
    if (t->tabuleiro[1][1] == VAZIO) {
        tabuleiro_marcaJogada(t, 1, 1, j->tipo);
        return 1;
    }
    return 0;
}

int regra4(JogadorIA *j, Tabuleiro *t) {
    if (t->tabuleiro[0][0] != VAZIO && t->tabuleiro[0][0] != j->tipo && t->tabuleiro[2][2] == VAZIO) {
        tabuleiro_marcaJogada(t, 2, 2, j->tipo);
        return 1;
    }
    if (t->tabuleiro[2][2] != VAZIO && t->tabuleiro[2][2] != j->tipo && t->tabuleiro[0][0] == VAZIO) {
        tabuleiro_marcaJogada(t, 0, 0, j->tipo);
        return 1;
    }
    if (t->tabuleiro[0][2] != VAZIO && t->tabuleiro[0][2] != j->tipo && t->tabuleiro[2][0] == VAZIO) {
        tabuleiro_marcaJogada(t, 2, 0, j->tipo);
        return 1;
    }
    if (t->tabuleiro[2][0] != VAZIO && t->tabuleiro[2][0] != j->tipo && t->tabuleiro[0][2] == VAZIO) {
        tabuleiro_marcaJogada(t, 0, 2, j->tipo);
        return 1;
    }
    return 0;
}

int regra5(JogadorIA *j, Tabuleiro *t) {
    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i = 0; i < 4; i++) {
        int linha = cantos[i][0];
        int coluna = cantos[i][1];
        if (t->tabuleiro[linha][coluna] == VAZIO) {
            tabuleiro_marcaJogada(t, linha, coluna, j->tipo);
            return 1;
        }
    }
    return 0;
}

int regra6(JogadorIA *j, Tabuleiro *t) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (t->tabuleiro[linha][coluna] == VAZIO) {
                tabuleiro_marcaJogada(t, linha, coluna, j->tipo);
                return 1;
            }
        }
    }
    return 0;
}


void ia_joga(JogadorIA *j, Tabuleiro *t) {
    if (regra1(j, t)) return;
    if (regra2(j, t)) return;
    if (regra3(j, t)) return;
    if (regra4(j, t)) return;
    if (regra5(j, t)) return;
    regra6(j, t);
}