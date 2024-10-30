#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight, index;
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

int find(vector<int>& par, int u){
    if (par[u] != u){
        par[u] = find(par, par[u]);
    }
    return par[u];
}

bool unite(vector<int>& par, vector<int>& rank, int u, int v){
    int rtU = find(par, u);
    int rtV = find(par, v);
    if (rtU != rtV){
        if (rank[rtU] < rank[rtV]){
            par[rtU] = rtV;
        } else if (rank[rtU] > rank[rtV]) {
            par[rtV] = rtU;
        } else {
            par[rtV] = rtU;
            rank[rtU]++;
        }
        return true;
    }
    return false;
}

vector<int> mins(int n, vector<Edge>&edges){
    sort(edges.begin(), edges.end());
    vector<int> par(n+1), rank(n+1, 0);
    for (int i = 1; i<=n; ++i){
        par[i] = i;
    }

    vector<int> otv;
    for (const Edge&edge : edges){
        if (unite(par, rank, edge.u, edge.v)) {
            otv.push_back(edge.index);
            if (otv.size() == n-1){
                break;
            }
        }
    }
    return otv;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i<m; ++i){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight   ;
        edges[i].index = i+1;
    }

    vector<int> otv = mins(n, edges);
    for (int edge_index : otv){
        cout << edge_index << " ";
    }
    cout << endl;
    return 0;
}