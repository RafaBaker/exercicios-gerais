#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "base_alunos.h"
#include "aluno.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos
{
    tAluno** alunos;
    int qtd;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos* base = malloc(sizeof(tBaseAlunos));

    base->alunos = NULL;
    base->qtd = 0;

    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    if (baseAlunos)
    {
        if (baseAlunos->alunos)
        {
            for (int i = 0; i < baseAlunos->qtd; i++)
            {
                DestruirAluno(baseAlunos->alunos[i]);
            }
            free(baseAlunos->alunos);
        }
        baseAlunos->alunos = NULL;
        free(baseAlunos);
    }
    baseAlunos = NULL;
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    int qtd;
    FILE* arquivo_binario;

    arquivo_binario = fopen(nomeArquivo, "r");
    if (arquivo_binario == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    fread(&qtd, sizeof(int), 1, arquivo_binario);
    //printf("qtd: %d\n", qtd);

    baseAlunos->qtd = qtd;
    baseAlunos->alunos = malloc(sizeof(tAluno*)*qtd);
    for (int i = 0; i < qtd; i++)
    {
        baseAlunos->alunos[i] = LeAluno(arquivo_binario);
    }

    fclose(arquivo_binario);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float total = 0;
    for (int i = 0; i < baseAlunos->qtd; i++)
    {
        total += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return total / (float)baseAlunos->qtd;
}