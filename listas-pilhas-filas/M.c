#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    // Verifica se a fila está vazia (apenas nó cabeça presente)
    if (f == NULL || f->prox == NULL) {
        return 0;  // Fila vazia, remoção falhou
    }
    
    // Remove o primeiro elemento após o cabeça (FIFO)
    celula *remover = f->prox;
    *y = remover->dado;       // Salva o valor no endereço y
    f->prox = remover->prox;  // Atualiza o ponteiro do cabeça
    
    // Libera a memória do nó removido
    free(remover);
    
    return 1;  // Remoção bem sucedida
}