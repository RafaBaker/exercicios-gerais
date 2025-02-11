
#include "operacao.h"
#include "conta.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Operacao
{
    tConta* conta;
    float valor;  
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tOperacao. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero (exceto aquelas passadas como parâmetro para a função).
 *
 * @param conta - A conta que será associada a uma operação
 * @param valor - O valor da operação
 *
 * @return A variável do tipo tOperacao inicializada.
 */
tOperacao* CriaOperacao(tConta* conta, float valor)
{
    tOperacao* op = (tOperacao*)malloc(sizeof(tOperacao));
    assert(op && "Erro ao alocar operação");

    //op->conta = (tConta*)malloc(sizeof(conta));
    op->conta = conta;

    op->valor = valor;

    return op;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma operacao.
 *
 * @param A variável do tipo tOperacao que será apagada.
 */
void DestroiOperacao(tOperacao* op)
{
    if (op != NULL)
    {
        free(op);
        op = NULL;
    }
}


/**
 * @brief Consulta o valor de uma operação especifica
 *
 * @param op - A operacao que queremos consultar o valor
 * @return O valor da operação cadastrada
 */
float ConsultaValorOperacao(tOperacao* op)
{
    return op->valor;
}


/**
 * @brief Imprime a operação. Ver formato nos exemplos de saída e/ou roteiro.
 *
 * @param op - A operacao que queremos imprimir
 */
void ImprimeOperacao(tOperacao* op)
{
    int id = RetornaIdConta(op->conta);
    printf("\nOperação na conta %d com valor %.2f", id, op->valor);
}

