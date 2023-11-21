// Programa1.h

#ifndef PROGRAMA1_H
#define PROGRAMA1_H

// Definição da estrutura do nó para a lista ligada
struct No1 {
    int valor;
    struct No1* prox;
};

// Definição do tipo ListaLigada
struct ListaLigada1 {
    struct No1* inicio;
};

// Funções para operações na lista ligada
void iniciarLista(struct ListaLigada1* lista);
void inserirNoFim(struct ListaLigada1* lista, int valor);
void removerNo(struct ListaLigada1* lista, int valor);
void imprimirLista(struct ListaLigada1* lista);
struct No1* buscarElemento(struct ListaLigada1* lista, int valor);
void dividirLista(struct ListaLigada1* lista, struct ListaLigada1* listaPositivos, struct ListaLigada1* listaNegativos);
void deletarLista(struct ListaLigada1* lista);

// Função principal do Programa1
void programa1_main();

#endif

