#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int64_t x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << std::gcd(std::abs(x2 - x1), std::abs(y2 - y1)) + 1;
}