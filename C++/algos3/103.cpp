#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<pair<int, int>> candles(n);
    for (int i = 0; i < n; i++) {
        cin >> candles[i].first >> candles[i].second;
    }

    set<int> parts; 
    vector<int> sides(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = 0; j < n; j++) {
            int position = a * candles[j].first + b * candles[j].second + c;
            if (position > 0) {
                sides[j]++; 
            } else {
                sides[j]--;
            }
        }
    }

    for (int side : sides) {
        parts.insert(side);
    }

    cout << (parts.size() < n ? "YES" : "NO") << endl;

    return 0;
}
