#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    //scanf("%[^\n]");
    scanf("\n");
    scanf("%[^\n]s", pessoa->nome);
    scanf("%*c");
    //printf("pessoa lida: %s\n", pessoa->nome);
}


int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->pai != NULL || pessoa->mae != NULL) {
        return 1; // Retorna 1 se pelo menos um dos ponteiros pai ou mae não for NULL
    } else {
        return 0; // Retorna 0 se ambos os ponteiros pai e mae forem NULL
    }
}

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

        printf("IRMAO: ");
        if (pessoa->irmao)
            printf("%s\n", pessoa->irmao->nome);
        else
            printf("NAO INFORMADO\n");
        printf("\n");
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if (pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai)
        return 1;
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int mae = -1, pai = -1, filho = -1;
    //char test[100];
    //scanf("%[^\n]s", test);
    //printf("test: %s\n", test);
    //printf("qtd: %d\n", qtd);
    for (int i = 0; i < numPessoas; i++)
    {
        //printf("i: %d\n", i);
        // scanf("%[^\n]s", test);
        // scanf("%*c");
        // printf("test: %s\n", test);
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        scanf("%*c");
        //printf("pai (id: %d): %s\n", pai, pessoas[pai].nome);   
        if (pai != -1)
        {
            pessoas[filho].pai = &pessoas[pai];
        }
        if (mae != -1)
        {
            //printf("mae: %s\n", pessoas[mae].nome);
            pessoas[filho].mae = &pessoas[mae];
        }
    }
    for (int i = 0; i < numPessoas; i++)
    {
        for (int j = 0; j < numPessoas; j++)
        {
            if (j == i)
                continue;
            
            // if (pessoas[j].irmao != NULL)
            //     continue;

            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]))
            {
                pessoas[i].irmao = &pessoas[j];
            }
        }
    }
}
