#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

int main () 
{

    int n, tam, soma;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        soma = 0;
        scanf("%d", &tam);
        int vet[tam];

        for (int j = 0; j < tam; j++)
        {
            scanf("%d", &vet[j]);
        }

        soma = SomaElementosPares(vet, tam);
        printf("%d\n", soma);
    }

    return 0;
}

int SomaElementosPares(int* vet, int numElementos)
{
    if (numElementos == 0)
        return 0;
    int div;
    div = vet[numElementos-1] % 2;
    if (div == 0)
    {
        return vet[numElementos-1] + SomaElementosPares(vet, numElementos-1);
    }
    else 
    {
        return 0 + SomaElementosPares(vet, numElementos-1);
    }
}
