#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char* str = CriaVetorTamPadrao();
    int tamanho = TAM_PADRAO;
    str = LeVetor(str, &tamanho);
    ImprimeString(str);
    LiberaVetor(str);
    return 0;
}
