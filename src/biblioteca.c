#include "biblioteca.h"

/*=========================================================
    Função para exibir o menu principal da biblioteca
    Parametros:
        Nada
  =========================================================*/
void exibirMenuBiblioteca(){
    printf("\n================== MENU BIBLIOTECA ==================\n");
    printf("1. Gerenciar Livros\n");
    printf("2. Gerenciar Usuarios\n");
    printf("3. Gerenciar Empréetimos\n\n");
    printf("4. Realizar Consulta\n\n");
    printf("5. Relatorios\n\n");

    printf("0. Encerrar o Programa\n\n");
}

/*=========================================================
    Função para exibir o sub-menu Gerenciar Livros
    Parametros:
        Nada
  =========================================================*/
void exibirMenuLivros(){
    printf("\n=============== GERENCIAR LIVROS ===============\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Alterar Livro\n");
    printf("3. Remover Livro\n");
    printf("4. Listar Livros\n\n");

    printf("0. Voltar\n\n");

}

/*=========================================================
    Função para exibir o sub-menu Gerenciar Usuários
    Parametros:
        Nada
  =========================================================*/
void exibirMenuUsuarios(){
    printf("\n============== GERENCIAR USUARIOS ==============\n");
    printf("1. Cadastrar Usuario\n");
    printf("2. Alterar Usuario\n");
    printf("3. Remover Usuario\n");
    printf("4. Listar Usuarios\n\n");

    printf("0. Voltar\n\n");
}
/*=========================================================
    Função para exibir o sub-menu Gerenciar Empréstimos
    Parametros:
        Nada
  =========================================================*/
void exibirMenuEmprestimos(){
    printf("\n================== MENU EMPRESTIMOS ==================\n");
    printf("1. Realizar Emprestimo\n");
    printf("2. Realizar Devolucao\n");
    printf("3. Consultar Emprestimos Ativos\n");
    printf("4. Consultar Historico de Emprestimos\n\n");

    printf("0. Voltar\n\n");

}
/*=========================================================
    Função para exibir o sub-menu Consultas
    Parametros:
        Nada
  =========================================================*/
void exibirMenuConsultas(){
    printf("\n=============== CONSULTAR LIVROS ===============\n");
    printf("1. Buscar por ISBN\n");
    printf("2. Buscar por Titulo\n");
    printf("3. Buscar por Autor\n");
    printf("4. Mostrar Livros Disponiveis\n");
    printf("5. Mostrar Livros Emprestados\n\n");

    printf("0. Voltar\n\n");
}

/*=========================================================
    Função para exibir o sub-menu Relatorios
    Parametros:
        Nada
  =========================================================*/
void exibirMenuRelatorios(){
    printf("\n================== RELATORIOS ==================\n");
    printf("1. Listar Todos os Livros\n");
    printf("2. Listar Todos os Usuarios\n");
    printf("3. Listar Emprestimos Ativos\n");
    printf("4. Listar Historico de Emprestimos\n");
    printf("5. Listar Livros Disponiveis\n");
    printf("6. Listar Livros Emprestados\n\n");

    printf("0. Voltar\n\n");
}