#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"


//#define NUM_INICIAL_LIVROS 5

// Estrutura que representa uma biblioteca de livros
struct Biblioteca
{
    tLivros** livros;
    int qtdLivros;
    //int tamMax;
};

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca()
{
    tBiblioteca* b = (tBiblioteca*)malloc(sizeof(tBiblioteca));
    assert(b && "Erro ao alocar biblioteca");

    b->livros = NULL;
    b->qtdLivros = 0;
    //b->tamMax = 10;

    return b;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca)
{
    if (biblioteca != NULL)
    {
        if (biblioteca->livros != NULL)
        {
            for (int i = 0; i < biblioteca->qtdLivros; i++)
            {
                ApagaLivro(biblioteca->livros[i]);
            }

            free(biblioteca->livros);
        }
        biblioteca->livros = NULL;

        free(biblioteca);
    }
    biblioteca = NULL;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro)
{
    biblioteca->livros = (tLivros**)realloc(biblioteca->livros, sizeof(tLivros*)*(biblioteca->qtdLivros+1));
    biblioteca->livros[biblioteca->qtdLivros] = livro;
    biblioteca->qtdLivros++;
}


/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo)
{
    int i, index = -1;
    // tLivros* livro, aux, vazio;
    tLivros* vazio = NULL;
    tLivros* aux = NULL;
    //tLivros* aux = CriaLivro();

    for (i = 0; i < biblioteca->qtdLivros; i++)
    {
        if (!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo))
        {
            biblioteca->livros[i] = vazio;
            ApagaLivro(biblioteca->livros[i]);
            index = i;
            printf("Livro removido com sucesso!\n");
            break;
        }
    }
    if (index != -1)
    {
        for (i = index; i < biblioteca->qtdLivros-1; i++)
        {
            aux = biblioteca->livros[i];
            biblioteca->livros[i] = biblioteca->livros[i+1];
            biblioteca->livros[i+1] = aux;
        }
        biblioteca->qtdLivros--;
    }
    else 
    {
        printf("Livro nao encontrado na biblioteca.\n");
    }
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo)
{
    return strcmp(getTitulo(livro), titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca)
{
    int i;
    if (biblioteca->qtdLivros)
    {
        printf("\n");
        printf("Lista de Livros na Biblioteca:\n");
        for (i = 0; i < biblioteca->qtdLivros; i++)
        {
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
    else 
    {
        printf("A biblioteca esta vazia!\n");
    }
}

