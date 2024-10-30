#include <iostream>
#include <vector>

void print_sums(size_t n, std::vector<int>& cs, int ln) {
    if (n == 0) {
        for (size_t i = 0; i < cs.size(); ++i) {
            std::cout << cs[i];
            if (i < cs.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= n && i <= ln; ++i) {
        cs.push_back(i);
        print_sums(n - i, cs, i);
        cs.pop_back();
    }
}

void print_sums(size_t n) {
    std::vector<int> cs;
    print_sums(n, cs, n);
}

int main() {
    size_t n;
    std::cin >> n;
    print_sums(n);
    return 0;
}