#include "pacote.h"
#include <stdlib.h>
#include <stdio.h>

struct pacote
{
    Type tipo;
    void *data;
    int qtd;
    int verificacao
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *pac = malloc(sizeof(tPacote));

    pac->tipo = type;
    pac->qtd = numElem;
    pac->verificacao = 0;

    switch (type)
    {
    case INT:
        pac->data = (int *)malloc(sizeof(int) * pac->qtd);
        break;
    case CHAR:
        pac->data = (char *)malloc(sizeof(char) * (pac->qtd+1));
        break;
    default:
        break;
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    if (pac != NULL)
    {
        if (pac->data != NULL)
        {
            free(pac->data);
        }
        pac->data = NULL;
        free(pac);
    }
    pac = NULL;
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    scanf("%*c");
    // char buffer[100];
    // scanf("%[^\n]s", buffer);
    // scanf("%*c");
    // printf("Buffer: %s\n", buffer);

    printf("\nDigite o conteúdo do vetor/mensagem: ");
    int i;
    char c;
    switch (pac->tipo)
    {
    case INT:
        for (i = 0; i < pac->qtd; i++)
        {
            scanf("%d", &((int *)pac->data)[i]);
        }
        //scanf("%*c");
        break;
    case CHAR:
        for (i = 0; i < pac->qtd; i++)
        {
            scanf("%c", &c);
            if (c == '\n')
            {
                break;
            }
            else 
            {
                ((char *)pac->data)[i] = c;
            }
            //printf("caracter %d: %c\n", i, ((char *)pac->data)[i]);
        }
        ((char *)pac->data)[i] = '\0';
        //scanf("%*c");
        // if (((char *)pac->data)[pac->qtd] == '\n')
        // {
        //     ((char *)pac->data)[pac->qtd] = '\0';
        // }
        break;
    default:
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{

    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->verificacao);
    switch (pac->tipo)
    {
    case INT:
        for (int i = 0; i < pac->qtd; i++)
        {
            printf("%d ", ((int *)pac->data)[i]);
        }
        break;
    case CHAR:
        printf("%s", pac->data);
        break;
    default:
        break;
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    for (int i = 0; i < pac->qtd; i++)
    {
        switch (pac->tipo)
        {
        case INT:
            pac->verificacao += ((int*)pac->data)[i];
            break;
        case CHAR:
            pac->verificacao += ((char*)pac->data)[i];
        default:
            break;
        }
    }
}
