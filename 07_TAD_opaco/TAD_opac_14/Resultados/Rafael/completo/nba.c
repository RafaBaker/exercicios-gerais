#include "partida.h"
#include "franquia.h"
#include "nba.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct nba
{
    tFranquia *listafranquias;
    int qtdfranquias, maxfranquias;

    tPartida *listapartidas;
    int qtdpartidas, maxpartidas;
};

/**
 * @brief Cria uma nova instância da NBA.
 *
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA()
{
    tNBA nba = (tNBA)malloc(sizeof(struct nba));
    assert(nba && "Erro ao alocar NBA");
    
    nba->qtdfranquias = 0;
    nba->qtdpartidas = 0;
    nba->maxfranquias = MAX_FR;
    nba->maxpartidas = MAX_PT;

    nba->listafranquias = (tFranquia*)malloc(sizeof(tFranquia)*MAX_FR*2);
    assert(nba->listafranquias && "Erro ao alocar vetor de franquias");
    for (int i = 0; i < nba->maxfranquias; i++)
    {
        nba->listafranquias[i] = NULL;
    }

    nba->listapartidas = (tPartida*)malloc(sizeof(tPartida)*MAX_PT*2);
    assert(nba->listapartidas && "Erro ao alocar vetor de partidas");
    for (int i = 0; i < nba->maxpartidas; i++)
    {
        nba->listapartidas[i] = NULL;
    }

    return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 *
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba)
{
    char controle;
    scanf("%c", &controle);
    scanf("%*c");
    while (controle != 'E')
    {
        switch (controle)
        {
        case 'E':
            return nba;
            break;
        case 'F':
            nba->listafranquias[nba->qtdfranquias] = LeFranquia();
            nba->qtdfranquias++;
            break;
        case 'P':
            nba->listapartidas[nba->qtdpartidas] = LePartida();
            nba->qtdpartidas++;
            break;
        default:
            break;
        }

        scanf("%c", &controle);
    }
    return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba)
{
    int vLeste = 0, vOeste = 0, aux = 0;
    //tFranquia time1; 

    for (int i = 0; i < nba->qtdpartidas; i++)
    {
        //vencedor
        aux = GetVencedorPartida(nba->listapartidas[i]);
    }
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba)
{
    if (nba != NULL)
    {
        if (nba->listafranquias != NULL)
        {
            for (int i = 0; i < nba->qtdfranquias; i++)
            {
                if (nba->listafranquias[i] != NULL)
                    LiberaFranquia(nba->listafranquias[i]);
            }
            free(nba->listafranquias);
        }

        if (nba->listapartidas != NULL)
        {
            for (int i = 0; i < nba->qtdpartidas; i++)
            {
                if (nba->listapartidas[i] != NULL)
                    LiberaPartida(nba->listapartidas[i]);
            }
            free(nba->listapartidas);
        }
        free(nba);
    }
}
