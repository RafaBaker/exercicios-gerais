#include "fila.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Fila
{
    Vector *moveis;
    // int qtd;
};

/**
 * @brief Cria uma fila vazia
 *
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Fila *FilaConstruct()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    // f->qtd = 0;

    f->moveis = VectorConstruct();
    return f;
}

/**
 * @brief Desaloca a memória alocada para a fila
 *
 * @param f Ponteiro para a fila
 * @param destroy Função que desaloca a memória alocada para cada elemento da fila
 */
void FilaDestroy(Fila *f, void (*destroy)(DataType))
{
    if (f)
    {
        if (f->moveis)
        {
            VectorDestroy(f->moveis, destroy);
        }
        f->moveis = NULL;

        free(f);
    }
    f = NULL;
}

/**
 * @brief Retorna o tamanho da fila
 *
 * @param f Ponteiro para a fila
 * @return int Tamanho da fila
 */
int FilaSize(Fila *f)
{
    return VectorSize(f->moveis);
}

/**
 * @brief Remove o primeiro elemento da fila
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @param f Ponteiro para a fila
 * @return DataType Elemento removido
 */
DataType FilaPop(Fila *f)
{
    DataType r = VectorPopFront(f->moveis);
    return r;
}

/**
 * @brief Adiciona um elemento no final da fila
 *
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
 */
void FilaPush(Fila *f, DataType val)
{
    VectorPushBack(f->moveis, val);
}
