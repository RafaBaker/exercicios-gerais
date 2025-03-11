#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "estabelecimento.h"
#include "produto.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento
{
    Vector* produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento* estab = malloc(sizeof(tEstabelecimento));

    estab->produtos = VectorConstruct();

    return estab;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    if (estabelecimento)
    {
        if (estabelecimento->produtos)
        {
            VectorDestroy(estabelecimento->produtos, DestroiProduto);
        }
        free(estabelecimento);
    }
    estabelecimento = NULL;
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    char nome[50];
    scanf("%[^\n]", nome);

    FILE* arquivo = fopen(nome, "r");
    if (!arquivo)
    {
        printf("erro ao abrir arquivo\n");
        exit(1);
    }

    int qtd = 0;
    fread(&qtd, sizeof(int), 1, arquivo);

    for (int i = 0; i < qtd; i++)
    {
        tProduto* p = LeProduto(arquivo);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(arquivo);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    int qtd = 0;

    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");
    if (VectorSize(estabelecimento->produtos))
    {
        for (int i = 0; i < VectorSize(estabelecimento->produtos); i++)
        {
            if (!TemEstoqueProduto(VectorGet(estabelecimento->produtos, i)))
            {
                ImprimeProduto(VectorGet(estabelecimento->produtos, i));
                qtd++;
            }
        }
    }
    if (!qtd)
    {
        printf("Nao ha produtos em falta!\n");
    }
}
