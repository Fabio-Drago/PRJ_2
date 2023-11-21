// Programa2.h

#ifndef PROGRAMA2_H
#define PROGRAMA2_H

// Definição da estrutura do nó para a lista circular duplamente ligada
struct No2 {
    char nome[50];
    struct No2* prox;
    struct No2* ant;
};

// Definição do tipo ListaCircularDupla
struct ListaCircularDupla {
    struct No2* inicio;
};

// Funções para operações na lista circular dupla
void iniciarListaCircularDupla(struct ListaCircularDupla* lista);
void adicionarAluno(struct ListaCircularDupla* lista, const char* nome);
void realizarSorteio(struct ListaCircularDupla* lista, int numeroInicial);

// Função principal do Programa2
void programa2_main();

#endif

