/*
	CAIO ITALO LIMA AMARO 03174784
	CIÊNCIA DA COMPUTAÇÃO 4 PERIODO NOTURNO
	30/09/2020 - POTA
	
	DESCRIAÇÃO CONSTRUIR UM SISTEMA DE BUSCA DO MODELO HASH SIMPLES
*/

#include <stdio.h>
#include <stdlib.h>

//CONSTRANTES
#define M 19 // REPRESENTA O TAMANHO DA TABELA

typedef struct{
	int matricula;
	char nome[50];
}Pessoa;

Pessoa tabelaHash[M];

//INICIALIZAR A TABElA COM VALOR DE CODIGO -1 ( -1 É VAZIA);
void inicializarTabela(){
	int i;
	for (i=0; i < M; i++){
		tabelaHash[i].matricula = -1;
	}
}

//FUNCÃO DE ESPALHAMENTO
int gerarCodigoHash(int chave){
	return chave % M;
}

//lER E RETORNAR UMA PESSOA

Pessoa lerPessoa(){
	Pessoa p;
	printf("Digite a  matricula: ");
	scanf("%d", &p.matricula);
	scanf("%*c");
	printf("Digite o nome: ");
	fgets(p.nome, 50, stdin);
	return p;
}

//INSERIR UMA PESSOA NA TABELA
void inserir(){
	Pessoa pes = lerPessoa();
	int indice = gerarCodigoHash(pes.matricula);
	
	while(tabelaHash[indice].matricula != -1){
		indice = gerarCodigoHash(indice + 1);
	} 
	tabelaHash[indice] = pes;
}

Pessoa* buscar(int chave){
	int indice = gerarCodigoHash(chave);
	while(tabelaHash[indice].matricula != -1){
		if(tabelaHash[indice].matricula == chave){
			return &tabelaHash[indice];
		}else{
			indice = gerarCodigoHash(indice +1);
		}
	}
	return NULL;
}

void imprimir(){
	int i;
	
	printf("------------TABELA-------------");
	for(i=0;i<M;i++){
		if(tabelaHash[i].matricula != -1){
			printf("\n %d = %d \t %s", i , tabelaHash[i].matricula, tabelaHash[i].nome);
		}else{
			printf("%d = \n", i);
		}
	}
	printf("-----------------------------");
}

int main(){
	int op, chave;
	Pessoa *p;
	inicializarTabela();
	
	do{
		printf("\n 1- INSERIR \n 2- BUSCAR \n 3- IMPRIMIR \n 0 - SAIR");;
		printf("\n");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				printf("Saindo.... \n");
				break;
			case 1:
				inserir();
				break;
			case 2:
				printf("Digite a matricula a ser procurada: ");
				scanf("%d",&chave);
				p = buscar(chave);
				if(p){
					printf("\n \t Matricula: %d \t Nome: %s \n", p->matricula, p->nome);
				}else{
					printf("\n matricula nao encontrada");
				}
				break;
			case 3:
				imprimir();
			default:
					printf("opcao invalida \n");
				break;
		}
	}while(op != 0);
}
