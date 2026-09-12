#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define TAM_TITULO 75
#define TAM_AUTOR 50
#define TAM_ISBN 15

typedef struct Livro{
    char isbn[TAM_ISBN];
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char anoPublicacao[4];
    int disponibilidade;
}TLivro;

/*=========================================================
    Função para exibir o menu principal da biblioteca
    Parametros:
        Nada
  =========================================================*/
void exibirMenuBiblioteca();

/*=========================================================
    Função para exibir o sub-menu Gerenciar Livros
    Parametros:
        Nada
  =========================================================*/
void exibirMenuLivros();

/*=========================================================
    Função para exibir o sub-menu Gerenciar Usuários
    Parametros:
        Nada
  =========================================================*/
void exibirMenuUsuarios();

/*=========================================================
    Função para exibir o sub-menu Gerenciar Empréstimos
    Parametros:
        Nada
  =========================================================*/
void exibirMenuEmprestimos();

/*=========================================================
    Função para exibir o sub-menu Consultas
    Parametros:
        Nada
  =========================================================*/
void exibirMenuConsultas();

/*=========================================================
    Função para exibir o sub-menu Relatorios
    Parametros:
        Nada
  =========================================================*/
void exibirMenuRelatorios();


#endif