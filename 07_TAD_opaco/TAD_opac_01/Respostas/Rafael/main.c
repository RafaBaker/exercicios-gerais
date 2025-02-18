#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "jogada.h"
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

int main(int argc, char const *argv[])
{
    tJogo* jogo = CriaJogo();
    ComecaJogo(jogo);
    while (ContinuaJogo())
    {
        DestroiJogo(jogo);
        jogo = CriaJogo();
        ComecaJogo(jogo);
    }
    DestroiJogo(jogo);
    return 0;
}
