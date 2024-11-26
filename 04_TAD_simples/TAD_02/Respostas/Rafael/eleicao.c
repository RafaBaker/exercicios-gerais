#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    tCandidato candidato;
    char cargo;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.totalEleitores = 0;


    int qtdCandidatos, qtdGov, qtdPre, i;
    scanf("%d", &qtdCandidatos);
    for (i = 0; i < qtdCandidatos; i++)
    {
        candidato = LeCandidato();
        cargo = ObtemCargo(candidato);
        if (cargo == 'P' && eleicao.totalPresidentes <= MAX_CANDIDATOS_POR_CARGO)
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato; 
            eleicao.totalPresidentes++;
        }
        else if (cargo == 'G' && eleicao.totalPresidentes <= MAX_CANDIDATOS_POR_CARGO)
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato; 
            eleicao.totalGovernadores++;
        }

    }

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{
    int qtdEleitores, i, j, votoG, votoP;
    char cargo;
    tEleitor eleitor;
    tCandidato candidato;

    scanf("%d", &qtdEleitores);
    eleicao.totalEleitores = qtdEleitores;

    for (i = 0; i < qtdEleitores; i++)
    {
        eleitor = LeEleitor();
        votoG = ObtemVotoGovernador(eleitor);
        votoP = ObtemVotoPresidente(eleitor);
        //navegando pelos governadores
        if (votoG)
        {
            for (j = 0; j < eleicao.totalGovernadores; j++)
            {
                if (VerificaIdCandidato(eleicao.governadores[j], votoG))
                {
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    break;
                }
            }
            if (j == eleicao.totalGovernadores)
                eleicao.votosNulosGovernador++;
        }
        else 
        {
            eleicao.votosBrancosGovernador++;
        }
        //navegando pelos presidentes
        if (votoP)
        {
            for (j = 0; j < eleicao.totalPresidentes; j++)
            {
                if (VerificaIdCandidato(eleicao.presidentes[j], votoP))
                {
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    break;
                }
            }
            if (j == eleicao.totalPresidentes)
                eleicao.votosNulosPresidente++;
        }
        else 
        {
            eleicao.votosBrancosPresidente++;
        }
        eleicao.eleitores[i] = eleitor;
    }
    // //IMPRIMINDO TODOS OS PRESIDENTES
    // for (i = 0; i < eleicao.totalPresidentes; i++ )
    // {
    //     ImprimeCandidato(eleicao.presidentes[i], 100.00);
    // }

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int i, j, votosInvalidosG = 0, votosInvalidosP = 0, votosValidosP = 0, votosValidosG = 0;
    int votos = 0, idMaiorVotosP = 0, maiorVotosP = 0, idMaiorVotosG = 0, maiorVotosG = 0;
    int empate = 0;
    tCandidato presEleito;
    tCandidato govEleito;

    if (eleicao.totalEleitores > 10)
        printf("ELEICAO ANULADA\n");
    else 
    {
        //checando se teve eleitor repetido
        for (i = 0; i < eleicao.totalEleitores; i++)
        {
            for (j = 0; j < eleicao.totalEleitores; j++)
            {
                if (j == i)
                    continue;
                if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
                {
                    printf("ELEICAO ANULADA\n");
                    exit(0);
                }
            }
        }

        votosInvalidosG = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;
        votosInvalidosP = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
        //printf("nulos: %d, brancos: %d\ninvalidos:%d\n", eleicao.votosNulosPresidente, eleicao.votosBrancosPresidente, votosInvalidosP);

        //checando o vencedor para presidente
        for (i = 0; i < eleicao.totalPresidentes; i++)
        {
            tCandidato candidato = eleicao.presidentes[i];
            votos = ObtemVotos(candidato);
            if (votos > maiorVotosP)
            {
                maiorVotosP = votos;
                idMaiorVotosP = candidato.id;
                empate = 0;
            }
            else if (votos == maiorVotosP)
            {
                empate = 1;
            }
        }
        printf("- PRESIDENTE ELEITO: ");
        if (empate)
        {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        else if (votosInvalidosP > maiorVotosP)
        {
            printf("SEM DECISAO\n");
        }
        else 
        {
            for (i = 0; i < eleicao.totalPresidentes; i++)
                if (VerificaIdCandidato(eleicao.presidentes[i], idMaiorVotosP))
                    presEleito = eleicao.presidentes[i];

            float perc = CalculaPercentualVotos(presEleito, eleicao.totalEleitores); 
            ImprimeCandidato(presEleito, perc);
        }

        //checando o vencedor para governadores
        for (i = 0; i < eleicao.totalGovernadores; i++)
        {
            tCandidato candidato = eleicao.governadores[i];
            votos = ObtemVotos(candidato);
            if (votos > maiorVotosG)
            {
                maiorVotosG = votos;
                idMaiorVotosG = candidato.id;
                empate = 0;
            }
            else if (votos == maiorVotosG)
            {
                empate = 1;
            }
        }
        printf("- GOVERNADOR ELEITO: ");
        if (empate)
        {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        else if (votosInvalidosG > maiorVotosG)
        {
            printf("SEM DECISAO\n");
        }
        else 
        {
            for (i = 0; i < eleicao.totalGovernadores; i++)
                if (VerificaIdCandidato(eleicao.governadores[i], idMaiorVotosG))
                    govEleito = eleicao.governadores[i];

            float perc = CalculaPercentualVotos(govEleito, eleicao.totalEleitores); 
            ImprimeCandidato(govEleito, perc);
        }

        //nulos e brancos
        int votosNulos = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
        int votosBrancos = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;
        printf("- NULOS E BRANCOS: %d, %d\n", votosNulos, votosBrancos);
    }
}