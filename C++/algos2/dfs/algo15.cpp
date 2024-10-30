#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int v, const vector<vector<int>>& list1, vector<bool>& list2, vector<int>& otv) {
    list2[v] = true;
    otv.push_back(v);
    for (int u : list1[v]) {
        if (!list2[u]) {
            dfs(u, list1, list2, otv);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> list1(N + 1);
    for (int i = 0; i < M; ++i) {
        int to, from;
        cin >> from >> to;
        list1[to].push_back(from);
    }
    vector<bool> list2(N + 1, false);
    vector<int> qwer;
    dfs(1, list1, list2, qwer);
    sort(qwer.begin(), qwer.end());
    for (int v : qwer) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}