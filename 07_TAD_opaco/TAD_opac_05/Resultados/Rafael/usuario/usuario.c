// #include "usuario.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <string.h>

// struct Usuario
// {
//     char* nome;
//     char* cpf;
// }; 

// /**
//  * @brief Cria um novo usuário.
//  * Se não for possível alocar memória, o programa é encerrado.
//  * 
//  * @return Um ponteiro para o novo usuário criado.
//  */
// tUsuario *CriaUsuario()
// {
//     tUsuario* usuario = (tUsuario*)malloc(sizeof(tUsuario));
//     assert(usuario && "Erro ao alocar o usuario");
//     usuario->cpf = NULL;
//     usuario->nome = NULL;
//     return usuario;
// }

// /**
//  * @brief Desaloca a memória de um usuário.
//  * 
//  * @param user Ponteiro para o usuário a ser destruído.
//  */
// void DestroiUsuario(tUsuario *user)
// {
//     free(user->cpf);
//     free(user->nome);
//     free(user);
// }

// /**
//  * @brief Lê os dados de um usuário da entrada padrão.
//  * 
//  * @param user Ponteiro para o usuário a ser lido.
//  */
// void LeUsuario(tUsuario *user)
// {
//     char nome[50];
//     char cpf[15];
//     scanf("%s ", nome);
//     scanf("%s ", cpf);

//     user->cpf = (char*)malloc(sizeof(char)*strlen(cpf)+1);
//     user->nome = (char*)malloc(sizeof(char)*strlen(nome)+1);
//     strcpy(user->cpf, cpf);
//     strcpy(user->nome, nome);
// }

// /**
//  * @brief Imprime os dados de um usuário.
//  * 
//  * @param user Ponteiro para o usuário a ser impresso.
//  */
// void ImprimeUsuario(tUsuario *user)
// {
//     printf("Nome: %s\n", user->nome);
//     printf("CPF: %s\n", user->cpf);
// }
