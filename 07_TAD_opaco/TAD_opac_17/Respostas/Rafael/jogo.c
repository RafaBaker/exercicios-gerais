#include <math.h> // compilar com -lm
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct Jogo
{
    int max, min;
    int valor, maxTentativas;
    int tentativas;
};
#include "jogo.h"

tJogo* CriaJogo()
{
    tJogo* jogo = (tJogo*)malloc(sizeof(tJogo));
    assert(jogo && "Erro ao alocar jogo");
    jogo->max = 0;
    jogo->min = 0;
    jogo->valor = 0;
    jogo->maxTentativas = 0;
    jogo->tentativas = 0;
    return jogo;
}

/**
 * @brief Libera toda a memória alocada para um jogo.
 * 
 * @param jogo - A variável do tipo jogo que será liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    if (jogo != NULL)
    {
        free(jogo);
    }
}

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param max - o valor máximo do intervalo do jogo.
 */
void DefineMaximo(tJogo* jogo, int max)
{
    jogo->max = max;
}

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param min - o valor mínimo do intervalo do jogo.
 */
void DefineMinimo(tJogo* jogo, int min)
{
    jogo->min = min;
}

/**
 * @brief Calcula o número a ser adivinhado pelo jogador
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n)
{
    
}

/**
 * @brief Calcula o número de tentativas que o usuário irá ter para acertar o número. 
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaNumeroTentativas(tJogo *jogo);

/**
 * @brief Executa o jogo. Calcula o que for necessário e lê as tentativas, fazendo as devidas verificações.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados.
 * @return int 1 se o usuário venceu o jogo ou 0 caso contrário
 */
int ProcessaTentativas(tJogo* jogo);
