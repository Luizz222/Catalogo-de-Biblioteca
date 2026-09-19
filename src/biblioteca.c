#include "../Libraries/biblioteca.h"
#include "../Libraries/tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=========================================================
    Função para exibir o menu principal da biblioteca
  =========================================================*/
void exibirMenuBiblioteca(){
    printf("\n================== MENU BIBLIOTECA ==================\n");
    printf("1. Gerenciar Livros\n");
    printf("2. Gerenciar Emprestimos\n");
    printf("3. Realizar Consulta de Livros\n");
    printf("4. Relatorios\n\n");

    printf("0. Encerrar o Programa\n\n");
    printf("Escolha uma opcao: ");
}

/*=========================================================
    Função para exibir o sub-menu Gerenciar Livros
  =========================================================*/
void exibirMenuLivros(TabelaHash * const tabela){
    int opcao = -1;

    printf("\n=============== GERENCIAR LIVROS ===============\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Remover Livro\n");
    printf("3. Listar Livros\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){
    case 1: {
        TLivro livro;

        printf("\n========== CADASTRAR LIVRO ==========\n");

        printf("ISBN: ");
        scanf("%14s", livro.isbn);
        getchar();

        printf("Titulo: ");
        fgets(livro.titulo, TAM_TITULO, stdin);
        livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(livro.autor, TAM_AUTOR, stdin);
        livro.autor[strcspn(livro.autor, "\n")] = '\0';

        printf("Ano de publicacao: ");
        scanf("%4s", livro.anoPublicacao);
        getchar();

        livro.disponibilidade = 1;

        inserir(tabela, livro.isbn, livro);
        break;
    }

    case 2: {
        char isbn[15];
        printf("Digite o isbn do livro que deseja excluir:\n");
        scanf("%14s", isbn);
        getchar();
        removerLivro(tabela, isbn);
        break;
    }

    case 3:
        listarLivro(tabela);
        break;

    case 0:
        printf("Retornando..\n");
        return;

    default:
        printf("\nOpcao invalida!\n");
    }
}

/*=========================================================
    Função para exibir o sub-menu Gerenciar Empréstimos
  =========================================================*/
void exibirMenuEmprestimos(TabelaHash * const tabela) {
    int opcao = -1;


        printf("\n================== GERENCIAR EMPRESTIMOS ==================\n");
        printf("1. Realizar Emprestimo\n");
        printf("2. Realizar Devolucao\n");
        printf("3. Consultar Emprestimos Ativos\n\n");
        printf("0. Voltar\n\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            getchar();

        }
        getchar();
        printf("\n");

        switch(opcao) {
        case 1: {
            char isbn[TAM_ISBN];
            printf("Digite o ISBN do livro para emprestimo: ");
            fgets(isbn, TAM_ISBN, stdin);
            isbn[strcspn(isbn, "\n")] = '\0';
            realizarEmprestimo(tabela, isbn);
            break;
        }
        case 2: {
            char isbn[TAM_ISBN];
            printf("Digite o ISBN do livro para devolucao: ");
            fgets(isbn, TAM_ISBN, stdin);
            isbn[strcspn(isbn, "\n")] = '\0';
            realizarDevolucao(tabela, isbn);
            break;
        }
        case 3: {
            consultarEmprestimosAtivos(tabela);
            break;
        }
        case 0:
            printf("Retornando ao menu principal..\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }

}

/*=========================================================
    Função para exibir o sub-menu Consultas
  =========================================================*/
void exibirMenuConsultas(TabelaHash * const tabela){
    int opcao = -1;

    printf("\n=============== CONSULTAS ===============\n");
    printf("1. Buscar por ISBN\n");
    printf("2. Buscar por Titulo\n");
    printf("3. Buscar por Autor\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao) {
        case 1: {
            TLivro livro;
            char isbn[TAM_ISBN];
            printf("Digite o ISBN do livro: ");
            fgets(isbn, TAM_ISBN, stdin);
            isbn[strcspn(isbn, "\n")] = '\0';
            buscarPorIsbn(tabela, isbn);
            break;
        }

        case 2: {
            char isbn[15];
            char titulo[TAM_TITULO];
            printf("Digite o titulo do livro: ");
            fgets(titulo, TAM_TITULO, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            buscarPorTitulo(tabela, titulo);
            break;
        }

        case 3: {
            char autor[TAM_AUTOR];
            printf("Digite o nome do(a) autor(a) do livro: ");
            fgets(autor, TAM_AUTOR, stdin);
            autor[strcspn(autor, "\n")] = '\0';
            buscarPorAutor(tabela, autor);
            break;
        }

        case 0: {
            printf("Retornando..\n");
            return;
        }
        default: {
            printf("\nOpcao invalida!\n");
        }
    }
}

/*=========================================================
    Função para exibir o sub-menu Relatorios
  =========================================================*/
void exibirMenuRelatorios(TabelaHash * const tabela){
    int opcao = -1;

    printf("\n================== RELATORIOS ==================\n");
    printf("1. Listar Livros Disponiveis\n");
    printf("2. Listar Livros Emprestados\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){
    case 1:
        listarLivrosDisponiveis(tabela);
        break;
    case 2:
        consultarEmprestimosAtivos(tabela);
        break;
    case 0:
        printf("Retornando..\n");
        return;
    default:
        printf("\nOpcao invalida!\n");
    }
}