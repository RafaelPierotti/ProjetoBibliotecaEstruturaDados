//Feito Por
//Jose Ricardo Gustavo – 202114786
//Rafael Pierotti - 202318464
//Marcelo Duran – 202324984
//Cauã Zambotto - 202318466

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct livro{
    char titulo[100];
    char autor[100];
    char editora[100];
    char genero[100];
    int ano_publicacao;
    float preco;
    struct livro* prox;
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
    if (novoLivro == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strncpy(novoLivro->titulo, titulo, sizeof(novoLivro->titulo) - 1);
    novoLivro->titulo[sizeof(novoLivro->titulo) - 1] = '\0';

    strncpy(novoLivro->autor, autor, sizeof(novoLivro->autor) - 1);
    novoLivro->autor[sizeof(novoLivro->autor) - 1] = '\0';

    strncpy(novoLivro->editora, editora, sizeof(novoLivro->editora) - 1);
    novoLivro->editora[sizeof(novoLivro->editora) - 1] = '\0';

    strncpy(novoLivro->genero, genero, sizeof(novoLivro->genero) - 1);
    novoLivro->genero[sizeof(novoLivro->genero) - 1] = '\0';
    novoLivro->ano_publicacao = ano_publicacao;
    novoLivro->preco = preco;
    novoLivro->prox = NULL;


    if (f->fim != NULL){
        f->fim->prox = novoLivro;
    }
    f->fim = novoLivro;
    if (f->inicio == NULL){
        f->inicio = f->fim;
    }
}

void removerLivros(Fila *f, char* titulo){
    if (vazia(f)){
        printf("Fila vazia!\n");
        exit(1);
    }

    strcpy(titulo, f->inicio->titulo);
    Livro* aux = f->inicio->prox;
    free(f->inicio);
    f->inicio = aux;
    if (f->inicio == NULL)
        f->fim = NULL;
    printf("Livro removido %s", titulo);
}

void mostrarLivros(Fila* f){
    if(vazia(f)){
        printf("Lista Vazia\m!");
        return;
    }

    Livro* aux = f->inicio;
    printf("Debug - listando livros");
    for (aux = f->inicio; aux != NULL; aux = aux->prox)
        printf("\nTítulo: %s, \nAutor: %s, \nEditora: %s, \nGênero: %s, \nAno de Publicação: %d, \nPreço: %.2f\n", aux->titulo, aux->autor, aux->editora, aux->genero, aux->ano_publicacao, aux->preco);
}

void buscarLivros(Fila* f, const char* titulo, const char* autor, int ano){
    Livro* livro = f->inicio;
    int encontrado = 0;

    while (livro != NULL){
        if  ((titulo == NULL || strcmp(livro->titulo, titulo) == 0) &&
             (autor == NULL || strcmp(livro->autor, autor) == 0) &&
             (ano == -1 || livro->ano_publicacao == ano)){
            printf("Resultado encontrado\n");
            printf("\nTítulo: %s, \nAutor: %s, \nEditora: %s, \nGênero: %s, \nAno de Publicação: %d, \nPreço: %f\n", livro->titulo, livro->autor, livro->editora, livro->genero, livro->ano_publicacao, livro->preco);
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

Fila* fila = NULL;

void menu_principal(){
    if(fila == NULL){
        fila = cria_fila();
    }

    system("cls");

    char titulo[100], autor[100], editora[100], genero[100];
    int ano;
    float preco;
    int opcao = -1;

    while (opcao != 0){
        printf("Escolha uma das opções");
        printf("\n1 - Adicionar Livros\n2 - Remover Livros\n3 - Pesquisar Livros\n4 - Listar Livros\n 0 - Sair\n");
        scanf("%d", &opcao);
        while (getchar() != '\n' && getchar() != EOF);

        switch (opcao) {
            case 1:
                printf("Informe o título do livro: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';

                printf("Informe o autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';

                printf("Informe a editora: ");
                fgets(editora, sizeof(editora), stdin);
                editora[strcspn(editora, "\n")] = '\0';

                printf("Informe o gênero: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = '\0';

                printf("Informe o ano de publicação: ");
                scanf("%d", &ano);
                while (getchar() != '\n' && getchar() != EOF);

                printf("Informe o preço: ");
                scanf("%f", &preco);
                while (getchar() != '\n' && getchar() != EOF);

                adicionarLivros(fila, titulo, autor, editora, genero, ano, preco);
                printf("Livro adicionado com sucesso!\n");
                menu_principal();
                break;

            case 2:
                printf("Título do livro para remover: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")];
                removerLivros(fila, titulo);
                menu_principal();
                break;

            case 3:
                printf("Buscar por (Caso deseje ignorar, deixe vazio): \n");
                printf("Título: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';

                printf("Ano (-1 para ignora)");
                scanf("%d", &ano);
                while (getchar() != '\n' && getchar() != EOF);

                buscarLivros(fila, strlen(titulo) ? titulo : NULL, strlen(autor) ? autor : NULL, ano);
                menu_principal();
                break;
            case 4:
                mostrarLivros(fila);
                break;
            case 0:
                printf("Saindo!");
                break;
            default:
                printf("Opção inválida!");
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    menu_principal();
    libera(fila);
    return 0;
}
