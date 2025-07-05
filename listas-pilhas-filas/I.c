#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    // Verifica se a pilha está vazia (após o nó cabeça)
    if (p == NULL || p->prox == NULL) {
        return 0;  // Falha na remoção
    }
    
    // Remove o primeiro elemento após o cabeça (topo da pilha)
    celula *remover = p->prox;
    *y = remover->dado;       // Salva o valor no endereço y
    p->prox = remover->prox;  // Atualiza o ponteiro do cabeça
    free(remover);            // Libera a memória do nó removido
    
    return 1;  // Sucesso na remoção
}