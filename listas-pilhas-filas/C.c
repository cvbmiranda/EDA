#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Insere no início da lista
void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;  // Novo nó aponta para o antigo primeiro elemento
    le->prox = novo;        // Cabeça aponta para o novo nó
}

// Insere x antes da primeira ocorrência de y
void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    
    // Percorre a lista procurando por y
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    
    // Cria novo nó
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = atual->prox;  // Novo nó aponta para o nó com y (ou NULL)
    atual->prox = novo;        // Nó anterior aponta para o novo nó
}