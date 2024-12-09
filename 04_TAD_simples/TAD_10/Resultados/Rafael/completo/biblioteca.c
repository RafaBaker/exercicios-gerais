#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca()
{
    tBiblioteca b;
    b.tamanho = 0;
    return b;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro)
{
    if (biblioteca.tamanho == MAX_LIVROS)
    {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
    else 
    {
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho++;
        printf("Livro adicionado com sucesso!\n");
    }
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo)
{
    int i, index = -1;
    tLivros livro, aux, vazio;

    *vazio.titulo = '\0';
    *vazio.autor = '\0';
    vazio.anoPublicacao = 0;

    for (i = 0; i < biblioteca.tamanho; i++)
    {
        livro = biblioteca.livros[i];
        if (!verificaTituloDoLivroNaBiblioteca(livro, titulo))
        {
            biblioteca.livros[i] = vazio;
            index = i;
            printf("Livro removido com sucesso!\n");
            break;
        }
    }
    if (index != -1)
    {
        for (i = index; i < biblioteca.tamanho-1; i++)
        {
            aux = biblioteca.livros[i];
            biblioteca.livros[i] = biblioteca.livros[i+1];
            biblioteca.livros[i+1] = aux;
        }
        biblioteca.tamanho--;
    }
    else 
    {
        printf("Livro nao encontrado na biblioteca.\n");
    }
    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo)
{
    return strcmp(livro.titulo, titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca)
{
    int i;
    if (biblioteca.tamanho)
    {
        printf("\n");
        printf("Lista de Livros na Biblioteca:\n");
        for (i = 0; i < biblioteca.tamanho; i++)
        {
            imprimeLivro(biblioteca.livros[i]);
        }
    }
    else 
    {
        printf("A biblioteca esta vazia!\n");
    }
}
