#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move os elementos do arr[0..i-1] que são maiores que key
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    int num;
    
    // Lê números até o EOF ou até atingir o limite do array
    while (scanf("%d", &num) != EOF && count < MAX_SIZE) {
        numbers[count] = num;
        count++;
    }
    
    // Ordena os números
    insertion_sort(numbers, count);
    
    // Imprime os números ordenados
    for (int i = 0; i < count; i++) {
        printf("%d", numbers[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}