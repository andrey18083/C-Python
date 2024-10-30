#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const int maxn = 1201;
vector<int> graph[maxn];
int cl[maxn];
bool us[maxn];
pair<int, int> a[maxn];

double dl(const pair<int, int>& ds, const pair<int, int>& dr) {
    return sqrt((ds.first - dr.first) * (ds.first - dr.first) + (ds.second - dr.second) * (ds.second - dr.second));
}

bool dfs(int v, int c) {
    us[v] = true;
    cl[v] = c;
    for (int to : graph[v]) {
        if (!us[to]) {
            if (!dfs(to, 1 - c)) {
                return false;
            }
        } else if (cl[to] == cl[v]) {
            return false;
        }
    }
    return true;
}

bool pr(double mid, int n) {
    for (int i = 0; i < n; ++i) {
        graph[i].clear();
        us[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dl(a[i], a[j]) < mid) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!us[i] && !dfs(i, 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    double l = 0, r = 1e9;
    for (int it = 0; it < 100; ++it) {
        double mid = (l + r) / 2;
        if (pr(mid, n)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    pr(l, n);
    cout << fixed << setprecision(15) << l/2 << "\n";
    for (int i = 0; i < n; ++i) {
        cout << cl[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}