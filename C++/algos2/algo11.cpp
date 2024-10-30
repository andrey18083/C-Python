#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& list1, vector<bool>& list2, vector<int>& list3) {
    list2[v] = true;
    list3.push_back(v);

    for (int u : list1[v]) {
        if (!list2[u]) {
            dfs(u, list1, list2, list3);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> list1(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        list1[a].push_back(b);
        list1[b].push_back(a);
    }
    vector<bool> list2(N + 1, false);
    vector<int> list3;
    dfs(1, list1, list2, list3);
    sort(list3.begin(), list3.end());
    cout << list3.size() << endl;
    for (int v : list3) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}