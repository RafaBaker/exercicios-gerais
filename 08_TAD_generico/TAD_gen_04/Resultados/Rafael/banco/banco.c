#include "banco.h"
#include "agencia.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco
{
    char nome[50];
    tAgencia** agencias;
    int qtdAgencias;
    int qtdMax;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{
    tBanco* banco = (tBanco*)malloc(sizeof(tBanco));
    assert(banco && "Erro ao alocar banco");

    banco->qtdMax = 10;
    banco->qtdAgencias = 0;

    banco->agencias = (tAgencia**)malloc(sizeof(tAgencia*)*banco->qtdMax);

    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    if (banco != NULL)
    {
        if (banco->agencias != NULL)
        {
            for (int i = 0; i < banco->qtdAgencias; i++)
            {
                DestroiAgencia(banco->agencias[i]);
            }
            free(banco->agencias);
            banco->agencias = NULL;
        }
        free(banco);
    }
    banco = NULL;
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{
    scanf("%[^\n]", banco->nome);
    scanf("%*c");
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    if (banco->qtdAgencias == banco->qtdMax)
    {
        banco->qtdMax *= 2;
        banco->agencias = realloc(banco->agencias, sizeof(tAgencia*)*banco->qtdMax);
    }
    banco->agencias[banco->qtdAgencias] = agencia;
    banco->qtdAgencias++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
 */
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    for (int i = 0; i < banco->qtdAgencias; i++)
    {
        if(ComparaAgencia(numAgencia, banco->agencias[i]))
        {
            AdicionaConta(banco->agencias[i], cliente);
        }
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for (int i = 0; i < banco->qtdAgencias; i++)
    {
        ImprimeDadosAgencia(banco->agencias[i]);
        printf("\n");
    }
}
