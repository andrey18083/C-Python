#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    unordered_map<int, int> cnt;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            for (int w : adj[v]) {
                if (w != u) {
                    ans += cnt[w];
                }
            }
        }
        for (int v : adj[u]) {
            cnt[v]++;
        }
    }

    cout << ans / 2 << "\n";

    return 0;
}