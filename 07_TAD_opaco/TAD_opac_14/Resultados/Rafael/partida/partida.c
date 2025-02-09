// #include "partida.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <string.h>

// struct partida 
// {
//     char* time1; //Casa
//     char* time2; //Visitante
//     int p_time1, p_time2;
// };

// /**
//  * @brief Lê uma partida do teclado.
//  * 
//  * @return tPartida Retorna um ponteiro para a partida lida.
//  */
// tPartida LePartida()
// {
//     tPartida p = (tPartida)malloc(sizeof(struct partida));
//     p->time1 = (char*)malloc(sizeof(char)*32);
//     p->time2 = (char*)malloc(sizeof(char)*32);
//     scanf("%s @ %s %d %d", p->time1, p->time2, &p->p_time1, &p->p_time2);
//     return p;
// }

// /**
//  * @brief Libera a memória alocada para uma partida.
//  * 
//  * @param p Ponteiro para a partida a ser liberada.
//  */
// void LiberaPartida(tPartida p)
// {
//     if (p != NULL)
//     {
//         if (p->time1 != NULL)
//         {
//             free(p->time1);
//         }
//         if (p->time2 != NULL)
//         {
//             free(p->time2);
//         }
//         free(p);
//     }
// }

// /**
//  * @brief Imprime as informações de uma partida.
//  * 
//  * @param p Ponteiro para a partida a ser impressa.
//  */
// void ImprimePartida(tPartida p)
// {
//     printf("A");
// }

// /**
//  * @brief Retorna o nome do time da casa.
//  * 
//  * @param p Ponteiro para a partida.
//  * @return char* Retorna o nome do time da casa.
//  */
// char * GetTime1Partida(tPartida p)
// {
//     return p->time1;
// }

// /**
//  * @brief Retorna o nome do time visitante.
//  * 
//  * @param p Ponteiro para a partida.
//  * @return char* Retorna o nome do time visitante.
//  */
// char * GetTime2Partida(tPartida p)
// {
//     return p->time2;
// }

// /**
//  * @brief Retorna o vencedor da partida.
//  * 
//  * @param p Ponteiro para a partida.
//  * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
//  */
// int GetVencedorPartida(tPartida p)
// {
//     if (p->p_time1 > p->p_time2)
//     {
//         return TIME_CASA;
//     }
//     else 
//     {
//         return TIME_FORA;
//     }
// }
