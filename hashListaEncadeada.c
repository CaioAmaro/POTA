/*
	CAIO ITALO LIMA AMARO 03174784
	CIÊNCIA DA COMPUTAÇÃO 4 PERIODO NOTURNO
	30/09/2020 - POTA
	
	DESCRIAÇÃO CONSTRUIR UM SISTEMA DE BUSCA DO MODELO HASH COM LISTA ENCADEADA
*/
#include <stdio.h>
#include <stdlib.h>

#define M 19

//TIPO DE PESSOA
typedef struct{
	int matricula;
	char nome[50];
} Pessoa;

// TIPO NÓ
typedef struct no{
	Pessoa pessoa;
	struct no *proximo;
} No;

//TIPO DE LISTA
typedef struct{
	No *inicio;
	int tam;
} Lista;

//TABELA ( VETOR DE PONTEIROS PARA LISTA)
Lista *tabela[M];



//CRIA E RETORNA UM TIPO PESSOA
Pessoa criarPessoa(){
	Pessoa p;
	printf("Digite o nome da pessoa: ");
	scanf("%*c");
	fgets(p.nome,50,stdin);
	printf("Digite a matricula: ");
	scanf("%d", &p.matricula);
	return p;
}

//IMPRIMIR UMA PESSOA
void imprimirPessoa (Pessoa p){
	printf("\n nome: %s\tMatricula: %d\n",p.nome,p.matricula);
}

//LISTAS
Lista* criarLista(){
	Lista *l = malloc(sizeof(Lista));
	l->inicio = NULL;
	l->tam = 0;
	return l;
}

void inserirInicio(Pessoa p,Lista *lista){
	No *no = malloc(sizeof(No));
	no->pessoa = p;
	
	no->proximo = lista->inicio;
	lista->inicio = no;
	lista->tam++;
}

//BUSCA 
No* buscarNo (int mat,No *inicio){
	while(inicio != NULL){
		if(inicio->pessoa.matricula == mat){
			return inicio;
		}else{
			inicio = inicio->proximo;
		}
	}
	return NULL;
}

void imprimirLista(No *inicio){
	while(inicio != NULL){
		imprimirPessoa(inicio->pessoa);
		inicio = inicio->proximo;
	}
}

void inicializar(){
	int i;
	for(i=0;i <M;i++){
		tabela[i] = criarLista();
	}
}

int funcaoEspalhamento(int mat){
	return mat % M;
}

void inserirTabela(){
	Pessoa pes = criarPessoa();
	int indice = funcaoEspalhamento(pes.matricula);
	inserirInicio(pes, tabela[indice]);
}

Pessoa* buscarPessoaTabela(int mat){
	int indice = funcaoEspalhamento(mat);
	No *no = buscarNo(mat,tabela[indice]->inicio);
	if(no){
		return &no->pessoa;
	}else{
		return NULL;
	}
}

void imprimirTabela(){
	int i;
	printf("\n----------TABELA---------\n");
	for(i=0; i<M; i++){
		printf("\n %d Lista tamanho: %d",i,tabela[i]->tam);
		imprimirLista(tabela[i]->inicio);
	}
	printf("\n----------FIM TABELA---------\n");
}

int main(){
	int op, mat;
	Pessoa *p;
	inicializar();
	
		do{
			printf("\n0 SAIR \n1 INSERIR \n2 BUSCAR \n3  IMPRIMIR TABELA\n");
			scanf("%d", &op);
			switch(op){
				case 0:
						printf("saindo.... \n");
					break;
					
				case 1:
					inserirTabela();
					break;
				
				case 2:
					printf("Qual matricula ser buscada");
					scanf("%d", &mat);
					p = buscarPessoaTabela(mat);
					if(p){
						printf("Pessoa encontrada: Matricula: %d  Nome: %s", p->matricula,p->nome);
					}else{
						printf("Pessoa nao encontrada");
					}
				
					break;
					
				case 3:
					imprimirTabela();
					break;
						
				default:
					printf("opcao invalida \n");
			}
		}while(op != 0);
	
	
	
	
	
	
	
	
	
	
	return 0;
}

















