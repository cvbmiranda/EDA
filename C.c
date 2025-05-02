#include <stdio.h>

int main() {
    int B, T;
    scanf("%d", &B);
    scanf("%d", &T);

    // Área total da nota = 160 * 70 = 11200
    // Metade da área = 5600

    // Área da parte do Eduardo (lado esquerdo)
    int areaEduardo = 70 * (B + T) / 2;

    if (areaEduardo > 5600) {
        printf("1\n"); // Eduardo
    } else if (11200 - areaEduardo > 5600) {
        printf("2\n"); // Daiane
    } else {
        printf("0\n"); // Nenhum
    }

    return 0;
}
