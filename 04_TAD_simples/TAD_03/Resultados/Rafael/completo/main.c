#include <stdio.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

int main(int argc, char const *argv[])
{
    char op[MAX_CARACTERES];
    char c;
    tLocadora locadora = criarLocadora();

    while (scanf("%s", op) == 1)
    {
        //printf("op: %s\n", op);
        scanf("[^\n]");
        scanf("%*c");
        if (!strcmp(op, "Cadastrar"))
        {
            locadora = lerCadastroLocadora(locadora);
        }
        else if (!strcmp(op, "Alugar"))
        {
            locadora = lerAluguelLocadora(locadora);
        }
        else if (!strcmp(op, "Devolver"))
        {
            locadora = lerDevolucaoLocadora(locadora);
        }
        else if (!strcmp(op, "Estoque"))
        {
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora(locadora);
        }
        scanf("[^#]");
        scanf("%c", &c);
        //printf("c: %c\n", c);
        if (c == '#')
            scanf("%c", &c);
        //printf("c: %c", c);
        printf("\n");
    }
    //printf("op: %s\n", op);
    consultarLucroLocadora(locadora);
    return 0;
}
