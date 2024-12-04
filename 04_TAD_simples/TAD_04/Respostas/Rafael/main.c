#include <stdio.h>
#include "aluno.h"

int main(int argc, char const *argv[])
{
    int n, i;
    tAluno aluno;

    scanf("%d", &n);
    scanf("%*c");
    tAluno alunos[n];
    for (i = 0; i < n; i++)
    {
        aluno = LeAluno();
        alunos[i] = aluno;
    }
    
    tAluno aux;
    int j, menor;
    for (i = 0; i < n-1; i++)
    {
        menor = i;
        for (j = i; j < n; j++)
        {
            if (ComparaMatricula(alunos[j], alunos[menor]) < 0)
                menor = j;
        }
        aux = alunos[i];
        alunos[i] = alunos[menor];
        alunos[menor] = aux;
    }

    for (i = 0; i < n; i++)
    {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }

    return 0;
}
