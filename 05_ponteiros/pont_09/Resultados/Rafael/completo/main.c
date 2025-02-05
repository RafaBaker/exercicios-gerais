#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

int main(int argc, char const *argv[])
{
    int qtd;
    scanf("%d\n", &qtd);
    tPessoa pessoas[qtd];

    for (int i = 0; i < qtd; i++)
    {
        tPessoa pessoa = CriaPessoa();
        LePessoa(&pessoa);
        //printf("Pessoa %s lida\n", pessoa);
        pessoas[i] = pessoa;
    }

    AssociaFamiliasGruposPessoas(pessoas);
    for (int i = 0; i < qtd; i++)
    {
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}
