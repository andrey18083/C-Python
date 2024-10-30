#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> list1;
vector<bool> list2;
vector<int> list3;

int dfs(int node) {
    list2[node] = true;
    int size = 1;
    for (int ng : list1[node]) {
        if (!list2[ng]) {
            size += dfs(ng);
        }
    }
    list3[node] = size;
    return size;
}

int main() {
    int n;
    cin >> n;
    list1.resize(n + 1);
    list2.assign(n + 1, false);
    list3.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        list1[u].push_back(v);
        list1[v].push_back(u);
    }
    dfs(1);
    int otv = -1;
    for (int i = 1; i <= n; ++i) {
        int sum = n - list3[i];
        for (int ng : list1[i]) {
            if (list3[ng] < list3[i]) {
                sum = max(sum, list3[ng]);
            }
        }
        if (sum <= n / 2) {
            otv = i;
        }
    }
    cout << otv << endl;
    return 0;
}