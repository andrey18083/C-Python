#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> list1;
vector<int> list2;

bool dfs(int v, int c) {
    list2[v] = c;
    for (int u : list1[v]) {
        if (list2[u] == -1) {
            if (!dfs(u, 1 - c)) {
                return false;
            }
        } else if (list2[u] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    list1.resize(n);
    list2.assign(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        list1[a].push_back(b);
        list1[b].push_back(a);
    }
    bool otv = true;
    for (int i = 0; i < n; ++i) {
        if (list2[i] == -1) {
            if (!dfs(i, 0)) {
                otv = false;
                break;
            }
        }
    }
    if (otv) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}