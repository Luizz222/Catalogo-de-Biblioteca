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
void inserir(TabelaHash * const tabela, const char *isbn, TLivro livro) {

    TNo *i;
    unsigned int posicao = hash(isbn);

    if (!verificarIsbn(tabela,isbn,livro,posicao )) {
        printf("O ISBN nao pode ser digitado, ja pertence a outro livro");
        return;
    }

    TNo *novo = malloc(sizeof(TNo));
    verificarMallocNO(novo);

    strncpy(novo->chave, isbn, sizeof(novo->chave) - 1);
    novo->chave[sizeof(novo->chave) - 1] = '\0';
    novo->livro = livro;

    if (tabela->gavetas[posicao] == NULL) {
        tabela->gavetas[posicao] = novo;
    }
    else {
        for (i = tabela->gavetas[posicao];i->proximo!=NULL;i=i->proximo);
        i->proximo = novo;
    }
    novo->proximo = NULL;
    //novo->proximo = tabela->gavetas[posicao];
    //tabela->gavetas[posicao] = novo;
    printf("Inserido: \"%s\" -> %s na gaveta %u\n", isbn, livro.titulo, posicao);
    printf("\nLivro cadastrado com sucesso!\n");
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
    int cont =0;
    unsigned int posicao = hash(isbn);
    TNo *atual = tabela->gavetas[posicao];

    printf("\n--- Resultado da Busca por ISBN: \"%s\" ---\n\n", isbn);

    while (atual != NULL) {
        if(strcmp(atual->livro.isbn, isbn) == 0){
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
            cont++;
        }

        atual = atual->proximo;
    }
    if (cont==0) {
        printf("Nenhum livro encontrado com o ISBN informado.\n");
    }

}

/*=========================================================
 Função para buscar livros por Título (varredura na tabela)
 Parâmetros:
 1 - tabela - ponteiro para a tabela hash
 2 - titulo - string com o título (ou parte dele) procurado
 =========================================================*/
void buscarPorTitulo(TabelaHash const * const tabela, const char *titulo) {
    int encontrados = 0;
    printf("\n--- Resultados da Busca por Titulo: \"%s\" ---\n\n", titulo);

    for (int i = 0; i < TAM_TABELA; i++) {
        TNo *atual = tabela->gavetas[i];
        while (atual != NULL) {
            // strstr verifica se o título procurado está contido no livro cadastrado
            if (strstr(atual->livro.titulo, titulo) != NULL) {
                printf("_________________________________________________________");
                printf("______________________________________\n\n");
                printf("ISBN: %s | Titulo: %s | Autor: %s | Ano: %s | Status: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao,
                       atual->livro.disponibilidade ? "Disponivel" : "Emprestado"
                );

                printf("_________________________________________________________");
                printf("______________________________________\n");
                encontrados++;
            }
            atual = atual->proximo;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com esse titulo.\n");
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
                printf("ISBN: %s | Titulo: %s | Autor: %s | Ano: %s | Status: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao,
                       atual->livro.disponibilidade ? "Disponivel" : "Emprestado");
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
        printf("===================POSICAO %d ==================\n",i);
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
    if (cond== 0) {
        printf("O livro com esse ISBN nao existe");
    }
}

/*=========================================================
 Função para verificar se não existe outro livro de exemplar diferente, com o mesmo ISBN
 1 - tabela - ponteiro para a tabela hash
 2 - isbn - chave isbn para procurar pelo livro
 3 - livro - para comparar com os livros que ja estaão guardados
 4 - posicao - para verificar a posicao do vetor
 ==========================================================*/
int verificarIsbn(TabelaHash const *tabela,const char *isbn,TLivro livro,unsigned int posicao) {
    TNo *novo = tabela->gavetas[posicao];
    while (novo!=NULL) {
        if (strcmp(novo->chave,isbn)==0 ) {
            if (strcmp(livro.titulo, novo->livro.titulo) != 0) {
                return 0;
            }
            return  1;
        }
        novo = novo->proximo;
    }
    return 1;
}

/*=========================================================
    Função para realizar o empréstimo de um livro (marca como 0)
  =========================================================*/
void realizarEmprestimo(TabelaHash *tabela, const char *isbn) {
    if (isbn == NULL || strlen(isbn) == 0) {
        printf("Erro: ISBN invalido.\n");
        return;
    }
    unsigned int posicao = hash(isbn);
    TNo *atual = tabela->gavetas[posicao];
    int encontrados = 0;
    int preenchidos = 1;
    TNo *noParaEmprestar = NULL;
    // percorre toda a lista encadeada da gaveta para analisar TODOS os nós com esse ISBN
    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            encontrados++;
            if (atual->livro.disponibilidade == 1) {
                preenchidos = 0; // achou pelo menos um exemplar disponível
                if (noParaEmprestar == NULL) {
                    noParaEmprestar = atual; // uarda o primeiro disponível encontrado
                }
            }
        }
        atual = atual->proximo;
    }
    // ISBN não existe
    if (encontrados == 0) {
        printf("\nErro: Livro com ISBN \"%s\" nao foi encontrado no acervo.\n", isbn);
        return;
    }
    // todos exemplares já estão emprestados (disponibilidade == 0)
    if (preenchidos) {
        printf("\nAviso: Todos os exemplares cadastrados com o ISBN \"%s\" ja estao emprestados!\n", isbn);
        return;
    }
    // pelo menos um disponível, realiza o empréstimo dele
    noParaEmprestar->livro.disponibilidade = 0;
    printf("\nEmprestimo realizado com sucesso para o livro: \"%s\"\n", noParaEmprestar->livro.titulo);
}

/*=========================================================
    Função para realizar a devolução de um livro (marca como 1)
  =========================================================*/
void realizarDevolucao(TabelaHash *tabela, const char *isbn) {
    unsigned int posicao = hash(isbn);
    TNo *atual = tabela->gavetas[posicao];

    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            if (atual->livro.disponibilidade == 1) {
                printf("Erro: O livro \"%s\" ja esta disponivel no acervo!\n", atual->livro.titulo);
                return;
            }
            atual->livro.disponibilidade = 1;
            printf("Devolucao realizada com sucesso para o livro: \"%s\"\n", atual->livro.titulo);
            return;
        }
        atual = atual->proximo;
    }
    printf("Erro: Livro com ISBN %s nao encontrado.\n", isbn);
}

/*=========================================================
    Função para listar apenas os empréstimos ativos (disponibilidade == 0)
  =========================================================*/
void consultarEmprestimosAtivos(TabelaHash const * const tabela) {
    int encontrados = 0;
    printf("\n================ LIVROS EMPRESTADOS (ATIVOS) ================\n\n");
    for (int i = 0; i < TAM_TABELA; i++) {
        TNo *atual = tabela->gavetas[i];
        while (atual != NULL) {
            if (atual->livro.disponibilidade == 0) {
                printf("ISBN: %s | Titulo: %s | Autor: %s | Ano: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao);
                encontrados++;
            }
            atual = atual->proximo;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum livro esta emprestado no momento.\n");
    }
}

/*=========================================================
 Função para listar todos os livros disponiveis
 1 - tabela - ponteiro para a tabela hash
 ==========================================================*/
void listarLivrosDisponiveis(TabelaHash *tabela) {
    int encontrados = 0;
    printf("\n================ LIVROS DISPONIVEIS ================\n\n");

    for (int i = 0; i < TAM_TABELA; i++) {
        TNo *atual = tabela->gavetas[i];
        while (atual != NULL) {
            if (atual->livro.disponibilidade == 1) {
                printf("ISBN: %s | Titulo: %s | Autor: %s | Ano: %s\n",
                       atual->livro.isbn,
                       atual->livro.titulo,
                       atual->livro.autor,
                       atual->livro.anoPublicacao);
                encontrados++;
            }
            atual = atual->proximo;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro ativo no momento.\n");
    }
}


/*=========================================================
 Função para Exibir colisao, carga,e comprimento medio
 1 - tabela - ponteiro para a tabela hash
 2 - M - Tamanho do vetor
 ==========================================================*/
void medicao(TabelaHash* tabela, int M) {
    int total_elementos = 0;
    int posicoes_ocupadas = 0;
    int num_colisoes = 0;

    // Percorre cada posição do vetor da tabela hash
    for (int i = 0; i < M; i++) {
        // Acessa o nó inicial da lista na posição i através do ponteiro da struct.
        // NOTA: Se na sua struct o nome do vetor for diferente de 'tabela',
        // altere 'tabela->tabela[i]' para 'tabela->vetor[i]' ou 'tabela->itens[i]'.
        TNo* atual = tabela->gavetas[i];

        if (atual != NULL) {
            posicoes_ocupadas++; // Encontrou uma posição ocupada

            // Contar quantos elementos existem nesta lista encadeada específica
            int elementos_na_lista = 0;

            while (atual != NULL) {
                elementos_na_lista++;
                atual = atual->proximo;
            }

            // Acumula o total global de elementos
            total_elementos += elementos_na_lista;

            // Se a lista tem mais de 1 elemento, os excedentes são colisões
            if (elementos_na_lista > 1) {
                num_colisoes += (elementos_na_lista - 1);
            }
        }
    }

    // Cálculos das métricas (item 5)
    float fator_carga = (float)total_elementos / M;
    float comp_medio = (posicoes_ocupadas > 0) ? ((float)total_elementos / posicoes_ocupadas) : 0.0f;

    // Exibição do relatório
    printf("\n===============================================\n");
    printf("   ANÁLISE DAS MÉTRICAS DA HASH (Tamanho M = %d)\n", M);
    printf("===============================================\n");
    printf(" Total de Elementos (N)        : %d\n", total_elementos);
    printf(" Posições Ocupadas no Vetor    : %d\n", posicoes_ocupadas);
    printf(" Número de Colisões            : %d\n", num_colisoes);
    printf(" Fator de Carga (alpha)        : %.2f\n", fator_carga);
    printf(" Comprimento Médio das Listas  : %.2f\n", comp_medio);
    printf("===============================================\n");
}

