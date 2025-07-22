#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Versão iterativa da busca
celula *busca(celula *le, int x) {
    celula *atual = le->prox; // Pula o nó cabeça
    
    while (atual != NULL) {
        if (atual->dado == x) {
            return atual; // Retorna a célula encontrada
        }
        atual = atual->prox;
    }
    
    return NULL; // Retorna NULL se não encontrar
}

// Versão recursiva da busca
celula *busca_rec(celula *le, int x) {
    if (le->prox == NULL) {
        return NULL; // Caso base: lista vazia
    }
    
    if (le->prox->dado == x) {
        return le->prox; // Encontrou o elemento
    }
    
    return busca_rec(le->prox, x); // Chama recursivamente para o próximo
}