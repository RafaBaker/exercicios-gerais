#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    int i = 0, j = 0;

    for (; i < rows; i++)
    {
        for (; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    int i = 0, j = 0;

    for (; i < rows; i++)
    {
        for (; j < cols; j++)
        {
            if (j == 0)
                printf("|");
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    return rows1 == rows2 && cols1 == cols2;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    return rows1 == rows2 && cols1 == cols2;
}

int possible_matrix_multiply(int cols1, int rows2)
{
    return cols1 == rows2;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    if (possible_matrix_sum(rows1, cols1, rows2, cols2))
    {
        int i, j;
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; j < cols1; j++)
            {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    else 
    {
        printf("Erro! Não é possível somar as matrizes");
    }
    
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    if (possible_matrix_sub(rows1, cols1, rows2, cols2))
    {
        int i, j;
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; j < cols1; j++)
            {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }
    else 
    {
        printf("Erro! Não é possível subtrair");
    }

}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    if (possible_matrix_multiply(cols1, rows2))
    {
        int i, j, k, mult, soma;
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; cols2; j++)
            {
                result[i][j] = 0;
                for (k = 0; k < rows1; k++)
                {
                    result[i][j] = result[i][j] + (matrix1[i][k]*matrix2[k][j]);
                }
            }
        }

    }
    else 
    {
        printf("Erro! o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz");
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j]*scalar;
        }
    }
}