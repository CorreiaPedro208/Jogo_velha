#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"
#include "partida.h"
#include "jogadorIA.h"

void configuraJogadores(Partida *p) {
    p->j1.tipo = JOGADOR_X;
    p->j2.tipo = JOGADOR_O;

    do {
        printf("\n=== MODO DE JOGO ===\n");
        printf("0 - Humano vs Humano\n");
        printf("1 - Humano vs IA\n");
        printf("Escolha: ");
        scanf("%d", &p->vs_ia);

        if (p->vs_ia != 0 && p->vs_ia != 1) {
            printf("Opcao invalida! Digite 0 para Humano vs Humano ou 1 para Jogar vs IA.\n");
        }
    } while (p->vs_ia != 0 && p->vs_ia != 1);

    srand(time(NULL));
    if (rand() % 2 == 0) {
    p->jogador_atual = &(p->j1);
    } else {
    p->jogador_atual = &(p->j2);
    }
}

void inicia(Partida *p) {
    tabuleiro_inicializa(&(p->tabuleiro));

    JogadorTeclado *jogador_inicio = p->jogador_atual;
    int end_game = 0;
    int qtd_jogadas = 0;
    char jogar_novamente = 'N';
    while (qtd_jogadas < 9 && !end_game) {

        if (qtd_jogadas == 0) {
            jogador_inicio = p->jogador_atual;
        }
        qtd_jogadas++;
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

        if (p->jogador_atual == &(p->j2) && p->vs_ia) {
            ia_joga((JogadorIA *)p->jogador_atual, &(p->tabuleiro));
        } else {
            jogador_teclado_joga(p->jogador_atual, &(p->tabuleiro));
        }
        
        tabuleiro_desenha(&(p->tabuleiro));

        int resultado = tabuleiro_temVencedor(&(p->tabuleiro));
        if (resultado == JOGADOR_X){
            printf("Jogador 1 (X) é o vencedor!\n");
            end_game = 1;
        } else if (resultado == JOGADOR_O) {
            printf("Jogador 2 (O) é o vencedor!\n");
            end_game = 1;
        } else if (resultado == VAZIO && qtd_jogadas == 9) {
            printf("Empate, deu velha!\n");
            end_game = 1;
        }

        if (end_game) {
            do {
                printf("\nJogar novamente? (S/N)  ");
                scanf(" %c", &jogar_novamente);

                if (jogar_novamente == 'S') {
                    p->jogador_atual = jogador_inicio;
                    qtd_jogadas = 0;
                    end_game = 0;
                    tabuleiro_inicializa(&(p->tabuleiro));
                } else if (jogar_novamente != 'N') {
                    printf("Opção inválida!\n");
                }
            } while (jogar_novamente != 'S' && jogar_novamente != 'N');
        }
        
        if (p->jogador_atual == &(p->j1)) {
            p->jogador_atual = &(p->j2);
        } else {
            p->jogador_atual = &(p->j1);
        }
    }
}
