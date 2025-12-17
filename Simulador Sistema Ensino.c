#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int totalAlunos = 0;
int qntdDisciplinas = 0;
#define MAX_DISC 10

typedef struct
{
	char nomeDisciplina[500];
	int notaDisciplina [100];

}Disciplina;
Disciplina disciplina[300];

//Struct permite tratarmos múltiplas varíaveis como uma só.
typedef struct {
	char nome[500];
	int id;
	Disciplina *disciplina[MAX_DISC];
	int qntdDisciplinas;

}Aluno;



//Array de structs do tipo Aluno (100).
Aluno aluno[600];

void ordenarAlunos(){
	// Implementar procedimento de ordenar alunos
	printf("");
}
void adicionarDisciplinaAluno(int *index)
{
	int  j = 0;
		//Descobrir por que esta finalizando o programa
	while (j < 3)
	{
		aluno[*index].disciplina[j] = malloc(sizeof(Disciplina));
		printf("Digite o nome do disciplina: ");
		fgets(aluno[aluno[*index].id].disciplina[j]->nomeDisciplina, 300, stdin);
		aluno[*index].disciplina[j]->nomeDisciplina[strcspn(aluno[j].disciplina[*index]->nomeDisciplina, "\n")] = '\0';
		j++;


	}


}
void adicionarAluno(Aluno alunos[], int *total){
	int idx = 0;
	printf("Digite o nome do aluno: ");
	fgets(alunos[*total].nome, 500, stdin);
	alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0';
	adicionarDisciplinaAluno(&alunos[*total].id);
	idx = 0;


	printf("----Aluno adicionado com sucesso!----\n");



	alunos[*total].id = *total;
	(*total)++;

}

/*void adicionarDisciplina()
{
	printf("Digite o nome do aluno: ");
	fgets()
	printf("Digite o nome do disciplina: ");
	fgets(disciplina->nomeDisciplina, 300, stdin);
}*/
void removerDisciplina()
{
	printf("Digite o nome do disciplina: ");
}

void adicionarNotaDisciplina(int *total)
{
	int i;
	char nomeAluno[200];
	printf("Digite o nome do aluno: ");
	fgets(nomeAluno, 200, stdin);
	nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

	for (i = 0; i < *total; i++ )
	{
		if (strcmp(nomeAluno, aluno[i].nome)== 0)
		{
			printf("Adicionar Disciplina: ");
			//Adiciona a disciplina tendo no index quantidade disciplinas
			fgets(aluno[i].disciplina[aluno[i].qntdDisciplinas]->nomeDisciplina, 300, stdin);
			aluno[i].qntdDisciplinas++;
		}
	}
	printf("Digite a disciplina para adicionar a nota: ");

}

void removerAluno(Aluno alunos[], int *total){
	int i;

	char nome[300];
	int j;


	printf("Digite o nome ou ID do aluno a ser removido: ");
	fgets(nome, 300, stdin);
	// Remover o caractere de nova linha, se presente
	nome[strcspn(nome, "\n")] = '\0';


	for (i = 1; i <= *total; i++){
		// Compara o nome armazenado na posição i com o nome fornecido.
		if (strcmp(nome, alunos[i].nome)== 0){
			printf("----Aluno removido com sucesso!----\n");
			printf("ID Aluno: %d ||, Nome Aluno: %s\n", aluno[i].id, alunos[i].nome);

			//Remove disciplinas aluno
			for (j = 0; j < aluno[i].qntdDisciplinas; j++)
			{
				aluno[i].disciplina[j] = NULL;
			}

			//Remove aluno
			for (j = i; j < *total - 1; j++) {
				aluno[j] = aluno[j + 1];
			}

			(*total)--;
		}
	}
}

//Fazer ordenar alunos dentro do desse procedimento abaixo.
void listarAlunos(Aluno alunos[], int *total){
	int i;
	int j=0;
	for (i = 0; i < *total; ++i) {
		printf("ID Aluno: %d, Nome Aluno: %s", alunos[i].id, alunos[i].nome);
		for (j = 0; j < alunos[i].qntdDisciplinas; j++)
		{
			printf("Disciplinas do aluno: %s ", alunos[i].disciplina[j]->nomeDisciplina);
		}

	}
}

void gerirAlunos(){
	int n;
	n = -1;
	while (n!= 0){
		printf("\n---------------Gestão de Alunos--------------\n1- Adicionar Aluno\n2- Adicionar Nota a uma Disciplina\n3- Remover Aluno\n4- Listar Alunos\n0- Voltar Menu Pricinpal\n");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1: adicionarAluno(aluno, &totalAlunos);
				break;
			case 2: adicionarNotaDisciplina(&totalAlunos);
				break;
			case 3: removerAluno(aluno, &totalAlunos);
				break;
			case 4: listarAlunos(aluno, &totalAlunos);
				break;
			case 0: return;
			default: printf("Opção inválida! Tente novamente.\n");
		}
	}
}
void gerirDisciplinas()
{
	int n;
	n = -1;
	while (n!= 0){
		printf("\n---------------Gestão de Disciplinas--------------\n1- Adicionar Disciplina\n2- Remover Disciplina\n3- Listar Disciplinas\n0- Voltar Menu Pricinpal\n");
		scanf("%d", &n);
		getchar();
		switch(n)
		{
			case 1: //adicionarDisciplina();
				break;
			case 2: removerDisciplina();
		}
	}
}
int  menu(){
	int n = -1;
	int z = -1;
	setlocale(LC_ALL,"Portuguese_Portugal.1252");
	while(z!=0){
		printf("---------------Menu---------------\n1- Gestão Alunos\n2- Gestão Disciplinas\n3- Ordernar Alunos\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: gerirAlunos();
				break;
			case 2: gerirDisciplinas();
				break;
			case 0: return 0;
			default: printf("Opção inválida! Tente novamente.\n");
		}
	}
}


//main
int main(){

	setlocale(LC_ALL,"Portuguese");
	menu();

}

