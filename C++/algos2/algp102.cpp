#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> a1;
std::vector<std::vector<int>> a2;

int log2(int n) {
    return static_cast<int>(std::log2(n));
}

void buildSparseTable(int n) {
    int log_n = log2(n) + 1;
    a2.resize(log_n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        a2[0][i] = a1[i];
    }
    for (int i = 1; i < log_n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            a2[i][j] = std::min(a2[i - 1][j], a2[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return std::min(a2[k][l], a2[k][r - (1 << k) + 1]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n;
    a1.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a1[i];
    }
    buildSparseTable(n);
    int64_t otv = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        otv += query(l, r);
    }
    std::cout << otv;
    return 0;
}