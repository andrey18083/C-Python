#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 20000;

vector<int> graph[maxn + 1];
int tn[maxn + 1], fp[maxn + 1];
bool list1[maxn + 1];
int tmr = 0;
set<int> otv;

void dfs(int v, int p = -1) {
    list1[v] = true;
    tn[v] = fp[v] = tmr++;
    int ch = 0;
    for (int u : graph[v]) {
        if (u == p) continue;
        if (list1[u]) {
            fp[v] = min(fp[v], tn[u]);
        } else {
            dfs(u, v);
            fp[v] = min(fp[v], fp[u]);
            if (fp[u] >= tn[v] && p != -1)
                otv.insert(v);
            ++ch;
        }
    }
    if (p == -1 && ch > 1)
        otv.insert(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!list1[i]) {
            dfs(i);
        }
    }
    cout << otv.size() << endl;
    for (int v : otv) {
        cout << v << endl;
    }
    return 0;
}