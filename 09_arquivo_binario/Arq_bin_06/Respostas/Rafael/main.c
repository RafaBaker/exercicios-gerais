#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "estabelecimento.h"

int main(int argc, char const *argv[])
{
    tEstabelecimento* e = CriaEstabelecimento();

    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);
    
    return 0;
}
