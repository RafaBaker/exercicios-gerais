#include "histograma.h"
#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Estrutura para representar um Histograma.
 */
struct tHistograma
{
    int* pixels;
    int qtdPixels;
    int nIntervalos;
    int qtdIntervalo;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma* histograma = malloc(sizeof(Histograma));

    int largura = ObterLargura(img);
    int altura = ObterAltura(img);

    histograma->pixels = malloc(sizeof(int)*nIntervalos);
    histograma->nIntervalos = nIntervalos;
    for (int i = 0; i < histograma->nIntervalos; i++)
    {
        histograma->pixels[i] = 0;
    }

    histograma->qtdPixels = 256;

    float qtdIntervalo = (float)histograma->qtdPixels/(float)histograma->nIntervalos;
    if (qtdIntervalo - (int)qtdIntervalo != 0.0)
    {
        qtdIntervalo = (int)qtdIntervalo+1;
    }

    histograma->qtdIntervalo = (int)qtdIntervalo;


    int valor, indexIntervalo = 0;
    switch (ObterTipoImagem(img))
    {
    case INT:
        int* pixelsInt = ObterDadosImagem(img);
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                valor = pixelsInt[i*largura + j];
                indexIntervalo = valor / histograma->qtdIntervalo;
                histograma->pixels[indexIntervalo] += 1;
            }
        }
        break;
    
    case FLOAT:
        float* pixelsF = ObterDadosImagem(img);
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                valor = (int)((pixelsF[i*largura+j])*255);
                indexIntervalo = valor / histograma->qtdIntervalo;
                histograma->pixels[indexIntervalo] += 1;
            }
        }
        break;
    default:
        break;
    }

    return histograma;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{
    int inicio, fim;
    for (int i = 0; i < histograma->nIntervalos; i++)
    {
        inicio = i*histograma->qtdIntervalo;
        fim = (i+1)*histograma->qtdIntervalo;
        printf("[%d, %d): %d\n", inicio, fim, histograma->pixels[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    if (histograma)
    {
        if (histograma->pixels)
        {
            free(histograma->pixels);
        }
        histograma->pixels = NULL;

        free(histograma);
    }
    histograma = NULL;
}
