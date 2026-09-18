#include <stdio.h>
#include <stdlib.h>
#include "../Libraries/biblioteca.h"
#include "../Libraries/tabelaHash.h"
int main(void){
    TabelaHash *tabelaLivros = criar_tabela();

    do{
        int opcao = -1;
        
        exibirMenuBiblioteca();
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao) {
        case 1:
            exibirMenuLivros(tabelaLivros);
            break;

        case 2:
            exibirMenuUsuarios();
            break;

        case 3:
            exibirMenuEmprestimos();
            break;
        
        case 4:
            exibirMenuConsultas(tabelaLivros);
            break;

        case 5:
            exibirMenuRelatorios();
            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            exit(0);

        default:
            printf("\nOpcao invalida!\n");
        }
    }while(1);
}