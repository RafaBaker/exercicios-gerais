#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct complexo
{
    float real;
    float imag;
};

/**
 * @brief Função que cria uma estrutura que armazena um número complexo
 *
 * @param real - Parte real do número complexo
 * @param imag - Parte Imaginária do número complexo
 *
 * @return Um ponteiro para um novo número complexo, cuja parte real e imaginária são iguais 
 * aos valores passados para a função
 */
tNumComplexo* CriaNumComplexo(float real, float imag)
{
    tNumComplexo* cplx = (tNumComplexo*)malloc(sizeof(tNumComplexo));

    cplx->real = real;
    cplx->imag = imag;

    return cplx;
}

/**
 * @brief Obtém a parte imaginária do número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos obter a parte imaginária
 *
 * @return A parte imaginária, do tipo float, do número complexo
 */
float PegaParteImagComplexo(tNumComplexo *cplx)
{
    return cplx->imag;
}

/**
 * @brief Obtém a parte real do número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos obter a parte real
 *
 * @return A parte real, do tipo float, do número complexo
 */
float PegaParteRealComplexo(tNumComplexo *cplx)
{
    return cplx->real;
}

/**
 * @brief Imprime um número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos imprimir
 *
 */
void ImprimeNumeroComplexo(tNumComplexo *cplx)
{
    printf("%.2f + i%.2f", cplx->real, cplx->imag);
}

/**
 * @brief Libera a memória alocada para um número complexo.
 *
 * @param cplx - Ponteiro para o número complexo que queremos imprimir
 *
 */
void DestroiNumeroComplexo(tNumComplexo *cplx)
{
    if (cplx)
    {
        free(cplx);
    }
    cplx = NULL;
}

/**
 * @brief retorna o número de bytes ocupado pela estrutura definida pelo usuário
 *
 * @return int - Número de bytes ocupado pela "struct complexo"
 *
 */
int RetornaNumBytesComplexo()
{
    return sizeof(tNumComplexo);
}

/**
 * @brief Função que soma dois números complexos
 *
 * @param n1 - Ponteiro para o primeiro número complexo a ser somado
 * @param n2 - Ponteiro para o segundo número complexo a ser somado
 *
 * @return Um ponteiro para um novo número complexo, cujos valores são iguais a soma entre n1 e n2
 */
tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo *n2)
{
    tNumComplexo* soma = CriaNumComplexo(PegaParteRealComplexo(n1)+PegaParteRealComplexo(n2), PegaParteImagComplexo(n1)+PegaParteImagComplexo(n2));
    return soma;
}

/**
 * @brief Função que multiplica dois números complexos
 *
 * @param n1 - Ponteiro para o primeiro número complexo a ser multiplicado
 * @param n2 - Ponteiro para o segundo número complexo a ser multiplicado
 *
 * @return Um ponteiro para um novo número complexo, cujos valores são iguais a multiplicação entre n1 e n2
 */
tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2)
{
    tNumComplexo* mult;
    float real = PegaParteRealComplexo(n1)*PegaParteRealComplexo(n2) - (PegaParteImagComplexo(n1)*PegaParteImagComplexo(n2));
    float imag = PegaParteRealComplexo(n1)*PegaParteImagComplexo(n2) + PegaParteRealComplexo(n2)*PegaParteImagComplexo(n1);
    
    mult = CriaNumComplexo(real, imag);

    return mult;
}
