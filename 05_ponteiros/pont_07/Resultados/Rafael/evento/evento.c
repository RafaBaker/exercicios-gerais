#include "evento.h"
#include <stdio.h>  
#include <string.h>

void cadastrarEvento(Evento* eventos, int* numEventos)
{
    Evento evento;
    int dia=0, mes=0, ano=0;
    char nome[50];

    //printf("numeventos: %d\n", *numEventos);
    if (*numEventos < 10)
    {
        scanf("%s", nome);
        scanf("[^\n]");
        scanf("%*c");
        strcpy(evento.nome, nome);


        scanf("%d %d %d", &dia, &mes, &ano);
        scanf("[^\n]");
        scanf("%*c");

        evento.dia = dia;
        evento.mes = mes;
        evento.ano = ano;

        eventos[*numEventos] = evento;
        //printf("numEventos: %d\n", *numEventos);
        (*numEventos)++;
        //printf("numEventos: %d\n", *numEventos);
        printf("Evento cadastrado com sucesso!\n");

    }
    else
    {
        printf("Limite de eventos atingido!\n");
    }

}

void exibirEventos(Evento* eventos, int* numEventos)
{
    Evento evento;
    //printf("numeventos: %d\n", *numEventos);
    if (*numEventos)
    {
        printf("Eventos cadastrados:\n");
        for (int i = 0; i < *numEventos; i++)
        {
            evento = eventos[i];
            printf("%d - %s - %d/%d/%d\n", i, evento.nome, evento.dia, evento.mes, evento.ano);
        }
    }
    else
    {
        printf("Nenhum evento cadastrado.\n");
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int indice;
    scanf("%d", &indice);
    scanf("[^\n]");
    scanf("%*c");
    //printf("indice: %d\n", indice);
    if (indice < *numEventos)
    {
        Evento evento;
        int dia, mes, ano;

        scanf("%d %d %d", &dia, &mes, &ano);
        scanf("[^\n]");
        scanf("%*c");

        evento.dia = dia;
        evento.mes = mes;
        evento.ano = ano;
        strcpy(evento.nome, eventos[indice].nome);

        eventos[indice] = evento;
        printf("Data modificada com sucesso!\n");
    }
    else
    {
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    //printf("numEventos: %d\n", *numEventos);
    if (*indiceA < *numEventos && *indiceB < *numEventos)
    {
        Evento aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;    
        printf("Eventos trocados com sucesso!\n");
    }
    else 
    {
        printf("Indices invalidos!\n");
    }
}
