#include <stdio.h>

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';
    int i,j;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    if (peca == PECA_1)
    {
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    }
    else if (peca == PECA_2)
    {
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;
    }
    return tabuleiro;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
                return 1;
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1)
    {
        if (tabuleiro.posicoes[y][x] == tabuleiro.peca1)
            return 1;
    }
    else if (peca == PECA_2)
    {
        if (tabuleiro.posicoes[y][x] == tabuleiro.peca2)
            return 1;
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if (tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio)
        return 1;
    return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y)
{
    return x <= 2 && x >= 0 && y <= 2 && y >= 0;
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");
        for (j = 0; j< TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}


