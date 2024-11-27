#include "filme.h"

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
        printf("Filme cadastrado - %d - ", codigo);
        imprimirNomeFilme(filme);
        printf("\n");
    }
    else 
    {
        printf("Filme ja cadastrado no estoque\n");
    }
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora)
{
    char codigo;
    scanf("[^\n]");
    scanf("%*c");
    scanf("%c", &codigo);
    while (codigo != '#')
    {
        tFilme filme =  leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
        scanf("[^\n]");
        scanf("%*c");
        scanf("%c", &codigo);
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
    int i, j;
    for (i = 0; i < quantidadeCodigos; i++)
    {
        for (j = 0; j < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {
                int qtdEstoque = obterQtdAlugadaFilme(locadora.filme[j]);
                if (qtdEstoque)
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                else
                {
                    int codigo = obterCodigoFilme(locadora.filme[j]);
                    printf("Filme %d - ", codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }
        }
    }
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
    locadora = alugarFilmesLocadora(locadora, codigos, qtdCodigos);
    printf("Total de filmes alugados: 1 com custo de R$5");
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
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora);

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora);

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora);

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora);