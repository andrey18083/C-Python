#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev;
    long long cap;
};

class dinic {
    int n;
    vector<vector<Edge>> graph;
    vector<int> level, ptr;
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const auto &e : graph[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long flow, int t) {
        if (u == t) return flow;
        while (ptr[u] < graph[u].size()) {
            Edge &e = graph[u][ptr[u]];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                long long pushed = dfs(e.to, min(flow, e.cap), t);
                if (pushed > 0) {
                    e.cap -= pushed;
                    graph[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
            ptr[u]++;
        }
        return 0;
    }

public:
    dinic(int n) : n(n) {
        graph.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void qwer(int u, int v, long long cap) {
        graph[u].push_back({v, (int)graph[v].size(), cap});
        graph[v].push_back({u, (int)graph[u].size() - 1, 0});
    }
    long long maxFlow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, LLONG_MAX, t)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    dinic dinic(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        dinic.qwer(u - 1, v - 1, cap);
    }
    cout << dinic.maxFlow(0, n - 1) << endl;
    return 0;
}
