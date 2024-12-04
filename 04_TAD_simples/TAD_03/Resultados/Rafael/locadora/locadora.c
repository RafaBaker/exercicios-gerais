#include "filme.h"
#include <stdio.h>

#define MAX_FILMES 100


typedef struct Locadora {
    tFilme filme[MAX_FILMES]; 
    int numFilmes; 
    int lucro; 
} tLocadora;

tLocadora criarLocadora ()
{
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo)
{
    int i;
    for (i = 0; i < locadora.numFilmes; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo))
            return 1;
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme)
{
    int codigo = obterCodigoFilme(filme);
    if (!verificarFilmeCadastrado(locadora, codigo))
    {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ", codigo);
        imprimirNomeFilme(filme);
        printf("\n");
        //printf("quantidade estoque: %d\n", filme.qtdEstoque);
    }
    else 
    {
        printf("Filme ja cadastrado no estoque\n");
    }
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora)
{
    char codigo, c2;
    int i = 0;
    scanf("%c", &codigo);
    printf("codigo: %c\n", codigo);
    while (codigo != '#')
    {
        scanf("%c", &c2);
        printf("c2: %c\n", c2);
        if (c2 != ',')
        {
            codigo = (codigo - '0')*10 + (c2 - '0');
            scanf("%*c");
        }
        else codigo -= '0';
        tFilme filme =  leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
        scanf("%c", &codigo);
        i++;
        if (i > 7)
            break;
        printf("codigo: %c\n", codigo);
    }
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int i, j, custo = 0, qtdAlugados = 0, flag = 0;
    for (i = 0; i < quantidadeCodigos; i++)
    {
        flag = 0;
        for (j = 0; j < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {
                flag = 1;
                int qtdEstoque = obterQtdEstoqueFilme(locadora.filme[j]);
                if (qtdEstoque)
                {
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    custo += obterValorFilme(locadora.filme[j]);
                    qtdAlugados++;
                }
                else
                {
                    int codigo = obterCodigoFilme(locadora.filme[j]);
                    printf("Filme %d - ", codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }
        }
        if (!flag)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    if (qtdAlugados) printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, custo);
    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora)
{
    char c1, c2;
    int codigo;
    int codigos[MAX_FILMES];
    int qtdCodigos = 0;
    int i;

    while (1)
    {
        scanf("%c", &c1);
        printf("c1: %c\n", c1);
        if (c1 == '#') break;

        scanf("%c", &c2);
        printf("c2: %c\n", c2);
        if (c2 == '\n')
        {
            codigo = c1 - '0';
            codigos[qtdCodigos] = codigo;
            qtdCodigos++;
        }
        else
        {
            scanf("[^\n]");
            scanf("%*c");
            codigo = (c1 - '0')*10 + (c2 - '0');
            codigos[qtdCodigos] = codigo;
            qtdCodigos++;
        }
    }
    locadora = alugarFilmesLocadora(locadora, codigos, qtdCodigos);
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int i, j;
    int codigo, lucro = 0, qtdAlugados = 0, flag = 0;
    for (i = 0; i < quantidadeCodigos; i++)
    {
        flag = 0;
        for (j = 0; j < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {
                flag = 1;
                codigo = obterCodigoFilme(locadora.filme[j]);
                qtdAlugados = obterQtdAlugadaFilme(locadora.filme[j]);
                if (qtdAlugados)
                {
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    lucro += obterValorFilme(locadora.filme[j]);
                    printf("Filme %d - ", codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                }
                else 
                {
                    printf("Nao e possivel devolver o filme %d - ", codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
            }
        }
        if (!flag)
            printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
    locadora.lucro += lucro;
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora)
{
    char c1, c2;
    int codigo;
    int codigos[MAX_FILMES];
    int qtdCodigos = 0;
    int i;

    while (1)
    {
        scanf("%c", &c1);
        if (c1 == '#') break;

        scanf("%c", &c2);
        if (c2 == '\n')
        {
            codigo = c1 - '0';
            codigos[qtdCodigos] = codigo;
            qtdCodigos++;
        }
        else
        {
            scanf("[^\n]");
            scanf("%*c");
            codigo = (c1 - '0')*10 + (c2 - '0');
            codigos[qtdCodigos] = codigo;
            qtdCodigos++;
        }
    }
    locadora = devolverFilmesLocadora(locadora, codigos, qtdCodigos);
    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora)
{
    int i, j, menor;
    tFilme aux;
    for (i = 0; i < locadora.numFilmes-1; i++)
    {
        menor = i;
        for (j = i+1; j < locadora.numFilmes; j++)
        {
            if (compararNomesFilmes(locadora.filme[j], locadora.filme[menor]) < 0)
                menor = j;
        }
        aux = locadora.filme[i];
        locadora.filme[i] = locadora.filme[menor];
        locadora.filme[menor] = aux; 
    }
    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora)
{
    int i;
    printf("~ESTOQUE~\n");

    locadora = ordenarFilmesLocadora(locadora);
    for (i = 0; i < locadora.numFilmes; i++)
    {
        int codigo = obterCodigoFilme(locadora.filme[i]);
        int estoque = obterQtdEstoqueFilme(locadora.filme[i]);
        printf("%d - ", codigo);
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", estoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora)
{
    if (locadora.lucro)
        printf("\nLucro total R$%d\n", locadora.lucro);
}