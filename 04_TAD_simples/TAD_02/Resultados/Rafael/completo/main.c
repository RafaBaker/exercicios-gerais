#include <stdio.h>
#include "candidato.h"
#include "eleicao.h"
#include "eleitor.h"

int main () {

    tEleicao eleicao;
    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);

    return 0;
}