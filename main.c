#include <stdlib.h>
#include <stdio.h>
#include "arvBB.h"
#include <time.h>

int main() {
    TipoApontador Arvore;
    Inicializa(&Arvore);
    TipoApontador ArvoreBalanceada;
    Inicializa(&ArvoreBalanceada);
    srand(time(NULL));
    int opcao;
    int chave;
    int itensAdd = 0;
    int j;

    do {
        printf("\nArvore de busca binaria\n");
        printf("1- Insere na arvore\n"
                     "2- Pesquisa na arvore\n"
                     "3- Imprimir por nível\n"
                     "0- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                /*
                printf("\n\nDigite o valor que deseja adicionar: ");
                scanf("%d", &chave);
                Insere(chave, &Arvore);
                ItensAdd++;
                */

                //Deixei gerando 20 valores de uma vez para ficar mais fácil, mas é só descomentar o código acima e comentar o abaixo

                for (j = 0; j < 20; j++) {
                    int valor = rand() % 100;  // Gera valores aleatórios de 0 a 99
                    Insere(valor, &Arvore);
                    itensAdd++;
                }

                if(itensAdd == 20){
                    BalanceiaABB(&Arvore, &ArvoreBalanceada);
                    printf("Arvore balanceada automaticamente!\n");
                    printf("\nArvore desbalanceada: ");
                    PreOrdem(Arvore);
                    printf("\nArvore balanceada: ");
                    PreOrdem(ArvoreBalanceada);
                }
                break;
            case 2:
                printf("Digite o elemento que deseja pequisar: ");
                scanf("%d", &chave);
                TipoApontador *x = Pesquisa(chave, &Arvore);
                printf("Elemento pesquisado: \n"
                       "Chave: %d", (*x)->chave);
                break;
            case 3:
                // Imprime por nível
                MostraPorNivel(Arvore);
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