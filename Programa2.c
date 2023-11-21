// Programa2.c

#include "Programa2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iniciarListaCircularDupla(struct ListaCircularDupla* lista) {
    lista->inicio = NULL;
}

void adicionarAluno(struct ListaCircularDupla* lista, const char* nome) {
    struct No2* novoAluno = (struct No2*)malloc(sizeof(struct No2));
    strcpy(novoAluno->nome, nome);

    if (lista->inicio == NULL) {
        lista->inicio = novoAluno;
        novoAluno->prox = novoAluno;
        novoAluno->ant = novoAluno;
    } else {
        novoAluno->prox = lista->inicio;
        novoAluno->ant = lista->inicio->ant;
        lista->inicio->ant->prox = novoAluno;
        lista->inicio->ant = novoAluno;
    }
}

void realizarSorteio(struct ListaCircularDupla* lista, int X) {
    if (lista->inicio == NULL) {
        printf("A lista de alunos está vazia.\n");
        return;
    }

    struct No2* atual = lista->inicio;
    while (atual->prox != lista->inicio) {
        // Contagem até X
        for (int i = 1; i < X; i++) {
            atual = atual->prox;
        }

        // Imprime e remove o aluno atual
        printf("Aluno eliminado: %s\n", atual->nome);

        struct No2* ant = atual->ant;
        struct No2* prox = atual->prox;

        ant->prox = prox;
        prox->ant = ant;

        // Libera a memória do nó eliminado
        free(atual);

        // Atualiza o ponteiro para o próximo aluno na contagem
        atual = prox;
    }

    // O último aluno restante ganha a bolsa
    printf("Aluno vencedor: %s\n", atual->nome);

    // Libera a memória do último aluno
    free(atual);

    // Reinicializa a lista
    iniciarListaCircularDupla(lista);
}

void programa2_main() {
    // Criar e inicializar a lista circular dupla
    struct ListaCircularDupla lista;
    iniciarListaCircularDupla(&lista);

    // Adicionar os 7 candidatos à lista
    adicionarAluno(&lista, "Candidato 1");
    adicionarAluno(&lista, "Candidato 2");
    adicionarAluno(&lista, "Candidato 3");
    adicionarAluno(&lista, "Candidato 4");
    adicionarAluno(&lista, "Candidato 5");
    adicionarAluno(&lista, "Candidato 6");
    adicionarAluno(&lista, "Candidato 7");

    // Definindo o número X para o sorteio
    int X = 3;

    // Realizando o sorteio e imprimindo os resultados
    printf("Resultado do Sorteio:\n");
    realizarSorteio(&lista, X);
}

