#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "base_alunos.h"

int main(int argc, char const *argv[])
{
    tBaseAlunos* base = CriarBaseAlunos();    

    char nome[50];
    scanf("%[^\n]", nome);

    LerBaseAlunos(base, nome);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;
}
