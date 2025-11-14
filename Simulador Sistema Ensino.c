#include <stdio.h>

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int n = -1;
float media;
void menu(){
		while(n!=0){
		printf("1- Gestão Alunos\n2- Gestão Notas\n3- Ordernar Alunos\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: gerirAlunos();
				break;
			case 2: gerirNotas();
				break;
			case 3: ordenar();
				break;
			case 0: return;
		}
	}
}
void gerirAlunos(){
		while(n!=0){
		printf("1- Adicionar Aluno\n2- Remover Aluno\n3- Listar Alunos\n4- Voltar ao Menu Principal\n0- Sair\n");
		scanf("%i", &n);
		switch(n){
			case 1: adicionarAlunos();
				break;
			case 2: removerAluno();
				break;
			case 3: listarAlunos();
				break;
			case 4: menu();
				break;
			case 0: return;
		}
	}
}

void gerirNotas(){
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
 int main(){
	setlocale(LC_ALL,"Portuguese");
	menu();
}

