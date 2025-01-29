#include <stdio.h>
#include "aluno.h"

int main () 
{
    int qtd = 0;    
    scanf("%d ", &qtd);
    tAluno* alunos[qtd];

    for (int i = 0; i < qtd; i++)
    {
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        alunos[i] = aluno;
    }

    int menor;
    for (int i = 0; i < qtd-1; i++)
    {
        menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (ComparaMatricula(alunos[menor], alunos[j]) == 1) {
                menor = j;
            }
        }
        tAluno* aux = alunos[i];
        alunos[i] = alunos[menor];
        alunos[menor] = aux;
    }

    for (int i = 0; i < qtd; i++)
    {
        if (VerificaAprovacao(alunos[i]))
        {
            ImprimeAluno(alunos[i]);
        }
    }

    for (int i = 0; i < qtd; i++)
    {
        ApagaAluno(alunos[i]);
        alunos[i] = NULL;
    }
    
    return 0;
}