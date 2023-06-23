//
// Created by higor on 23/06/2023.
//

#ifndef PRATICAABB_ARVBB_H
#define PRATICAABB_ARVBB_H

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo{
    int chave;
    TipoApontador Esq, Dir;
}TipoNo;

void Inicializa(TipoApontador *No);
TipoApontador *Pesquisa(int x, TipoApontador *p);
void Insere(int x, TipoApontador *p);

#endif //PRATICAABB_ARVBB_H
