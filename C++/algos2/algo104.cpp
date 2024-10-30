#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int n, m;
std::vector<int> a1;
std::vector<std::vector<int>> a2;

int findPower(int x) {
    int p = 0;
    while (x != 0) {
        x /= 2;
        ++p;
    }
    return p;
}

void buildSparseTable() {
    int ln = static_cast<int>(std::log2(n)) + 1;
    a2.resize(ln, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        a2[0][i] = a1[i];
    }

    for (int i = 1; i < ln; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            a2[i][j] = std::min(a2[i - 1][j], a2[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    int k = findPower(r - l + 1) - 1;
    return std::min(a2[k][l], a2[k][r - (1 << k) + 1]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a;
    std::cin >> n >> m >> a;
    a1.resize(n);
    a1[0] = a;
    for (int i = 1; i < n; ++i) {
        a1[i] = (23 * a1[i - 1] + 21563) % 16714589;
    }
    buildSparseTable();
    int o1, o2, otv = 0;
    std::cin >> o1 >> o2;
    for (int i = 1; i <= m; ++i) {
        int l = std::min(o1, o2) - 1;
        int r = std::max(o1, o2) - 1;
        otv = query(l, r);
        if (i != m) {
            o1 = ((17 * o1 + 751 + otv + 2 * i) % n) + 1;
            o2 = ((13 * o2 + 593 + otv + 5 * i) % n) + 1;
        }
    }
    std::cout << o1 << " " << o2 << " " << otv << std::endl;
    return 0;
}