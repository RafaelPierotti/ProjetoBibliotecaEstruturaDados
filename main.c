//Feito Por
//Jose Ricardo Gustavo – 202114786
//Rafael Pierotti - 202318464
//Marcelo Duran – 202324984
//Cauã Zambotto - 202318466

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_LINHA 1024
#define DELIMITADOR ";"

typedef struct livro{
    char titulo[100];
	char autor[100];
	char editora[100];
	char genero[100];
	int ano_publicacao;
	float preco;
    struct Livro* prox;
 //   int qtd_estoque;
//	int qtd_local;
	//int qtd_saidos;
}Livro;

typedef struct aluno{
	char ra[50];
	char nome[100];
	char data_nasc[20];
	char endereco[100];
	char telefone[20];
}aluno;

typedef struct funcionario{
	char cod[50];
	char nome[100];
	char data_nasc[20];
	char endereco[100];
	char telefone[20];
}funcionario;

typedef struct fila {
    Livro* inicio;
    Livro* fim;
}Fila;

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int vazia(Fila* f){
    return (f->inicio == NULL);
}

void enqueue(Fila* f, const char* titulo, const char* autor, const char* editora, const char* genero, int ano_publicacao, float preco){
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));

    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->editora, editora);
    strcpy(novoLivro->genero, genero);
    novoLivro->ano_publicacao = ano_publicacao;
    novoLivro->preco = preco;
    novoLivro->prox = NULL;

    if (f->fim == NULL)
        f->fim->prox = novoLivro;
    f->fim = novoLivro;
    if (f->inicio == NULL)
        f->inicio = f->fim;
}

void dequeue(Fila *f){
    if (vazia(f)){
        printf("Fila vazia!\n");
        exit(1);
    }
    float temp;
    temp = f->inicio->titulo;
    Livro* aux = f->inicio->prox;
    free(f->inicio);
    f->inicio = aux;
    if (f->inicio == NULL)
        f->fim = NULL;
    return temp;
}

void mostrarLivros(Fila* f){
    Livro* aux;
    for (aux = f->inicio; aux != NULL, aux = aux->prox)
        prinf("Título: %s, Autor: %s, Editora: %s, Gênero: %s, Ano de Publicação: %d, Preço: %f\n", aux->titulo, aux->autor, aux->editora, aux->genero, aux->ano_publicacao, aux->preco);
}

void libera(Fila* f){
    Livro* aux = f->inicio;
    while (aux != NULL) {
        Livro* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(f);
}

void inclui_livro(){
	livro livro;
	FILE *arq;
	struct tm *p;
    time_t seconds;
    time(&seconds);

	system("CLS");

	printf("\nDados Inclusao Livro\n\n");
	printf("Codigo: ");
	scanf("%d", &livro.cod);
	printf("Nome do Livro: ");
	fflush(stdin);
	gets(livro.nome);
	printf("Nome do Autor: ");
	fflush(stdin);
	gets(livro.autor);
	printf("Quantidade em Estoque: ");
	scanf("%d", &livro.qtd_estoque);
	livro.qtd_local = livro.qtd_estoque;
	livro.qtd_saidos = 0;

	if((arq = fopen("livro.csv", "a")) != NULL){
		fprintf(arq, "\n%d;%s;%s;%d;%d;%d", livro.cod, livro.nome, livro.autor, livro.qtd_estoque, livro.qtd_local, livro.qtd_saidos);
    	p = localtime(&seconds);
		printf("Inclusao Concluida!");
	}
	fclose(arq);

	if((arq = fopen("log_inclusao.txt", "a")) != NULL){
		fprintf(arq, "\nData: %d/%d/%d Hora: %d:%d:%d - Incluido Livro: %s - Codigo: %d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, livro.nome, livro.cod);
	}
	fclose(arq);

	menu_principal();
}

void inclui_aluno(){
	aluno aluno;
	FILE *arq;
	struct tm *p;
    time_t seconds;
    time(&seconds);

	system("CLS");

	printf("\nDados Inclusao Aluno\n\n");
	printf("RA: ");
	fflush(stdin);
	gets(aluno.ra);
	printf("Nome do Aluno: ");
	fflush(stdin);
	gets(aluno.nome);
	printf("Data de Nascimento: ");
	fflush(stdin);
	gets(aluno.data_nasc);
	printf("Endereco: ");
	fflush(stdin);
	gets(aluno.endereco);
	printf("Telefone: ");
	fflush(stdin);
	gets(aluno.telefone);

	if((arq = fopen("aluno.csv", "a")) != NULL){
		fprintf(arq, "\n%s;%s;%s;%s;%s", aluno.ra, aluno.nome, aluno.data_nasc, aluno.endereco, aluno.telefone);
		p = localtime(&seconds);
		printf("Inclusao Concluida!");
	}
	fclose(arq);

	if((arq = fopen("log_inclusao.txt", "a")) != NULL){
		fprintf(arq, "\nData: %d/%d/%d Hora: %d:%d:%d - Incluido Aluno: %s - RA: %s", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, aluno.nome, aluno.ra);
	}
	fclose(arq);

	menu_principal();
}

void inclui_funcionario(){
	funcionario funcionario;
	FILE *arq;
	struct tm *p;
    time_t seconds;
    time(&seconds);

	system("CLS");

	printf("\nDados Inclusao Funcionario\n\n");
	printf("Codigo: ");
	fflush(stdin);
	gets(funcionario.cod);
	printf("Nome do Funcionario: ");
	fflush(stdin);
	gets(funcionario.nome);
	printf("Data de Nascimento: ");
	fflush(stdin);
	gets(funcionario.data_nasc);
	printf("Endereco: ");
	fflush(stdin);
	gets(funcionario.endereco);
	printf("Telefone: ");
	fflush(stdin);
	gets(funcionario.telefone);

	if((arq = fopen("funcionario.txt", "a")) != NULL){
		fprintf(arq, "\n%s;%s;%s;%s;%s", funcionario.cod, funcionario.nome, funcionario.data_nasc, funcionario.endereco, funcionario.telefone);
		p = localtime(&seconds);
		printf("Inclusao Concluida!");
	}
	fclose(arq);

	if((arq = fopen("log_inclusao.csv", "a")) != NULL){
		fprintf(arq, "\nData: %d/%d/%d Hora: %d:%d:%d - Incluido Funcionario: %s - Codigo: %s", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, funcionario.nome, funcionario.cod);
	}
	fclose(arq);

	menu_principal();
}

void entrada_livro(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Entradas Livros\n\n1 - Aluno\n2 - Funcionario\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Aluno
			entrada_livro_aluno();
			break;

		case 2: //Funcionario
			entrada_livro_funcionario();
			break;

		case 3: //Voltar
			menu_entrada();
			break;

		default:
			printf("Opcao Invalida");
			entrada_livro();
	}
}

void saida_livro(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Saidas Livros\n\n1 - Aluno\n2 - Funcionario\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Aluno
			saida_livro_aluno();
			break;

		case 2: //Funcionario
			saida_livro_funcionario();
			break;

		case 3: //Voltar
			menu_saida();
			break;

		default:
			printf("Opcao Invalida");
			saida_livro();
	}
}

void entrada_pessoa(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Entradas Pessoas\n\n1 - Aluno\n2 - Funcionario\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Aluno
			entrada_aluno();
			break;

		case 2: //Funcionario
			entrada_funcionario();
			break;

		case 3: //Voltar
			menu_entrada();
			break;

		default:
			printf("Opcao Invalida");
			entrada_pessoa();
	}
}

void saida_pessoa(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Saidas Pessoas\n\n1 - Aluno\n2 - Funcionario\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Aluno
			saida_aluno();
			break;

		case 2: //Funcionario
			saida_funcionario();
			break;

		case 3: //Voltar
			menu_saida();
			break;

		default:
			printf("Opcao Invalida");
			saida_pessoa();
	}
}

void entrada_livro_aluno(){
	char linha[MAX_LINHA];
	int n_livro = 0, i, f, g, qtd_entrada;
	int cod_livro;
	char ra[50];
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);

    system("CLS");

    printf("\nEntrada Livro Aluno\n");

    // Lendo livro.csv
    if((arq = fopen("livro.csv", "r")) != NULL){
	    while (fgets(linha, MAX_LINHA, arq) != NULL) {
	    	n_livro = n_livro + 1;
		}
	}
	fclose(arq);

	livro livro[n_livro];

	if((arq = fopen("livro.csv", "r")) != NULL){
		i = 0;
		while(fscanf(arq, "%d;%[^;];%[^;];%d;%d;%d", &livro[i].cod, livro[i].nome, livro[i].autor, &livro[i].qtd_estoque, &livro[i].qtd_local, &livro[i].qtd_saidos) != EOF){
			i = i + 1;
		}
	}
	fclose(arq);

	printf("RA: ");
	fflush(stdin);
	gets(ra);

	printf("Codigo do Livro: ");
	scanf("%d", &cod_livro);

	for(f = 0; f < n_livro; f++){
		if(cod_livro == livro[f].cod){
					printf("Quantidade Devolvida: ");
					scanf("%d", &qtd_entrada);
					livro[f].qtd_local = livro[f].qtd_local + qtd_entrada;
					livro[f].qtd_saidos = livro[f].qtd_saidos - qtd_entrada;
				    if((arq = fopen("livro.csv", "w")) != NULL){
				    	fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[0].cod, livro[0].nome, livro[0].autor, livro[0].qtd_estoque, livro[0].qtd_local, livro[0].qtd_saidos);
				    }
					fclose(arq);

					if((arq = fopen("livro.csv", "a")) != NULL){
						for(g = 1; g < n_livro; g ++){
						    fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[g].cod, livro[g].nome, livro[g].autor, livro[g].qtd_estoque, livro[g].qtd_local, livro[g].qtd_saidos);
						}
					}
					fclose(arq);

					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao_livros.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Aluno - RA: %s - Devolveu o Livro - Codigo: %d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, ra, cod_livro);
					}
					fclose(arqmov);
				}
			}
	menu_principal();
}

void saida_livro_aluno(){
	char linha[MAX_LINHA];
	int n_livro = 0, i, f, g, qtd_retirado;
	int cod_livro;
	char ra[50];
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);

    system("CLS");

    printf("\nSaida Livro Aluno\n");

    // Lendo livro.csv
    if((arq = fopen("livro.csv", "r")) != NULL){
	    while (fgets(linha, MAX_LINHA, arq) != NULL) {
	    	n_livro = n_livro + 1;
		}
	}
	fclose(arq);

	livro livro[n_livro];

	if((arq = fopen("livro.csv", "r")) != NULL){
		i = 0;
		while(fscanf(arq, "%d;%[^;];%[^;];%d;%d;%d", &livro[i].cod, livro[i].nome, livro[i].autor, &livro[i].qtd_estoque, &livro[i].qtd_local, &livro[i].qtd_saidos) != EOF){
			i = i + 1;
		}
	}
	fclose(arq);

	printf("RA: ");
	fflush(stdin);
	gets(ra);
			printf("Codigo do Livro: ");
			scanf("%d", &cod_livro);

			for(f = 0; f < n_livro; f++){
				if(cod_livro == livro[f].cod){
					printf("Quantidade Retirada: ");
					scanf("%d", &qtd_retirado);
					livro[f].qtd_local = livro[f].qtd_local - qtd_retirado;
					livro[f].qtd_saidos = livro[f].qtd_saidos + qtd_retirado;
				    if((arq = fopen("livro.csv", "w")) != NULL){
				    	fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[0].cod, livro[0].nome, livro[0].autor, livro[0].qtd_estoque, livro[0].qtd_local, livro[0].qtd_saidos);
				    }
					fclose(arq);

					if((arq = fopen("livro.csv", "a")) != NULL){
						for(g = 1; g < n_livro; g ++){
						    fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[g].cod, livro[g].nome, livro[g].autor, livro[g].qtd_estoque, livro[g].qtd_local, livro[g].qtd_saidos);
						}
					}
					fclose(arq);

					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao_livros.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Aluno - RA: %s - Retirou o Livro - Codigo: %d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, ra, cod_livro);
					}
					fclose(arqmov);
				}
			}
	menu_principal();
}

void entrada_livro_funcionario(){
	char linha[MAX_LINHA];
	int n_livro = 0, i, f, g, qtd_entrada;
	int cod_livro;
	char cod[50];
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);

    system("CLS");

    printf("\nEntrada Livro Funcionario\n");

    // Lendo livro.csv
    if((arq = fopen("livro.csv", "r")) != NULL){
	    while (fgets(linha, MAX_LINHA, arq) != NULL) {
	    	n_livro = n_livro + 1;
		}
	}
	fclose(arq);

	livro livro[n_livro];

	if((arq = fopen("livro.csv", "r")) != NULL){
		i = 0;
		while(fscanf(arq, "%d;%[^;];%[^;];%d;%d;%d", &livro[i].cod, livro[i].nome, livro[i].autor, &livro[i].qtd_estoque, &livro[i].qtd_local, &livro[i].qtd_saidos) != EOF){
			i = i + 1;
		}
	}
	fclose(arq);

	printf("Codigo Funcionario: ");
	fflush(stdin);
	gets(cod);

	printf("Codigo do Livro: ");
	scanf("%d", &cod_livro);

	for(f = 0; f < n_livro; f++){
		if(cod_livro == livro[f].cod){
					printf("Quantidade Devolvida: ");
					scanf("%d", &qtd_entrada);
					livro[f].qtd_local = livro[f].qtd_local + qtd_entrada;
					livro[f].qtd_saidos = livro[f].qtd_saidos - qtd_entrada;
				    if((arq = fopen("livro.csv", "w")) != NULL){
				    	fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[0].cod, livro[0].nome, livro[0].autor, livro[0].qtd_estoque, livro[0].qtd_local, livro[0].qtd_saidos);
				    }
					fclose(arq);

					if((arq = fopen("livro.csv", "a")) != NULL){
						for(g = 1; g < n_livro; g ++){
						    fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[g].cod, livro[g].nome, livro[g].autor, livro[g].qtd_estoque, livro[g].qtd_local, livro[g].qtd_saidos);
						}
					}
					fclose(arq);

					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao_livros.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Funcionario - Codigo: %s - Devolveu o Livro - Codigo: %d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, cod, cod_livro);
					}
					fclose(arqmov);
				}
			}
	menu_principal();
}

void saida_livro_funcionario(){
	char linha[MAX_LINHA];
	int n_livro = 0, i, f, g, qtd_retirado;
	int cod_livro;
	char cod[50];
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);

    system("CLS");

    printf("\nSaida Livro Funcionario\n");

    // Lendo livro.csv
    if((arq = fopen("livro.csv", "r")) != NULL){
	    while (fgets(linha, MAX_LINHA, arq) != NULL) {
	    	n_livro = n_livro + 1;
		}
	}
	fclose(arq);

	livro livro[n_livro];

	if((arq = fopen("livro.csv", "r")) != NULL){
		i = 0;
		while(fscanf(arq, "%d;%[^;];%[^;];%d;%d;%d", &livro[i].cod, livro[i].nome, livro[i].autor, &livro[i].qtd_estoque, &livro[i].qtd_local, &livro[i].qtd_saidos) != EOF){
			i = i + 1;
		}
	}
	fclose(arq);

	printf("Codigo Funcionario: ");
	fflush(stdin);
	gets(cod);

	printf("Codigo do Livro: ");
	scanf("%d", &cod_livro);

	for(f = 0; f < n_livro; f++){
		if(cod_livro == livro[f].cod){
					printf("Quantidade Retirada: ");
					scanf("%d", &qtd_retirado);
					livro[f].qtd_local = livro[f].qtd_local - qtd_retirado;
					livro[f].qtd_saidos = livro[f].qtd_saidos + qtd_retirado;
				    if((arq = fopen("livro.csv", "w")) != NULL){
				    	fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[0].cod, livro[0].nome, livro[0].autor, livro[0].qtd_estoque, livro[0].qtd_local, livro[0].qtd_saidos);
				    }
					fclose(arq);

					if((arq = fopen("livro.csv", "a")) != NULL){
						for(g = 1; g < n_livro; g ++){
						    fprintf(arq, "%d;%s;%s;%d;%d;%d\n", livro[g].cod, livro[g].nome, livro[g].autor, livro[g].qtd_estoque, livro[g].qtd_local, livro[g].qtd_saidos);
						}
					}
					fclose(arq);

					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao_livros.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Funcionario - Codigo: %s - Retirou o Livro - Codigo: %d", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, cod, cod_livro);
					}
					fclose(arqmov);
				}
			}
	menu_principal();
}

void entrada_aluno(){
	char ra[50];
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);
    int val;

	system("CLS");

	printf("\nEntrada Aluno\n");
	printf("\nRA: ");
	fflush(stdin);
	gets(ra);

	if((arq = fopen("aluno.csv", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ) {
	            if(strcmp(campo,ra) == 0){
	            	val = 1;
	            	printf("RA Encontrado!");
					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Aluno - RA: %s - Entrou", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, ra);
					}
					fclose(arqmov);
				}
	            campo = strtok(NULL, DELIMITADOR);
	        }
    	}
	}
	fclose(arq);

	if(val == 1){
		menu_principal();
	}else{
		entrada_aluno();
	}
}

void saida_aluno(){
	char ra[50];
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);
    int val;

	system("CLS");

	printf("\nSaida Aluno\n");
	printf("\nRA: ");
	fflush(stdin);
	gets(ra);

	if((arq = fopen("aluno.csv", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ) {
	            if(strcmp(campo,ra) == 0){
	            	val = 1;
	            	printf("RA Encontrado!");
					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Aluno - RA: %s - Saiu", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, ra);
					}
					fclose(arqmov);
				}
	            campo = strtok(NULL, DELIMITADOR);
	        }
    	}
	}
	fclose(arq);

	if(val == 1){
		menu_principal();
	}else{
		saida_aluno();
	}
}

void entrada_funcionario(){
	char cod[50];
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);
    int val;

	system("CLS");

	printf("\nEntrada Funcionario\n");
	printf("\nCodigo: ");
	fflush(stdin);
	gets(cod);

	if((arq = fopen("funcionario.csv", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ) {
	            if(strcmp(campo,cod) == 0){
	            	val = 1;
	            	printf("Codigo Encontrado!");
					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Funcionario - Codigo: %s - Entrou", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, cod);
					}
					fclose(arqmov);
				}
	            campo = strtok(NULL, DELIMITADOR);
	        }
    	}
	}
	fclose(arq);

	if(val == 1){
		menu_principal();
	}else{
		entrada_funcionario();
	}
}

void saida_funcionario(){
	char cod[50];
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	FILE *arqmov;
	struct tm *p;
    time_t seconds;
    time(&seconds);
    int val;

	system("CLS");

	printf("\nSaida Funcionario\n");
	printf("\nCodigo: ");
	fflush(stdin);
	gets(cod);

	if((arq = fopen("funcionario.csv", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ) {
	            if(strcmp(campo,cod) == 0){
	            	val = 1;
	            	printf("Codigo Encontrado!");
					p = localtime(&seconds);
					if((arqmov = fopen("log_movimentacao.txt", "a")) != NULL){
						fprintf(arqmov, "\nData: %d/%d/%d Hora: %d:%d:%d - Funcionario - Codigo: %s - Saiu", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, p->tm_hour, p->tm_min, p->tm_sec, cod);
					}
					fclose(arqmov);
				}
	            campo = strtok(NULL, DELIMITADOR);
	        }
    	}
	}
	fclose(arq);

	if(val == 1){
		menu_principal();
	}else{
		saida_funcionario();
	}
}

void listar_livros(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("livro.csv", "r")) != NULL){
	    printf("Codigo\tNome\tAutor\tQuant_Estoque\tQuant_Local\tQuant_Saidos");
		while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("\n");
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ){
	            printf( "%s\t", campo);
	            campo = strtok(NULL, DELIMITADOR);
	        }
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_livros();
	}
}

void listar_alunos(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("aluno.csv", "r")) != NULL){
	    printf("RA\tNome\tData_Nascimento\tEndereco\tTelefone");
		while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("\n");
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ){
	            printf( "%s\t", campo);
	            campo = strtok(NULL, DELIMITADOR);
	        }
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_alunos();
	}
}

void listar_funcionarios(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("funcionario.csv", "r")) != NULL){
	    printf("Codigo\tNome\tData_Nascimento\tEndereco\tTelefone");
		while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("\n");
	        campo = strtok(linha, DELIMITADOR);
	        while( campo != NULL ){
	            printf( "%s\t", campo);
	            campo = strtok(NULL, DELIMITADOR);
	        }
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_funcionarios();
	}
}

void listar_inclusoes(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("log_inclusao.txt", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("%s", linha);
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_inclusoes();
	}
}

void listar_movimentacoes(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("log_movimentacao.txt", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("%s", linha);
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_movimentacoes();
	}
}

void listar_movimentacoes_livros(){
	char linha[MAX_LINHA];
	char *campo;
	FILE *arq;
	int op;

	system("CLS");

	if((arq = fopen("log_movimentacao_livros.txt", "r")) != NULL){
	    while(fgets(linha, MAX_LINHA, arq) != NULL){
			printf("%s", linha);
		}
    }
	fclose(arq);

	printf("\n\nVoltar Menu Principal\n\n1 - Sim\n2 - Nao\n\nOpcao: ");
	scanf("%d", &op);

	if(op == 1){
		menu_principal();
	}else if(op == 2){
		listar_movimentacoes();
	}
}

void menu_incluir(){
	int op;

	system("CLS");

	printf("\nMenu Incluir\n\n1 - Livro\n2 - Aluno\n3 - Funcionario\n4 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Incluir Livro
			inclui_livro();
			break;

		case 2: //Incluir Aluno
			inclui_aluno();
			break;

		case 3: //Incluir Funcionario
			inclui_funcionario();
			break;

		case 4: //Voltar
			menu_principal();
			break;

		default:
			printf("Opcao Invalida");
			menu_incluir();
	}
}

void menu_entrada(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Entradas\n\n1 - Livros\n2 - Pessoas\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Livro
			entrada_livro();
			break;

		case 2: //Pessoa
			entrada_pessoa();
			break;

		case 3: //Voltar
			menu_registrar();
			break;

		default:
			printf("Opcao Invalida");
			menu_entrada();
	}
}

void menu_saida(){
	int op;

	system("CLS");

	printf("\nMenu Registrar Saidas\n\n1 - Livros\n2 - Pessoas\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Livro
			saida_livro();
			break;

		case 2: //Pessoa
			saida_pessoa();
			break;

		case 3: //Voltar
			menu_registrar();
			break;

		default:
			printf("Opcao Invalida");
			menu_saida();
	}
}

void menu_registrar(){
	int op;

	system("CLS");

	printf("\nMenu Registrar\n\n1 - Entrada\n2 - Saida\n3 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Entradas
			menu_entrada();
			break;

		case 2: //Saidas
			menu_saida();
			break;

		case 3: //Voltar
			menu_principal();
			break;

		default:
			printf("Opcao Invalida");
			menu_registrar();
	}
}

void menu_registro(){
	int op;

	system("CLS");

	printf("\nMenu Registros\n\n1 - Listar Livros\n2 - Listar Alunos\n3 - Listar Funcionarios\n4 - Listar Inclusoes\n5 - Listar Entrada/Saida Pessoas\n6 - Listar Entrada/Saida Livros\n7 - Voltar\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Livros
			listar_livros();
			break;

		case 2: //Alunos
			listar_alunos();
			break;

		case 3: //Funcionarios
			listar_funcionarios();
			break;

		case 4: //Inclusoes
			listar_inclusoes();
			break;

		case 5: //Movimentacoes
			listar_movimentacoes();
			break;

		case 6: //Movimentacoes Livros
			listar_movimentacoes_livros();
			break;

		case 7: //Voltar
			menu_principal();
			break;

		default:
			printf("Opcao Invalida");
			menu_registro();
	}
}

void menu_principal(){
	int op;

	system("CLS");

	printf("\nMenu Principal\n\n1 - Incluir\n2 - Registrar\n3 - Consultar Registros\n4 - Sair\n\nOpcao: ");
	scanf("%d", &op);

	switch(op){
		case 1: //Incluir
			menu_incluir();
			break;

		case 2: //Registrar
			menu_registrar();
			break;

		case 3: //Registros
			menu_registro();
			break;

		case 4:
			exit(0);

		default:
			printf("Opcao Invalida");
			menu_principal();
	}
}

int main() {
	menu_principal();
	return 0;
}
