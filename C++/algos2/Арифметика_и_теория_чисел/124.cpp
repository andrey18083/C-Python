#include <iostream>
#include <cmath>
#include <vector>

std::vector<bool> sieve(int n) {
    std::vector<bool> a(n + 1, true);
    a[0] = a[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (a[i]) {
            for (int j = i * 2; j <= n; j += i) {
                a[j] = false;
            }
        }
    }
    return a;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    bool ot = true;
    std::vector<bool> a = sieve(m);
    for (int i = n; i <= m; ++i) {
        if (a[i]) {
            std::cout << i << "\n";
            ot = false;
        }
    }
    if (ot) {
        std::cout << "Absent\n";
    }
    return 0;
}
