#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define max 10

typedef struct Aluno{
	char s_nome[30];
	int idade;	
}Aluno;

typedef struct {
	Aluno aluno[max];
	int nElem;
		
}Lista;

//Variaveis globaiss
	FILE *file;

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
		printf("LISTA DELETADA COM SUCESSO !!!\n\n");
	}else
		printf("NAO A LISTA PARA EXCLUIR!!!\n\n");
}

//Cadastra Aluno na lista
void cadastrarAluno(Lista *lista, Aluno al){
				
	lista->aluno[lista->nElem]=al;//Armazena dentro do Array
	
	printf("\nALUNO CADASTRADO COM SUCESSO!!!\n\n");
	
	lista->nElem++; //Acrescenta um aluno
}

//Mostra todos alunos cadastrados
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

//Busca alunos pelo nome
void buscarAluno(Lista *lista){
	if(lista->nElem>=1){
		char nome[30];
		int i;
		int x=0; //quantidade achada;
		Aluno al;
	
		printf("Qual nome deseja pesquisar: ");
		scanf("%s",&nome);
		
		for(i=0; i<lista->nElem;i++){
			if(strcasecmp(nome,lista->aluno[i].s_nome)==0){

				al=lista->aluno[i];
				
				printf("\nNOME: %s",al.s_nome);
				printf("\nIDADE: %d", al.idade);
				printf("\n\n");
				
				x=1;
			}
		}
		
		if(x==0){
			printf("\nNenhum dado encontrado !!!\n\n");
		}
		
	}else
		printf("Seria melhor criar uma lista primeiro !!!\n\n");	
}

//Salva dados em arquivo .txt
void salvar(Lista *lista){
	
	Aluno al;
	int i;
	
	file = fopen("Alunos.txt","w");
	fclose(file);
		
	if(lista->nElem>=1){
		for(i=0;i<lista->nElem;i++){
			al=lista->aluno[i];
			
			file = fopen("Alunos.txt","a");
			
			fprintf(file,"NOME: %s\n",al.s_nome); //Guarda dentro do txt
			fprintf(file,"IDADE: %d\n\n",al.idade);
			
			fclose(file);			
		}	
		printf("ARQUIVO SALVO NA PASTA RAIZ COM SUCESSO !!! \n\n");
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
		printf("Cadastrar Aluno - 2\n");
		printf("Listar Alunos - 3\n");
		printf("Excluir lista - 4\n");
		printf("Buscar aluno [por nome] - 5\n");
		printf("Salvar Lista em arquivo Alunos.txt - 6\n\n");
		
		
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
				if(lista.nElem>=0){
					printf("CADASTRO ALUNO NOVO\n\n");
					printf("NOME: ");
					setbuf(stdin,0); // Limpar o buffer
					
					gets(al.s_nome); // A string aceita space				
	
					printf("Idade: ");
					scanf("%i",&al.idade);				
					cadastrarAluno(&lista, al);
				}
				else
					printf("NAO FOI POSSIVEL CADASTRAR POIS NAO A UMA LISTA\n\n");
										
				break;
				
			case 3:
				listagem(&lista);
				break;
				
			case 4:				
				excluirLista(&lista);
				break;
			
			case 5:
				buscarAluno(&lista);
				break;				
			
			case 6:							
				salvar(&lista);
				
				break;
			
			default :
				printf("\nOPCAO INVALIDA !!!\n\n");
		}
		system("PAUSE"); //Tempo para visualizar a resposta
		
	}
	
	return 0;
}
