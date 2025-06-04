#include <stdio.h>

// Função de busca binária que retorna o índice j onde v[j-1] < x <= v[j]
int busca_binaria(int *v, int n, int x) {
    int esq = 0, dir = n - 1, meio;
    
    // Casos especiais
    if (x <= v[0]) return 0;
    if (x > v[n-1]) return n;
    
    while (esq <= dir) {
        meio = esq + (dir - esq) / 2;
        
        if (v[meio] < x) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    
    // Quando sai do loop, esq aponta para o primeiro elemento >= x
    return esq;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", busca_binaria(v, N, x));
    }
    
    return 0;
}