#include "data.h"
#include <stdlib.h>
#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return tData - Data "Vazia"
 */
tData *CriaData()
{
    tData *data = (tData *)malloc(sizeof(tData));
    if (data != NULL)
    {
        data->ano = -1;
        data->mes = -1;
        data->dia = -1;
        return data;
    }
    else
    {
        printf("Erro ao alocar data\n");
    }
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData *data)
{
    scanf("%d/%d/%d", data->dia, data->mes, data->ano);
    scanf("%*c");
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados.
 */
void LiberaData(tData *data)
{
    if (data != NULL)
    {
        free(data);
    }
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *data)
{
    if (data->dia > 31)
        return 0;
    if (data->mes > 12)
        return 0;

    int dias = numeroDiasMes(mes, ano);
    if (dia > dias)
        return 0;

    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData *data);

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData *data);

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *data)
{
    return (data->ano % 400 == 0) || ((data->ano % 4 == 0) && (data->ano % 100 != 0));
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData *data)
{
    if (data->mes == 2)
    {
        if (verificaBissexto(data->ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }

    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
        return 31;
    else
        return 30;
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData *data1, tData *data2)
{
    if (data1->ano > data2->ano)
        return 1;
    if (data1->ano > data2->ano)
        return -1;
    if (data1->mes > data2->mes)
        return 1;
    if (data1->mes > data2->mes)
        return -1;
    if (data1->dia > data2->dia)
        return 1;
    if (data1->dia > data2->dia)
        return -1;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *data)
{
    int i, dias, total = 0;
    for (i = 1; i < data->mes; i++)
    {
        dias = numeroDiasMes(data);
        total += dias;
    }
    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *data1, tData *data2)
{

    int dias1 = 0, dias2 = 0, i, difAnos = 0;
    if (data1->ano > data2->ano)
    {
        for (i = data2->ano; i < data1->ano; i++)
        {
            difAnos += calculaDiasAteMes(13, i);
        }
    }
    else if (data2->ano > data1->ano)
    {
        for (i = data1->ano; i < data2->ano; i++)
        {
            difAnos += calculaDiasAteMes(13, i);
        }
    }
    dias1 = calculaDiasAteMes(mes1, data1->ano);
    dias1 += dia1;
    dias2 = calculaDiasAteMes(mes2, data2->ano);
    dias2 += dia2;
    int dif = dias2 - dias1;
    if (dif >= 0)
        return dif + difAnos;
    else
    {
        dif = dif * (-1);
        return dif + difAnos;
    }
}
