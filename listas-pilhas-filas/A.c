#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *atual = le->prox;
    
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    
    printf("NULL");
}

void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL");
        return;
    }
    
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}

