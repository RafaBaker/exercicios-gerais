#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    int i, soma = 0, flag = 1;
    for (i = 0; i < tamanho; i++)
    {
        soma += array[i];
        if (flag)
        {
            *menor = array[i];
            *maior = array[i];
            flag = 0;
            continue;
        }
        if (array[i] < *menor)
        {
            *menor = array[i];
        }
        if (array[i] > *maior)
        {
            *maior = array[i];
        }
    }
    *media = (float)soma/(float)tamanho;
}