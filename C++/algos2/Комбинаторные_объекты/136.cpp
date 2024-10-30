#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nm;
    for (int i = 1; i <= n; ++i) {
        nm.push_back(i);
    }
    k--;
    vector<int> otv;
    for (int i = 1; i <= n; ++i) {
        int f = fact(n - i);
        int me = k / f;
        otv.push_back(nm[me]);
        nm.erase(nm.begin() + me);
        k %= f;
    }
    for (int i = 0; i < n; ++i) {
        cout << otv[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}