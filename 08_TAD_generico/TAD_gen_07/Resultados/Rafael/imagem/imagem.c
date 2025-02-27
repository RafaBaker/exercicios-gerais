#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    Tipo tipo;
    int altura;
    int largura;
    void *pixels;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->pixels;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem *img = malloc(sizeof(Imagem));

    img->tipo = tipo;
    img->altura = altura;
    img->largura = largura;

    img->pixels = malloc(sizeof(void *) * altura * largura);

    return img;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{
    char buffer[100];
    int altura, largura, tipo;

    scanf("%*c");
    scanf("%d %d %d\n", &altura, &largura, &tipo);
    // scanf("%[^\n]s", buffer);
    // scanf("%*c");
    // printf("Buffer: %s\n", buffer);

    Imagem *img = CriarImagem(altura, largura, tipo);

    switch (tipo)
    {
    case FLOAT:
        float n = 0;
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                scanf("%f", &n);
                ((float*)img->pixels)[i*largura + j] = n;
            }
        }
        break;
    case INT:
        int m = 0;
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                scanf("%d", &m);
                ((int*)img->pixels)[i*largura + j] = m;
            }
        }
        break;
    default:
        break;
    }

    return img;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img)
{

}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img)
{
    if (img)
    {
        if (img->pixels)
        {
            free(img->pixels);
        }
        img->pixels = NULL;

        free(img);
    }
    img = NULL;
}
