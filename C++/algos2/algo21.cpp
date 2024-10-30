#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 100001;

vector<int> graph[maxn];
vector<int> list1;
bool vs[maxn];
bool inpr[maxn];

bool dfs(int node) {
    vs[node] = true;
    inpr[node] = true;
    for (int sosed : graph[node]) {
        if (!vs[sosed]) {
            if (dfs(sosed)) {
                return true;
            }
        } else if (inpr[sosed]) {
            return true;
        }
    }

    list1.push_back(node);
    inpr[node] = false;
    return false;
}

bool tpsr(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!vs[i]) {
            if (dfs(i)) {
                return false; 
            }
        }
    }
    reverse(list1.begin(), list1.end());
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    if (tpsr(n)) {
        for (int node : list1) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}