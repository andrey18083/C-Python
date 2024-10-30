#include <iostream>
#include <string>
#include <cmath>

std::string decodeHamming(std::string S) {
    int m = S.length();
    int r = 0; 
    while ((1 << r) < (m + r + 1)) {
        r++;
    }
    int erp = 0;
    for (int i = 0; i < r; i++) {
        int pb = 0;
        for (int j = 1; j <= m; j++) {
            if (j & (1 << i)) {
                pb ^= (S[j - 1] - '0');
            }
        }
        if (pb != 0) {
            erp += (1 << i);
        }
    }
    if (erp > 0) {
        S[erp - 1] = (S[erp - 1] == '0') ? '1' : '0';
    }
    std::string otv;
    for (int i = 0; i < m; i++) {
        if ((i + 1) & (i + 1)) {
            int po = 0;
            while ((1 << po) <= (i + 1)) {
                po++;
            }
            if ((1 << (po - 1)) != (i + 1)) {
                otv += S[i];
            }
        }
    }
    return otv;
}

int main() {
    std::string a;
    std::cin >> a;
    std::string b = decodeHamming(a);
    std::cout << b << std::endl;
    return 0;
}
