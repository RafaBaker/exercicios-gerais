#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar um produto.
 */
struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int qtdVendida;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida)
{
    tProduto* produto = (tProduto*)malloc(sizeof(tProduto));
    
    produto->codigo = codigo;
    memset(produto->nome, 0, 50);
    strcpy(produto->nome, nome);
    produto->preco = preco;
    produto->qtdVendida = quantidadeVendida;

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
    int qtdVendida;

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), 50, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&qtdVendida, sizeof(int), 1, arquivo);

    //printf("codigo: %d\n", codigo);
    //printf("nome: %s\n", nome);
    //printf("preco: %.2f\n", preco);
    //printf("qtdvendida: %d\n", qtdVendida);


    tProduto* p = CriaProduto(codigo, nome, preco, qtdVendida);
    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->qtdVendida);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto)
{
    return produto->qtdVendida;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto)
{
    return produto->preco;
}
