#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define max 10

typedef struct Aluno{
	char s_nome[15];
	int idade;	
}Aluno;

typedef struct {
	Aluno aluno[max];
	int nElem;
		
}Lista;

//Cria uma lista ("Manipulada pelo nElem")
void criarLista(Lista *lista){
	if(lista->nElem<0){
		lista->nElem=0; 
		printf("LISTA CRIADA COM SUCESSO!!!\n\n");
	}
	else
		printf("LISTA JA CRIADA !!!\n\n");
}

//Excluir lista ja criada
void excluirLista(Lista *lista){
	if(lista->nElem>=0){
		lista->nElem=-1;
		printf("LISTA EXCLUIDO COM SUCESSO !!!\n\n");
	}else
		printf("NAO A LISTA PARA EXCLUIR!!!\n\n");
}

void cadastrarAluno(Lista *lista, Aluno al){
					
	lista->aluno[lista->nElem]=al;
	printf("\nALUNO CADASTRADO COM SUCESSO!!!\n\n");
	lista->nElem++;
}

void listagem(Lista *lista){
	
	Aluno al;
	int i;
	
	if(lista->nElem>=1){
		for(i=0;i<lista->nElem;i++){
			al=lista->aluno[i];
			
			printf("NOME: %s",al.s_nome);
			printf("\nIDADE: %d", al.idade);
			printf("\n\n");
		}	
	}
	else
		printf("SEM DADOS !!!\n\n");
	
	
}

int main (){
	
	int op;
	
	Lista lista; 
	Aluno al;
	
	lista.nElem = -1;
	
	while(true){
		system("CLS"); // Limpa a tela
		
		printf("Criar lista - 1\n");
		printf("Excluir lista - 2\n");
		printf("Cadastrar Aluno -3\n");
		printf("Listar Alunos - 4\n");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d",&op);
		
		printf("\n\n");
		
		switch (op){
			case 0:
				exit(0);
				break;
		
			case 1:
				criarLista(&lista);
				break;
			
			case 2:
				excluirLista(&lista);
				break;
			
			case 3:
				if(lista.nElem>=0){
					printf("CADASTRO ALUNO NOVO\n\n");
					printf("NOME: ");
					scanf("%s",al.s_nome);
	
					printf("Idade: ");
					scanf("%i",&al.idade);				
					cadastrarAluno(&lista, al);
				}
				else
					printf("NAO FOI POSSIVEL CADASTRAR POIS NAO A UMA LISTA\n\n");
										
				break;
				
			case 4:				
				listagem(&lista);
				break;
		}
		system("PAUSE"); //Tempo para visualizar a resposta
		
	}
	
	return 0;
}
