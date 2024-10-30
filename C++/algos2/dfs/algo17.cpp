#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 500005;
vector<int> graph[maxn];
bool list1[maxn];
int dd[maxn];

void dfs(int nd, int dp) {
    list1[nd] = true;
    dd[nd] = dp;
    for (int neighbor : graph[nd]) {
        if (!list1[neighbor]) {
            dfs(neighbor, dp + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    int fn = 1;
    for (int i = 2; i <= N; ++i) {
        if (dd[i] > dd[fn]) {
            fn = i;
        }
    }
    fill(list1, list1 + maxn, false);
    fill(dd, dd + maxn, 0);
    dfs(fn, 0);
    int dm = *max_element(dd + 1, dd + N + 1);
    cout << dm << endl;
    return 0;
}