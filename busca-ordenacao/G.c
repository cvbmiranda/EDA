#include <stdio.h>
#include <stdlib.h>

#define MAX_PLACAS 1000000 // Tamanho máximo estimado

int placas[MAX_PLACAS];
int total_placas = 0;

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void inserir_placa(int placa) {
    placas[total_placas++] = placa;
    qsort(placas, total_placas, sizeof(int), comparar);
}

void listar_menores(int T) {
    for (int i = 0; i < T; i++) {
        if (i != 0) printf(" ");
        printf("%d", placas[i]);
    }
    printf("\n");
}

int main() {
    int O, valor;
    
    while (scanf("%d", &O) != EOF) {
        if (O == 1) {
            scanf("%d", &valor);
            inserir_placa(valor);
        } else if (O == 2) {
            scanf("%d", &valor);
            listar_menores(valor);
        }
    }
    
    return 0;
}