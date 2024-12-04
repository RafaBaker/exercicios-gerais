#include "aluno.h"
#include <stdio.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3)
{
    tAluno aluno;
    sprintf(aluno.nome, "%s", nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;
    return aluno;
}

tAluno LeAluno()
{
    char nome[100];
    int matricula=0, n1=0, n2=0, n3=0;
    tAluno aluno;


    scanf("%[^\n]s", nome);
    scanf("%*c");
    scanf("%d", &matricula);
    scanf("%*c");
    scanf("%d %d %d", &n1, &n2, &n3);
    scanf("%*c");

    aluno = CriaAluno(nome, matricula, n1, n2, n3);
    
    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2)
{
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    else if (aluno1.matricula < aluno2.matricula)
        return -1;
    else 
        return 0;
}

int CalculaMediaAluno(tAluno aluno)
{
    return (aluno.n1 + aluno.n2 + aluno.n3)/3;
}

int VerificaAprovacao(tAluno aluno)
{
    return CalculaMediaAluno(aluno)>=7;
}

void ImprimeAluno(tAluno aluno)
{
    printf("%s\n", aluno.nome);
}