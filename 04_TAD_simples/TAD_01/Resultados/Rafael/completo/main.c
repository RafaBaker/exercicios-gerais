#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

int main(int argc, char const *argv[])
{
    tJogo jogo = CriaJogo();
    ComecaJogo(jogo);
    while (ContinuaJogo())
    {
        ComecaJogo(jogo);
    }
    return 0;
}
