#include <iostream>

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    int r = a % b;
    if (r == 0) {
        return b;
    } else {
        return gcd(b, r);
    }
}

int main() {
    int x;
    int y;
    std::cin >> x;
    std::cin >> y;
    std::cout << gcd(x, y) << std::endl;
    return 0;
}