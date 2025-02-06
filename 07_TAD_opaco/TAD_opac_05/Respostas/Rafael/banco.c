#include "conta.h"
#include "usuario.h"
#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Banco
{
    int qtdContas;
    int contasAlocadas;
    tConta **contas;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco* banco = (tBanco*)malloc(sizeof(tBanco));
    assert(banco && "Erro ao criar a conta");
    banco->contasAlocadas = 5;
    banco->qtdContas = 0;
    banco->contas = (tConta**)malloc(sizeof(tConta*)*(banco->contasAlocadas));
    //printf("sizeof(tConta*) %d\n", sizeof(tConta*));
    for (int i = 0; i < banco->contasAlocadas; i++)
    {
        //assert(banco->contas[i] && "sla o que deu");
        banco->contas[i] = NULL;
        banco->contas[i] = CriaConta();
        //printf("Conta [%d] criada: %p\n", i, (void*)banco->contas[i]);
    }
    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    int i;
    if (banco != NULL)
    {
        for (i = 0; i < banco->contasAlocadas; i++)
        {
            //printf("Liberei a conta na posição [%d]\n", i);
            //ImprimeConta(banco->contas[i]);
            if (banco->contas[i] != NULL)
            {
                //printf("Destruindo conta na posição [%d]: %p\n", i, (void*)banco->contas[i]);
                DestroiConta(banco->contas[i]);
                banco->contas[i] = NULL;
            }
            else
            {
                printf("Conta nula!\n");
            }
        }
        free(banco->contas);
        free(banco);
    }
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    LeConta(banco->contas[banco->qtdContas]);
    //printf("conta criada!: \n");
    //ImprimeConta(banco->contas[banco->qtdContas]);
    banco->qtdContas++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int numero;
    float saque;

    scanf("%d %f ", &numero, &saque);

    int i;
    for (i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero))
        {
            SaqueConta(banco->contas[i], saque);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int numero;
    float deposito;

    scanf("%d %f ", &numero, &deposito);

    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero))
        {
            //printf("Feito o depósito na conta: %d no valor de %.2f\n ", numero, deposito);
            DepositoConta(banco->contas[i], deposito);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int numOrigem, numDestino, indexOrigem = -1, indexDestino = -1;
    float valor;

    scanf("%d %d %f ", &numDestino, &numOrigem, &valor);

    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numOrigem))
        {
            indexOrigem = i;
            break;
        }
    }
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numDestino))
        {
            indexDestino = i;
            break;
        }
    }

    //printf("Transferencia feita: Conta %d para Conta %d no valor de %.2f\n", indexOrigem, indexDestino, valor);
    TransferenciaConta(banco->contas[indexDestino], banco->contas[indexOrigem], valor);
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
    }
}
