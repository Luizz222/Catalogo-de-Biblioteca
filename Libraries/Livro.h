//
// Created by Luiz Flávio on 09/09/2026.
//

#ifndef LIVRO_H
#define LIVRO_H
typedef struct {
    char titulo[100];
    char autor[100];
    bool situacao;
    char categoria[100];
    char anoPublicacao[20];
    char isbn[14];
}Livro;

#endif //LIVRO_H
