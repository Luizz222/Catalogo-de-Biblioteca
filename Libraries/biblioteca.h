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



#endif