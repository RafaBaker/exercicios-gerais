#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano)
{
    if (dia > 31)
        return 0;
    if (mes > 12)
        return 0;

    int dias = numeroDiasMes(mes,  ano);
    if (dia > dias)
        return 0;

    return 1;
}

void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%d", dia, mes, ano);
}

void imprimeMesExtenso(int mes)
{
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %4d\n", ano);
}

int verificaBissexto(int ano)
{
    return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));
}

int numeroDiasMes(int mes, int ano)
{
    if (mes == 2)
        {
            if (verificaBissexto(ano))
            {
                return 29;
            } 
            else 
            {
                return 28;
            }
        }
    
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        return 31;
    else 
        return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
        return 1;
    if (ano2 > ano1)
        return -1;
    if (mes1 > mes2)
        return 1;
    if (mes2> mes1)
        return -1;
    if (dia1 > dia2)
        return 1;
    if (dia2 > dia1)
        return -1;

    return 0;
}

int calculaDiasAteMes(int mes, int ano)
{
    int i, dias, total = 0;
    for (i = 1; i < mes; i++)
    {
        dias = numeroDiasMes(i, ano);
        total += dias;
    }
    return total;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias1 = 0, dias2 = 0, i, difAnos = 0;
    if (ano1 > ano2)
    {
        for (i = ano2; i < ano1; i++)
        {
            difAnos += calculaDiasAteMes(13, i);
        }
    }
    else if (ano2 > ano1)
    {
        for (i = ano1; i < ano2; i++)
        {
            difAnos += calculaDiasAteMes(13, i);
        }
    }
    dias1 = calculaDiasAteMes(mes1, ano1);
    dias1 += dia1;
    dias2 = calculaDiasAteMes(mes2, ano2);
    dias2 += dia2;
    int dif = dias2-dias1;
    if (dif >= 0)
        return dif+difAnos;
    else
    {
        dif = dif*(-1);
        return dif+difAnos;
    }
}

void imprimeProximaData(int dia, int mes, int ano)
{
    if (numeroDiasMes(mes, ano) == dia)
    {
        dia = 1;
        mes += 1;
        if (mes == 13)
        {
            mes = 1;
            ano++;
        }
    }
    else
    {
        dia++;
    }
    imprimeData(dia, mes, ano);
}