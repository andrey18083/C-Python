#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> der;
vector<int> dp;
vector<int> tn, tt;
int tm;

void dfs(int v, int p, int d) {
    tn[v] = ++tm;
    dp[v] = d;

    for (int u : der[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }

    tt[v] = ++tm;
}

bool is_ancestor(int a, int b) {
    return tn[a] <= tn[b] && tt[b] <= tt[a];
}

int main() {
    int n;
    cin >> n;
    der.resize(n);
    dp.resize(n);
    tn.resize(n);
    tt.resize(n);
    int rt;
    for (int i = 0; i < n; ++i) {
        int par;
        cin >> par;
        if (par == 0) {
            rt = i;
        } else {
            der[par - 1].push_back(i);
        }
    }
    dfs(rt, -1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (is_ancestor(a, b)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}