#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

const int maxn = 100000;
const int dpr = 17;

vector<int> adj[maxn];
int depth[maxn];
int parent[maxn][dpr];
int odd_count[maxn];

void dfs(int v, int p) {
    parent[v][0] = p;
    if (v % 2 == 1) {
        odd_count[v] = 1;
    } else {
        odd_count[v] = 0;
    }
    if (p != -1) {
        odd_count[v] += odd_count[p];
    }
    for (int u : adj[v]) { 
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

void preprocess(int n) {
    for (int j = 1; j<dpr; ++j) {
        for (int i =0; i<n; ++i) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            } else {
                parent[i][j] = -1;
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = dpr - 1; i>=0; --i) {
        if (parent[u][i] != -1 && depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = dpr - 1; i>=0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[0] = 0;
    dfs(0, -1);
    preprocess(n);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lca(a ,b);
        int otv = odd_count[a] + odd_count[b] - 2*odd_count[l];
        if (l%2 == 1) {
            otv++;
        }
        cout << otv << endl; 
    }
    return 0;
}