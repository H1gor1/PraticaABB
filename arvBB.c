//
// Created by higor on 23/06/2023.
//

#include "arvBB.h"
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

void Inicializa(TipoApontador *No){
    *No = NULL;
}

TipoApontador *Pesquisa(int x, TipoApontador *p){
    if(*p == NULL) {
        printf("Erro: Registro nao esta presente na arvore\n");
        return NULL;
    }
    if(x < (*p)->chave){
        return Pesquisa(x, &(*p)->Esq);
    }
    if(x > (*p)->chave){
        return Pesquisa(x, &(*p)->Dir);
    }
    else {
        return p;
    }
}

void Insere(int x, TipoApontador *p){
    if (*p == NULL){
        *p = (TipoApontador) malloc(sizeof(TipoNo));
        (*p)->chave = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if(x < (*p)->chave){
        Insere(x, &(*p)->Esq);
        return;
    }
    if(x > (*p)->chave){
        Insere(x, &(*p)->Dir);
    }
    else{
        printf("Erro: Registro ja existe na arvore\n");
        return;
    }
}

void InOrdem(TipoApontador p, int *vet, int *indice) {
    if (p != NULL) {
        InOrdem(p->Esq, vet, indice);
        vet[*indice] = p->chave;
        (*indice)++;
        InOrdem(p->Dir, vet, indice);
    }
}

TipoApontador MontaArvore(int *vet, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }
    int meio = (inicio + fim) / 2;
    TipoApontador p = (TipoApontador)malloc(sizeof(TipoNo));
    p->chave = vet[meio];
    p->Esq = MontaArvore(vet, inicio, meio - 1);
    p->Dir = MontaArvore(vet, meio + 1, fim);
    return p;
}

void BalanceiaABB(TipoApontador *p, TipoApontador *p2) {
    int tamanho = CalculaTamanhoArvore(*p);
    int *vet = (int*) malloc(tamanho * sizeof(int));
    int indice = 0;

    InOrdem(*p, vet, &indice);

    TipoApontador novaArvore = MontaArvore(vet, 0, tamanho - 1);

    free(vet);

    *p2 = novaArvore;
}

void MostraPorNivel(TipoApontador raiz) {
    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    Fila fila;
    fazFilaVazia(&fila);

    printf("Elementos da arvore por nivel: ");

    // Enfileirar a raiz inicialmente
    TipoElemento elementoRaiz;
    elementoRaiz.elemento = raiz;
    enfileira(elementoRaiz, &fila);

    // Percorrer a árvore em largura
    while (!vazia(&fila)) {
        TipoElemento elementoAtual;
        desenfileira(&elementoAtual, &fila);

        TipoApontador no = elementoAtual.elemento;

        // Mostrar o valor do nó atual
        printf("%d ", no->chave);

        // Enfileirar os filhos do nó atual (se existirem)
        if (no->Esq != NULL) {
            TipoElemento elementoEsq;
            elementoEsq.elemento = no->Esq;
            enfileira(elementoEsq, &fila);
        }
        if (no->Dir != NULL) {
            TipoElemento elementoDir;
            elementoDir.elemento = no->Dir;
            enfileira(elementoDir, &fila);
        }
    }

    printf("\n");
}

int CalculaTamanhoArvore(TipoApontador p) {
    if (p == NULL) {
        return 0;  // Árvore vazia, tamanho é zero
    }

    // Recursivamente calcula o tamanho da subárvore esquerda e da subárvore direita
    int tamanhoEsquerda = CalculaTamanhoArvore(p->Esq);
    int tamanhoDireita = CalculaTamanhoArvore(p->Dir);

    // Retorna o tamanho total da árvore
    return 1 + tamanhoEsquerda + tamanhoDireita;
}

void PreOrdem(TipoApontador p){
    if (p == NULL){
        return;
    }
    printf("%d ", p->chave);
    PreOrdem(p->Esq);
    PreOrdem(p->Dir);
}
