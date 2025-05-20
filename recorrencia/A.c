#include <stdio.h>
#include <string.h>

#define MAX_N 1000000

// Memoização para armazenar resultados já calculados
int memo[MAX_N + 1];

// Função f91 com memoização
int f91(int n) {
    if (n > MAX_N) return n - 10; // Evita estouro de memória
    
    if (memo[n] != -1) return memo[n]; // Retorna valor memoizado
    
    if (n >= 101) {
        memo[n] = n - 10;
    } else {
        memo[n] = f91(f91(n + 11));
    }
    
    return memo[n];
}

int main() {
    int n;
    
    // Inicializa a memoização com -1 (não calculado)
    memset(memo, -1, sizeof(memo));
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break; // Termina quando ler 0
        
        printf("f91(%d) = %d\n", n, f91(n));
    }
    
    return 0;
}