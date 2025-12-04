#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int totalAlunos = 0;
int c;
int i;
int n;

//Struct permite tratarmos múltiplas varíaveis como uma só.
typedef struct {
	char nome[500];
	int id;
	float nota[100];
}Aluno;

//Array de structs do tipo Aluno (100).
Aluno aluno[100];

void gerirNotas(){
	// Implementar procedimento de gerir notas
	printf("");

}
void ordenar(){
	// Implementar procedimento de ordenar alunos
	printf("");

	
}


void adicionarAluno(Aluno aluno[], int *totalAlunos){
	printf("Digite o nome do aluno: ");
	fgets(aluno[*totalAlunos].nome, 500, stdin);
	aluno[*totalAlunos].nome[strcspn(aluno[*totalAlunos].nome, "\n")] = '\0';


	printf("Digite a nota do aluno: ");
	scanf("%f", &aluno[*totalAlunos].nota);

	aluno[*totalAlunos].id = *totalAlunos;
	(*totalAlunos)++;

	printf("\n");
	// Remover o caractere de nova linha, se presente
	//alunos[totalAlunos][strcspn(alunos[totalAlunos], "\n")] = '\0';

}

void removerAluno(){
	char nome[300];
	int j;

	printf("Digite o nome ou ID do aluno a ser removido: ");
	fgets(nome, 300, stdin);
	// Remover o caractere de nova linha, se presente
	nome[strcspn(nome, "\n")] = '\0';



	for (i = 0; i < totalAlunos; i++){
		// Compara o nome armazenado na posição i com o nome fornecido.
		if (strcmp(nome, alunos[i])== 0){
			printf("----Aluno removido com sucesso!----\n");
			printf("ID Aluno: %d ||, Nome Aluno: %s\n", ids[i], alunos[i]);
			for (j = i; j < totalAlunos - 1; j++) {
				strcpy(alunos[j], alunos[j+1]);
			}

			totalAlunos--;
		}
	}
}


void listarAlunos(){
	for (int i = 0; i < totalAlunos; ++i) {
		printf("ID Aluno: %d ||, Nome Aluno: %s\n", ids[i], alunos[i]);
	}
}

void gerirAlunos(){
	n = -1;
	while (n!= 0){
		printf("---------------Gestão de Alunos--------------\n1- Adicionar Aluno\n2- Remover Aluno\n3- Listar Alunos\n0- Voltar Menu Pricinpal\n");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1: adicionarAluno();
				break;
			case 2: removerAluno();
				break;
			case 3: listarAlunos();
				break;
			case 0: return;
			default: printf("Opção inválida! Tente novamente.\n");
		}
	}
}
int  menu(){
	int z = -1;
	setlocale(LC_ALL,"Portuguese_Portugal.1252");
	while(z!=0){
		printf("---------------Menu---------------\n1- Gestão Alunos\n2- Gestão Notas\n3- Ordernar Alunos\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: gerirAlunos();
				break;
				//case 2: gerirNotas();
				//	break;
				//case 3: ordenar();
				//	break;
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

