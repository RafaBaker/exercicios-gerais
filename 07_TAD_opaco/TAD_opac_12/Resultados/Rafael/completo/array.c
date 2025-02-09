#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Array{
    int* data;
    int tamanho;
};

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array* array = (Array*)malloc(sizeof(Array));
    assert(array && "Não foi possível alocar o array");
    array->data = NULL;
    array->tamanho = 0;
    return array;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{    
    if (array != NULL)
    {
        if (array->data != NULL)
        {
            free(array->data);
        }
        free(array);
    }
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    int num;
    char c = '\0';
    while (1)
    {
        if (scanf("%d", &num) == 1)
        {
            array->tamanho++;
            array->data = (int*)realloc(array->data, sizeof(int)*(array->tamanho));
            assert(array->data && "Erro ao realocar array->data");
            array->data[array->tamanho-1] = num;

            scanf("%c", &c);
            if (c == '.')
            {
                break;
            }
            else if (c != ' ')
            {
                continue;
            }
        }
        else 
        {
            scanf("%c", &c);
            if (c == '.')
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    int i, j, menor, aux;
    for (i = 0; i < array->tamanho-1; i++)
    {
        menor = i;
        for (j = i; j < array->tamanho; j++)
        {
            if (array->data[j] < array->data[menor])
            {
                menor = j;
            }
        }
        aux = array->data[menor];
        array->data[menor] = array->data[i];
        array->data[i] = aux;
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado)
{
    int inicio = 0, fim = array->tamanho-1, meio = 0;
    while (inicio < fim)
    {
        meio = (inicio + fim)/2;
        if (array->data[meio] == elementoBuscado)
        {
            return meio;
        }

        if (array->data[meio] > elementoBuscado)
        {
            fim = meio;
        }
        else
        {
            inicio = meio +1;
        }
    }
    return -1;
}

int ObterElementoArray(Array* array, int indice)
{
    return array->data[indice];
}