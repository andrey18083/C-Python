#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    long long n, sum = 0, otv = -9999999999;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum = std::max(a[i], sum + a[i]);
        otv = std::max(otv, sum);
    }
    std::cout << otv;
}