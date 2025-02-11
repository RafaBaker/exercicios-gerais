#include "sistema.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Sistema
{
    char** tickets;
    int qtdTickets;
    float faturamento;
};

/**
 * @brief Cria um sistema de gerenciamento de tíquetes de um estacionamento
 * 
 * @return Uma variável do tipo tSistema;
 */
tSistema* CriaSistema()
{
    tSistema* sys = (tSistema*)malloc(sizeof(tSistema));
    sys->qtdTickets = 0;
    sys->faturamento = 0;
    sys->tickets = (char**)malloc(sizeof(char*));
    return sys;
}

/**
 * @brief Libera toda a memória necessária para armazenar um sistema de gerenciamento do estacionamento.
 * 
 * @param sys - Variável que terá sua memória liberada
 */
void DestroiSistema(tSistema* sys)
{
    if (sys != NULL)
    {
        if (sys->tickets != NULL)
        {
            for (int i = 0; i < sys->qtdTickets; i++)
            {
                if (sys->tickets[i] != NULL)
                    free(sys->tickets[i]);
            }
            free(sys->tickets);
        }
        free(sys);
    }
}

/**
 * @brief Lê os dados do sistema e os tíquetes a serem processados
 * 
 * @param sys - A variável que armazenará os dados do sistema e os tíquetes

 */
void LeSistema(tSistema* sys)
{

}

/**
 * @brief Processa um tíquete e faz as contas para saber o valor que o motorista deve pagar.
 * 
 * @param sys A variável que representa o sistema e seus dados.
 * @param dataEntrada - Uma variável que representa os dados da data de entrada do tíquete processado
 * @param dataSaida - Uma variável que representa os dados da data de saída do tíquete processado.
 * @return Um número real que representa o preço de um ticket específico que tem dataEntrada e foi faturado na dataSaida
 */
float CalculaPrecoTiquete(tSistema* sys, tData* dataEntrada, tData* dataSaida)
{
    return 1.0;
}

/**
 * @brief Imprime o faturamento de um sistema.
 * 
 * @param sys O sistema que terá seu faturamento impresso em tela
 */
void ImprimeFaturamentoSistema(tSistema *sys)
{
    
}

