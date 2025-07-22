#include <stdio.h>

// Função para imprimir um traço com determinada altura
void imprimir_traco(int altura) {
    printf(".");
    for (int i = 0; i < altura; i++) {
        printf("-");
    }
    printf("\n");
}

// Função recursiva principal para gerar a régua
void gerar_regua(int ordem, int altura_atual) {
    if (altura_atual > 0) {
        gerar_regua(ordem, altura_atual - 1);
        imprimir_traco(altura_atual);
        gerar_regua(ordem, altura_atual - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n > 0) {
        gerar_regua(n, n);
    } else {
        // Caso especial para n = 0 (régua vazia)
        printf("\n");
    }
    
    return 0;
}