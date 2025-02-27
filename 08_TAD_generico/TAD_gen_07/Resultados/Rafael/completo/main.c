#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

int main ()
{
    int nIntervalos;

    scanf("%d", &nIntervalos);

    Imagem* img = LerImagem();

    Histograma* hist = CalcularHistograma(img, nIntervalos);
    MostrarHistograma(hist);
    DestruirHistograma(hist);
    DestruirImagem(img);


    return 0;
}