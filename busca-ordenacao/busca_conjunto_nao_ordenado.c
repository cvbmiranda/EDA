#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int position;
} Element;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Aloca memória para os elementos
    Element* elements = (Element*)malloc(N * sizeof(Element));
    
    // Lê os elementos e armazena com suas posições
    for (int i = 0; i < N; i++) {
        scanf("%d", &elements[i].value);
        elements[i].position = i;
    }
    
    // Ordena os elementos por valor para busca binária
    // Função de comparação para qsort
    int compare(const void* a, const void* b) {
        Element* elemA = (Element*)a;
        Element* elemB = (Element*)b;
        if (elemA->value < elemB->value) return -1;
        if (elemA->value > elemB->value) return 1;
        return 0;
    }
    qsort(elements, N, sizeof(Element), compare);
    
    // Processa as consultas
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        
        // Busca binária no array ordenado
        int left = 0, right = N - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (elements[mid].value == x) {
                result = elements[mid].position;
                break;
            }
            if (elements[mid].value < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%d\n", result);
    }
    
    free(elements);
    return 0;
}