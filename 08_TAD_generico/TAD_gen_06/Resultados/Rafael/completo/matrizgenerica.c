#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// Adaptado do código compartilhado pelo prof. Thiago

struct matrizgenerica
{
    void ***data;
    int linhas;
    int colunas;
    int byte;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    tMatrizGenerica *mat = malloc(sizeof(tMatrizGenerica));

    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->byte = numByteElem;

    mat->data = malloc(sizeof(void**) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        mat->data[i] = malloc(sizeof(void*)*colunas);
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            mat->data[i][j] = malloc(numByteElem);
            //mat->data[i][j] = NULL;
        }
    }

    return mat;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat)
{
    if (mat != NULL)
    {
        if (mat->data != NULL)
        {
            for (int i = 0; i < mat->linhas; i++)
            {
                if (mat->data[i] != NULL)
                {
                    for (int j = 0; j < mat->colunas; j++)
                    {
                        if (mat->data[i][j] != NULL)
                            free(mat->data[i][j]);
                    }
                    free(mat->data[i]);
                }
            }
            free(mat->data);
        }
        free(mat);
    }
    mat = NULL;
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat)
{
    if (mat != NULL)
    {
        return mat->linhas;
    }
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->colunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna)
{
    return mat->data[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem)
{
    memcpy(ObtemElementoMatrizGenerica(mat,linha,coluna), elem, mat->byte);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void(imprime_elemento(void *)))
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            imprime_elemento(ObtemElementoMatrizGenerica(mat, i, j));
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat)
{
    tMatrizGenerica *transposta = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->byte);
    for (int i = 0; i < transposta->linhas; i++)
    {
        for (int j = 0; j < transposta->colunas; j++)
        {
            AtribuiElementoMatrizGenerica(transposta, i, j, ObtemElementoMatrizGenerica(mat, j, i));
        }
    }
    return transposta;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void *(*multi_elem)(void *, void *), void *(*soma_elem)(void *, void *))
{
    tMatrizGenerica *result = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat1), ObtemNumeroColunasMatrizGenerica(mat2), numByteTarget);
    void* mult, *soma;

    for (int i = 0; i < ObtemNumeroLinhasMatrizGenerica(result); i++)
    {
        for (int j = 0; j < ObtemNumeroColunasMatrizGenerica(result); j++)
        {
            for (int k = 0; k < ObtemNumeroColunasMatrizGenerica(mat1); k++)
            {
                mult = multi_elem(ObtemElementoMatrizGenerica(mat1,i,k), ObtemElementoMatrizGenerica(mat2,k,j));
                
                if (k == 0)
                {
                    AtribuiElementoMatrizGenerica(result, i, j, mult);
                }
                else 
                {
                    soma = soma_elem(ObtemElementoMatrizGenerica(result,i,j), mult);
                    AtribuiElementoMatrizGenerica(result, i, j, soma);
                    free(soma);
                }
                free(mult);
            }
        }
    }

    return result;

}

/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void *(*converte_elem)(void *))
{ 
    tMatrizGenerica* nova = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat2), ObtemNumeroColunasMatrizGenerica(mat2), novoNumByteElem);

    for (int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat2); i++)
    {
        for (int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat2); j++)
        {
            void* original = ObtemElementoMatrizGenerica(mat2, i, j);

            void* convertido = converte_elem(original);

            memcpy(ObtemElementoMatrizGenerica(nova, i, j), convertido, novoNumByteElem);

            free(convertido);
        }
    }

    return nova;
}
