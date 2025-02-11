#include "agencia.h"
#include "conta.h"
#include "operacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Agencia
{
    tConta **contas;
    int qtdContas;
    tOperacao **operacoes;
    int qtdOP;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia *CriaAgencia()
{
    tAgencia *agencia = (tAgencia *)malloc(sizeof(tAgencia));

    agencia->contas = malloc(sizeof(tConta *));
    agencia->qtdContas = 0;

    agencia->operacoes = malloc(sizeof(tOperacao *));
    agencia->qtdOP = 0;

    return agencia;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia *agencia)
{
    if (agencia != NULL)
    {
        if (agencia->contas != NULL)
        {
            for (int i = 0; i < agencia->qtdContas; i++)
            {
                DestroiConta(agencia->contas[i]);
                agencia->contas[i] = NULL;
            }
            free(agencia->contas);
        }

        if (agencia->operacoes != NULL)
        {
            for (int i = 0; i < agencia->qtdOP; i++)
            {
                DestroiOperacao(agencia->operacoes[i]);
                agencia->operacoes[i] = NULL;
            }
            free(agencia->operacoes);
        }

        free(agencia);
        agencia = NULL;
    }
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia)
{
    // char buffer[100];
    // scanf("%[^\n]s", buffer);
    // printf("\nbuffer: %s", buffer);
    int qtd, id = 0, i = 0, flag = 0;
    float valor = 0;
    scanf("%d", &qtd);

    // Registrando as contas
    while (1)
    {
        flag = 0;
        scanf("%d", &id);
        if (id <= 0)
        {
            printf("\nDigite um id valido para a conta a ser cadastrada!");
            continue;
        }
        for (i = 0; i < agencia->qtdContas; i++)
        {
            if (ConfereIdConta(agencia->contas[i], id))
            {
                printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
                flag = 1;
                break;
            }
        }

        if (flag)
            continue;

        agencia->contas = realloc(agencia->contas, sizeof(tConta *) * (agencia->qtdContas + 1));
        agencia->contas[agencia->qtdContas] = CriaConta(id);
        agencia->qtdContas++;
        if (agencia->qtdContas == qtd)
            break;
    }

    // Registrando as operações
    tConta *aux = NULL;
    char buffer[100];
    scanf("%d", &qtd);
    // scanf("%*c");
    // scanf("%[^\n]s", buffer);
    // printf("\nbuffer: %s", buffer);
    //scanf("%*c");
    // while (scanf("%d %f", &id, &valor) == 2)

    while (1)
    {
        scanf("%d %f", &id, &valor);
        //printf("\nid: %d valor: %.2f", id, valor);
        aux = BuscaContaPorId(agencia, id);
        if (aux != NULL)
        {
            agencia->operacoes = realloc(agencia->operacoes, sizeof(tOperacao*)*(agencia->qtdOP+1));
            agencia->operacoes[agencia->qtdOP] = CriaOperacao(aux, valor);
            agencia->qtdOP++;
            
            //alterando o saldo da conta
            AlteraSaldoConta(aux, valor);
        }
        else 
        {
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
            // printf("\nid:%d valor:%.2f", id, valor);
        }
        if (agencia->qtdOP == qtd)
            break;
    }   
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta *BuscaContaPorId(tAgencia *agencia, int id)
{
    for (int i = 0; i < agencia->qtdContas; i++)
    {
        if (ConfereIdConta(agencia->contas[i], id))
        {
            return agencia->contas[i];
        }
    }
    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia *agencia)
{
    printf("\nA lista de operações suspeitas:");
    for (int i = 0; i < agencia->qtdOP; i++)
    {
        float valor = ConsultaValorOperacao(agencia->operacoes[i]);
        if (valor >= 20000 || valor <= -20000)
        {
            ImprimeOperacao(agencia->operacoes[i]);
        }
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia)
{
    printf("\nOs dois correntistas com maior saldo são:");
    //achando o maior
    int maiorId = 0;
    float maiorVal = 0, atualVal = 0;
    for (int i = 0; i < agencia->qtdContas; i++)
    {
        atualVal = RetornaSaldoConta(agencia->contas[i]);
        if (atualVal > maiorVal)
        {
            maiorVal = atualVal;
            maiorId = i;
        }
    }

    printf("\nId: %d, Saldo: %.2f", RetornaIdConta(agencia->contas[maiorId]), maiorVal);
    
    //achando o segundo maior
    int segId = 0;
    float segVal = 0;
    for (int i = 0; i < agencia->qtdContas; i++)
    {
        if (i == maiorId)
        {
            continue;
        }
        atualVal = RetornaSaldoConta(agencia->contas[i]);
        if (atualVal > segVal)
        {
            segVal = atualVal;
            segId = i;
        }
    }
    printf("\nId: %d, Saldo: %.2f", RetornaIdConta(agencia->contas[segId]), segVal);
}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia *agencia)
{
    float total = 0;
    for (int i = 0; i < agencia->qtdContas; i++)
    {
        total += RetornaSaldoConta(agencia->contas[i]);
    }
    printf("\nO saldo total da agencia eh: %.2f", total);
}
