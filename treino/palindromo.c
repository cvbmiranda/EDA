#include <stdio.h>
#include <string.h> // Para usar a função strlen()

int main() {
    int N;
    char palavra[100]; // Array para armazenar a palavra (tamanho arbitrário grande)
    
    // Lendo a entrada
    scanf("%d", &N); // Lê o tamanho da palavra
    scanf("%s", palavra); // Lê a palavra
    
    int eh_palindromo = 1; // Inicialmente assumimos que é palíndromo (1 = verdadeiro)
    
    // Verificando se é palíndromo
    for (int i = 0; i < N / 2; i++) {
        // Compara o caractere da posição i com o correspondente no final
        if (palavra[i] != palavra[N - 1 - i]) {
            eh_palindromo = 0; // Se encontrar algum diferente, não é palíndromo
            break; // Pode parar a verificação
        }
    }
    
    // Imprimindo o resultado
    printf("%d\n", eh_palindromo);
    
    return 0;
}