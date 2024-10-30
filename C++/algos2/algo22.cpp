#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Edge {
    ll v, num;
    bool is_bridge;
    Edge* bck;
    Edge(ll v, ll num) : v(v), num(num), is_bridge(false), bck(nullptr) {}
};

vector<vector<Edge*>> graph;
vector<ll> list1, list2, otv;
vector<bool> list3;

void dfs(ll v, ll dp = 0, Edge* p = nullptr) {
    list3[v] = true;
    list1[v] = list2[v] = dp;
    for (Edge* u : graph[v]) {
        if (!list3[u->v]) {
            dfs(u->v, dp + 1, u);
            list1[v] = min(list1[v], list1[u->v]);
        }
        else if (p && p->num != u->num) {
            list1[v] = min(list1[v], list2[u->v]);
        }
    }
    if (p && list1[v] == list2[v]) {
        p->is_bridge = true;
        p->bck->is_bridge = true;
        otv.push_back(p->num + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    graph.resize(n);
    list1.resize(n);
    list2.resize(n);
    list3.resize(n);
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--;
        u--;
        Edge* a = new Edge(u, i);
        Edge* b = new Edge(v, i);
        a->bck = b;
        b->bck = a;
        graph[v].push_back(a);
        graph[u].push_back(b);
    }
    for (ll i = 0; i < n; i++) {
        if (!list3[i]) {
            dfs(i);
        }
    }
    sort(otv.begin(), otv.end());
    cout << otv.size() << endl;
    for (auto i : otv) {
        cout << i << " ";
    }
    for (vector<Edge*>& ed : graph) {
        for (Edge* e : ed) {
            delete e;
        }
    }
    return 0;
}