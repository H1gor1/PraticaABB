//
// Created by higor on 23/06/2023.
//

#ifndef PRATICAABB_FILA_H
#define PRATICAABB_FILA_H


#define maxtam 100
#include "arvBB.h"


typedef int TipoApontadorF;
typedef struct {
    TipoApontador elemento;
} TipoElemento;

typedef struct {
    TipoElemento elementos[maxtam];
    TipoApontadorF frente, tras;
} Fila;

void fazFilaVazia(Fila *fila);
int vazia(Fila *fila);
void enfileira(TipoElemento elementos, Fila *fila);
void desenfileira(TipoElemento *elemento, Fila *fila);



#endif //PRATICAABB_FILA_H
