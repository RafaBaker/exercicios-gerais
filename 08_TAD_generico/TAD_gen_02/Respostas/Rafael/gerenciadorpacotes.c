#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct gerenciadorpacotes
{
    tPacote** pacotes;
    int qtdPacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador()
{
    tGerenciador* geren = (tGerenciador*)malloc(sizeof(tGerenciador));

    geren->pacotes = NULL;
    geren->qtdPacotes = 0;

    return geren;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac)
{
    geren->qtdPacotes++;
    geren->pacotes = realloc(geren->pacotes, (sizeof(tPacote*)*geren->qtdPacotes));
    geren->pacotes[geren->qtdPacotes-1] = pac; 
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren)
{
    if (geren != NULL)
    {
        if (geren->pacotes != NULL)
        {
            for (int i = 0; i < geren->qtdPacotes; i++)
            {
                DestroiPacote(geren->pacotes[i]);
            }
            free(geren->pacotes);
        }
        geren->pacotes = NULL;
        free(geren);
    }
    geren = NULL;
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx)
{
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren)
{
    for (int i = 0; i < geren->qtdPacotes; i++)
    {
        ImprimirPacoteNoIndice(geren, i);
    }
}
