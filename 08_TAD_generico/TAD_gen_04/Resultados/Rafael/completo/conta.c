#include "conta.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar uma conta bancária.
 */
struct Conta{
    int num;
    float saldo;
    char nome[50];
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta()
{
    tConta* conta = (tConta*)malloc(sizeof(tConta));
    assert(conta && "erro ao alocar conta");

    conta->saldo = 0;
    conta->num = 0;
    conta->nome[0] = '\0';

    return conta;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta)
{
    if (conta != NULL)
    {
        free(conta);
    }
    conta = NULL;
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta)
{
    scanf("%d;%[^;];%f", &conta->num, conta->nome, &conta->saldo);
    scanf("[^\n]");
    scanf("%*c");
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta)
{
    return conta->saldo;
}
