#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100005;

vector<int> list1[maxn];
vector<int> list2;
vector<bool> vis(maxn, false);
int p[maxn] = {0};

long long dfs(int k) {
    long long sum = p[k];
    vis[k] = true;
    for (int nt : list1[k]) {
        if (!vis[nt]) {
            sum += dfs(nt);
        }
    }
    list2.push_back(k);
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; 
            cin >> x;
            list1[i].push_back(x);
        }
    }
    long long otv = dfs(1);
    cout << otv << " " << list2.size() << endl;
    for (int i = 0; i < list2.size(); ++i) {
        cout << list2[i] << " ";
    }
    cout << endl;
    return 0;
}