#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 501

typedef struct pilha {
    char dados[MAX];
    int topo;
} pilha;

void init(pilha *p) {
    p->topo = -1;
}

int vazia(pilha *p) {
    return p->topo == -1;
}

int cheia(pilha *p) {
    return p->topo == MAX - 1;
}

void push(pilha *p, char c) {
    if (!cheia(p))
        p->dados[++p->topo] = c;
}

char pop(pilha *p) {
    if (!vazia(p))
        return p->dados[p->topo--];
    return '\0';
}

char topo(pilha *p) {
    if (!vazia(p))
        return p->dados[p->topo];
    return '\0';
}

int precedencia(char op) {
    switch (op) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        default: return 0;
    }
}

int associativa_direita(char op) {
    return op == '^';
}

int main() {
    char expr[MAX];
    scanf("%s", expr);

    char saida[MAX];
    int j = 0;
    pilha p;
    init(&p);

    int balanceamento = 0;

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];

        if (isalpha(c)) {
            saida[j++] = c;
        } else if (c == '(') {
            push(&p, c);
            balanceamento++;
        } else if (c == ')') {
            balanceamento--;
            while (!vazia(&p) && topo(&p) != '(')
                saida[j++] = pop(&p);
            if (vazia(&p)) {
                printf("incorretamente parentizada\n");
                return 0;
            }
            pop(&p); // descarta '('
        } else if (strchr("+-*/^", c)) {
            while (!vazia(&p) && topo(&p) != '(' &&
                    (precedencia(topo(&p)) > precedencia(c) ||
                    (precedencia(topo(&p)) == precedencia(c) && !associativa_direita(c)))) {
                saida[j++] = pop(&p);
            }
            push(&p, c);
        }
    }

    if (balanceamento != 0) {
        printf("incorretamente parentizada\n");
        return 0;
    }

    while (!vazia(&p)) {
        if (topo(&p) == '(' || topo(&p) == ')') {
            printf("incorretamente parentizada\n");
            return 0;
        }
        saida[j++] = pop(&p);
    }

    saida[j] = '\0';
    printf("%s\n", saida);
    return 0;
}
