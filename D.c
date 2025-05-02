#include <stdio.h>

void converterParaRomano(int numero) {
    // Arrays com os valores romanos e seus equivalentes decimais
    int valores[] =    {1000, 900, 500, 400, 100,  90,  50,  40,  10,   9,   5,   4,   1};
    char* romanos[] = {"M",  "CM","D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            printf("%s", romanos[i]);
            numero -= valores[i];
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int valor;
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        converterParaRomano(valor);
    }

    return 0;
}
