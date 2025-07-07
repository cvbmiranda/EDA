#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXC 1000001  // Aumentado para 1 milhão
#define MAXL 27

static char cidades[MAXC][MAXL];
static int fila[MAXC];
static int ini = 0, fim = 0;

// Versão ultra-rápida de putchar para strings
static inline void puts_fast(const char *s) {
    while (*s) putchar_unlocked(*s++);
    putchar_unlocked('\n');
}

int main(void) {
    int n = 0;
    // Leitura rápida usando fread
    char buffer[1000000];
    setvbuf(stdin, buffer, _IOFBF, sizeof(buffer));
    
    while (scanf("%26s", cidades[n]) == 1) {
        fila[fim++] = n++;
    }

    // Saída rápida com buffer
    setvbuf(stdout, NULL, _IOFBF, 0);
    
    while (ini < fim) {
        int cur = fila[ini++];
        puts_fast(cidades[cur]);

        if (ini == fim) break;

        // Calcula última letra da cidade atual
        int L = strlen(cidades[cur]);
        char last = cidades[cur][L-1] | 32;  // to lowercase
        
        // Calcula primeira letra da próxima cidade
        char first = cidades[fila[ini]][0] | 32;
        
        if (first == last) {
            fila[fim++] = fila[ini++];
        }
    }

    return 0;
}