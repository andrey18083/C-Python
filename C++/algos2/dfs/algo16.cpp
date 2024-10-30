#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100001;
vector<int> list1[maxn];
int list2[maxn];

void dfs(int nd, int pr) {
    list2[nd] = 1;
    for (int ch : list1[nd]) {
        if (ch != pr) {
            dfs(ch, nd);
            list2[nd] += list2[ch];
        }
    }
}

int main() {
    int V;
    cin >> V;
    for (int i = 0; i < V - 1; ++i) {
        int u, v;
        cin >> u >> v;
        list1[u].push_back(v);
        list1[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= V; ++i) {
        cout << list2[i] << " ";
    }
    cout << endl;
    return 0;
}