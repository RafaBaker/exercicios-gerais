#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

int main(int argc, char const *argv[])
{
    int qtdPessoas, qtdAssoc;
    scanf("%d\n", &qtdPessoas);
    tPessoa pessoas[qtdPessoas];
    tPessoa pessoas2[qtdPessoas];

    for (int i = 0; i < qtdPessoas; i++)
    {
        tPessoa pessoa = CriaPessoa();
        LePessoa(&pessoa);
        //printf("Pessoa %s lida\n", pessoa);
        pessoas[i] = pessoa;
    }

    // scanf("%d", &qtdAssoc);
    // //printf("qtd:%d\n", qtdAssoc);
    // scanf("^[\n]");
    // scanf("%*c");

    // char test[50];
    // scanf("%[^\n]s", test);
    // printf("%s\n", test);
    
    AssociaFamiliasGruposPessoas(pessoas, qtdPessoas);
    for (int i = 0; i < qtdPessoas; i++)
    {
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}
