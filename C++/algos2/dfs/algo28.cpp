#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<int> list1, list2;
set<int, greater<int>> mHeap;

int main() {
    int n;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    list1.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int to;
            cin >> to;
            graph[i].push_back(to);
            list1[to]++;
        }
    }
    for (int i = 1; i < list1.size(); i++) {
        if (list1[i] == 0) {
            mHeap.insert(i);
        }
    }
    while (!mHeap.empty()) {
        int v = *mHeap.begin();
        mHeap.erase(mHeap.begin());
        list2.push_back(v);
        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            list1[to]--;
            if (list1[to] == 0) {
                mHeap.insert(to);
            }
        }
    }
    for (int i = list2.size() - 1; i >= 0; i--) {
        cout << list2[i] << " ";
    }
    cout << endl;
    return 0;
}