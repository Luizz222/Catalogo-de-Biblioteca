#include "biblioteca.h"
#include "tabelaHash.h"
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
    printf("3. Gerenciar Empréetimos\n");
    printf("4. Realizar Consulta\n");
    printf("5. Relatorios\n\n");

    printf("0. Encerrar o Programa\n\n");
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
    scanf("%d", &opcao);
    getchar();
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
    scanf("%d", &opcao);
    getchar();
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

    printf("\n================== MENU EMPRESTIMOS ==================\n");
    printf("1. Realizar Emprestimo\n");
    printf("2. Realizar Devolucao\n");
    printf("3. Consultar Emprestimos Ativos\n");
    printf("4. Consultar Historico de Emprestimos\n\n");

    printf("0. Voltar\n\n");
    scanf("%d", &opcao);
    getchar();
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
void exibirMenuConsultas(){
    int opcao = -1;

    printf("\n=============== CONSULTAR LIVROS ===============\n");
    printf("1. Buscar por ISBN\n");
    printf("2. Buscar por Titulo\n");
    printf("3. Buscar por Autor\n");
    printf("4. Mostrar Livros Disponiveis\n");
    printf("5. Mostrar Livros Emprestados\n\n");

    printf("0. Voltar\n\n");
    scanf("%d", &opcao);
    getchar();
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
    scanf("%d", &opcao);
    getchar();
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