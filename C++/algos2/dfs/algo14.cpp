#include <iostream>
#include <vector>

using namespace std;

const int maxn = 505;

int n;
int graph[maxn][maxn];
vector<int> list1;
vector<bool> list2(maxn, false);

bool dfs(int v, int parent) {
    list2[v] = true;
    list1.push_back(v);

    for (int i = 0; i < n; ++i) {
        if (graph[v][i]) {
            if (!list2[i]) {
                if (dfs(i, v)) {
                    return true;
                }
            } else if (i != parent) {
                int j = (int) list1.size() - 1;
                while (list1[j] != i) {
                    --j;
                }
                vector<int> list3(list1.begin() + j, list1.end());
                cout << "YES" << endl;
                cout << list3.size() << endl;
                for (int vr : list3) {
                    cout << vr + 1 << " ";
                }
                return true;
            }
        }
    }
    list1.pop_back();
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    bool otv = false;
    for (int i = 0; i < n; ++i) {
        if (!list2[i]) {
            if (dfs(i, -1)) {
                otv = true;
                break;
            }
        }
    }
    if (!otv) {
        cout << "NO" << endl;
    }

    return 0;
}