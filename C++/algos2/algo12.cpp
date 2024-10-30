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
    vector<vector<int>> otv;
    for (int i = 1; i <= N; ++i) {
        if (!list2[i]) {
            vector<int> list3;
            dfs(i, list1, list2, list3);
            sort(list3.begin(), list3.end());
            otv.push_back(list3);
        }
    }
    cout << otv.size() << endl;
    for (const auto& comp : otv) {
        cout << comp.size() << endl;
        for (int v : comp) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}