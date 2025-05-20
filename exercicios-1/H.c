#include <stdio.h>

#define MAX_DISCIPLINAS 10000

int main() {
    int D;
    scanf("%d", &D);

    int ano, semestre, m;
    
    while (scanf("%d %d %d", &ano, &semestre, &m) == 3) {
        int cod, matriculados, aprovados;
        int reprovacoes[MAX_DISCIPLINAS] = {0};
        int maxReprovados = -1;

        int usados[MAX_DISCIPLINAS] = {0};

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &cod, &matriculados, &aprovados);
            int reprovados = matriculados - aprovados;
            reprovacoes[cod] = reprovados;
            usados[cod] = 1;

            if (reprovados > maxReprovados)
                maxReprovados = reprovados;
        }

        printf("%d/%d\n", ano, semestre);
        for (int i = 0; i < D; i++) {
            if (usados[i] && reprovacoes[i] == maxReprovados)
                printf("%d ", i);
        }
        printf("\n\n");
    }

    return 0;
}
