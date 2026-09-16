#include "../Libraries/biblioteca.h"
#include "../Libraries/tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=========================================================
    Função para exibir o menu principal da biblioteca
    Parametros:
        Nada
  =========================================================*/
void exibirMenuBiblioteca(){
    printf("\n================== MENU BIBLIOTECA ==================\n");
    printf("1. Gerenciar Livros\n");
    printf("2. Gerenciar Usuarios\n");
    printf("3. Gerenciar Emprestimos\n");
    printf("4. Realizar Consulta de Livros\n");
    printf("5. Relatorios\n\n");

    printf("0. Encerrar o Programa\n\n");
    printf("Escolha uma opcao: ");
}

/*=========================================================
    Função para exibir o sub-menu Gerenciar Livros
    Parametros:
        1 - Ponteiro para a tabela hash
  =========================================================*/
void exibirMenuLivros(TabelaHash * const tabela){
    int opcao = -1;

    printf("\n=============== GERENCIAR LIVROS ===============\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Alterar Livro\n");
    printf("3. Remover Livro\n");
    printf("4. Listar Livros\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){

    case 1:
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

        printf("\nLivro cadastrado com sucesso!\n");
        break;
    
    case 2:
        
        break;

    case 3:
        
        break;
    case 4:

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
    Função para exibir o sub-menu Gerenciar Usuários
    Parametros:
        Nada
  =========================================================*/
void exibirMenuUsuarios(){
    int opcao = -1;

    printf("\n============== GERENCIAR USUARIOS ==============\n");
    printf("1. Cadastrar Usuario\n");
    printf("2. Alterar Usuario\n");
    printf("3. Remover Usuario\n");
    printf("4. Listar Usuarios\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){
    case 1:
        
        break;
    
    case 2:
        
        break;

    case 3:
        
        break;

    case 4:
        
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
    Parametros:
        Nada
  =========================================================*/
void exibirMenuEmprestimos(){
    int opcao = -1;

    printf("\n================== GERENCIAR EMPRESTIMOS ==================\n");
    printf("1. Realizar Emprestimo\n");
    printf("2. Realizar Devolucao\n");
    printf("3. Consultar Emprestimos Ativos\n");
    printf("4. Consultar Historico de Emprestimos\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){
    case 1:
        
        break;
    case 2:
        
        break;

    case 3:
        
        break;

    case 4:
        
        break;
    
    case 0:
    printf("Retornando..\n");
    return;

    default:
        printf("\nOpcao invalida!\n");
    }

}
/*=========================================================
    Função para exibir o sub-menu Consultas
    Parametros:
        Nada
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

    switch(opcao){
    case 1:
        char isbn[TAM_ISBN];
        printf("Digite o ISBN do livro: ");
        fgets(isbn, TAM_ISBN, stdin);
        isbn[strcspn(isbn, "\n")] = '\0';
        buscarPorIsbn(tabela, isbn);
        break;

    case 2:
        char titulo[TAM_TITULO];
        printf("Digite o titulo do livro: ");
        fgets(titulo, TAM_TITULO, stdin);
        titulo[strcspn(titulo, "\n")] = '\0';
        buscarPorTitulo(tabela, titulo);
        break;

    case 3:
        char autor[TAM_AUTOR];
        printf("Digite o nome do(a) autor(a) do livro: ");
        fgets(autor, TAM_AUTOR, stdin);
        autor[strcspn(autor, "\n")] = '\0';
        buscarPorAutor(tabela, autor);
        break;

    case 0:
    printf("Retornando..\n");
    return;

    default:
        printf("\nOpcao invalida!\n");
    }
}

/*=========================================================
    Função para exibir o sub-menu Relatorios
    Parametros:
        Nada
  =========================================================*/
void exibirMenuRelatorios(){
    int opcao = -1;

    printf("\n================== RELATORIOS ==================\n");
    printf("1. Listar Todos os Livros\n");
    printf("2. Listar Todos os Usuarios\n");
    printf("3. Listar Emprestimos Ativos\n");
    printf("4. Listar Historico de Emprestimos\n");
    printf("5. Listar Livros Disponiveis\n");
    printf("6. Listar Livros Emprestados\n\n");

    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    switch(opcao){
    case 1:
        
        break;
    
    case 2:
        
        break;

    case 3:
        
        break;
    case 4:
        
        break;

    case 5:
        
        break;

    case 6:

        break;
        
    case 0:
    printf("Retornando..\n");
    return;

    default:
        printf("\nOpcao invalida!\n");
    }
}

