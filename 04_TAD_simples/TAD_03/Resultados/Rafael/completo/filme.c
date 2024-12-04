#include <stdio.h>
#include "filme.h"

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
    int valor = 0, quantidade = 0;

    scanf(",");
    scanf("%[^,]s", nome);
    scanf("%*c");
    scanf("%d", &valor);
    scanf("%*c");
    scanf("%d", &quantidade);
    scanf("%*c");
    filme = criarFilme(nome, codigo, valor, quantidade);

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
    int i = 0;
    while (filme1.nome[i] != '\0' || filme2.nome[i] != '\0')
    {
        if (filme1.nome[i] > filme2.nome[i])
            return 1;
        else if (filme1.nome[i] < filme2.nome[i])
            return -1;
        i++;
    }
    if (filme1.nome[i] == '\0' && filme2.nome[i] == '\0')
        return 0;
}