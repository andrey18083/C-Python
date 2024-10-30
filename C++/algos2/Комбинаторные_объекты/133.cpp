#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> otv;
    for (int i = 1; i <= N; ++i) {
        otv.push_back(i);
    }
    do {
        for (int n : otv) {
            std::cout << n;
        }
        std::cout << std::endl;
    } while (std::next_permutation(otv.begin(), otv.end()));
    return 0;
}