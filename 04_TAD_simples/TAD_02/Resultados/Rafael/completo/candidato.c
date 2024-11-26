#include <stdio.h>

typedef struct {
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    int votos;
} tCandidato;

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;
    sprintf(candidato.nome, "%s", nome);
    sprintf(candidato.partido, "%s", partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}

tCandidato LeCandidato()
{
    char nome[50];
    char partido[50];
    char cargo;
    int id = 0;
    scanf("[^\n]");
    scanf("%*c");
    scanf("%[^,]s", nome);
    scanf("%*c%*c");
    scanf("%[^,]s", partido);
    scanf("%*c%*c");
    scanf("%c%*c%*c", &cargo);
    scanf("%d", &id);
    tCandidato candidato;
    candidato.votos = 0;
    candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    return candidato1.id == candidato2.id;
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos += 1;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    int votos = ObtemVotos(candidato);
    float perc = ((float)votos/(float)totalVotos) *100;
    return perc;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos)
{
    printf("%s ", candidato.nome);
    printf("(%s), ", candidato.partido);
    printf("%d voto(s), ", candidato.votos);
    printf("%.2f%%\n", percentualVotos);
}

