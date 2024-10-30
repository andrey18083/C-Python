#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

struct Edge {
    int a, b, c, f;
    bool del = false;
    Edge(int a, int b, int c, int f) : a(a), b(b), c(c), f(f) {}
};

const int INF = 1e9;
int n, m, s, t;
std::vector<Edge> e;
std::vector<std::vector<int>> g;
std::vector<int> ptr, dist;

void addd(int a, int b, int c) {
    g[a].push_back(e.size()); e.emplace_back(a, b, c, 0);
    g[b].push_back(e.size()); e.emplace_back(b, a, 0, 0);
}

bool bfs() {
    memset(dist.data(), -1, dist.size() * sizeof(int));
    std::queue<int> q; q.push(s); dist[s] = 0;
    while (!q.empty() && dist[t] == -1) {
        int cur = q.front(); q.pop();
        for (int id : g[cur]) {
            int to = e[id].b;
            if (!e[id].del && dist[to] == -1 && e[id].f < e[id].c) {
                dist[to] = dist[cur] + 1;
                q.push(to);
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int cur, int flow) {
    if (flow == 0 || cur == t) return flow;
    for (; ptr[cur] < g[cur].size(); ++ptr[cur]) {
        int id = g[cur][ptr[cur]], to = e[id].b;
        if (e[id].del || dist[to] != dist[cur] + 1) continue;
        int delta = dfs(to, std::min(flow, e[id].c - e[id].f));
        if (delta) {
            e[id].f += delta; e[id ^ 1].f -= delta;
            return delta;
        }
    }
    return 0;
}

int dinic() {
    int total = 0;
    while (bfs()) {
        memset(ptr.data(), 0, n * sizeof(int));
        int pushed;
        while ((pushed = dfs(s, INF))) total += pushed;
    }
    return total;
}

void ress() {
    for (int i = 0; i < e.size(); i += 2) {
        if (e[i].del) e[i ^ 1].del = true;
        e[i].f = 0; e[i ^ 1].f = 0;
    }
}

void qwer(int cur, std::vector<int> &list) {
    if (cur == t) return;
    list.push_back(cur);
    for (int id : g[cur]) {
        int to = e[id].b;
        if (!e[id].del && e[id].f == 1) {
            e[id].del = true; qwer(to, list); return;
        }
    }
}


void vihod() {
    std::vector<int> path; qwer(s, path);
    path.push_back(t);
    for (int o : path) std::cout << o + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin >> n >> m >> s >> t; 
    s--; t--;
    g.resize(n); ptr.resize(n); dist.resize(n);
    for (int i = 0; i < m; i++) {
        int from, to; std::cin >> from >> to;
        if (from != to) addd(--from, --to, 1);
    }
    if (dinic() < 2) {
        std::cout << "NO";
    } else {
        std::cout << "YES\n"; 
        vihod(); 
        ress(); 
        dinic(); 
        vihod();
    }
}