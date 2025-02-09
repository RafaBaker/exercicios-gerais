#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Array* array = CriarArray();
    LerArray(array);
    OrdenarArray(array);

    int elementoBuscado = 0;
    scanf("%d", &elementoBuscado);
    
    int indice = BuscaBinariaArray(array, elementoBuscado);
    if (indice != -1)
    {
        printf("Elemento %d encontrado no índice %d.", elementoBuscado, indice);
    }
    else
    {
        printf("Elemento %d não encontrado no array (%d).", elementoBuscado, indice);
    }
    
    DestruirArray(array);

    return 0;
}
