#include <stdio.h>
#define MAX_CARACTERES 20 

typedef struct Filme {
    int codigo; 
    char nome[MAX_CARACTERES]; 
    int valor; 
    int qtdEstoque; 
    int qtdAlugada; 
} tFilme;

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade)
{
    tFilme filme;

    //printf("estou aqui?\n");
    filme.codigo = codigo;
    //printf("nome do filme:%s\n", nome);
    sprintf(filme.nome, "%s", nome);
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

/**
 * @brief Lê um filme.
 * @param codigo Código do filme.
 * @return Filme lido.
*/
tFilme leFilme(int codigo)
{
    tFilme filme;
    char nome[MAX_CARACTERES];
    scanf(",");
    scanf("%[^,]s", nome);
    criarFilme(nome, codigo, 100, 100);

    return filme;
}

int obterCodigoFilme (tFilme filme)
{
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme)
{
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme)
{
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme)
{
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme)
{
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo)
{
    return filme.codigo == codigo; 
}

tFilme alugarFilme (tFilme filme)
{
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme)
{
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2)
{
    int i;
    while (filme1.nome[i] == filme2.nome[i])
    {
        if (filme1.nome[i] == '\0')
            return 1;
        if (filme2.nome[i] == '\0')
            return -1;
        i++;
    }
    if (filme1.nome[i] == '\0' && filme2.nome[i] == '\0')
        return 0;
}