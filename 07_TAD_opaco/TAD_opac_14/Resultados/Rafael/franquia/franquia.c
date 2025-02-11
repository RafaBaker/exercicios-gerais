#include "franquia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct franquia
{
    char *nome;
    char *conferencia;
    int vit_casa, vit_fora;
    int der_casa, der_fora;
    float aproveitamento;
};

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 *
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia()
{
    tFranquia franquia = (tFranquia)malloc(sizeof(struct franquia));
    assert(franquia && "Erro ao alocar a franquia");
    franquia->nome = (char*)malloc(sizeof(char)*MAX_NOME);
    assert(franquia->nome && "Erro ao alocar nome da franquia");
    franquia->conferencia = (char*)malloc(sizeof(char)*MAX_NOME);
    assert(franquia->conferencia && "Erro ao alocar conferência da franquia");

    scanf("%s %s", franquia->nome, franquia->conferencia);
    scanf("[^\n]");
    scanf("%*c");

    franquia->vit_casa = 0;
    franquia->vit_fora = 0;
    franquia->der_casa = 0;
    franquia->der_fora = 0;
    franquia->aproveitamento = 0.0;

    return franquia;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 *
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f)
{
    if (f != NULL)
    {
        if (f->conferencia != NULL)
        {
            free(f->conferencia);
        }
        if (f->nome != NULL)
        {
            free(f->nome);
        }
        free(f);
    }
}

/**
 * @brief Imprime as informações de uma franquia.
 *
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f)
{
    char conf[3];
    if (!strcmp("LESTE", f->conferencia))
    {
        strcpy(conf, "CL");
    }
    if (!strcmp("OESTE", f->conferencia))
    {
        strcpy(conf, "CO");
    }

    printf("%s [%s] %d %d %.2f %d %d\n", f->nome, conf, f->vit_casa+f->vit_fora, f->der_casa+f->der_fora, f->aproveitamento, f->vit_casa, f->vit_fora);
}

/**
 * @brief Retorna o nome da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char *GetNomeFranquia(tFranquia f)
{
    return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char *GetConferenciaFranquia(tFranquia f)
{
    return f->conferencia;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f)
{
    f->vit_casa++;
    int total = f->vit_casa + f->vit_fora + f->der_casa + f->der_fora;
    int vitorias = f->vit_casa + f->vit_fora;
    f->aproveitamento = ((float)vitorias/(float)total)*100.0;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f)
{
    f->vit_fora++;
    int total = f->vit_casa + f->vit_fora + f->der_casa + f->der_fora;
    int vitorias = f->vit_casa + f->vit_fora;
    f->aproveitamento = ((float)vitorias/(float)total)*100.0;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f)
{
    f->der_casa++;
    int total = f->vit_casa + f->vit_fora + f->der_casa + f->der_fora;
    int vitorias = f->vit_casa + f->vit_fora;
    f->aproveitamento = ((float)vitorias/(float)total)*100.0;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f)
{
    f->der_fora++;
    int total = f->vit_casa + f->vit_fora + f->der_casa + f->der_fora;
    int vitorias = f->vit_casa + f->vit_fora;
    f->aproveitamento = ((float)vitorias/(float)total)*100.0;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f)
{
    return f->vit_casa;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f)
{
    return f->vit_fora;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f)
{
    return f->der_casa;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f)
{
    return f->der_fora;
}
