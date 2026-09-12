#include <stdio.h>
#include "biblioteca.h"
int main(void){

    do{
        int opcao = -1;
        exibirMenuBiblioteca();

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            exibirMenuLivros();
            break;

        case 2:
            exibirMenuUsuarios();
            break;

        case 3:
            exibirMenuEmprestimos();
            break;
        
        case 4:
            exibirMenuConsultas();
            break;

        case 5:
            exibirMenuRelatorios();

        case 0:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }while(1);
}