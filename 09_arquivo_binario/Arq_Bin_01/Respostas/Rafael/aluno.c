#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct aluno
{
    char nome[100];
    char dataNasc[20];
    char cursoUfes[50];
    char periodoIngresso[20];
    int perConclusao;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos)
{
    Aluno** alunos = (Aluno**)malloc(sizeof(Aluno*)*numeroAlunos);

    for (int i = 0; i < numeroAlunos; i++)
    {
        alunos[i] = NULL;
    }

    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNasc, dtNasc);
    strcpy(aluno->cursoUfes, cursoUfes);
    strcpy(aluno->periodoIngresso, periodoIngresso);
    aluno->perConclusao = percConclusao;
    aluno->CRA = CRA;

    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
    char nome[100];
    char dataNasc[20];
    char cursoUfes[50];
    char periodoIngresso[20];
    int perConclusao;
    float CRA;

    scanf("%[^\n]s", nome);
    scanf("%*c");
    scanf("%[^\n]s", dataNasc);
    scanf("%*c");
    scanf("%[^\n]s", cursoUfes);
    scanf("%*c");
    scanf("%[^\n]s", periodoIngresso);
    scanf("%*c");

    scanf("%d\n", &perConclusao);
    scanf("%f\n", &CRA);

    vetorAlunos[numeroAlunos] = CriaAluno(nome, dataNasc, cursoUfes, periodoIngresso, perConclusao, CRA);
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
    if (alunos)
    {
        for (int i = 0; i < numeroAlunos; i++)
        {
            if (alunos[i])
            {
                free(alunos[i]);
            }
            alunos[i] = NULL;
        }
        free(alunos);
    }
    alunos = NULL;
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        
    }
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{

}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{

}
