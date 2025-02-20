#include "tadgen.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("tad_gen_01\n");

    int qtd=0, tipo=-1;
    printf("Digite o tipo e numero de elementos: \n");
    scanf("%d %d", &tipo, &qtd);

    tGeneric* gen = CriaGenerico(tipo, qtd);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}
