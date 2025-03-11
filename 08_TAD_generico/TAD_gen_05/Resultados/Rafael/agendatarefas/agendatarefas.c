#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct agendatarefas
{
    void** tarefas;
    int* prioridade;
    void (**executa)(void*);
    void (**destroi)(void*);
    int qtdTarefas;
    int capacidade;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas* tar = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));
    assert(tar && "Erro ao alocar agendaTarefas");
    
    tar->capacidade = numElem;
    tar->qtdTarefas = 0;

    tar->prioridade = malloc(sizeof(int)*tar->capacidade);
    tar->tarefas = malloc(sizeof(void*)*tar->capacidade);
    tar->executa = malloc(sizeof(void(*)(void*))*tar->capacidade);
    tar->destroi = malloc(sizeof(void(*)(void*))*tar->capacidade);

    return tar;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar)
{
    if (tar)
    {
        //destruindo cada tarefa com sua função
        for (int i = 0; i < tar->qtdTarefas; i++)
        {
            tar->destroi[i](tar->tarefas[i]);
        }
        free(tar->prioridade);
        free(tar->executa);
        free(tar->destroi);
        free(tar->tarefas);

        free(tar);
    }
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) )
{
    if (tar->capacidade >= tar->qtdTarefas)
    {
        tar->tarefas[tar->qtdTarefas] = tarefa;
        tar->prioridade[tar->qtdTarefas] = prioridade;
        tar->executa[tar->qtdTarefas] = executa;
        tar->destroi[tar->qtdTarefas] = destroi;
        tar->qtdTarefas++;
    }
} 

void OrdenaTarefas(tAgendaTarefas *tar)
{
    for (int i = 0; i < tar->qtdTarefas; i++)
    {
        for (int j = 0; j < tar->qtdTarefas-1; j++)
        {
            if (tar->prioridade[j] < tar->prioridade[j+1])
            {
                int pAux;
                pAux = tar->prioridade[j];
                tar->prioridade[j] = tar->prioridade[j+1];
                tar->prioridade[j+1] = pAux;

                void* tAux;
                tAux = tar->tarefas[j];
                tar->tarefas[j] = tar->tarefas[j+1];
                tar->tarefas[j+1] = tAux;

                void (*auxExec)(void*);
                auxExec = tar->executa[j];
                tar->executa[j] = tar->executa[j+1];
                tar->executa[j+1] = auxExec;

                void (*auxDest)(void*);
                auxDest = tar->destroi[j];
                tar->destroi[j] = tar->destroi[j+1];
                tar->destroi[j+1] = auxDest;
            }
        }
    }
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar)
{
    OrdenaTarefas(tar);
    for (int i = 0; i < tar->qtdTarefas; i++)
    {
        tar->executa[i](tar->tarefas[i]);
    }
}
