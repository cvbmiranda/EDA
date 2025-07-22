#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    if (primeiro >= ultimo) {
        return 1; // Caso base: todos os pares foram verificados
    }

    int soma_ref = v[primeiro] + v[ultimo];
    int soma_atual = v[primeiro + 1] + v[ultimo - 1];

    if (soma_ref != soma_atual) {
        return 0;
    }

    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}
