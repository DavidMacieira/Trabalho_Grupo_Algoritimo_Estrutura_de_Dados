#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
/*int n = -1;
float media;*/
char alunos[100][100];
int totalAlunos = 0;
int c;
int i;




/*void gerirNotas(){
		while(n!=0){
		printf("1- Calcular média de aluno\n2- Calcular média da turma\n3- Voltar ao Menu Principal\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: mediaAluno();
				break;
			case 2: mediaTurma();
				break;
			case 3: menuPrincipal();
				break;
			case 0: return;
		}
	}
}
void ordenar(){
		while(n!=0){
		printf("1- Ordernar alunos porMedia\n2- Ordenar por nome de aluno\n3- Ordenar por número de aluno\n4- Voltar ao Menu Principal\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: ordernarMedia();
				break;
			case 2: ordernarNome();
				break;
			case 3: ordernarNumero();
				break;
			case 4: 
			case 0: return;
		}
	}
	
}
*/

void adicionarAluno(){
	//Consumindo o ´/n´ do buffer de entrada.
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("Digite o nome do aluno: ");
	fgets(alunos[totalAlunos], 100, stdin);
	for (i = 0; i < 3; i++){
		printf("%s", alunos[i]);
	}
	totalAlunos++;

}
void removerAluno(){
	char nome[100];
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("Digite o nome ou ID do aluno a ser removido: ");
	fgets(nome, 100, stdin);
	for (i = 0; i < 100; i++){
		if (strcmp(nome, alunos[i])== 0){
			strcpy(alunos[i], alunos[i+1]);
			totalAlunos--;
		}
	}
}

void listarAlunos(){
	for (i = 0; i < totalAlunos; i++){
		printf("%s", alunos[i]);
	}
}

void gerirAlunos(){
	int n = -1;
	while (n!= 0){
		printf("1- Adicionar Aluno\n2- Remover Aluno\n3- Listar Alunos\n0- Voltar Menu Pricinpal\n");
		scanf("%d", &n);
		switch(n) {
			case 1: adicionarAluno();
				break;
			case 2: removerAluno();
				break;
			case 3: listarAlunos();
				break;
			case 0: return;
		}
	}
}
void menu(){
	int n = -1;
		while(n!=0){
		printf("1- Gestão Alunos\n2- Gestão Notas\n3- Ordernar Alunos\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: gerirAlunos();
				break;
			//case 2: gerirNotas();
			//	break;
			//case 3: ordenar();
			//	break;
			case 0: return;
		}
	}	
}



void main(){
	setlocale(LC_ALL,"Portuguese");
	menu();
}

