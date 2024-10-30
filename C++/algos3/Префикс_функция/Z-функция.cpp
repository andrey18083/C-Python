#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s; 
    int n = s.length();
    std::vector<int> z(n, 0); 
    long long b = 10e9;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        if (b >= 0) {
            d = 0;
        }
        if (i <= r) {
            d = z[i - l];
            if (i + d - 1 < r) {
                z[i] = d;
                b = 0;
                continue;
            } else {
                d = r - i + 1;
            }
        }
        while (i + d < n && s[d] == s[i + d]) {
            d++;
        }
        z[i] = d;
        l = i;
        r = i + d - 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << z[i] << " ";
    }
    return 0;
}