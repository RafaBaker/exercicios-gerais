#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    scanf("%[^\n]s", pessoa->nome);
    scanf("%*c");
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->pai != NULL || pessoa->mae != NULL) {
        return 1; // Retorna 1 se pelo menos um dos ponteiros pai ou mae não for NULL
    } else {
        return 0; // Retorna 0 se ambos os ponteiros pai e mae forem NULL
    }
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    //printf("Função ImprimePessoa\n");
    if (VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        printf("PAI: ");
        if (pessoa->pai)
            printf("%s\n", pessoa->pai->nome);
        else
            printf("NAO INFORMADO\n");

        printf("MAE: ");
        if (pessoa->mae)
            printf("%s\n", pessoa->mae->nome);
        else
            printf("NAO INFORMADO\n");
        printf("\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int mae, pai, filho;
    if (scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho) == 3)
    {
        if (pai != -1)
        {
            *pessoas[filho].pai = pessoas[pai];
        }
        if (mae != -1)
        {
            *pessoas[filho].mae = pessoas[mae];
        }
    }
}
