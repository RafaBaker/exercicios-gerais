#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "estabelecimento.h"

int main(int argc, char const *argv[])
{
    tEstabelecimento* estab = CriaEstabelecimento();
    LeEstabelecimento(estab);
    ImprimeProdutosEmFaltaEstabelecimento(estab);
    DestroiEstabelecimento(estab);
    return 0;
}
