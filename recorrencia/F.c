#include <stdio.h>

int soma_digitos(long long n) {
    // Caso base: quando o número tem apenas 1 dígito
    if (n < 10) {
        return n;
    }
    // Passo recursivo: último dígito + soma dos demais dígitos
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d\n", soma_digitos(n));
    return 0;
}