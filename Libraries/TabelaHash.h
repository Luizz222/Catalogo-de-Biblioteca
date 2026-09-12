#include "Livro.h";

#ifndef TABELAHASH_H
#define TABELAHASH_H

typedef struct No {
    char isbn[14];
    Livro livro;
    No *prox;
}No;



#endif //TABELAHASH_H
