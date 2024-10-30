#include <iostream>
#include <vector>

using namespace std;

bool cpa(int n, vector<int>& coins) {
    int count = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (n % coins[i] == 0) {
            count += (n / coins[i]) / 2;
        }
    }
    return count >= 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(m);
    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }
    if (cpa(n,coins)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}