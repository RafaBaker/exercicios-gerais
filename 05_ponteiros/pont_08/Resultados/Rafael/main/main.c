#include "tDepartamento.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int qtdDep;
    char nome[STRING_MAX];
    char diretor[STRING_MAX];
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    int m1, m2, m3;
    tDepartamento dep;

    scanf("%d", &qtdDep);
    scanf("[^\n]");
    scanf("%*c");

    tDepartamento deps[qtdDep];

    for (int i = 0; i < qtdDep; i++)
    {
        scanf("%[^\n]s", nome);
        scanf("[^\n]");
        scanf("%*c");

        scanf("%[^\n]s", diretor);
        scanf("[^\n]");
        scanf("%*c");

        scanf("%[^\n]s", curso1);
        scanf("[^\n]");
        scanf("%*c");

        scanf("%[^\n]s", curso2);
        scanf("[^\n]");
        scanf("%*c");

        scanf("%[^\n]s", curso3);
        scanf("[^\n]");
        scanf("%*c");

        scanf("%d %d %d", &m1, &m2, &m3);
        scanf("[^\n]");
        scanf("%*c");

        dep = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
        deps[i] = dep;
    }
    OrdenaDepartamentosPorMedia(deps, qtdDep);
    for (int i = 0; i < qtdDep; i++)
    {
        ImprimeAtributosDepartamento(deps[i]);
    }


    return 0;
}