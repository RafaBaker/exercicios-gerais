typedef struct{
    int x;
    int y;
    int sucesso;
} tJogada;

tJogada LeJogada()
{
    tJogada jogada;
    printf("Digite uma posicao (x e y):\n");
    if (scanf("%d %d", &jogada.x, &jogada.y) == 2)
    {
        jogada.sucesso = 1;
    }
    else
    {
        jogada.sucesso = 0;
    }
    return jogada;
}


int ObtemJogadaX(tJogada jogada)
{
    return jogada.x;
}


int ObtemJogadaY(tJogada jogada)
{
    return jogada.y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada)
{
    return jogada.sucesso;
}


