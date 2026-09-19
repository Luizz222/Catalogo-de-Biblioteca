#include "../Libraries/biblioteca.h"
#ifndef TABELAHASH_H
#define TABELAHASH_H

#define TAM_TABELA 10
#define TAM_CHAVE 50


typedef struct TNo {
    char chave[TAM_CHAVE];
    TLivro livro;
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
        3 - livro - valor a ser inserido na tabela hash
  =========================================================*/
void inserir(TabelaHash * const tabela, const char *isbn, TLivro livro);

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

/*=========================================================
 Função para buscar um livro por ISBN na Tabela Hash
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - string com o ISBN procurado
 =========================================================*/
void buscarPorIsbn(TabelaHash const * const tabela, const char *isbn);


/*=========================================================
 Função para buscar livros por Título (varredura na tabela)
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - titulo - string com o título (ou parte dele) procurado
 =========================================================*/
void buscarPorTitulo(TabelaHash const * const tabela, const char *titulo);

/*=========================================================
 Função para buscar livros por Autor (varredura na tabela)
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - autor - string com o autor (ou parte dele) procurado
 =========================================================*/
void buscarPorAutor(TabelaHash const * const tabela, const char *autor);

/*=========================================================
 Função para listar todos os livros contidos na tabela hash
 Parâmetro:
 1 - tabela - ponteiro para a tabela hash
 ==========================================================*/
void listarLivro(TabelaHash *tabela);

/*=========================================================
 Função para remover o livro de acordo com o isbn do proprio
 Paramêtros:
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 ==========================================================*/
void removerLivro(TabelaHash *tabela, char *isbn);

/*=========================================================
 Função para verificar se não existe outro livro de exemplar diferente, com o mesmo ISBN
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 3 - livro - para comparar com os livros que ja estaão guardados
 4 - posicao - para verificar a posicao do vetor
 ==========================================================*/
int verificarIsbn(TabelaHash const *tabela,const char *isbn,TLivro livro,unsigned int posicao);

/*=========================================================
 Função para realizar um empréstimo
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 ==========================================================*/
void realizarEmprestimo(TabelaHash *tabela, const char *isbn);

/*=========================================================
 Função para realizar uma devolucao pelo isbn
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 ==========================================================*/
void realizarDevolucao(TabelaHash *tabela, const char *isbn);

/*=========================================================
 Função para listar todos os emprestimos ativos
 1 - tabela - ponteiro para a tabela hash
 2 - ponteiro constante para a tabela
 ==========================================================*/
void consultarEmprestimosAtivos(TabelaHash const * const tabela);
#endif