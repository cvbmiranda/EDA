#include <stdio.h>

void troca_x_por_y(char *str, int pos) {
    // Caso base: final da string
    if (str[pos] == '\0') {
        return;
    }
    
    // Se encontrar 'x', substitui por 'y'
    if (str[pos] == 'x') {
        str[pos] = 'y';
    }
    
    // Chamada recursiva para próxima posição
    troca_x_por_y(str, pos + 1);
}

int main() {
    char str[81];
    scanf("%s", str);
    
    troca_x_por_y(str, 0);
    printf("%s\n", str);
    
    return 0;
}