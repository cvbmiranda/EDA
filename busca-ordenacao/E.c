#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_HOUSES 45000
#define MAX_ORDERS 45000

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Lê os números das casas
    int houses[MAX_HOUSES];
    for (int i = 0; i < N; i++) {
        scanf("%d", &houses[i]);
    }

    // Lê as encomendas
    int orders[MAX_ORDERS];
    for (int i = 0; i < M; i++) {
        scanf("%d", &orders[i]);
    }

    // Cria um array para mapear número da casa para sua posição
    // Como os números podem ser até 1e9, usamos um array esparso
    // Vamos assumir que podemos usar um array grande o suficiente
    // Na prática, para C, seria melhor usar uma tabela hash, mas para
    // simplificar, vamos fazer uma busca linear (já que N ≤ 45000)

    int total_time = 0;
    int current_pos = 0; // Começa na primeira casa (índice 0)

    for (int i = 0; i < M; i++) {
        int target_house = orders[i];
        int target_pos = -1;

        // Encontra a posição da casa alvo
        for (int j = 0; j < N; j++) {
            if (houses[j] == target_house) {
                target_pos = j;
                break;
            }
        }

        // Calcula a distância e adiciona ao tempo total
        total_time += abs(target_pos - current_pos);
        current_pos = target_pos;
    }

    printf("%d\n", total_time);

    return 0;
}