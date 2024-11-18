#include <stdio.h>
#include "data.h"

int main()
{
    int dia, mes, ano, diasMes;
    scanf("%2d/%2d/%4d", &dia, &mes, &ano);
    if (!(verificaDataValida(dia, mes, ano)))
    {
        printf("A data informada eh invalida\n");
    }
    else 
    {
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);
        if (verificaBissexto(ano))
        {
            printf("O ano informado eh bissexto\n");
        }
        else 
        {
            printf("O ano informado nao eh bissexto\n");
        }
        diasMes = numeroDiasMes(mes, ano);
        printf("O mes informado possui %d dias\n", diasMes);
        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
    }

    return 0;
}