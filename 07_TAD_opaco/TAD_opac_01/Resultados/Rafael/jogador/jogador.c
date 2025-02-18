
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Jogador
{
    int id;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador)
{
    tJogador* jogador = (tJogador*)malloc(sizeof(tJogador));
    assert(jogador && "Erro ao alocar jogador");

    jogador->id = idJogador;

    return jogador;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador)
{
    if (jogador != NULL)
    {
        free(jogador);
    }
    jogador = NULL;
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    int peca = jogador->id;
    tJogada* jogada = CriaJogada();
    while (1)
    {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
        if (FoiJogadaBemSucedida(jogada))
        {
            int x = ObtemJogadaX(jogada);
            int y = ObtemJogadaY(jogada);
            if (EhPosicaoValidaTabuleiro(x, y))
            {
                if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
                {
                    MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
                    printf("Jogada [%d,%d]!\n", x, y);
                    break;
                }
                else 
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
                }
            }
            else
            {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            }
        }
    }
    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    int i, j;
    int peca = jogador->id;
    //Checando verticais
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca)))
                break;
        }
        if (j == 3)
        {
            return 1;
        }
    }
    //Checando horizontais
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, peca)))
                break;
        }
        if (j == 3)
        {
            return 1;
        }
    }
    //Checando diagonal 1
    for (i = 0, j = 0; i < TAM_TABULEIRO, j < TAM_TABULEIRO; i++, j++)
    {
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca)))
            break;
    }
    if (i == 3 && j == 3)
        return 1;
    
    //Checando diagonal 2
    for (i = 2, j = 0; i >= 0, j < TAM_TABULEIRO; i--, j++)
    {
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca)))
            break;
    }
    if (i == -1 && j == 3)
        return 1;

    return 0;
}
