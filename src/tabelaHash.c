#include "biblioteca.h"
#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=========================================================
    Função para criar uma tabela hash
    Parametros:
        1 - void
    Retorno:
        Tabela Hash criada
  =========================================================*/
TabelaHash *criar_tabela(void) {
    TabelaHash *tabela = malloc(sizeof(TabelaHash));
    verificarMallocTABELA(tabela);
    int i;
    for (i = 0; i < TAM_TABELA; i++) {
        tabela->gavetas[i] = NULL;
    }
    return tabela;
}

/* ---------- funcao hash (versao djb2) ---------- */
/* 5381 e 33 sao constantes classicas do algoritmo djb2 (nao tem
 * nada de magico nelas alem de, na pratica, funcionarem bem).
 * O importante e o "h = h * 33 + letra": a MULTIPLICACAO por 33 a
 * cada passo faz a posicao da letra pesar diferente no resultado
 * final -- e exatamente o que a soma simples nao fazia. */
unsigned int hash(const char *chave) {
    unsigned long h = 5381;
    int i;
    for (i = 0; chave[i] != '\0'; i++) {
        h = h * 33 + (unsigned char) chave[i];
    }
    return (unsigned int) (h % TAM_TABELA);
}
/*=========================================================
    Função para inserir um dado na tabela hash
    Parametros:
        1 - tabela - ponteiro para a tabela hash
        2 - chave - ponteiro para a chave
        3 - valor - valor a ser inserido na tabela hash
  =========================================================*/
void inserir(TabelaHash * const tabela, const char *chave, TLivro livro) {
    unsigned int posicao = hash(chave);

    TNo *novo = malloc(sizeof(TNo));
    verificarMallocNO(novo);

    strncpy(novo->chave, chave, sizeof(novo->chave) - 1);
    novo->chave[sizeof(novo->chave) - 1] = '\0';
    novo->livro = livro;

    novo->proximo = tabela->gavetas[posicao];
    tabela->gavetas[posicao] = novo;

    printf("Inserido: \"%s\" -> %s na gaveta %u\n", chave, livro.titulo, posicao);
}

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - no - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMallocNO(TNo const * const no){
    if(no == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - tabela - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMallocTABELA(TabelaHash const * const tabela){
    if(tabela == NULL) {
        printf("Erro: sem memoria para criar a tabela.\n");
        exit(1);
    }
}