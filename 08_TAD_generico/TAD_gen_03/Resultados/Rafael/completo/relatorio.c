#include "relatorio.h"
#include "vector.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    float soma = 0, media = 0, qtdAprovado = 0;
    float qtdFem = 0, qtdMasc = 0, qtdOutro = 0;
    float notaAtual;
    int i, aprovado, qtd;

    qtd = VectorSize(alunos);
    for (i = 0; i < qtd; i++)
    {
        aprovado = 0;
        tAluno* aluno = (tAluno*)VectorGet(alunos, i);
        notaAtual = GetNotaAluno(aluno);
        if (notaAtual >= 6)
        {
            aprovado = 1;
            qtdAprovado++;
        }
        soma += notaAtual;
        
        char genero = GetGeneroAluno(aluno);
        //printf("genero: %c\n", genero);
        switch (genero)
        {
        case 'F':
            qtdFem++;
            break;
        case 'M':
            qtdMasc++;
            break;
        case 'O':
            qtdOutro++;
            break;
        default:
            break;
        }
    }

    media = soma/(float)qtd;
    printf("Media das notas: %.2f\n", media);
    float porcAprovado = (qtdAprovado/(float)qtd)*100;
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcAprovado);
    
    printf("Porcentagem de cada genero: \n");
    float porcMasculino = (qtdMasc/qtd)*100; 
    printf("Masculino: %.2f%%\n", porcMasculino);
    float porcFeminino = (qtdFem/qtd)*100;
    printf("Feminino: %.2f%%\n", porcFeminino);
    float porcOutro = (qtdOutro/qtd)*100;
    printf("Outro: %.2f%%\n", porcOutro);
}