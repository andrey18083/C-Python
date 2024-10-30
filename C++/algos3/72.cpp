#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

struct Edge {
    int from;
    int to;
    int flow;
    int capacity;
    Edge(int f, int t, int cap)
        : from(f), to(t), flow(0), capacity(cap) {}
    int residual() const { return capacity - flow; }
};

class Node {
public:
    int id;
    char value;
    vector<Edge*> edges;
    Node(int id_, char val = 0) : id(id_), value(val) {}
    ~Node() { for (auto edge : edges) delete edge; }
};

bool dfs(vector<Node*>& nodes, int src, int tgt, deque<Edge*>& path, vector<bool>& visited) {
    if (src == tgt) return true;
    if (visited[src]) return false;
    visited[src] = true;
    for (auto edge : nodes[src]->edges) {
        if (edge->residual() > 0) {
            if (dfs(nodes, edge->to, tgt, path, visited)) {
                path.push_front(edge);
                return true;
            }
        }
    }
    return false;
}

Edge* findd(Node* node, int target) {
    for (auto edge : node->edges) {
        if (edge->to == target) return edge;
    }
    return nullptr;
}

int qwer(vector<Node*>& nodes, int src, int tgt) {
    int maxFlow = 0;
    while (true) {
        deque<Edge*> path;
        vector<bool> visited(nodes.size(), false);
        if (!dfs(nodes, src, tgt, path, visited)) break;
        ++maxFlow;
        for (auto edge : path) {
            edge->flow += 1;
            Edge* reverseEdge = findd(nodes[edge->to], edge->from);
            if (reverseEdge) reverseEdge->flow -= 1;
        }
    }
    return maxFlow;
}

void chisto0(vector<Node*>& nodes) {
    for (auto node : nodes) delete node;
}

int main() {
    int n;
    string name;
    cin >> n >> name;
    size_t nameLength = name.size();
    vector<Node*> nodes(nameLength + n + 2);
    for (size_t i = 0; i < nameLength; ++i) {
        nodes[i] = new Node(i, name[i]);
    }
    unordered_map<char, vector<int>> charMapping;
    for (int i = 0; i < n; ++i) {
        int blockNodeIndex = nameLength + i;
        nodes[blockNodeIndex] = new Node(blockNodeIndex);
        string line;
        cin >> line;
        sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
        for (char chisto0 : line) {
            charMapping[chisto0].push_back(blockNodeIndex);
            for (size_t j = 0; j < nameLength; ++j) {
                if (name[j] == chisto0) {
                    nodes[j]->edges.push_back(new Edge(j, blockNodeIndex, 1));
                    nodes[blockNodeIndex]->edges.push_back(new Edge(blockNodeIndex, j, 0));
                }
            }
        }
    }
    int source = nameLength + n;
    int target = nameLength + n + 1;
    nodes[source] = new Node(source);
    nodes[target] = new Node(target);
    for (size_t i = 0; i < nameLength; ++i) {
        nodes[source]->edges.push_back(new Edge(source, i, 1));
        nodes[i]->edges.push_back(new Edge(i, source, 0));
    }
    for (size_t i = nameLength; i < nameLength + n; ++i) {
        nodes[i]->edges.push_back(new Edge(i, target, 1));
        nodes[target]->edges.push_back(new Edge(target, i, 0));
    }
    int maxFlow = qwer(nodes, source, target);
    if (maxFlow == nameLength) {
        cout << "YES" << endl;
        for (size_t i = 0; i < nameLength; ++i) {
            if (i > 0) cout << ' ';
            for (auto edge : nodes[i]->edges) {
                if (edge->flow == edge->capacity) {
                    cout << (edge->to - nameLength + 1);
                }
            }
        }
    } else {
        cout << "NO" << endl;
    }
    chisto0(nodes);
    return 0;
}
