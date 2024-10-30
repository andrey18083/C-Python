#include <iostream>
#include <vector>
#include <set>


using namespace std;

using Graph = vector<vector<int>>;

class Algor {
public:
    Algor(int leftSize, int rightSize, const Graph &leftGraph) 
        : leftPartSize(leftSize), rightPartSize(rightSize), 
          leftGraph(leftGraph), rightPart(rightSize, -1) {}
    void poisk() {
        vector<bool> visited(leftPartSize, false);
        for (int i = 0; i < leftPartSize; ++i) {
            fill(visited.begin(), visited.end(), false);
            if (dfs(i, visited)) {
                fill(visited.begin(), visited.end(), false);
            }
        }
    }
    vector<int> getMatching() const {
        return rightPart;
    }

private:
    int leftPartSize, rightPartSize;
    const Graph &leftGraph;
    vector<int> rightPart;
    bool dfs(int from, vector<bool> &visited) {
        if (visited[from]) return false;
        visited[from] = true;
        for (int to : leftGraph[from]) {
            if (rightPart[to] == -1 || dfs(rightPart[to], visited)) {
                rightPart[to] = from;
                return true;
            }
        }
        return false;
    }
};

void dfs(int from, const Graph &leftGraph, const vector<int> &rightPart, 
                    vector<bool> &markedLeft, vector<bool> &markedRight) {
    if (markedLeft[from]) return;
    markedLeft[from] = true;
    for (int to : leftGraph[from]) {
        if (rightPart[to] != -1) {
            markedRight[to] = true;
            dfs(rightPart[to], leftGraph, rightPart, markedLeft, markedRight);
        }
    }
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int m, n;
        cin >> m >> n;
        Graph adjMatrix(m, vector<int>(n, true));
        for (int i = 0; i < m; ++i) {
            int girlIndex;
            cin >> girlIndex;
            while (girlIndex) {
                --girlIndex;
                adjMatrix[i][girlIndex] = false;
                cin >> girlIndex;
            }
        }
        Graph reversedLeftPart(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (adjMatrix[i][j])
                    reversedLeftPart[i].push_back(j);
        Algor kuhn(m, n, reversedLeftPart);
        kuhn.poisk();
        auto matching = kuhn.getMatching();
        set<int> free;
        for (int i = 0; i < m; ++i) free.insert(i);
        for (int leftVertex : matching)
            if (leftVertex != -1)
                free.erase(leftVertex);
        vector<bool> markLeft(m, false), markRight(n, false);
        for (int v : free)
            dfs(v, reversedLeftPart, matching, markLeft, markRight);
        vector<int> boysIndices, girlsIndices;
        for (int i = 0; i < m; ++i)
            if (markLeft[i])
                boysIndices.push_back(i + 1);
        for (int i = 0; i < n; ++i)
            if (!markRight[i])
                girlsIndices.push_back(i + 1);
        cout << boysIndices.size() + girlsIndices.size() << '\n';
        cout << boysIndices.size() << ' ' << girlsIndices.size() << '\n';
        for (int boyIndex : boysIndices)
            cout << boyIndex << ' ';
        cout << '\n';
        for (int girlIndex : girlsIndices)
            cout << girlIndex << ' ';
        cout << "\n";
    }
}