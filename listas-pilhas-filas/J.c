#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x) {
    // Verifica se o nó cabeça é válido
    if (p == NULL) {
        return 0;  // Falha na inserção
    }
    
    // Cria novo nó
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) {
        return 0;  // Falha na alocação de memória
    }
    
    // Configura novo nó
    novo->dado = x;
    novo->prox = p->prox;  // Novo nó aponta para o antigo topo
    
    // Atualiza o topo da pilha
    p->prox = novo;
    
    return 1;  // Sucesso na inserção
}