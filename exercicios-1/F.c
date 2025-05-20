#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Primeira pirâmide
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d", i);
            if (j < i) printf(" ");
        }
        printf("\n");
    }

    printf("\n"); // Linha em branco entre as pirâmides

    // Segunda pirâmide
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d", j);
            if (j < i) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
