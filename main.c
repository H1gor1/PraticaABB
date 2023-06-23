#include <stdlib.h>
#include <stdio.h>
#include "arvBB.h"

int main() {
    TipoApontador Arvore;
    Inicializa(&Arvore);
    int opcao;
    int chave;

    do {
        printf("\nArvore de busca binaria\n");
        printf("1- Insere na arvore\n"
                     "2- Pesquisa na arvore\n"
                     "3- Imprimir por nível\n"
                     "0- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nDigite o valor que deseja adicionar: ");
                scanf("%d", &chave);
                Insere(chave, &Arvore);
                break;
            case 2:
                printf("Digite o elemento que deseja pequisar: ");
                scanf("%d", &chave);
                TipoApontador *x = Pesquisa(chave, &Arvore);
                printf("Elemento pesquisado: \n"
                       "Chave: %d", (*x)->chave);
                break;
            case 3:
                //Imprime por nível;
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}