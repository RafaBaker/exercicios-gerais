#include <stdio.h>
#include "biblioteca.h"
#include <string.h>

int main () 
{
    int n, op;
    char titulo[100];
    tLivros livro;
    tBiblioteca b;
    b = inicializarBiblioteca();
    scanf("%d", &n);
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &op);
        scanf("%*c");
        switch (op)
        {
        case 1:
            livro = lerLivro();
            b = adicionarLivroNaBiblioteca(b, livro);
            break;
        case 2:
            scanf("%[^\n]s", titulo);
            scanf("%*c");
            b = removerLivroDaBiblioteca(b, titulo);
            break;
        case 3:
            listarLivrosDaBiblioteca(b);
            break;
        default:
            printf("Operacao invalida!\n");
            exit(0);
            break;
        }
    }

    return 0;
}