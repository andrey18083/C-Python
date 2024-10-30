#include <iostream>
#include <vector>

std::vector<int64_t> a1;
std::vector<int64_t> a2;
std::vector<int64_t> a3;
int64_t n;

int64_t sum(int64_t n) {
    if (n < 0) {
        return 0;
    }
    int64_t res = 0;
    for (int64_t i = n; i >= 0; i = (i & (i + 1)) - 1) {
        res += a2[i];
    }
    return res;
}

int64_t sum_interval(int64_t x1, int64_t x2) {
    return sum(x2) - sum(x1 - 1);
}

void increase(int64_t x, int64_t y) {
    for (int64_t i = x; i < n; i |= i + 1) {
        a2[i] += y;
    }
}

int main() {
    std::cin >> n;
    a1.resize(n, 0);
    a2.resize(n, 0);
    for (int64_t i = 0; i < n; ++i) {
        std::cin >> a1[i];
        increase(i, a1[i]);
    }
    int64_t q, x;
    std::cin >> q >> x;
    a3.resize(2 * q);
    a3[0] = x;
    for (int i = 1; i < a3.size(); ++i) {
        a3[i] = (a3[i - 1] * 11173 + 1) % 1000000007;
    }
    int64_t otv = 0;
    for (int64_t i = 0; i < q; ++i) {
        int64_t l = std::min(a3[i * 2] % n, a3[i * 2 + 1] % n);
        int64_t r = std::max(a3[i * 2] % n, a3[i * 2 + 1] % n);
        otv = (otv + sum_interval(l, r)) % 1000000007;
    }
    std::cout << otv;
}