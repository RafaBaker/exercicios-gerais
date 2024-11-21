#include "tabuleiro.h"
#include "jogada.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2


typedef struct{
    int id;
} tJogador;

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador j;
    j.id = idJogador;
    return j;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int peca = jogador.id;
    tJogada jogada;
    while (1)
    {
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
        if (FoiJogadaBemSucedida(jogada))
        {
            int x = ObtemJogadaX(jogada);
            int y = ObtemJogadaY(jogada);
            if (EhPosicaoValidaTabuleiro(x, y))
            {
                if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
                {
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
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
    
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int i, j;
    int peca = jogador.id;
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

