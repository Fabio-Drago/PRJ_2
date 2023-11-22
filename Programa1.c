// Programa1.c

#include <stdio.h>
#include <stdlib.h>
#include "Programa1.h"

// Inicializa a lista ligada.
void iniciarLista(struct ListaLigada1* lista) {
    lista->inicio = NULL;
}

// Insere um novo nó no final da lista com o valor especificado.
void inserirNoFim(struct ListaLigada1* lista, int valor) {
    struct No1* novoNo = malloc(sizeof(struct No1));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        struct No1* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

// Remove o nó com o valor especificado da lista.
void removerNo(struct ListaLigada1* lista, int valor) {
    struct No1* atual = lista->inicio;
    struct No1* ant = NULL;

    while (atual != NULL && atual->valor != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (ant == NULL) {
            lista->inicio = atual->prox;
        } else {
            ant->prox = atual->prox;
        }
        free(atual);
    }
}

// Imprime os valores da lista.
void imprimirLista(struct ListaLigada1* lista) {
    struct No1* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Busca um elemento na lista e retorna o nó correspondente.
struct No1* buscarElemento(struct ListaLigada1* lista, int valor) {
    struct No1* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Divide a lista original em duas listas separadas de positivos e negativos.
void dividirLista(struct ListaLigada1* lista, struct ListaLigada1* listaPositivos, struct ListaLigada1* listaNegativos) {
    struct No1* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor >= 0) {
            inserirNoFim(listaPositivos, atual->valor);
        } else {
            inserirNoFim(listaNegativos, atual->valor);
        }
        atual = atual->prox;
    }
}

// Deleta todos os nós da lista liberando a memória alocada.
void deletarLista(struct ListaLigada1* lista) {
    struct No1* atual = lista->inicio;
    while (atual != NULL) {
        struct No1* aux = atual;
        atual = atual->prox;
        free(aux);
    }
    lista->inicio = NULL;
}

// Função principal que executa o programa.
void programa1_main() {
    struct ListaLigada1 minhaLista;
    iniciarLista(&minhaLista);

    // Inserção de elementos na lista original.
    inserirNoFim(&minhaLista, 5);
    inserirNoFim(&minhaLista, -3);
    inserirNoFim(&minhaLista, 8);
    inserirNoFim(&minhaLista, 0);
    inserirNoFim(&minhaLista, -2);
    inserirNoFim(&minhaLista, 4);

    printf("Lista original: ");
    imprimirLista(&minhaLista);

    // Remove um nó da lista.
    removerNo(&minhaLista, 0);
    printf("Lista após remover o elemento 0: ");
    imprimirLista(&minhaLista);

    // Busca um elemento na lista.
    struct No1* resultadoBusca = buscarElemento(&minhaLista, 8);
    if (resultadoBusca != NULL) {
        printf("Elemento 8 encontrado.\n");
    } else {
        printf("Elemento 8 não encontrado.\n");
    }

    // Divide a lista em positivos e negativos.
    struct ListaLigada1 listaPositivos, listaNegativos;
    iniciarLista(&listaPositivos);
    iniciarLista(&listaNegativos);

    dividirLista(&minhaLista, &listaPositivos, &listaNegativos);

    // Imprime as duas listas resultantes.
    printf("Lista de positivos: ");
    imprimirLista(&listaPositivos);
    printf("Lista de negativos: ");
    imprimirLista(&listaNegativos);

    // Deleta todos os nós das listas.
    deletarLista(&minhaLista);
    deletarLista(&listaPositivos);
    deletarLista(&listaNegativos);
}

