#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    long long soma = 0;

    // Leitura dos valores e soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    int media = soma / N;
    int encontrou = 0;

    // Impressão dos valores maiores que a média
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (encontrou) printf(" ");
            printf("%d", vetor[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("0");
    }

    printf("\n");
    return 0;
}
