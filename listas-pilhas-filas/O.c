#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 500

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

bool empilha(Pilha *p, char valor) {
    if (p->topo == MAX - 1) return false;
    p->dados[++p->topo] = valor;
    return true;
}

bool desempilha(Pilha *p, char *valor) {
    if (p->topo == -1) return false;
    *valor = p->dados[p->topo--];
    return true;
}

bool verifica_parenteses(const char *expressao) {
    Pilha p;
    inicializa(&p);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        
        // Empilha aberturas
        if (c == '(' || c == '[' || c == '{') {
            if (!empilha(&p, c)) return false;
        }
        // Verifica fechamentos
        else if (c == ')' || c == ']' || c == '}') {
            char topo;
            if (!desempilha(&p, &topo)) return false;
            
            // Verifica correspondência
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return false;
            }
        }
    }
    
    // Verifica se a pilha está vazia (todos abertos foram fechados)
    return p.topo == -1;
}

int main() {
    char expressao[MAX + 1];
    fgets(expressao, MAX + 1, stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // Remove newline
    
    if (verifica_parenteses(expressao)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }
    
    return 0;
}