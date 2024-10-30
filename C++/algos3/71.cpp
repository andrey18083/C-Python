#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 250;
vector<int> graph[MAXN + 1];
int matchA[MAXN + 1];
int matchB[MAXN + 1];
bool visited[MAXN + 1];
int n, m;

bool bpm(int u) {
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (matchB[v] == -1 || bpm(matchB[v])) {
                matchA[u] = v;
                matchB[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxxx() {
    memset(matchA, -1, sizeof(matchA));
    memset(matchB, -1, sizeof(matchB));
    int result = 0;
    for (int u = 1; u <= n; u++) {
        memset(visited, false, sizeof(visited));
        if (bpm(u)) {
            result++;
        }
    }
    return result;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v;
        while (cin >> v && v != 0) {
            graph[i].push_back(v);
        }
    }
    int maxMatch = maxxx();
    cout << maxMatch << endl;
    for (int i = 1; i <= n; i++) {
        if (matchA[i] != -1) {
            cout << i << " " << matchA[i] << endl;
        }
    }
    return 0;
}
