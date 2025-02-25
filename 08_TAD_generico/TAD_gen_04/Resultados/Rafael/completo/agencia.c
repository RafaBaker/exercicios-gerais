#include "agencia.h"
#include "conta.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    int num;
    char nome[50];
    Vector* contas;
    // int qtdContas;
    // int qtdMax;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia* agencia = (tAgencia*)malloc(sizeof(tAgencia));
    assert(agencia && "Erro ao alocar agencia");

    // agencia->qtdMax = 10;
    // agencia->qtdContas = 0;

    agencia->contas = VectorConstruct();
    assert(agencia->contas && "erro ao alocar contas na agencia");

    agencia->nome[0] = '\0';
    agencia->num = 0;

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    if (agencia != NULL)
    {
        tAgencia* ag = (tAgencia*)agencia;

        VectorDestroy(ag->contas, DestroiConta);

        free(agencia);
    }
    agencia = NULL;
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]", &agencia->num, agencia->nome);
    scanf("%*c");
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return numAgencia == agencia2->num;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float total = 0, media;
    int qtd;
    for (int i = 0; i < VectorSize(agencia->contas); i++)
    {
        total += GetSaldoConta(VectorGet(agencia->contas, i));
    }
    media = total/(float)VectorSize(agencia->contas);
    return media;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("\tNome: %s\n", agencia->nome);
	printf("\tNumero: %d\n", agencia->num);
	printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
	printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}
