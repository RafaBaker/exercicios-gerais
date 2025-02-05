#include "utils_char2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao()
{
    char* vetor;
    vetor = (char*)malloc(sizeof(char)*(TAM_PADRAO+1));
    assert(vetor && "Erro ao alocar vetor");
    int i;
    for (i = 0; i < TAM_PADRAO; i++)
    {
        vetor[i] = '_';
    }
    vetor[i] = '\0';

    return vetor;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo)
{
    int tamanho = tamanhoantigo+TAM_PADRAO+1;
    char* novoVetor = (char*)realloc(vetor, sizeof(char)*tamanho);
    assert(novoVetor && "Erro ao realocar");
    
    int i;
    for (i = tamanhoantigo; i < tamanho-1; i++)
    {
        novoVetor[i] = '_';
    }
    novoVetor[i] = '\0';
    return novoVetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho)
{
    printf("tamanho: %d\n", *tamanho);
    char c = '_';
    int i = 0;
    while (c != '\n')
    {
        scanf("%c", &c);
        if (c == '\n')
        {
            break;
        }
        vetor[i] = c;
        i++;
        if (i == tamanho)
        {
            vetor = AumentaTamanhoVetor(vetor, tamanho);
            *tamanho += TAM_PADRAO;
        }
    }
    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor)
{
    printf("%s\n", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor)
{
    free(vetor);
}
