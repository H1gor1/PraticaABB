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
void InOrdem(TipoApontador p, int *vet, int *indice);
TipoApontador MontaArvore(int *vet, int inicio, int fim);
void BalanceiaABB(TipoApontador *p, TipoApontador *p2);
void PreOrdem(TipoApontador p);
int CalculaTamanhoArvore(TipoApontador p);
void MostraPorNivel(TipoApontador raiz);

#endif //PRATICAABB_ARVBB_H
