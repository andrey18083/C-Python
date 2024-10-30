#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> used;
int n,m;

void dfs(int v) {
    used[v] = 1;
    for (int i = 1; i<=n; i++){
        if (g[v][i] == 1 && used[i] == 0){
            cout << v << " " << i << endl;
            dfs(i);
        }
    }
    used[v] = 2;
}

int main() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>(n + 1, 0));
    used.assign(n + 1, 0);
    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    dfs(1);
    return 0;
}