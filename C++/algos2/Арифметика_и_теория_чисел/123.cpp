#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    while (n % 2 == 0) {
        a.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        a.push_back(n);
    }
    for (const int& i : a) {
        std::cout << i << " ";
    }
}