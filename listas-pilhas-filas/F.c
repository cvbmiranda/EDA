#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox;  // Pula o nó cabeça de l
    celula *ultimo_impar = l1;  // Ponteiro para o último ímpar
    celula *ultimo_par = l2;    // Ponteiro para o último par
    
    while (atual != NULL) {
        if (abs(atual->dado) % 2 == 1) {  // É ímpar
            ultimo_impar->prox = atual;
            ultimo_impar = ultimo_impar->prox;
        } else {  // É par
            ultimo_par->prox = atual;
            ultimo_par = ultimo_par->prox;
        }
        atual = atual->prox;
    }
    
    // Finaliza ambas as listas
    ultimo_impar->prox = NULL;
    ultimo_par->prox = NULL;
    
    // Lista original fica vazia
    l->prox = NULL;
}