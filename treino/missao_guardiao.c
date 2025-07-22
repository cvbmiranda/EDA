#include <stdlib.h>

typedef struct no {
    int chave; 
    struct no *esq, *dir;
} no;

int numero_folhas(no *r) {
    // Caso base : árvore binária vazia ou nó NULL
    if (r == NULL) {
        return 0;
    }
    
    //Se é uma folha (não tem filhos)
    if (r->esq == NULL && r->dir == NULL ){
        return 1;
    }

    // Soma  as folhas das subárvores esquerda e direita 
    return numero_folhas(r->esq) + numero_folhas(r->dir);
}