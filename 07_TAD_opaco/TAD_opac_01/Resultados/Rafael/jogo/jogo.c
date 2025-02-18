#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Jogo
{
    tTabuleiro* tabuleiro;
    tJogador* jogador1;
    tJogador* jogador2;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo()
{
    tJogo* jogo = (tJogo*)malloc(sizeof(tJogo));
    assert(jogo && "Erro ao alocar jogo");
    
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo)
{
    int vez = ID_JOGADOR_1, vencedor = 0;
    while (!AcabouJogo(jogo))
    {
        if (vez == ID_JOGADOR_1)
        {
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
            if (VenceuJogador(jogo->jogador1, jogo->tabuleiro))
            {
                vencedor = ID_JOGADOR_1;
                break;
            }
            vez = ID_JOGADOR_2;
        }

        else if (vez == ID_JOGADOR_2)
        {
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
            if (VenceuJogador(jogo->jogador2, jogo->tabuleiro))
            {
                vencedor = ID_JOGADOR_2;
                break;
            }
            vez = ID_JOGADOR_1;
        }
    }
    if (vencedor)
    {
        printf("JOGADOR %d Venceu!\n", vencedor);
    }
    else 
    {
        printf("Sem vencedor!\n"); 
    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo)
{
    return !(TemPosicaoLivreTabuleiro(jogo->tabuleiro));
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char c;
    printf("Jogar novamente? (s,n)\n");
    while (1)
    {
        scanf("[^\n]");
        scanf("%*c");
        scanf("%c", &c);
        if (c == 's' || c == 'n') return c == 's';
    }
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    if (jogo != NULL)
    {
        DestroiJogador(jogo->jogador1);
        DestroiJogador(jogo->jogador2);
        DestroiTabuleiro(jogo->tabuleiro);

        free(jogo);
    }
    jogo = NULL;
}
