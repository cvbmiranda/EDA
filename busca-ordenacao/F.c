#include <stdio.h>
#include <stdlib.h>

// Função de busca binária que retorna o número de elementos <= target
int count_circles(long long *radii, int C, long long distance_sq) {
    int left = 0, right = C - 1;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Compara o quadrado do raio com a distância ao quadrado
        if (radii[mid] * radii[mid] >= distance_sq) {
            result = mid + 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int C, T;
    scanf("%d %d", &C, &T);
    
    // Lê os raios dos círculos (já em ordem crescente)
    long long *radii = (long long *)malloc(C * sizeof(long long));
    for (int i = 0; i < C; i++) {
        scanf("%lld", &radii[i]);
    }
    
    long long total_points = 0;
    
    for (int i = 0; i < T; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        
        // Calcula a distância ao quadrado para evitar raiz quadrada
        long long distance_sq = x * x + y * y;
        
        // Conta quantos círculos contêm este ponto
        int points = count_circles(radii, C, distance_sq);
        total_points += points;
    }
    
    printf("%lld\n", total_points);
    free(radii);
    return 0;
}