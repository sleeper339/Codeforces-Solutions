#include <stdio.h>

void Solve() {
    int n;
    
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        printf("%d ", i);

        for (int j = 1; j <= (n-i); j++) {
            printf("%d ", j);
        }
        printf("\n");

        if(i < n) {
            printf("%d ", i);

            for(int j = (n-i) + 1; j <= n; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
}

int main() {
    Solve();

    return 0;
}