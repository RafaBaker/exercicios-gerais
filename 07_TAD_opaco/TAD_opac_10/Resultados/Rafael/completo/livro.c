#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Livros
{
    char *titulo;
    char *autor;
    int ano;
};

#include "livro.h"

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros *CriaLivro()
{
    tLivros *livro = (tLivros *)malloc(sizeof(tLivros));
    assert(livro && "Erro ao alocar livro");

    livro->titulo = NULL;
    livro->autor = NULL;
    livro->ano = -1;

    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros *livro)
{
    livro->titulo = malloc(sizeof(char) * 50);
    livro->autor = malloc(sizeof(char) * 50);

    scanf("%[^\n]s", livro->titulo);
    scanf("%*c");
    scanf("%[^\n]s", livro->autor);
    scanf("%*c");

    scanf("%d", &livro->ano);
    scanf("[^\n]");
    scanf("%*c");
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
 */
void ImprimeLivro(tLivros *livro)
{
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->ano);
    printf("\n");
}

/**
 * Retorna o título do livro.
 *
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
 */
char *getTitulo(tLivros *livro)
{
    return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 *
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
 */
void ApagaLivro(tLivros *livro)
{
    if (livro != NULL)
    {
        if (livro->autor != NULL)
        {
            free(livro->autor);
        }
        livro->autor = NULL;

        if (livro->titulo != NULL)
        {
            free(livro->titulo);
        }
        livro->titulo = NULL;

        free(livro);
    }
    livro = NULL;
}
