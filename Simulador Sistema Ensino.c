#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int totalAlunos = 0;
//int qntdDisciplinas = 0;
#define MAX_DISC 8
int idRemovido = -1;
int disciplinaEscolhida = -1;

typedef struct
{
	char nomeDisciplina[500];
	float notaDisciplina;

}Disciplina;


//Array de structs tipo disciplina com disciplinas fixas
Disciplina disciplinasBase[MAX_DISC] = {
	{"Geografia", 0.0f},
	{"Matematica", 0.0f},
	{"Portugues", 0.0f},
	{"Historia", 0.0f},
	{"Ciencias", 0.0f},
	{"Ingles", 0.0f},
	{"Educacao Fisica", 0.0f},
	{"Filosofia", 0.0f}
};

//Struct permite tratarmos múltiplas varíaveis como uma só.
typedef struct {
	char nome[500];
	int id;
	Disciplina disciplinas[MAX_DISC];
}Aluno;


typedef struct {
	Aluno *alunoPtr;
	float nota;
} AlunoDisciplina;

//Array de structs do tipo Aluno.
Aluno aluno[600];

int comparaAlunos(const void *a, const void *b) {
	return strcmp((const char *)a, (const char *)b);
}
void ordenarAlunospNome() {
	//criacao de uma cópia do array alunos para poder ordenar sem alterações no array original
	char AlunosCopia[600][500];
	for(int i = 0; i < totalAlunos; i++) {
		strcpy(AlunosCopia[i], aluno[i].nome); // copia o nome
	}
	qsort(AlunosCopia, totalAlunos, sizeof(AlunosCopia[0]), comparaAlunos);

	printf("Ordenacao de Alunos por nome: (%d alunos no total)\n", totalAlunos);
	for (int i = 0; i < totalAlunos; i++) {
		printf("%d - %s\n", i + 1, AlunosCopia[i]);
	}
}

float calcularMedia(Aluno aluno) {
	float soma=0;
	int notasPreenchidas=0;
	for (int i=0; i<8; i++) {
		if (aluno.disciplinas[i].notaDisciplina != 0.00) {
			soma += aluno.disciplinas[i].notaDisciplina;
			notasPreenchidas++;
		}
	}
	return soma/notasPreenchidas;
}

// função de comparação para qsort
int compararAlunosPorDisciplina(const void *a, const void *b) {
	Aluno *alunoA = (Aluno *)a;
	Aluno *alunoB = (Aluno *)b;

	float notaA = alunoA->disciplinas[disciplinaEscolhida].notaDisciplina;
	float notaB = alunoB->disciplinas[disciplinaEscolhida].notaDisciplina;

	if (notaA < notaB) return 1;  // ordem decrescente
	if (notaA > notaB) return -1;
	return 0;
}


int compararAlunosPorMedia(const void *a, const void *b) {
	Aluno *alunoA = (Aluno *)a;
	Aluno *alunoB = (Aluno *)b;

	float mediaA = calcularMedia(*alunoA);
	float mediaB = calcularMedia(*alunoB);

	// alunos sem notas vão sempre para o fim
	if (mediaA < 0 && mediaB < 0) return 0;       // ambos sem notas
	if (mediaA < 0) return 1;                     // alunoA sem notas -> atrás
	if (mediaB < 0) return -1;                    // alunoB sem notas -> atrás

	// ordem decrescente: melhor média primeiro
	if (mediaA < mediaB) return 1;
	if (mediaA > mediaB) return -1;
	return 0;
}



void ordenarAlunospMedia() {

	if (totalAlunos <= 0) {
		printf("Nao ha alunos para ordenar.\n");
		return;
	}

	Aluno *alunosCopia = malloc(sizeof(Aluno) * totalAlunos);

	if (alunosCopia == NULL) {
		printf("Erro de memoria.\n");
		return;
	}

	for (int i = 0; i < totalAlunos; i++) {
		alunosCopia[i] = aluno[i];
	}

	qsort(alunosCopia, totalAlunos, sizeof(Aluno), compararAlunosPorMedia);

	printf("\nOrdenacao de alunos por media (melhor -> pior):\n");

	for (int i = 0; i < totalAlunos; i++) {
		float media = calcularMedia(alunosCopia[i]);
		if (media < 0) { // sem notas
			printf("%d - | ID: %d | Nome: %s | Sem notas\n",
				   i + 1,
				   alunosCopia[i].id,
				   alunosCopia[i].nome);
		} else {
			printf("%d - | ID: %d | Nome: %s | Media: %.2f\n",
				   i + 1,
				   alunosCopia[i].id,
				   alunosCopia[i].nome,
				   media);
		}
	}


	free(alunosCopia);
}

void ordenarAlunospDisciplina() {
	if (totalAlunos == 0) {
		printf("Nao ha alunos registados!\n");
		return;
	}

	printf("\n--------------Ordenacao de alunos por disciplina (melhor -> pior)--------------\n");

	// mostrar disciplinas
	for (int i = 0; i < MAX_DISC; i++) {
		printf("| ID: %d | Nome: %s \n", i + 1, disciplinasBase[i].nomeDisciplina);
	}

	int disciplinaEscolhida;
	scanf("%d", &disciplinaEscolhida);
	getchar();
	disciplinaEscolhida--; // converter para 0..7

	if (disciplinaEscolhida < 0 || disciplinaEscolhida >= MAX_DISC) {
		printf("Disciplina invalida!\n");
		return;
	}

	// criar array de structs temporário com ponteiro para aluno e nota da disciplina
	AlunoDisciplina aux[600];
	for (int i = 0; i < totalAlunos; i++) {
		aux[i].alunoPtr = &aluno[i];
		aux[i].nota = aluno[i].disciplinas[disciplinaEscolhida].notaDisciplina;
	}

	// função de comparação
	int cmp(const void *a, const void *b) {
		float na = ((AlunoDisciplina*)a)->nota;
		float nb = ((AlunoDisciplina*)b)->nota;
		if (na < nb) return 1;
		if (na > nb) return -1;
		return 0;
	}

	qsort(aux, totalAlunos, sizeof(AlunoDisciplina), cmp);

	// imprimir
	printf("\nOrdenacao de alunos por %s:\n", disciplinasBase[disciplinaEscolhida].nomeDisciplina);
	for (int i = 0; i < totalAlunos; i++) {
		printf("%d - | ID: %d | Nome: %s | Nota: %.2f\n",
			   i + 1,
			   aux[i].alunoPtr->id,
			   aux[i].alunoPtr->nome,
			   aux[i].nota);
	}
}
void ordenarAlunospNotas() {
	int a = -1;
	while (a!=0) {
		printf("\n---------------Ordenacao de Alunos por Notas--------------\n1- Ordenar por media\n2- Ordenar por nota da disciplina\n0- Sair\n");
		scanf("%d", &a);
		getchar();
		switch (a) {
			case 1:
				ordenarAlunospMedia();
				break;
			case 2:
				ordenarAlunospDisciplina();
				break;
			case 0: return;
		}
	}
}

void ordenarAlunos() {
	int opcao = -1;
	if (totalAlunos>0) {
		while (opcao!=0)
		{
			printf("\n---------------Ordenacao de Alunos--------------\n1- Ordenar por nome\n2- Ordenar por notas (melhor para pior)\n0- Voltar\n");
			scanf("%d", &opcao);
			getchar();

			switch (opcao) {
				case 1:
					ordenarAlunospNome();
					break;
				case 2:
					ordenarAlunospNotas();
					break;
				case 0: return;
			}
		}
	} else {
		printf("Nao ha alunos registados!\n");
	}
}

//Fazer ordenar alunos dentro do desse procedimento abaixo.
void listarAlunos(Aluno alunos[], int *total) {
	int i;
	int j=0;

	for (i = 0; i < *total; ++i) {
		printf("ID Aluno: %d, Nome Aluno: %s\n", alunos[i].id, alunos[i].nome);

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
void listarAlunosSemDisc(Aluno alunos[], int *total) {
	int i;
	int j=0;

	for (i = 0; i < *total; ++i) {
		printf("ID Aluno: %d, Nome Aluno: %s\n", alunos[i].id, alunos[i].nome);

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
	if (idRemovido > 0) {
		alunos[*total].id = idRemovido;
		idRemovido = 0;
	} else {
		alunos[*total].id = *total + 1;
	}
	(*total)++;

	printf("----Aluno adicionado com sucesso!----\n");


}

void adicionarNotaDisciplina(int *total)
{
	int i;
	int j;
	int n = -1;
	float novaNota;
	char nomeAluno[500];
	int idAluno = -1;
	//Listar alunos para o utilizador escolher
	listarAlunosSemDisc(aluno, &totalAlunos);

	printf("Digite o nome do aluno:");
	fgets(nomeAluno, 500, stdin);
	nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

	for (i = 0; i < *total; i++ )
	{
		//Compara o nome armazenado na posição i com o nome fornecido e retorna 0 se forem iguais
		if (strcmp(nomeAluno, aluno[i].nome)== 0)
		{
			idAluno = i;
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
	if (idAluno == -1)
		{
		printf("Aluno nao encontrado!");
		}

	printf("Digite o ID da disciplina:");
	scanf("%d", &n);
	getchar();

	n--; // converte ID (1..8) para índice (0..7)

	if (n < 0 || n >= MAX_DISC) {
		printf("Disciplina invalida.\n");
		return;
	}
	//Adiciona nota para a disciplina desejada
	printf("Digite a nota para %s:",
		   aluno[idAluno].disciplinas[n].nomeDisciplina);
	scanf("%f", &novaNota);
	getchar();

	// Checa se a nova nota é válida
	if (novaNota < 0 || novaNota > 20) {
		printf("Nota invalida! A nota existente para %s permanece: %.2f\n", aluno[idAluno].disciplinas[n].nomeDisciplina,
			   aluno[idAluno].disciplinas[n].notaDisciplina);
		// Não sobrescreve a nota
	} else {
		// Nota válida → atualizar
		aluno[idAluno].disciplinas[n].notaDisciplina = novaNota;
		printf("Nota atribuida com sucesso!\n");
	}

}


void removerAluno(Aluno *alunos, int *total){
	int i;
	char nome[300];
	int j;
	listarAlunos(aluno, total);

	if (totalAlunos == 0) {
		printf("Nao ha alunos registados.");
		return;
	}
	printf("Digite o nome do aluno a ser removido: ");
	fgets(nome, 300, stdin);
	// Remover o caractere de nova linha, se presente
	nome[strcspn(nome, "\n")] = '\0';


	for (i = 0; i < *total; i++){
		// Compara o nome armazenado na posição i com o nome fornecido.
		if (strcmp(nome, alunos[i].nome)== 0){
			printf("ID Aluno: %d || Nome Aluno: %s\n", alunos[i].id, alunos[i].nome);
			idRemovido = alunos[i].id;

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
			default: printf("Opçao invalida! Tente novamente.\n");
		}
	}
}

int menu(){
	int n = -1;
	int z = -1;
	setlocale(LC_ALL,"Portuguese_Portugal.1252");
	while(z!=0){
		printf("---------------Menu---------------\n1- Gestao Alunos\n2- Ordernar Alunos\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: gerirAlunos();
				break;
			case 2: ordenarAlunos();
				break;
			case 0: return 0;
			default: printf("Opçao inválida! Tente novamente.\n");
		}
	}
}


//main
int main(){
setlocale(LC_ALL, "Portuguese_Portugal.1252");
	menu();
}
