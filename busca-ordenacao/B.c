#include <stdio.h>

// Função de busca binária para encontrar j tal que v[j-1] < x <= v[j]
int busca_binaria(int *v, int n, int x) {
    if (n == 0) return 0;
    if (x <= v[0]) return 0;
    if (x > v[n-1]) return n;

    int left = 0, right = n - 1, j = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] >= x) {
            j = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return j;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", busca_binaria(v, N, x));
    }

    return 0;
}