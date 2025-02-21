
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Vector
{
    int qtd;
    int capacidade;
    DataType *data;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector* v = malloc(sizeof(Vector));
    assert(v && "erro ao alocar vetor");

    v->qtd = 0;
    v->capacidade = 10;

    v->data = malloc(sizeof(DataType)*v->capacidade);
    assert(v->data && "Erro ao alocar data");

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if (v->capacidade == v->qtd)
    {
        v->capacidade *= 2;
        v->data = realloc(v->data, v->capacidade*sizeof(DataType));
    }
    ((DataType*)v->data)[v->qtd] = val;
    v->qtd++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    if (v != NULL)
    {
        if (v->data != NULL)
        {
            for (int i = 0; i < v->qtd; i++)
            {
                destroy(v->data[i]);
            }
            free(v->data);
        }
        v->data = NULL;
        free(v);
    }
    v = NULL;
}
