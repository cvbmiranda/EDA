#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N;
    int topo;
} pilha;

int empilha(pilha *p, int x) {
    // Verifica se a pilha está cheia e precisa redimensionar
    if (p->topo == p->N) {
        // Dobra o tamanho do vetor (estratégia comum)
        int nova_capacidade = p->N * 2;
        int *novos_dados = realloc(p->dados, nova_capacidade * sizeof(int));
        
        if (novos_dados == NULL) {
            return 0;  // Falha no redimensionamento
        }
        
        p->dados = novos_dados;
        p->N = nova_capacidade;
    }
    
    // Insere o elemento e incrementa o topo
    p->dados[p->topo] = x;
    p->topo++;
    
    return 1;  // Sucesso na inserção
}