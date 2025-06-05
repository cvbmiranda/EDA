#include <stdio.h>
#include <math.h>

int contagemCirculos(int raios[], int C, long long dist2) {
    int ini = 0, fim = C - 1, resp = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        long long raio2 = (long long)raios[meio] * raios[meio];

        if (raio2 >= dist2) {
            resp = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    return resp == -1 ? 0 : C - resp;
}

int main() {
    int C, T;
    scanf("%d %d", &C, &T);

    int raios[C];
    for (int i = 0; i < C; i++) {
        scanf("%d", &raios[i]);
    }

    long long total_pontos = 0;

    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        long long dist2 = (long long)x * x + (long long)y * y;

        int pontos = contagemCirculos(raios, C, dist2);
        total_pontos += pontos;
    }

    printf("%lld\n", total_pontos);
    return 0;
}