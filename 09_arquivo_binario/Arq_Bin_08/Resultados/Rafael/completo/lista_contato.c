#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lista_contato.h"
#include "contato.h"
#include "vector.h"

struct ListaContato
{
    Vector* contatos;
};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato()
{
    tListaContato* l = (tListaContato*)malloc(sizeof(tListaContato));

    l->contatos = VectorConstruct();

    return l;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l)
{
    if (l)
    {
        if (l->contatos)
        {
            VectorDestroy(l->contatos, DestruirContato);
        }
        l->contatos = NULL;
        free(l);
    }
    l = NULL;
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato)
{
    int achou = 0;
    for (int i = 0; i < VectorSize(l->contatos); i++)
    {
        tContato* aux = VectorGet(l->contatos, i);
        if (ComparaNomeContato(aux, contato) || ComparaTelefoneContato(aux, contato))
        {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            achou = 1;
            break;
        }
    }
    if (!achou)
    {
        VectorPushBack(l->contatos, contato);
    }
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo)
{

    //printf("Nome do arquivo: %s\n", nomeArquivo);
    FILE* arquivo =  fopen(nomeArquivo, "r");

    if (!arquivo)
        return;
    //assert(arquivo && "Erro ao abrir arquivo (r)");

    int n;
    char nome[100];
    unsigned long int telefone;

    fread(&n, sizeof(int), 1, arquivo);

    for (int i = 0; i < n; i++)
    {
        tContato* contato =  CarregarContato(arquivo);
        AdicionarContatoListaContato(l, contato);
    }

    fclose(arquivo);
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo)
{
    FILE* arquivo = fopen(nomeArquivo, "w");

    //assert(arquivo && "Erro ao abrir arquivo (w)");

    int qtd = VectorSize(l->contatos);
    fwrite(&qtd, sizeof(int), 1, arquivo);

    for (int i = 0; i < qtd; i++)
    {
        SalvarContato(VectorGet(l->contatos, i), arquivo);
    }

    fclose(arquivo);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l)
{
    unsigned long int telefone;
    int achou = 0;

    scanf("%lu\n", &telefone);
    for (int i = 0; i < VectorSize(l->contatos); i++)
    {
        if (GetTelefoneContato(VectorGet(l->contatos, i)) == telefone)
        {
            ImprimirContato(VectorGet(l->contatos, i));
            achou = 1;
            break;
        }
    }

    if (!achou)
    {
        printf("Contato nao encontrado\n");
    }
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l)
{
    char nome[100];
    int achou = 0;

    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*c");
    for (int i = 0; i < VectorSize(l->contatos); i++)
    {
        if (!strcmp(GetNomeContato(VectorGet(l->contatos, i)), nome))
        {
            ImprimirContato(VectorGet(l->contatos, i));
            achou = 1;
            break;
        }
    }

    if (!achou)
    {
        printf("Contato nao encontrado\n");
    }
}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l)
{
    int i;

    printf("\nLista de contatos cadastrados\n");
    for (int i = 0; i < VectorSize(l->contatos); i++)
    {
        ImprimirContato(VectorGet(l->contatos, i));
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l)
{

    unsigned long int telefone;
    int achou = 0;
    scanf("%lu", &telefone);

    for (int i = 0; i < VectorSize(l->contatos); i++)
    {
        if (GetTelefoneContato(VectorGet(l->contatos, i)) == telefone)
        {
            DestruirContato(VectorGet(l->contatos, i));
            VectorRemove(l->contatos, i);
            printf("Contato removido com sucesso\n");
            achou = 1;
            break;
        }
    }

    if (!achou)
    {
        printf("\nNao existe um contato cadastrado com esse numero de telefone\n");
    }
}