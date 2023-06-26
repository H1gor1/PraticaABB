//
// Created by higor on 23/06/2023.
//

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void fazFilaVazia(Fila *fila) {
    fila->frente = 0;
    fila->tras = fila->frente;
}

int vazia(Fila *fila) {
    return (fila->frente == fila->tras);
}

void enfileira(TipoElemento elementos, Fila *fila) {
    if ((fila->tras + 1) % maxtam == fila->frente) {
        printf("Erro! A fila está cheia!\n");
    } else {
        fila->elementos[fila->tras] = elementos;
        fila->tras = (fila->tras + 1) % maxtam;
    }
}

void desenfileira(TipoElemento *elemento, Fila *fila) {
    if (vazia(fila)) {
        printf("Erro! Fila vazia!\n");
    } else {
        *elemento = fila->elementos[fila->frente];
        fila->frente = (fila->frente + 1) % maxtam;
    }
}