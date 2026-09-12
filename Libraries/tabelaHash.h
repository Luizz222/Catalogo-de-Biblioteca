#ifndef TABELAHASH_H
#define TABELAHASH_H

#define TAM_TABELA 10
#define TAM_CHAVE 50


typedef struct TNo {
    char chave[TAM_CHAVE];
    int dado;
    struct TNo *proximo;
} TNo;


typedef struct TabelaHash {
    TNo *gavetas[TAM_TABELA];
} TabelaHash;

/*=========================================================
    Função para criar uma tabela hash
    Parametros:
        1 - void
    Retorno:
        Tabela Hash criada
  =========================================================*/
TabelaHash *criar_tabela(void);

/* ---------- funcao hash (versao djb2) ---------- */
/* 5381 e 33 sao constantes classicas do algoritmo djb2 (nao tem
 * nada de magico nelas alem de, na pratica, funcionarem bem).
 * O importante e o "h = h * 33 + letra": a MULTIPLICACAO por 33 a
 * cada passo faz a posicao da letra pesar diferente no resultado
 * final -- e exatamente o que a soma simples nao fazia. */
unsigned int hash(const char * chave);


/*=========================================================
    Função para inserir um dado na tabela hash
    Parametros:
        1 - tabela - ponteiro para a tabela hash
        2 - chave - ponteiro para a chave
        3 - valor - valor a ser inserido na tabela hash
  =========================================================*/
void inserir(TabelaHash * const tabela, const char *chave, int valor);

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - no - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMallocNO(TNo const * const no);


/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - tabela - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMallocTABELA(TabelaHash const * const tabela);

#endif