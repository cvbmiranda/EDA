#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N;  // Capacidade total da fila
    int p;  // Índice do primeiro elemento
    int u;  // Índice do próximo espaço vazio
} fila;

int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f == NULL || f->p == f->u) {
        return 0;  // Fila vazia, remoção falhou
    }
    
    // Remove o elemento do início da fila
    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;  // Avança p circularmente
    
    return 1;  // Remoção bem sucedida
}