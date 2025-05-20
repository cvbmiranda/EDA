#include <stdio.h>
#include <math.h>

int main() {
    int a, b, n;
    scanf("%d %d", &a, &b);
    scanf("%d", &n);

    // Calcula log(a^b) = b * log(a)
    double log_exp = b * log((double)a);

    // Calcula log(n!) = log(1) + log(2) + ... + log(n)
    double log_fact = 0;
    for (int i = 2; i <= n; i++) {
        log_fact += log((double)i);
    }

    if (log_exp > log_fact)
        printf("Lucas\n");
    else
        printf("Pedro\n");

    return 0;
}
