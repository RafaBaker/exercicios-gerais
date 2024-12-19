#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int qtd;
    scanf("%d", &qtd);

    int* vetor = CriaVetor(qtd);
    LeVetor(vetor, qtd);
    float media = CalculaMedia(vetor, qtd);
    printf("%.2f", media);
    LiberaVetor(vetor);
    return 0;
}