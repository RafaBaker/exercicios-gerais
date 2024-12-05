#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id)
{
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa()
{
    tEmpresa empresa;
    int id, qtd;

    scanf("%d", &id);
    empresa = criaEmpresa(id);
    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    printf("oi\n");
    printf("empresa.id: %d\n", empresa.id);
    printf("empresa.qtd: %d\n", empresa.qtdFuncionarios);
    int i, id1, id2;
    for (i = 0; i < empresa.qtdFuncionarios; i++)
    {
        id1 = getIdFuncionario(funcionario);
        id2 = getIdFuncionario(empresa.funcionarios[i]);
        if (id1 == id2)
        {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, id2);
            return empresa;
        }
    }
    empresa.funcionarios[i] = funcionario;
    empresa.qtdFuncionarios++;
    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa)
{
    int i;
    printf("oi\n");
    printf("Empresa %d:\n", empresa.id);
    for (i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
