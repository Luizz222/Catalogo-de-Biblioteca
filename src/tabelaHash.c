#include "../Libraries/biblioteca.h"
#include "../Libraries/tabelaHash.h"
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

/*=========================================================
 Função para buscar um livro por ISBN na Tabela Hash
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - string com o ISBN procurado
 =========================================================*/
void buscarPorIsbn(TabelaHash const * const tabela, const char *isbn){
    unsigned int posicao = hash(isbn);
    TNo *atual = tabela->gavetas[posicao];

    printf("\n--- Resultado da Busca por ISBN: \"%s\" ---\n\n", isbn);

    while (atual != NULL) {
        if(strcmp(atual->livro.isbn, isbn) == 0){
            printf("_________________________________________________________");
            printf("______________________________________\n\n");
            printf("ISBN: %s | Título: %s | Autor: %s | Ano: %s | Status: %s\n",
                   atual->livro.isbn,
                   atual->livro.titulo,
                   atual->livro.autor,
                   atual->livro.anoPublicacao,
                   atual->livro.disponibilidade ? "Disponível" : "Emprestado");
            printf("_________________________________________________________");
            printf("______________________________________\n");
            return;
        }

        atual = atual->proximo;
    }

    printf("Nenhum livro encontrado com o ISBN informado.\n");
}

/*=========================================================
 Função para buscar livros por Título (varredura na tabela)
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - titulo - string com o título (ou parte dele) procurado
 =========================================================*/
void buscarPorTitulo(TabelaHash const * const tabela, const char *titulo) {
    int encontrados = 0;
    printf("\n--- Resultados da Busca por Título: \"%s\" ---\n\n", titulo);

    for (int i = 0; i < TAM_TABELA; i++) {
        TNo *atual = tabela->gavetas[i];
        while (atual != NULL) {
            // strstr verifica se o título procurado está contido no livro cadastrado
            if (strstr(atual->livro.titulo, titulo) != NULL) {
                printf("_________________________________________________________");
                printf("______________________________________\n\n");
                printf("ISBN: %s | Título: %s | Autor: %s | Ano: %s | Status: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao,
                       atual->livro.disponibilidade ? "Disponível" : "Emprestado"
                );

                printf("_________________________________________________________");
                printf("______________________________________\n");
                encontrados++;
            }
            atual = atual->proximo;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com esse título.\n");
    }
}

/*=========================================================
 Função para buscar livros por Autor (varredura na tabela)
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - autor - string com o autor (ou parte dele) procurado
 =========================================================*/
void buscarPorAutor(TabelaHash const * const tabela, const char *autor){
    int encontrados = 0;

    printf("\n--- Resultados da Busca por Autor: \"%s\" ---\n\n", autor);

    for(int i = 0; i < TAM_TABELA; i++){
        TNo *atual = tabela->gavetas[i];

        while(atual != NULL){
            // strstr verifica se o autor procurado está contido no autor cadastrado
            if(strstr(atual->livro.autor, autor) != NULL){
                printf("_________________________________________________________");
                printf("______________________________________\n\n");
                printf("ISBN: %s | Título: %s | Autor: %s | Ano: %s | Status: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao,
                       atual->livro.disponibilidade ? "Disponível" : "Emprestado");
                printf("_________________________________________________________");
                printf("______________________________________\n");

                encontrados++;
            }

            atual = atual->proximo;
        }
    }

    if(encontrados == 0){
        printf("Nenhum livro encontrado para esse autor.\n");
    }
}

/*=========================================================
 Função para listar todos os livros contidos na tabela hash
 Parâmetro:
 1 - tabela - ponteiro para a tabela hash
 ==========================================================*/
void listarLivro(TabelaHash *tabela) {
    int cond=0;
    for (int i =0; i<TAM_TABELA;i++) {
        TNo *atual = tabela->gavetas[i];
        if (atual == NULL) {
            cond++;
        }

        while (atual!=NULL) {
            printf("_________________________________________________________");
            printf("______________________________________\n\n");
            printf("ISBN: %s | Titulo: %s | Autor: %s | Ano: %s | Status: %s\n",
                   atual->livro.isbn,
                   atual->livro.titulo,
                   atual->livro.autor,
                   atual->livro.anoPublicacao,
                   atual->livro.disponibilidade ? "Disponivel" : "Emprestado");
            printf("_________________________________________________________");
            printf("______________________________________\n");
            atual = atual->proximo;
        }
    }
    if (cond == 10) {
        printf("Nao existe nenhum livro");
    }

}

/*=========================================================
 Função para remover o livro de acordo com o isbn do proprio
 Paramêtros:
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 ==========================================================*/
void removerLivro(TabelaHash *tabela, char *isbn) {
    if (isbn==NULL) {
        printf("O ISBN não foi digitado");
        return;;
    }
    int cond = 0;
    unsigned int posicao = hash(isbn);
    TNo *novo = tabela->gavetas[posicao];
    TNo *anterior = NULL;

    while (novo !=NULL) {

        if (strcmp(novo->chave,isbn) == 0) {
            if (anterior == NULL) {
                tabela->gavetas[posicao] = novo->proximo;
            }
            else {
                anterior->proximo = novo->proximo;
            }
            free(novo);
            printf("Livro removido com sucesso!!!");
            cond=1;
            return;
        }

        anterior = novo;
        novo = novo->proximo;
    }
    if (cond ==0) {
        printf("O livro com esse ISBN nao existe");
    }
}
