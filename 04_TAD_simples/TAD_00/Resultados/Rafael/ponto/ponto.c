#include <stdio.h>
#include <math.h>
#include "ponto.h"

/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y)
{
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p)
{
    return p.x;
}

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p)
{
    return p.y;
}

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x)
{
    p.x = x;
    return p;
}

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y)
{
    p.y = y;
    return p;
}

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2)
{
    float dist, x1, x2, y1, y2, deltax, deltay;
    x1 = pto_acessa_x(p1);
    x2 = pto_acessa_x(p2);
    y1 = pto_acessa_y(p1);
    y2 = pto_acessa_y(p2);
    deltax = (x1-x2)*(x1-x2);
    deltay = (y1-y2)*(y1-y2);
    dist = deltax+deltay;
    dist = sqrt(dist);
    return dist;
}