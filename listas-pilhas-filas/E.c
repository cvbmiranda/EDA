#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox;  // Primeiro elemento de l1 (pula cabeça)
    celula *p2 = l2->prox;  // Primeiro elemento de l2
    celula *p3 = l3;        // Último elemento da lista resultante (inicia no cabeça)
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->dado <= p2->dado) {
            p3->prox = p1;  // Adiciona p1 à lista resultante
            p1 = p1->prox;  // Avança p1
        } else {
            p3->prox = p2;  // Adiciona p2 à lista resultante
            p2 = p2->prox;  // Avança p2
        }
        p3 = p3->prox;      // Avança p3
    }
    
    // Adiciona os elementos restantes de l1 ou l2
    if (p1 != NULL) {
        p3->prox = p1;
    } else {
        p3->prox = p2;
    }
    
    // Garante que l1 e l2 ficam vazias (opcional, conforme enunciado)
    l1->prox = NULL;
    l2->prox = NULL;
}