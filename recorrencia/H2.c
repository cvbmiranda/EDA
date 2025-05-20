#include <stdio.h>

// Função para imprimir uma linha com 'm' traços
void imprimir_linha(int m) {
    printf(".");
    for (int i = 0; i < m; i++) {
        printf("-");
    }
    printf("\n");
}

// Função recursiva principal
void regua_inglesa(int n, int m) {
    if (n == 0) return;
    
    regua_inglesa(n - 1, m);
    imprimir_linha(n);
    regua_inglesa(n - 1, m);
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n > 0) {
        regua_inglesa(n, 1);
    }
    
    return 0;
}