#include <stdio.h>
#include <string.h>

int main() {
    int F, L;
    scanf("%d %d", &F, &L);

    char sala[20][25][3]; // até 20 fileiras, 25 lugares, 3 caracteres por assento ("XX" ou "--")
    
    // Inicializa a sala toda como vazia
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < L; j++) {
            strcpy(sala[i][j], "--");
        }
    }

    char lugar[10];
    while (scanf("%s", lugar) != EOF) {
        char fileira = lugar[0];
        int pos;
        sscanf(lugar + 1, "%d", &pos); // extrai número da posição

        int f_index = fileira - 'A';   // transforma A → 0, B → 1, ...
        int l_index = pos - 1;         // transforma posição 1 → 0

        if (f_index < F && l_index < L) {
            strcpy(sala[f_index][l_index], "XX"); // marca como ocupado
        }
    }

    // Imprime cabeçalho
    printf("  ");
    for (int i = 1; i <= L; i++) {
        printf(" %02d", i);
    }
    printf("\n");

    // Imprime de trás pra frente (última fileira primeiro)
    for (int i = F - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < L; j++) {
            printf("%s ", sala[i][j]);
        }
        printf("\n");
    }

    return 0;
}
