#include <iostream>

int qwer(int n, int k) {
    int res = n;
    int prc = 0;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            int cc = 0;
            while (k % i == 0) {
                k /= i;
                cc++;
            }
            int p = i;
            int tp = 0;
            while (p <= n) {
                tp += n / p;
                p *= i;
            }
            res = std::min(res, tp / cc);
            prc++;
        }
    }
    if (k > 1) {
        int tp = 0;
        int p = k;
        while (p <= n) {
            tp += n / p;
            p *= k;
        }
        res = std::min(res, tp);
        prc++;
    }
    return res;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int otv = qwer(n, k);
    std::cout << otv << std::endl;
    return 0;
}