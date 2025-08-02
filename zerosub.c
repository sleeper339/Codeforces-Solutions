#include <stdio.h>

void Solve() {
    int n, k;

    scanf("%d", &n);
    scanf("%d", &k);

    int i = 0;
    for(; i < k; i++) printf("1");
    for(; i < n; i++) printf("0");

    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) Solve();

    return 0;
}