#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int ma = 200001;
const int lma = 20;

size_t n, l;
vector<pair<int, int>> g[ma];
int tn[ma], tt[ma];
int tm;
pair<int, int> up[ma][lma];

void dfs(int v, int p = 1, int c = INT_MAX) {
    tn[v] = tm++;
    up[v][0] = make_pair(p, c);
    for (int i = 1; i <= l; ++i) {
        up[v][i].first = up[up[v][i - 1].first][i - 1].first;
        up[v][i].second = min(up[v][i - 1].second, up[up[v][i - 1].first][i - 1].second);
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].first;
        dfs(to, v, g[v][i].second);
    }
    tt[v] = tm++;
}

bool upper(int a, int b) {
    return tn[a] <= tn[b] && tt[a] >= tt[b];
}

int minlca(int a, int b) {
    int otv = INT_MAX;
    for (int i = l; i >= 0; i--) {
        if (!upper(up[a][i].first, b)) {
            otv = min(otv, up[a][i].second);
            a = up[a][i].first;
        }
    }
    if (!upper(a, b)) {
        otv = min(otv, up[a][0].second);
    }
    for (int i = l; i >= 0; i--) {
        if (!upper(up[b][i].first, a)) {
            otv = min(otv, up[b][i].second);
            b = up[b][i].first;
        }
    }
    if (!upper(b, a)) {
        otv = min(otv, up[b][0].second);
    }
    return otv;
}


int main() {
    int m;
    cin >> n;
    l = 1;
    while ((1 << l) <= n) ++l;
    for (int i = 2; i < n + 1; i++) {
        int x;
        int p;
        cin >> x >> p;
        g[x].push_back(make_pair(i, p));
    }
    dfs(1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int otv = minlca(u, v);
        cout << otv << endl;
    };
    return 0;
}