#include <stdio.h>

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int n = -1;
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
			case 1: gerirAlunos();
				break;
			case 2: gerirNotas();
				break;
			case 3: ordenar();
				break;
			case 4: menu();
				break;
			case 0: return;
		}
	}
}

void gerirNotas(){
	
}

void ordenar(){
	
}
 int main(){
	setlocale(LC_ALL,"Portuguese");
	menu();
}

