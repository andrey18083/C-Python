#include <iostream>
#include <vector>
#include <set>

using namespace std;

int V, S, E;
vector<set<int>> graph;
vector<bool> selected;

bool canFormIndependentSet(int pos, int count) {
    if (count == S) return true;
    if (pos >= V) return false;

    bool canInclude = true;
    for (int neighbor : graph[pos]) {
        if (selected[neighbor]) {
            canInclude = false;
            break;
        }
    }

    selected[pos] = true;
    if (canInclude && canFormIndependentSet(pos + 1, count + 1)) return true;
    selected[pos] = false;
    
    return canFormIndependentSet(pos + 1, count);
}

int main() {
    cin >> V >> S >> E;
    graph.resize(V + 1);
    selected.resize(V + 1, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    if (canFormIndependentSet(1, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
