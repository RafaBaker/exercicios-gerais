#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2, dif;
    scanf("%2d/%2d/%4d", &dia1, &mes1, &ano1);
    scanf("%2d/%2d/%4d", &dia2, &mes2, &ano2);
    if (!(verificaDataValida(dia1, mes1, ano1) && verificaDataValida(dia2, mes2, ano2)))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    else 
    {
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
        if (!comparaData(dia1, mes1, ano1, dia2, mes2, ano2))
        {
            printf("As datas sao iguais\n");
        }
        else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
            printf("A segunda data eh mais antiga\n");
        else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
            printf("A primeira data eh mais antiga\n");

        dif = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
        printf("A diferenca em dias entre as datas eh: %02d dias\n", dif);
    }

    return 0;
}