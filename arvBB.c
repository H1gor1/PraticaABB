//
// Created by higor on 23/06/2023.
//

#include "arvBB.h"
#include <stdlib.h>
#include <stdio.h>

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

