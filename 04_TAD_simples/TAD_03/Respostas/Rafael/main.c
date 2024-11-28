#include <stdio.h>
#include "locadora.h"
#include "filme.h"

int main(int argc, char const *argv[])
{
    char op[MAX_CARACTERES];
    tLocadora locadora = criarLocadora();

    while (scanf("%[^\n]s", op) == 1)
    {
        if (op == "Cadastrar")
        {
            locadora = lerCadastroLocadora(locadora);
        }
    }
    return 0;
}
