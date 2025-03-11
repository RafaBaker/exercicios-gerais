#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "produto.h"

/**
 * @brief Estrutura para representar um produto.
 */
struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int qtd;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade)
{
    tProduto* produto = malloc(sizeof(tProduto));

    produto->codigo = codigo;
    produto->preco = preco;
    produto->qtd = quantidade;
    strcpy(produto->nome, nome);

    return produto;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto)
{
    if (produto)
    {
        free(produto);
    }
    produto = NULL;
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo)
{
    int codigo;
    char nome[50];
    float preco;
    int qtd;

    fread(&codigo, sizeof(int), 1, arquivo);

    fread(nome, sizeof(char), 50, arquivo);

    fread(&preco, sizeof(float), 1, arquivo);

    fread(&qtd, sizeof(int), 1, arquivo);

    tProduto* p = CriaProduto(codigo, nome, preco, qtd);
    return p;
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto)
{
    if (produto->qtd)
        return 1;
    else 
        return 0;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}
