#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno
{
    char nome[100];
    char dtNasc[11];
    char curso[50];
    int periodo;
    float coeficiente;    
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dtNasc, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->coeficiente = coeficienteRendimento;
    aluno->periodo = periodo;

    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    if (aluno)
    {
        free(aluno);
    }
    aluno = NULL;
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[100];
    char dtNasc[11];
    char curso[50];
    int periodo = 0;
    float coeficiente = 0;   

    fread(nome, sizeof(char), 100, arquivo_binario);
    //printf("nome: %s\n", nome);
    fread(dtNasc, sizeof(char), 11, arquivo_binario);
    //printf("dtNasc: %s\n", dtNasc);
    fread(curso, sizeof(char), 50, arquivo_binario);
    //printf("curso: %s\n", curso);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    //printf("periodo: %d\n", periodo);
    fread(&coeficiente, sizeof(float), 1, arquivo_binario);
    //printf("coeficiente: %.2f\n", coeficiente);

    tAluno* aluno = CriarAluno(nome, dtNasc, curso, periodo, coeficiente);
    return aluno;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->coeficiente;
}
