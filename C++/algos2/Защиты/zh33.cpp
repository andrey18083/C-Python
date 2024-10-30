#include <iostream>
#include <vector>

void ps(int n, int k, std::vector<int>& cur) {
    if (n == 0) {
        for (int i = cur.size()-1; i >= 0; --i) {
            if (cur[i] < 10) {
                std::cout << cur[i];
            } else {
                char ch = 'a' + cur[i] - 10;
                std::cout << ch << ' ';
            }
        }
        std::cout << std::endl;
        return;
    }
    for (int i = k-1; i >= 0; --i) {
        cur.push_back(i);
        ps(n - 1, k, cur);
        cur.pop_back();
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cur;
    ps(n, k ,cur);
    return 0;
}