#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000000000;

int bfs(vector<vector<int>>& graph, int st, int end) {
    int n = graph.size();
    vector<int> dl(n, maxn);
    queue<int> q;
    dl[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && dl[v] == maxn) {
                dl[v] = dl[u] + 1;
                q.push(v);
            }
        }
    }
    return (dl[end] == maxn) ? -1 : dl[end];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int st, end;
    cin >> st >> end;
    cout << bfs(graph, st - 1, end - 1) << endl;
    return 0;
}