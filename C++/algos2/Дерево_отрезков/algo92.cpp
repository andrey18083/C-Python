#include <iostream>
#include <cmath>
#include <vector>

const long long big = pow(10, 10);

long long find_pow(long long n) {
    long long per = 0;
    while (n >>= 1) {
        ++per;
    }
    return per;
}

void build(std::vector<long long>& derevo, const std::vector<long long>& arr, long long a, long long x, long long y) {
    if (x == y) {
        derevo[a] = arr[y];
    } else {
        long long M = x + (y - x) / 2;
        build(derevo, arr, a * 2, x, M);
        build(derevo, arr, a * 2 + 1, M + 1, y);
        derevo[a] = std::max(derevo[a * 2], derevo[a * 2 + 1]);
    }
}

void update(std::vector<long long>& derevo, long long a, long long la, long long ra, long long q, long long p) {
    if (la == ra) {
        derevo[a] = p;
    } else {
        long long mid = la + (ra - la) / 2;
        if (q > mid) {
            update(derevo, a * 2 + 1, mid + 1, ra, q, p);
        } else {
            update(derevo, a * 2, la, mid, q, p);
        }
        derevo[a] = std::max(derevo[a * 2], derevo[a * 2 + 1]);
    }
}

long long sum(std::vector<long long>& derevo, long long a, long long la, long long ra, long long l, long long r) {
    if (l > r) {
        return -big;
    } else if (l == la && r == ra) {
        return derevo[a];
    } else {
        long long mid = la + (ra - la) / 2;
        return std::max(sum(derevo, a * 2, la, mid, l, std::min(r, mid)),
                        sum(derevo, a * 2 + 1, mid + 1, ra, std::max(l, mid + 1), r));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    long long n, k;
    std::cin >> n;
    long long treeSize = 4 * n;
    std::vector<long long> derevo(treeSize);
    std::vector<long long> arr(n);
    for (long long q = 0; q < n; ++q) {
        std::cin >> arr[q];
    }
    build(derevo, arr, 1, 0, n - 1);
    std::cin >> k;
    for (long long q = 0; q < k; ++q) {
        long long cmd;
        std::cin >> cmd;
        if (cmd == 2) {
            long long pos, p;
            std::cin >> pos >> p;
            update(derevo, 1, 0, n - 1, pos, p);
        } else if (cmd == 1) {
            long long l, r;
            std::cin >> l >> r;
            std::cout << sum(derevo, 1, 0, n - 1, l, r) << "\n";
        }
    }
    return 0;
}