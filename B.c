#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int matriz[N][N];

    // Preenchendo a matriz com os valores das camadas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int camada = (i < j ? i : j); // Pega a menor distância até a borda horizontal
            if (N - i - 1 < camada) camada = N - i - 1; // Pega a menor distância até a borda inferior
            if (N - j - 1 < camada) camada = N - j - 1; // Pega a menor distância até a borda direita
            matriz[i][j] = camada + 1;
        }
    }

    // Imprimindo a matriz no formato correto
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matriz[i][j]);
            if (j < N - 1) printf(" "); // Evita espaço no final da linha
        }
        printf("\n"); // Quebra de linha para a próxima linha da matriz
    }

    return 0;
}
