#include <stdio.h>
#include <stdlib.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Caso base: vetor com 2 elementos
    if (ultimo - primeiro == 1) {
        return 1;  // Qualquer par de números forma uma PA trivial
    }
    
    // Calcula a diferença entre os extremos atuais
    int diff_atual = v[ultimo] - v[primeiro];
    
    // Calcula a diferença esperada para ser PA
    int diff_esperada = (v[ultimo] - v[primeiro]) / (ultimo - primeiro);
    
    // Verifica se a progressão é mantida
    if (v[primeiro + 1] - v[primeiro] != diff_esperada) {
        return 0;
    }
    
    // Chamada recursiva para o subvetor interno
    return pa_recursiva(v, primeiro + 1, ultimo);
}

int main() {
    int n;
    printf("Digite o tamanho do vetor (par e >=4): ");
    scanf("%d", &n);
    
    if (n % 2 != 0 || n < 4) {
        printf("O tamanho deve ser par e >=4.\n");
        return 1;
    }
    
    int *v = (int *)malloc(n * sizeof(int));
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    int resultado = pa_recursiva(v, 0, n - 1);
    printf("O vetor %s uma PA.\n", resultado ? "é" : "não é");
    
    free(v);
    return 0;
}