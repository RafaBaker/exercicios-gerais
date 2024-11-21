#include "jogador.h"
#include "tabuleiro.h"

typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    
} tJogo;

tJogo CriaJogo()
{
    tJogo jogo;
    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    tTabuleiro tab = CriaTabuleiro();
    tJogador jog1 = CriaJogador(ID_JOGADOR_1);
    tJogador jog2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = tab;
    jogo.jogador1 = jog1;
    jogo.jogador2 = jog2;
    int vez = ID_JOGADOR_1;
    int vencedor = 0;

    while(!AcabouJogo(jogo))
    {
        if (vez == ID_JOGADOR_1)
        {
            tab = JogaJogador(jog1, tab);
            ImprimeTabuleiro(tab);
            if (VenceuJogador(jog1, tab))
            {
                vencedor = ID_JOGADOR_1;
                break;
            }
            vez = ID_JOGADOR_2;
        }
        else if (vez == ID_JOGADOR_2)
        {
            tab = JogaJogador(jog2, tab);
            ImprimeTabuleiro(tab);
            if (VenceuJogador(jog2, tab))
            {
                vencedor = ID_JOGADOR_2;
                break;
            }
            vez = ID_JOGADOR_1;
        }
        jogo.tabuleiro = tab;
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


int AcabouJogo(tJogo jogo)
{
    return !(TemPosicaoLivreTabuleiro(jogo.tabuleiro));
}

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
