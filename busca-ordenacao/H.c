#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, P, X;
    scanf("%d %d %d", &N, &P, &X);
    
    int *ids = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &ids[i]);
    }
    
    // Ordena os IDs
    qsort(ids, N, sizeof(int), comparar);
    
    // Calcula os índices da página
    int inicio = P * X;
    int fim = (P + 1) * X;
    if (fim > N) fim = N;
    
    // Imprime os IDs da página
    for (int i = inicio; i < fim; i++) {
        printf("%d\n", ids[i]);
    }
    
    free(ids);
    return 0;
}