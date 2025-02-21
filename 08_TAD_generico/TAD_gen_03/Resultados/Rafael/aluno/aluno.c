#include "aluno.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Aluno
{
    char nome[50];
    float nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno()
{
    tAluno* aluno = malloc(sizeof(tAluno));
    assert(aluno && "Erro ao alocar aluno");

    aluno->nome[0] = '\0';
    aluno->nota = 0.0;
    aluno->genero = 'R';

    return aluno;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno)
{
    if (aluno != NULL)
    {
        free(aluno);
    }
    aluno = NULL;
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno)
{
    // char buffer[100];
    // scanf("%[^\n]s", buffer);
    // scanf("%*c");
    // printf("Buffer: %s\n", buffer);
    scanf("%[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
    //printf("aluno->nome: %s\n", aluno->nome);
    scanf("[^\n]");
    scanf("%*c");
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno)
{
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno)
{
    return aluno->nota;
}

