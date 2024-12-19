#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    scanf("%*c");
    char* vetor = CriaVetor(tamanho);
    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);
    return 0;
}