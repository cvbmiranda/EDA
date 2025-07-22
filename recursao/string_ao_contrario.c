#include <stdio.h>
#include <string.h>

// Função recursiva para inverter a string
void inverterString(char *str, int inicio, int fim) {
    if (inicio >= fim) return; // Caso base
    
    // Troca os caracteres das posições inicio e fim
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    // Chamada recursiva para o próximo par de caracteres
    inverterString(str, inicio + 1, fim - 1);
}

int main() {
    char str[501]; // String com até 500 caracteres + '\0'
    
    // Lê a string da entrada
    fgets(str, sizeof(str), stdin);
    
    // Remove o '\n' no final (se existir)
    str[strcspn(str, "\n")] = '\0';
    
    // Chama a função para inverter
    inverterString(str, 0, strlen(str) - 1);
    
    // Imprime a string invertida
    printf("%s\n", str);
    
    return 0;
}