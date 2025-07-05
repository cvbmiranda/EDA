#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// 1. Remove o elemento imediatamente após p
void remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return;  // Não há elemento para remover
    }
    
    celula *remover = p->prox;
    p->prox = remover->prox;
    free(remover);
}

// 2. Remove a primeira ocorrência de x
void remove_elemento(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;
    
    while (atual != NULL && atual->dado != x) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual != NULL) {  // Encontrou x
        anterior->prox = atual->prox;
        free(atual);
    }
}

// 3. Remove todas as ocorrências de x
void remove_todos_elementos(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;
    
    while (atual != NULL) {
        if (atual->dado == x) {
            celula *remover = atual;
            anterior->prox = atual->prox;
            atual = atual->prox;
            free(remover);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}