#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct Fila {
    struct No *inicio;
    struct No *fim;
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool estaVazia(Fila *fila) {
    return (fila->inicio == NULL && fila->fim == NULL);
}

void enfileirar(Fila *fila, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->dado = valor;
    novo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void mostrarFila(Fila *fila) {
    No *atual = fila->inicio;
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Elementos da fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberarFila(Fila *fila) {
    No *atual = fila->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Portuguese");

    Fila fila1;
    inicializar(&fila1);

    enfileirar(&fila1, 10);
    enfileirar(&fila1, 20);
    enfileirar(&fila1, 30);

    mostrarFila(&fila1);

    liberarFila(&fila1);

    return 0;
}