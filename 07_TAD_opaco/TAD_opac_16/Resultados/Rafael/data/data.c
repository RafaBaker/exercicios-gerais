#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Data
{
    int dia, mes, ano;
    int diaSemana;
    int hora, minuto;
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
        data->diaSemana = -1;
        data->hora = -1;
        data->minuto = -1;
        return data;
    }
    else
    {
        printf("Erro ao alocar data\n");
        exit(0);
    }
}

/**
 * @brief Libera toda a memoria alocada dinamicamente para armazenar uma data
 *
 * @param tData - Data que será liberada
 */
void DestroiData(tData *data)
{
    if (data != NULL)
    {
        free(data);
        data = NULL;
    }
}

/**
 * @brief Processa o dia, mês e ano da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaMesAno(tData *data, char *str)
{
    // printf("test str: %s\n", str);
    sscanf(str, "%d/%d/%d", &data->dia, &data->mes, &data->ano);
    printf("ProcessaDiaMesAno: str %s\n", str);
    printf("ProcessaDiaMesAno: data->dia %d data->mes %d data->ano %d\n", data->dia, data->mes, data->ano);
}

/**
 * @brief Processa o dia da semana da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaDaSemana(tData *data, char *str)
{
    // printf("test str: %s\n", str);
    sscanf(str, "%d", &data->diaSemana);
}

/**
 * @brief Processa hora, minuto e segundo da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaHorario(tData *data, char *str)
{
    // printf("test str: %s\n", str);
    sscanf(str, "%d:%d", &data->hora, &data->minuto);
    printf("ProcessaHorario: str %s\n", str);
    printf("ProcessaHorario: data->hora %d\n", data->hora);
    printf("ProcessaHorario: data->minuto %d\n", data->minuto);
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

    int dias = NumeroDiasMes(data);
    if (data->dia > dias)
        return 0;

    return 1;
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *data)
{
    return (data->ano % 400 == 0);
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
        if (VerificaBissexto(data))
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
int ComparaDiaMesAno(tData *data1, tData *data2)
{
    if (data1->ano > data2->ano)
        return 1;
    if (data1->ano < data2->ano)
        return -1;
    if (data1->mes > data2->mes)
        return 1;
    if (data1->mes < data2->mes)
        return -1;
    if (data1->dia > data2->dia)
        return 1;
    if (data1->dia < data2->dia)
        return -1;
    return 0;
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
    tData d;
    d.ano = data->ano;
    for (i = 1; i < data->mes; i++)
    {
        d.mes = i;
        dias = NumeroDiasMes(&d);
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
    int dias1 = data1->dia, dias2 = data2->dia;
    tData i;

    // dias no ano
    dias1 += CalculaDiasAteMes(data1);
    dias2 += CalculaDiasAteMes(data2);

    int difAnos = 0;
    if (data1->ano > data2->ano)
    {
        //difAnos = data1->ano - data2->ano;
        for (i = *data2; i.ano < data1->ano; i.ano++)
        {
            difAnos += VerificaBissexto(&i) ? 366 : 365;
        }
    }
    else if (data2->ano > data1->ano)
    {
        //difAnos = data2->ano - data1->ano;
        for (i = *data1; i.ano < data2->ano; i.ano++)
        {
            difAnos += VerificaBissexto(&i) ? 366 : 365;
        }
    }
    
    int dif = dias2 - dias1;
    printf("data1: %02d/%02d/%d\n", data1->dia, data1->mes, data1->ano);
    printf("data2: %02d/%02d/%d\n", data2->dia, data2->mes, data2->ano);
    printf("dif dias: %d\n", dif);
    if (dif >= 0)
    {
        return dif + difAnos;
    }
    else
    {
        dif = dif*(-1);
        return dif+difAnos;
    }
}

/**
 * @brief Calcula a diferença em horas entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return float número de horas entre as duas datas (2,5 horas = 2h30)
 */
float CalculaHorasEntreDatas(tData *data1, tData *data2)
{
    float horas = (float)data2->hora - (float)data1->hora;
    float minutos = (data2->minuto - data1->minuto) / (float)60;

    printf("data1: %02d/%02d/%d dia semana: %d\n", data1->dia, data1->mes, data1->ano, data1->diaSemana);
    printf("hora1: %02d:%02d\n", data1->hora, data1->minuto);
    printf("data2: %02d/%02d/%d dia semana: %d\n", data2->dia, data2->mes, data2->ano, data1->diaSemana);
    printf("hora2: %02d:%02d\n", data2->hora, data2->minuto);
    printf("dif: %.2f\n", horas+minutos);

    return horas+minutos;
}

/**
 * @brief Verifica se uma data corresponde a um sábado ou domingo
 *
 * @param data1 Primeira data a ser comparada.
 * @return int 1 se é sábado ou domingo, 0 caso contrário
 */
int DataEhSabadoOuDomingo(tData *data)
{
    return !(data->diaSemana == 0 && data->dia == 6);
}

/**
 * @brief Atualiza a data para a data do dia seguinte (esta data deve ser válida!)
 *
 * @param data Data a ser modificada.
 *
 */
void DataDiaSeguinte(tData *data)
{
    if (NumeroDiasMes(data) == data->dia)
    {
        data->dia = 1;
        data->mes += 1;
        if (data->mes == 13)
        {
            data->mes = 1;
            data->ano++;
        }
    }
    else
    {
        data->dia++;
    }
}

/**
 * @brief Copia os dados de Dia/Mês/Ano de uma data src para uma data tgt.
 *
 * @param src Data que terá seus dados copiados
 * @param tgt Data que armazenará a cópia
 */
void CopiaDiaMesAno(tData *src, tData *tgt)
{
    tgt->dia = src->dia;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
    tgt->diaSemana = src->diaSemana;
    tgt->hora = src->hora;
    tgt->minuto = src->minuto;
}
