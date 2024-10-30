#include <iostream>
#include <vector>

std::vector<std::vector<int>> a1;
std::vector<std::vector<int>> a2;
int n, m;

int calculateSum(int x, int y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    int result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            result += a2[i][j];
        }
    }
    return result;
}

int calculateSum(int x1, int y1, int x2, int y2) {
    return calculateSum(x2, y2) - calculateSum(x1 - 1, y2) - calculateSum(x2, y1 - 1) + calculateSum(x1 - 1, y1 - 1);
}

void update(int x, int y, int d) {
    a1[x][y] += d;
    for (int i = x; i < n; i |= i + 1) {
        for (int j = y; j < m; j |= j + 1) {
            a2[i][j] += d;
        }
    }
}

int main() {
    int otv;
    std::cin >> otv;
    if (otv != 3) {
        int p;
        std::cin >> p;
        n = p;
        m = p;
        a1.resize(n, std::vector<int>(m));
        a2.resize(n, std::vector<int>(m));
    }
    while (otv != 3) {
        if (otv == 1) {
            int x, y, d;
            std::cin >> x >> y >> d;
            update(x, y, d);
        } else if (otv == 2) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << calculateSum(x1, y1, x2, y2) << std::endl;
        }
        std::cin >> otv;
    }
    return 0;
}