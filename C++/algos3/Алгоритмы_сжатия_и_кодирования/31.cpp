#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string hamcod(const std::string &a) {
    int m = a.length();
    int r = 0;
    while (pow(2, r) < m + r + 1) {
        r++;
    }

    std::string otv(m + r, '0');

    int j = 0;
    for (int i = 1; i <= m + r; i++) {
        if (pow(2, j) == i) {
            j++;
        } else {
            otv[i - 1] = a[i - 1 - j];
        }
    }

    for (int i = 0; i < r; i++) {
        int pp = pow(2, i);
        int pv = 0;

        for (int k = 1; k <= m + r; k++) {
            if (k & pp) {
                pv ^= (otv[k - 1] - '0');
            }
        }

        otv[pp - 1] = pv + '0';
    }

    return otv;
}

int main() {
    std::string a;
    std::cin >> a;
    std::string b = hamcod(a);
    std::cout << b << std::endl;
    return 0;
}
