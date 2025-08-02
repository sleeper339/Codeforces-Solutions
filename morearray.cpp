#include <iostream>
#include <vector>

void Solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int t = a[0], c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > t + 1) {
            c++;
            t = a[i];
        }
    }

    std::cout << c << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Solve();
    }
}