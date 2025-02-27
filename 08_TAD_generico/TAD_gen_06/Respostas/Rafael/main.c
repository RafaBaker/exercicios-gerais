#include <stdio.h>
#include <stdlib.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

void ImprimeInt(void *elem);
void ImprimeFloat(void *elem);
void ImprimeDouble(void *elem);
void ImprimeChar(void *elem);

void *ConverteIntComplexo(void *elem);
void *ConverteFloatComplexo(void *elem);
void *ConverteDoubleComplexo(void *elem);
void *ConverteCharComplexo(void *elem);

int main()
{
    int linhas = -1, colunas = -1, tipo = -1;
    tMatrizGenerica *mat;

    printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");
    scanf("%d %d %d\n", &linhas, &colunas, &tipo);

    switch (tipo)
    {
    case 0:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(int));
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                int temp;
                scanf("%d\n", &temp);
                AtribuiElementoMatrizGenerica(mat, i, j, &temp);
            }
        }
        break;
    case 1:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(float));
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                float temp;
                scanf("%f\n", &temp);
                AtribuiElementoMatrizGenerica(mat, i, j, &temp);
            }
        }
        break;
    case 2:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(double));
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                double temp;
                scanf("%lf\n", &temp);
                AtribuiElementoMatrizGenerica(mat, i, j, &temp);
            }
        }
        break;
    case 3:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(char));
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                char temp;
                scanf("%c\n", &temp);
                AtribuiElementoMatrizGenerica(mat, i, j, &temp);
            }
        }
        break;

    case 4:
        mat = CriaMatrizGenerica(linhas, colunas, RetornaNumBytesComplexo());
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                tNumComplexo *temp;
                float real, imag;

                scanf("(%f,%f)\n", &real, &imag);
                temp = CriaNumComplexo(real, imag);
                AtribuiElementoMatrizGenerica(mat, i, j, &temp);

                DestroiNumeroComplexo(temp);
            }
        }
        break;
    default:
        break;
    }

    printf("Digite a operação desejada\n\t1 - Apenas imprimir a matriz\n\t2 - Converter para o tipo complexo e imprimir\n\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");
    int op;
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        switch (tipo)
        {
        case 0:
            ImprimirMatrizGenerica(mat, ImprimeInt);
            break;
        case 1:
            ImprimirMatrizGenerica(mat, ImprimeFloat);
            break;
        case 2:
            ImprimirMatrizGenerica(mat, ImprimeDouble);
            break;
        case 3:
            ImprimirMatrizGenerica(mat, ImprimeChar);
            break;
        case 4:
            ImprimirMatrizGenerica(mat, ImprimeNumeroComplexo);
            break;
        default:
            break;
        }
        break;

    case 2:
        tMatrizGenerica *convertida;
        switch (tipo)
        {
        case 0:
            convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteIntComplexo);
            break;
        case 1:
            convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteFloatComplexo);
            break;
        case 2:
            convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteDoubleComplexo);
            break;
        case 3:
            convertida = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverteCharComplexo);
            break;
        // case 4:
        //     ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), );
        //     break;
        default:
            break;
        }
        ImprimirMatrizGenerica(convertida, ImprimeNumeroComplexo);
        break;

    default:
        break;
    }

    DestroiMatrizGenerica(mat);

    return 0;
}

void ImprimeInt(void *elem)
{
    printf("%d", *(int *)elem);
}

void ImprimeFloat(void *elem)
{
    printf("%.2f", *(float *)elem);
}

void ImprimeDouble(void *elem)
{
    printf("%.2lf", *(double *)elem);
}

void ImprimeChar(void *elem)
{
    printf("%c", *(char *)elem);
}

void *ConverteIntComplexo(void *elem)
{
    void *conv;
    conv = CriaNumComplexo((*(int *)elem), 0);
    return conv;
}
void *ConverteFloatComplexo(void *elem)
{
    void *conv;
    conv = CriaNumComplexo((*(float *)elem), 0);
    return conv;
}
void *ConverteDoubleComplexo(void *elem)
{
    void *conv;
    conv = CriaNumComplexo((*(double *)elem), 0);
    return conv;
}
void *ConverteCharComplexo(void *elem)
{
    switch (*(char *)elem)
    {
    case '1':
        return CriaNumComplexo(1, 0);
        break;
    case '2':
        return CriaNumComplexo(2, 0);
        break;
    case '3':
        return CriaNumComplexo(3, 0);
        break;
    case '4':
        return CriaNumComplexo(4, 0);
        break;
    case '5':
        return CriaNumComplexo(5, 0);
        break;
    case '6':
        return CriaNumComplexo(6, 0);
        break;
    case '7':
        return CriaNumComplexo(7, 0);
        break;
    case '8':
        return CriaNumComplexo(8, 0);
        break;
    case '9':
        return CriaNumComplexo(9, 0);
        break;
    default:
        break;
    }
}