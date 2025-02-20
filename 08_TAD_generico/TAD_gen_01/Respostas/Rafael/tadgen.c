#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct generic
{
    void *data;
    int qtd;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *g = malloc(sizeof(tGeneric));
    assert(g && "Erro ao alocar 'g'");

    switch (type)
    {
    case INT:
        g->data = malloc(numElem * sizeof(int));
        break;
    case FLOAT:
        g->data = malloc(numElem * sizeof(float));
        break;
    default:
        free(g);
        break;
    }
    assert(g->data && "Erro ao alocar g->data");

    g->tipo = type;
    g->qtd = numElem;

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    if (gen != NULL)
    {
        if (gen->data != NULL)
        {
            free(gen->data);
        }
        gen->data = NULL;
        free(gen);
    }
    gen = NULL;
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    char buffer[60];
    char c;
    scanf("%c", &c);
    // printf("gen.qtd: %d:\n", gen->qtd);
    printf("\nDigite o vetor:");
    for (int i = 0; i < gen->qtd; i++)
    {
        switch (gen->tipo)
        {
        case INT:
            scanf("%d", &((int*)gen->data)[i]);
            //printf("gen.data: %d\n", ((int*)gen->data)[i]);
            break;
        case FLOAT:
            scanf("%f", &((float*)gen->data)[i]);
            //printf("gen.data: %.2f\n", ((float*)gen->data)[i]);
            break;
        default:
            break;
        }
    }
    // scanf("%[^\n]s", buffer);
    // scanf("%*c");
    // printf("Buffer: %s\n", buffer);
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{
    printf("\n");
    for (int i = 0; i < gen->qtd; i++)
    {
        switch (gen->tipo)
        {
        case INT:
            printf("%d ", ((int*)gen->data)[i]);
            break;
        case FLOAT:
            printf("%.2f ", ((float*)gen->data)[i]);
        default:
            break;
        }
    }
    printf("\n");
}
