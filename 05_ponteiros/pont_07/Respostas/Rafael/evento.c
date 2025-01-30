#include "evento.h"
#include <stdio.h>  
#include <string.h>

void cadastrarEvento(Evento* eventos, int* numEventos)
{
    Evento evento;
    int dia, mes, ano;
    char nome[50];

    printf("numeventos: %d\n", *numEventos);
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
        *numEventos++;
        printf("Evento cadastrado com sucesso!\n");

    }

}

void exibirEventos(Evento* eventos, int* numEventos)
{
    Evento evento;
    printf("Eventos cadastrados:\n");
    printf("numeventos: %d\n", *numEventos);
    for (int i = 0; i < *numEventos; i++)
    {
        evento = eventos[i];
        printf("%d - %s - %02d/%02d/%d\n", i, evento.nome, evento.dia, evento.mes, evento.ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int indice;
    scanf("%d", &indice);
    scanf("[^\n]");
    scanf("%*c");

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

        eventos[indice] = evento;
        printf("Data modificada com sucesso!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    Evento aux = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;    
}
