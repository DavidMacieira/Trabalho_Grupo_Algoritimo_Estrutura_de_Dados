#include <stdio.h>

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int n = -1;

void gerirAlunos(){
	
}

void gerirNotas(){
	
}

void ordenar(){
	
}
int main(){
	setlocale(LC_ALL,"Portuguese");
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

