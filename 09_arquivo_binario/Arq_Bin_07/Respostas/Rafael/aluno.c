#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Aluno
{
    char* nome;
    char* dataNascimento;
    char* curso;
    float prctConclusao;
    float cfRendimento;
};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));

    aluno->nome = malloc(sizeof(char)*(strlen(nome)+1));
    aluno->dataNascimento = malloc(sizeof(char)*(strlen(dataNascimento)+1));
    aluno->curso = malloc(sizeof(char)*(strlen(curso)+1));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->prctConclusao = prctConclusao;
    aluno->cfRendimento = cfRendimento;

    return aluno;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno)
{
    if (aluno)
    {
        if (aluno->nome)
        {
            free(aluno->nome);
        }
        aluno->nome = NULL;
        
        if (aluno->dataNascimento)
        {
            free(aluno->dataNascimento);
        }
        aluno->dataNascimento = NULL;

        if (aluno->curso)
        {
            free(aluno->curso);
        }
        aluno->curso = NULL;

        free(aluno);
    }
    aluno = NULL;
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno()
{
    char nome[100];
    char dataNascimento[20];
    char curso[50];
    float prctConclusao;
    float cfRendimento;

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", dataNascimento);
    scanf("%*c");

    scanf("%[^\n]", curso);
    scanf("%*c");

    scanf("%f\n", &prctConclusao);
    scanf("%f\n", &cfRendimento);
    
    tAluno* a = CriaAluno(nome, dataNascimento, curso, prctConclusao, cfRendimento);
    return a;
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{
    return strcmp(aluno1->nome, aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file)
{
    int numBytes = 0;

    numBytes += fwrite(aluno->nome, sizeof(char), sizeof(aluno->nome), file);
    numBytes += fwrite(aluno->dataNascimento, sizeof(char), sizeof(aluno->dataNascimento), file);
    numBytes += fwrite(aluno->curso, sizeof(char), sizeof(aluno->curso), file);
    numBytes += fwrite(&aluno->prctConclusao, sizeof(float), 1, file);
    numBytes += fwrite(&aluno->cfRendimento, sizeof(float), 1, file);

    return numBytes;
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file)
{
    int numBytes = 0;

    numBytes += fread(aluno->nome, sizeof(char), sizeof(aluno->nome), file);
    numBytes += fread(aluno->dataNascimento, sizeof(char), sizeof(aluno->dataNascimento), file);
    numBytes += fread(aluno->curso, sizeof(char), sizeof(aluno->curso), file);
    numBytes += fread(&aluno->prctConclusao, sizeof(float), 1, file);
    numBytes += fread(&aluno->cfRendimento, sizeof(float), 1, file);

    return numBytes;
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno)
{
    printf("Aluno: %s\n", aluno->nome);
}
