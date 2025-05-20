#include <stdio.h>
#include <string.h>

// Função para calcular a soma dos dígitos de uma string representando um número
int soma_digitos(char *numero) {
    int soma = 0;
    for (int i = 0; numero[i] != '\0'; i++) {
        soma += numero[i] - '0';
    }
    return soma;
}

// Função para calcular o grau-9
int grau_9(int soma) {
    int grau = 1;
    while (soma > 9) {
        int nova_soma = 0;
        int temp = soma;
        while (temp > 0) {
            nova_soma += temp % 10;
            temp /= 10;
        }
        soma = nova_soma;
        grau++;
    }
    return grau;
}

int main() {
    char numero[1001];
    while (1) {
        scanf("%s", numero);
        if (strcmp(numero, "0") == 0) break;

        int soma = soma_digitos(numero);
        if (soma % 9 == 0) {
            int grau = grau_9(soma);
            printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grau);
        } else {
            printf("%s is not a multiple of 9.\n", numero);
        }
    }
    return 0;
}