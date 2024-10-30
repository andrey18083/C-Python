#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> list1, list2;
vector<bool> list3;
vector<int> od, cmp;

void dfs1(int v) {
    list3[v] = true;
    for (int u : list1[v]) {
        if (!list3[u]) {
            dfs1(u);
        }
    }
    od.push_back(v);
}

void dfs2(int v, int k) {
    list3[v] = true;
    cmp[v] = k;
    for (int u : list2[v]) {
        if (!list3[u]) {
            dfs2(u, k);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    list1.resize(n + 1);
    list2.resize(n + 1);
    list3.assign(n + 1, false);
    cmp.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        list1[a].push_back(b);
        list2[b].push_back(a);
    }
    for (int v = 1; v <= n; ++v) {
        if (!list3[v]) {
            dfs1(v);
        }
    }
    reverse(od.begin(), od.end());
    list3.assign(n + 1, false);
    int cnt = 0;
    for (int v : od) {
        if (!list3[v]) {
            dfs2(v, ++cnt);
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i) {
        cout << cmp[i] << " ";
    }
    return 0;
}