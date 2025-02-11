#include "agencia.h"
#include "conta.h"
#include "operacao.h"

#include <stdio.h>

int main()
{
    tAgencia* agencia = CriaAgencia();
    printf("--- Agencia Bancaria ---");
    LeOperacoes(agencia);
    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);
    DestroiAgencia(agencia);

    return 0;
}