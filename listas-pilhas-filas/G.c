#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N;
    int topo;
} pilha;

int desempilha(pilha *p, int *y) {
    // Verifica se a pilha está vazia
    if (p == NULL || p->topo == 0) {
        return 0;  // Falha na remoção
    }
    
    // Remove o elemento do topo e salva em y
    p->topo--;          // Decrementa o topo
    *y = p->dados[p->topo];  // Salva o valor no endereço y
    
    return 1;  // Sucesso na remoção
}