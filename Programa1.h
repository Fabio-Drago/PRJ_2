// Programa1.h

#ifndef PROGRAMA1_H
#define PROGRAMA1_H

// Defini��o da estrutura do n� para a lista ligada
struct No1 {
    int valor;
    struct No1* prox;
};

// Defini��o do tipo ListaLigada
struct ListaLigada1 {
    struct No1* inicio;
};

// Fun��es para opera��es na lista ligada
void iniciarLista(struct ListaLigada1* lista);
void inserirNoFim(struct ListaLigada1* lista, int valor);
void removerNo(struct ListaLigada1* lista, int valor);
void imprimirLista(struct ListaLigada1* lista);
struct No1* buscarElemento(struct ListaLigada1* lista, int valor);
void dividirLista(struct ListaLigada1* lista, struct ListaLigada1* listaPositivos, struct ListaLigada1* listaNegativos);
void deletarLista(struct ListaLigada1* lista);

// Fun��o principal do Programa1
void programa1_main();

#endif

