#include <stdio.h>
#include <string.h>

// Função recursiva para mover os 'x's para o final
void move_xs(char *str, char *resultado, int pos_str, int pos_resultado) {
    if (str[pos_str] == '\0') {
        resultado[pos_resultado] = '\0';
        return;
    }
    
    if (str[pos_str] == 'x') {
        move_xs(str, resultado, pos_str + 1, pos_resultado);
        resultado[strlen(resultado)] = 'x';
        resultado[strlen(resultado) + 1] = '\0';
    } else {
        resultado[pos_resultado] = str[pos_str];
        move_xs(str, resultado, pos_str + 1, pos_resultado + 1);
    }
}

int main() {
    char str[101];
    char resultado[101] = "";
    
    scanf("%s", str);
    move_xs(str, resultado, 0, 0);
    
    printf("%s\n", resultado);
    
    return 0;
}