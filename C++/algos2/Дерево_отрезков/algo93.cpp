#include <iostream>
#include <cmath>
#include <vector>
#define ll long long

const ll big = pow(10, 10);

ll find_pow(ll n) {
    ll per = 0;
    while (n != 0) {
        n /= 2;
        ++per;
    }
    return per;
}

void build(std::vector<std::pair<ll, ll>>& derevo, const std::vector<ll>& arr, ll a, ll x, ll y) {
    if (x == y) {
        derevo[a] = {arr[y], y};
    } else {
        ll M = (x + y) / 2;
        build(derevo, arr, a * 2 + 1, M + 1, y);
        build(derevo, arr, a * 2, x, M);
        build(derevo, arr, a * 2 + 1, M + 1, y);
        derevo[a] = std::max(derevo[a * 2], derevo[a * 2 + 1]);
    }
}

void update(std::vector<std::pair<ll, ll>>& derevo, ll a, ll la, ll ra, ll q, ll p) {
    if (la == ra) {
        derevo[a] = {p, la};
    } else {
        ll mid = (la + ra) / 2;
        if (q > mid) {
            update(derevo, a * 2 + 1, mid + 1, ra, q, p);
        } else {
            update(derevo, a * 2, la, mid, q, p);
        }
        derevo[a] = std::max(derevo[a * 2], derevo[a * 2 + 1]);
    }
}

std::pair<ll, ll> sum(const std::vector<std::pair<ll, ll>>& derevo, ll a, ll la, ll ra, ll l, ll r) {
    if (l > r) {
        return {-big, 0};
    } else if (l == la && r == ra) {
        return derevo[a];
    } else {
        ll mid = (la + ra) / 2;
        return std::max(sum(derevo, a * 2, la, mid, l, std::min(r, mid)), 
                        sum(derevo, a * 2 + 1, mid + 1, ra, std::max(l, mid + 1), r));
    }
}

int main() {
    ll n;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> derevo(4 * n);
    std::vector<ll> arr(n);
    for (ll q = 0; q < n; ++q) {
        std::cin >> arr[q];
    }
    build(derevo, arr, 1, 0, n - 1);
    ll k;
    std::cin >> k;
    for (ll q = 0; q < k; ++q) {
        ll cmd;
        std::cin >> cmd;
        if (cmd == 2) {
            ll pos, p;
            std::cin >> pos >> p;
            update(derevo, 1, 0, n - 1, pos, p);

        } else if (cmd == 1) {
            ll l, r;
            std::cin >> l >> r;
            std::pair<ll, ll> result = sum(derevo, 1, 0, n - 1, l, r);
            std::cout << result.second << "\n";
        }
    }
    return 0;
}