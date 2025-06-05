void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int indice_minimo(int *v, int i, int n) {
    if (i == n - 1)
        return i;
    int min_indice = indice_minimo(v, i + 1, n);
    return (v[i] < v[min_indice]) ? i : min_indice;
}

void selecao_recursiva(int *v, int i, int n) {
    if (i == n)
        return;
    int min_indice = indice_minimo(v, i, n);
    troca(&v[i], &v[min_indice]);
    selecao_recursiva(v, i + 1, n);
}

void ordena(int *v, int n) {
    selecao_recursiva(v, 0, n);
}
