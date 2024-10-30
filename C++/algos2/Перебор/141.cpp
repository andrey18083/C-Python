#include <iostream>
#include <vector>
#include <algorithm>

const int big = 1e9;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }
    int otv = big;
    if (n == 1) {
        otv = 0;
    } else {
        std::vector<int> vertex(n);
        for (int i = 1; i < n; ++i) {
            vertex[i] = i;
        }
        do {
            int sum = 0;
            bool prov = true;

            for (int i = 0; i < n - 1; ++i) {
                if (graph[vertex[i]][vertex[i + 1]] == 0) {
                    prov = false;
                    break;
                } else {
                    sum += graph[vertex[i]][vertex[i + 1]];
                }
            }
            if (prov && graph[vertex[n - 1]][vertex[0]] != 0) {
                sum += graph[vertex[n - 1]][vertex[0]];
                otv = std::min(otv, sum);
            }
        } while (std::next_permutation(vertex.begin() + 1, vertex.end()));
    }
    if (otv == big) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << otv << std::endl;
    }
    return 0;
}