#include <iostream>
#include <vector>

std::vector<long long> derevo;

long long find_pow(long long n) {
    long long per = 0;
    while (n != 0) {
        n /= 2;
        per++;
    }
    return per;
}

void build(std::vector<long long>& arr, long long a, long long b, long long c) {
    if (b == c) {
        derevo[a] = arr[b];
    } else {
        long long M = (b + c) / 2;
        build(arr, a * 2 + 1, M + 1, c);
        build(arr, a * 2, b, M);
        derevo[a] = derevo[a * 2] + derevo[a * 2 + 1];
    }
}

void update(long long a, long long la, long long ra, long long y, long long x) {
    if (la == ra) {
        derevo[a] = x;
    } else {
        long long mid = (la + ra) / 2;
        if (y > mid) {
            update(a * 2 + 1, mid + 1, ra, y, x);
        } else {
            update(a * 2, la, mid, y, x);
        }
        derevo[a] = derevo[a * 2] + derevo[a * 2 + 1];
    }
}

long long sum(long long a, long long la, long long ra, long long b, long long c) {
    if (b > c) {
        return 0;
    } else if (b == la && c == ra) {
        return derevo[a];
    } else {
        long long mid = (la + ra) / 2;
        return sum(a * 2, la, mid, b, std::min(c, mid)) + sum(a * 2 + 1, mid + 1, ra, std::max(b, mid + 1), c);
    }
}

int main() {
    long long n;
    std::cin >> n;
    derevo.resize(4 * n);
    std::vector<long long> arr(n);
    for (auto& el : arr) {
        std::cin >> el;
    }
    build(arr, 1, 0, n - 1);
    long long k;
    std::cin >> k;
    for (long long y = 0; y < k; ++y) {
        long long prov;
        std::cin >> prov;
        if (prov == 2) {
            long long pos, x;
            std::cin >> pos >> x;
            update(1, 0, n - 1, pos, x);
        } else if (prov == 1) {
            long long b, c;
            std::cin >> b >> c;
            std::cout << sum(1, 0, n - 1, b, c) << "\n";
        }
    }
}