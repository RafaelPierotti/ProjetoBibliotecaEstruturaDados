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
}Livro;

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

void adicionarLivros(Fila* f, const char* titulo, const char* autor, const char* editora, const char* genero, int ano_publicacao, float preco){
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

void removerLivros(Fila *f){
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
        printf("Título: %s, Autor: %s, Editora: %s, Gênero: %s, Ano de Publicação: %d, Preço: %f\n", aux->titulo, aux->autor, aux->editora, aux->genero, aux->ano_publicacao, aux->preco);
}

void buscarLivros(Fila* f, const char* titulo, const char* autor, int ano){
    Livro* livro = f->inicio;
    int encontrado = 0;

    while (livro != NULL){
        if  (titulo == NULL || strcmp(livro->titulo, titulo) == 0) && (autor == NULL || strcmp(livro->autor, autor) == 0) && (ano == -1 || livro->ano_publicacao == ano){
            printf("Resultado encontrado\n");
            prinf("Título: %s, Autor: %s, Editora: %s, Gênero: %s, Ano de Publicação: %d, Preço: %f\n", livro->titulo, livro->autor, livro->editora, livro->genero, livro->ano_publicacao, livro->preco);
            encontrado = 1;
        }
        livro = livro->prox;
    }

    if (!encontrado){
        printf("Nenhum livro encontrado!");
    }
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
    Fila* fila = cria_fila();
    char titulo[100], autor[100], editora[100], genero[100].
    int ano;
    float preco;
    int opcao = -1;

    while (opcao != 0){
        printf("Escolha uma das opções");
        prinf("\n1 - Adicionar Livros\n2 - Remover Livros\n3 - Pesquisar Livros\n4 - Listar Livros\n 0 - Sair");
        scanf("%d", opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                printf("Informe o título do livro: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")];

                printf("Informe o autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")];

                printf("Informe a editora: ");
                fgets(editora, sizeof(editora), stdin);
                editora[strcspn(editora, "\n")];

                printf("Informe o gênero: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")];

                prinf("Informe o ano de publicação: ");
                scanf("%d", &ano);

                printf("Informe o preço: ");
                scanf("%f", &preco);

                adicionarLivros(fila, titulo, autor, editora, genero, ano, preco);
                printf("Livro adicionado com sucesso!\n");
                break;

            case 2:

        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
  menu_principal();
  return 0;

}
