#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "produto.h"
#include "vector.h"
#include "estabelecimento.h"

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
    tEstabelecimento* e = (tEstabelecimento*)malloc(sizeof(tEstabelecimento));

    e->produtos = VectorConstruct();

    return e;
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
            //free(estabelecimento->produtos);
        }
        estabelecimento->produtos = NULL;

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
    char nomeArquivo[100];
    scanf("%[^\n]", nomeArquivo);
    scanf("%*c");

    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (!arquivo)
    {
        printf("Não foi possivel abrir o arquivo\n");
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
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{
    int qtd = 0;
    float preco = 0;
    float valorTotal = 0;

    for (int i = 0; i < VectorSize(estabelecimento->produtos); i++)
    {
        qtd = GetQuantidadeVendidaProduto(VectorGet(estabelecimento->produtos, i));
        preco = GetPrecoProduto(VectorGet(estabelecimento->produtos, i));

        valorTotal += qtd*preco;
    }
    return valorTotal;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{
    //calculando a quantidade
    // int qtdTotal = 0;
    // for (int i = 0; i < VectorSize(estabelecimento->produtos); i++)
    // {
    //     qtdTotal += GetQuantidadeVendidaProduto(VectorGet(estabelecimento->produtos, i));
    // }

    float valorTotal = GetValorTotalVendidoEstabelecimento(estabelecimento);
    printf("Valor total vendido: R$ %.2f\n", valorTotal);

    printf("Produtos vendidos:\n");
    float porc = 0;
    int qtd = 0;
    float preco = 0;
    float valor = 0;
    int tamanho = VectorSize(estabelecimento->produtos);

    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    for (int i = 0; i < tamanho; i++)
    {

        qtd = GetQuantidadeVendidaProduto(VectorGet(estabelecimento->produtos, i));
        preco = GetPrecoProduto(VectorGet(estabelecimento->produtos, i));
        valor = qtd*preco;

        porc = (valor/valorTotal)*100;
        ImprimeProduto(VectorGet(estabelecimento->produtos, i));
        printf(";%.2f%\n", porc);
    }

}
