#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () 
{
    int op = -1, rows1, cols1, rows2, cols2;

    while(1)
    {
        scanf("%d %d", &rows1, &cols1);
        int matrix1[rows1][cols1];
        matrix_read(rows1, cols1, matrix1);
        scanf("%d %d", &rows2, &cols2);
        int matrix2[rows2][cols2];
        matrix_read(rows2, cols2, matrix2);
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            break;
        case 2:
            if (possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            break;
        case 3:
            if(possible_matrix_multiply(cols1, rows2))
            {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }
            break;
        case 4:
            int scalar = 0, flag = -1;
            scanf("%d %d", &scalar, &flag);
            if (flag == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);
            }
            else if (flag == 2)
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);
            }
            break;
        case 5:
            flag = -1;
            scanf("%d", &flag);
            if (flag == 1)
            {
                int result[cols1][rows1];
                transpose_matrix(rows1, cols1, matrix1, result);
                matrix_print(cols1, rows1, result);
            }
            else if (flag == 2)
            {
                int result[cols2][rows2];
                transpose_matrix(rows2, cols2, matrix2, result);
                matrix_print(cols2, rows2, result);
            }
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}