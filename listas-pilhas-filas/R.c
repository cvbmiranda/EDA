#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR 100
#define MAX_STACK 1000

typedef struct {
    char dados[MAX_STACK][MAX_STR];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

bool empilha(Pilha *p, const char *valor) {
    if (p->topo == MAX_STACK - 1) return false;
    strcpy(p->dados[++p->topo], valor);
    return true;
}

bool desempilha(Pilha *p, char *valor) {
    if (p->topo == -1) return false;
    strcpy(valor, p->dados[p->topo--]);
    return true;
}

bool vazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    Pilha historico;
    inicializa(&historico);
    char comando[10];
    char str[MAX_STR];
    
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            scanf(" %[^\n]", str);
            empilha(&historico, str);
        } 
        else if (strcmp(comando, "desfazer") == 0) {
            if (vazia(&historico)) {
                printf("NULL\n");
            } else {
                char ultimo[MAX_STR];
                desempilha(&historico, &ultimo);
                printf("%s\n", ultimo);
            }
        }
    }
    
    return 0;
}