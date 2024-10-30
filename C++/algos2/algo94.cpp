#include <iostream>
#include <cmath>
#include <vector>

long long n;
long long s = 0;
std::vector<long long> derevo;

long long find_pow(long long n) {
    return static_cast<long long>(std::log2(n) + 1);
}

void build(const std::vector<long long>& arr, long long a, long long x, long long y) {
    if (x == y) {
        derevo[a] = arr[y];
    } else {
        long long M = (x + y) / 2;
        build(arr, a * 2, x, M);
        build(arr, a * 2 + 1, M + 1, y);
        derevo[a] = derevo[a * 2] + derevo[a * 2 + 1];
    }
}

void update(long long a, long long la, long long ra, long long q, long long p) {
    if (la == ra) {
        derevo[a] = p;
    } else {
        long long mid = (la + ra) / 2;
        q > mid ? update(a * 2 + 1, mid + 1, ra, q, p) : update(a * 2, la, mid, q, p);
        derevo[a] = derevo[a * 2] + derevo[a * 2 + 1];
    }
}

void sum(long long a, long long la, long long ra, long long l, long long r) {
    if (l > r) {
        return;
    } else if (l == la && r == ra) {
        s += derevo[a];
        return;
    } else {
        long long mid = (la + ra) / 2;
        sum(a * 2, la, mid, l, std::min(r, mid));
        sum(a * 2 + 1, mid + 1, ra, std::max(l, mid + 1), r);
    }
}

int main() {
    std::cin >> n;
    derevo.resize(4 * n);
    std::vector<long long> arr(n);
    for (long long q = 0; q < n; ++q) {
        std::cin >> arr[q];
        arr[q] = (std::abs(arr[q]) + 1) % 2;
    }
    build(arr, 1, 0, n - 1);
    long long k;
    std::cin >> k;
    for (long long q = 0; q < k; ++q) {
        long long cmd;
        std::cin >> cmd;
        if (cmd == 2) {
            long long pos, p;
            std::cin >> pos >> p;
            update(1, 0, n - 1, pos, std::abs(p + 1) % 2);
        } else if (cmd == 1) {
            long long l, r;
            s = 0;
            std::cin >> l >> r;
            sum(1, 0, n - 1, l, r);
            std::cout << s << "\n";
        }
    }
}