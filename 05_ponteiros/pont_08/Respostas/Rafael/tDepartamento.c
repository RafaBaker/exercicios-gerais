#include "tDepartamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento dep;
    strcpy(dep.curso1, curso1);
    strcpy(dep.curso2, curso2);
    strcpy(dep.curso3, curso3);
    strcpy(dep.nome, nome);
    strcpy(dep.diretor, diretor);
    dep.m1 = m1;
    dep.m2 = m2;
    dep.m3 = m3;
    return dep;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    printf("\n");
    printf("Departamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);
    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);
    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);
    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);
    float media = (float)(depto.m1+depto.m2+depto.m3)/(float)3;
    printf("\tMedia dos cursos: %.2f", media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    float mediaMaior = 0, mediaJ = 0;
    int maior, i, j;
    tDepartamento aux;
    for (i = 0; i < num_deptos-1; i++)
    {
        mediaMaior = (float)(vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3)/(float)3;
        maior = i;
        for (j = i+1; j < num_deptos; j++)
        {
            mediaJ = (float)(vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3)/(float)3;
            if (mediaJ > mediaMaior)
            {
                maior = j;
            }
        }
        aux = vetor_deptos[i];
        vetor_deptos[i] = vetor_deptos[maior];
        vetor_deptos[maior] = aux;
    }
}

