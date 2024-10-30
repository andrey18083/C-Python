#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 1e9;

vector<int> bfs(const vector<vector<int>>& graph, int st, int end, vector<int>& prev) {
    int n = graph.size();
    vector<int> dl(n, maxn);
    queue<int> q;
    q.push(st);
    dl[st] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == end) {
            break;
        }
        for (int u = 0; u < n; ++u) {
            if (graph[v][u] && dl[u] == maxn) {
                dl[u] = dl[v] + 1;
                prev[u] = v;
                q.push(u);
            }
        }
    }
    vector<int> path;
    if (dl[end] != maxn) {
        for (int v = end; v != -1; v = prev[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
    }
    return path;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    int st, end;
    cin >> st >> end;
    st--;
    end--;
    vector<int> prev(n, -1);
    vector<int> otv = bfs(graph, st, end, prev);
    if (otv.empty()) {
        cout << -1 << endl;
    } else {
        cout << otv.size() - 1 << endl;
        if (otv.size() - 1 == 0) {
            return 0;
        } else {
            for (int v : otv) {
                cout << v + 1 << " "; 
            }
        }
    }
    return 0;
}