#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Vector
{
    DataType* data;
    int qtd;
    int capacidade;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector* v = (Vector*)malloc(sizeof(Vector));
    
    v->capacidade = 10;
    v->qtd = 0;

    v->data = (DataType*)malloc(sizeof(DataType)*v->capacidade);

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
        v->data = realloc(v->data, sizeof(DataType)*v->capacidade);
    }

    v->data[v->qtd] = val;
    v->qtd++;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i)
{
    v->data[i] = NULL;
    for (int j = i; j < v->qtd-1; j++)
    {
        DataType aux = v->data[j];
        v->data[j] = v->data[j+1];
        v->data[j+1] = aux;
    }
    v->qtd--;
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
 * @brief Troca os elementos i e j do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do primeiro elemento
 * @param j Índice do segundo elemento
*/
void VectorSwap(Vector *v, int i, int j)
{
    DataType aux = VectorGet(v, i);
    v->data[i] = VectorGet(v, j);
    v->data[j] = aux;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    if (v)
    {
        if (v->data)
        {
            for (int i = 0; i < v->qtd; i++)
            {
                destroy(VectorGet(v, i));
            }
            free(v->data);
        }
        v->data = NULL;
        free(v);
    }
    v = NULL;
}
