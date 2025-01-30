#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void LeIntervalo(int * m, int * n)
{
    scanf("%d %d", m, n);
    //printf("m: %d\n", *m);
}

int EhPrimo(int n)
{
    int i, resto, qtdDiv=0;
    for (i = 1; i <= n; i++)
    {
        resto = n % i;
        if (resto == 0)
        {
            qtdDiv++;
        }
    }
    return qtdDiv==2;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    *maior = m;
    //printf("maior: %d\n", *maior);
    *menor = n;
    //printf("menor: %d\n", *menor);
    for (int i = m; i <= n; i++)
    {
        //printf("i: %d\n", i);
        if (EhPrimo(i))
        {
            if (i < *menor)
            {
                *menor = i;
                //printf("menor trocado\n");
                //printf("menor: %d\n", *menor);
            }
            if (i > *maior)
            {
                *maior = i;
                //printf("maior trocado\n");
                //printf("maior: %d\n", *maior);
            }
        }
    }
}
