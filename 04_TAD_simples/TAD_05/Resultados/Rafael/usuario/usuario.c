#include "usuario.h"
#include <stdio.h>

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario usuario;
    sprintf(usuario.cpf, "%s", cpf);
    sprintf(usuario.nome, "%s", nome);
    return usuario;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user)
{
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}
