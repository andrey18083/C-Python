#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_M = 105;

int a[MAX_N];
array<int, MAX_M> count;
array<int, MAX_M> segTree[MAX_N * 4];
int n, m, q;

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node][a[start]]++;
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        for (int i = 1; i <= m; i++) {
            segTree[node][i] = segTree[node * 2][i] + segTree[node * 2 + 1][i];
        }
    }
}

void query(int node, int start, int end, int l, int r, array<int, MAX_M> &result) {
    if (start > r || end < l) {
        return;
    }
    if (start >= l && end <= r) {
        for (int i = 1; i <= m; i++) {
            result[i] += segTree[node][i];
        }
        return;
    }
    int mid = (start + end) / 2;
    query(node * 2, start, mid, l, r, result);
    query(node * 2 + 1, mid + 1, end, l, r, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);
    
    cin >> q;
    int p = 0;
    for (int i = 1; i <= q; i++) {
        int xi, yi;
        cin >> xi >> yi;

        int l = (xi + p) % n + 1;
        int k = (yi + p) % m + 1;

        int ans = 0;
        for (int r = l; r <= n; r++) {
            array<int, MAX_M> result = {};
            query(1, 1, n, l, r, result);

            int distinct_servers = 0;
            for (int j = 1; j <= m; j++) {
                if (result[j] > 0) {
                    distinct_servers++;
                }
            }

            if (distinct_servers >= k) {
                ans = r;
                break;
            }
        }
        cout << ans << '\n';
        p = ans;
    }

    return 0;
}
