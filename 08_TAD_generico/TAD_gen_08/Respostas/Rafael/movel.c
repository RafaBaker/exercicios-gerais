#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
 * @brief Estrutura representando um Movel.
 */
struct Movel
{
    char nome[30];
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome)
{
    tMovel* m = (tMovel*)malloc(sizeof(tMovel));

    strcpy(m->nome, nome);

    return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m)
{
    if (m)
    {
        free(m);
    }
    m = NULL;
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel()
{
    tMovel* m;
    char nome[30];

    scanf("%[^\n]s", nome);
    scanf("%*c");

    m = CriaMovel(nome);
    return m;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m)
{
    printf("%s\n", m->nome);
}
