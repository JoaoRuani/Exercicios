#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char arqName[] = "database.db";
const char arqAux[] = "copyBase.db";


typedef struct{
	char Nome[50];
	int Idade;
	float Salario;
}Registro;

int menu(int sub);
void inserir_registro(FILE *arq, long pos);
void salvar_registro(Registro x, long pos, FILE *arq);
void listar_registros(FILE *arq);
void alterar_registro(FILE *arq);
void apagar_registro(FILE *arq);
void print_registro(Registro x, int i);
void pesquisar_registro(FILE *arq, int type);
 
int main(int argc, char *argv[]){
	FILE *database;
	if((database = fopen(arqName, "a+b")) == NULL){
		fprintf(stderr,"Erro: O arquivo %s não foi aberto!", arqName);
		exit(2);
	}
	int op;
	while((op = menu(0)) != 0){
		system("cls");
		char sair;
		switch(op){
			case 1:
				do{
					fseek(database, 0, SEEK_END);
					inserir_registro(database, ftell(database));
					printf("\n\nDigite 0 para sair ou digite outro valor para continuar: ");
					scanf("%c", &sair);
				}while(sair!='0');
				break;
			case 2:
				alterar_registro(database);
				break;
			case 3:
				apagar_registro(database);
				system("pause");
				break;
			case 4:
				listar_registros(database);
				system("pause");
				break;
			case 5:
				while((op = menu(1)) != 0){
					if(op>=1 && op<=2){
						pesquisar_registro(database, op);
						system("pause");
					}						
					system("cls");
				}
				break;
			default:
				printf("\n Opcao inválida!\n");
		}
	}
	fclose(database);
}
int menu(int sub) {
	system("cls");
	int opcao;
	printf("\n***********************************\n\n");
	if(!sub){
		printf("1. Inserir Registro\n");
		printf("2. Alterar Registro\n");
		printf("3. Apagar Registro\n");
		printf("4. Listar Registros\n");
		printf("5. Pesquisar Registro\n");
		printf("0. Sair\n");
	}
	else{
		printf("1. Pesquisar por intervalo de idades\n");
		printf("2. Pesquisar por nome\n");
		printf("0. Voltar\n");
	}
	printf("\n***********************************\n\n");
	printf("Digite a opcao: ");
	scanf("%d", &opcao);
	fflush(stdin);
	return opcao;
}
void inserir_registro(FILE *arq, long pos){
		Registro x;
		fflush(stdin);
		printf("Digite o nome: ");
		gets(x.Nome);
		printf("Digite a idade: ");
		scanf("%d", &x.Idade);
		printf("Digite o salario: ");
		scanf("%f", &x.Salario);
		fflush(stdin);
		salvar_registro(x, pos, arq);
}
void salvar_registro(Registro x, long pos, FILE *arq){
	rewind(arq);
	fseek(arq, pos, SEEK_SET);
	fwrite(&x, sizeof(Registro), 1, arq);
	fflush(arq);
}
void listar_registros(FILE *arq){
	Registro x;
	int i;
	rewind(arq);
	for(i = 1; fread(&x, sizeof(Registro), 1, arq) != 0; i++)
		print_registro(x, i);
}
void alterar_registro(FILE *arq){
	Registro x;
	int op;
	listar_registros(arq);
	printf("\nQual registro deseja alterar: ");
	scanf("%d", &op);    
	rewind(arq);
	if(fseek(arq, (op-1)* sizeof(Registro), SEEK_SET) != 0)
		printf("\nNão é possível alterar esse registro!\n\n");
	else
		inserir_registro(arq, ftell(arq));
	
}
void apagar_registro(FILE *arq) {
	FILE *copia;
	if((copia = fopen(arqAux, "w+b")) == NULL)
		printf("\nErro: nao foi possivel criar %s\n\n", arqAux);
	else{
		int excluir, i;
		Registro x;
		fflush(arq);
		listar_registros(arq);
		printf("Qual registro deseja excluir: ");
		scanf("%d", &excluir);
		rewind(arq);
		for(i = 1; ; i++){
			if(i == excluir)
				fseek(arq, sizeof(Registro), SEEK_CUR);
			else{
				if(fread(&x, sizeof(Registro), 1, arq) != 1)
					break;
				fwrite(&x, sizeof(Registro), 1, copia);
			}
		}
		fclose(arq);
		fclose(copia);
		remove(arqName);
		rename(arqAux, arqName);
		arq = fopen(arqName, "r+b");
		fflush(arq);
	}
}
void pesquisar_registro(FILE *arq, int type) {
	Registro x;
	int idade1, idade2;
	char nome[51];
	rewind(arq);
	if(type == 1){
		printf("1 Idade: ");
		scanf("%d", &idade1);
		printf("2 Idade: ");
		scanf("%d", &idade2);
		if(idade1 > idade2){
			int aux;
			aux = idade1;
			idade1 = idade2;
			idade2 = aux;
		}		
	}
	else{
		printf("Digite o nome: ");
		gets(nome);
	}                                             
	int i;
	for(i = 1; fread(&x, sizeof(Registro), 1, arq) != 0; i++){
		if(x.Idade >= idade1 && x.Idade <= idade2 && type == 1)
			print_registro(x, i);
		if(!strcmp(nome, x.Nome) && type == 2)
			print_registro(x, i);
	}	
}
void print_registro(Registro x, int i){
	printf("%d - \n", i);
	printf("\tNome:     %s\n", x.Nome);
	printf("\tIdade:    %d\n",x.Idade);
	printf("\tSalario:  %.2f\n\n", x.Salario);
}
