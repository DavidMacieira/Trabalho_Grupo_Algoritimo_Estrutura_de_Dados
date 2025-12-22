#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int totalAlunos = 0;
int qntdDisciplinas = 0;
#define MAX_DISC 8

typedef struct
{
	char nomeDisciplina[500];
	float notaDisciplina;

}Disciplina;

//Array de structs tipo disciplina com disciplinas fixas
Disciplina disciplinasBase[MAX_DISC] = {
	{"Geografia", {0}},
	{"Matematica", {0}},
	{"Portugues", {0}},
	{"Historia", {0}},
	{"Ciencias", {0}},
	{"Ingles", {0}},
	{"Educacao Fisica", {0}},
	{"Filosofia", {0}}
};

//Struct permite tratarmos múltiplas varíaveis como uma só.
typedef struct {
	char nome[500];
	int id;
	Disciplina disciplinas[MAX_DISC];
}Aluno;

//Array de structs do tipo Aluno (100).
Aluno aluno[600];

void ordenarAlunos(){
	// Implementar procedimento de ordenar alunos
	printf("");
}

//Fazer ordenar alunos dentro do desse procedimento abaixo.
void listarAlunos(Aluno alunos[], int *total) {
	int i;
	int j=0;

	for (i = 0; i < *total; ++i) {
		printf("ID Aluno: %d, Nome Aluno: %s\n", alunos[i].id + 1, alunos[i].nome);

		// Cabeçalho das disciplinas
		printf("%-10s %-20s %-10s\n", "ID", "Disciplina", "Nota");

		for (j = 0; j < MAX_DISC; j++)
		{
			printf("%-10d %-20s %-10.2f\n",
				j + 1,
				alunos[i].disciplinas[j].nomeDisciplina,
				alunos[i].disciplinas[j].notaDisciplina
			);
		}
		printf("\n");
	}
}
void adicionarAluno(Aluno alunos[], int *total){
	int i;
	printf("Digite o nome do aluno: ");
	fgets(alunos[*total].nome, 500, stdin);
	alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0';

	for (i = 0; i < MAX_DISC; i++)
	{
		//Adiciona todas as disciplinas base ao aluno
		strcpy(alunos[*total].disciplinas[i].nomeDisciplina, disciplinasBase[i].nomeDisciplina);
	}

	alunos[*total].id = *total;
	(*total)++;

	printf("----Aluno adicionado com sucesso!----\n");


}

void adicionarNotaDisciplina(int *total)
{
	int i;
	int j;
	int n = -1;
	char nomeAluno[500];
	int idAluno;
	//Listar alunos para o utilizador escolher
	listarAlunos(aluno, &totalAlunos);

	printf("Digite o nome do aluno:");
	fgets(nomeAluno, 500, stdin);
	nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

	for (i = 0; i < *total; i++ )
	{
		//Compara o nome armazenado na posição i com o nome fornecido e retorna 0 se forem iguais
		if (strcmp(nomeAluno, aluno[i].nome)== 0)
		{
			idAluno = aluno[i].id;
			printf("Disciplinas:\n");
			printf("%-10s %-20s %-10s\n", "ID Disc.", "Disciplina", "Nota");
			for (j = 0; j < 8; j++)
			{
				printf("%-10d %-20s %-10.2f\n",
					j+1,
					aluno[i].disciplinas[j].nomeDisciplina,
					aluno[i].disciplinas[j].notaDisciplina
	 );
			}
		}
	}
	printf("Digite o ID da disciplina:");
	scanf("%d", &n);

	n--; // converte ID (1..8) para índice (0..7)

	if (n < 0 || n >= MAX_DISC) {
		printf("Disciplina invalida.\n");
		return;
	}
	//Adiciona nota para a disciplina desejada
	printf("Digite a nota para %s:",
		   aluno[idAluno].disciplinas[n].nomeDisciplina);

	scanf("%f",
		  &aluno[idAluno].disciplinas[n].notaDisciplina);
}

void removerAluno(Aluno alunos[], int *total){
	int i;
	char nome[300];
	int j;
	listarAlunos(aluno, &totalAlunos);


	printf("Digite o nome ou ID do aluno a ser removido: ");
	fgets(nome, 300, stdin);
	// Remover o caractere de nova linha, se presente
	nome[strcspn(nome, "\n")] = '\0';


	for (i = 0; i <= *total; i++){
		// Compara o nome armazenado na posição i com o nome fornecido.
		if (strcmp(nome, alunos[i].nome)== 0){
			printf("ID Aluno: %d ||, Nome Aluno: %s\n", aluno[i].id, alunos[i].nome);

			//Remove aluno
			for (j = i; j < *total - 1; j++) {
				aluno[j] = aluno[j + 1];
			}

			(*total)--;
			printf("----Aluno removido com sucesso!----\n");
		}
	}
}



void gerirAlunos(){
	int n;
	n = -1;
	while (n!= 0){
		printf("\n---------------Gestao de Alunos--------------\n1- Adicionar Aluno\n2- Adicionar Nota a uma Disciplina\n3- Remover Aluno\n4- Listar Alunos\n0- Voltar Menu Pricinpal\n");
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
		printf("\n---------------Gestao de Disciplinas--------------\n1- Adicionar Disciplina\n2- Remover Disciplina\n3- Listar Disciplinas\n0- Voltar Menu Pricinpal\n");
		scanf("%d", &n);
		getchar();
		switch(n)
		{
			case 1: //adicionarDisciplina();
				break;
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

