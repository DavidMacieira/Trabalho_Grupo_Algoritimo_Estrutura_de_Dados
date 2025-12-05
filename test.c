#include <stdio.h>
#include <string.h>
//
// Created by PedroAugustoConsani on 05/12/2025.
//
typedef struct
{
    char nome[1000];
    int idade;
    char disciplina[1000][1000];
}Aluno;
void listarAluno(Aluno lista[])
{
    int i;
    int j;
    for (i = 0; i < 2; i++)
    {
        printf("Disciplinas do aluno: ");
        //printf("Aluno %s, Disciplina: %s, Idade: %d\n", lista[i].nome, lista[i].disciplina[i], lista[i].idade );
        for (j = 0; j < 2; j++)
        {
            printf("%s ", lista[i].disciplina[j]);
        }
    }
}
int main()
{
    Aluno aluno[2];
    /*strcpy(aluno[0].nome, "Pedro");
    strcpy(aluno[0].disciplina[0], "Matematica" );
    aluno[0].idade = 18*/;

    strcpy(aluno[1].nome, "Gabriel");
    strcpy(aluno[1].disciplina[0], "Portugues");
    strcpy(aluno[1].disciplina[1], "Geografia");
    aluno[1].idade = 20;



    listarAluno(aluno);


}
