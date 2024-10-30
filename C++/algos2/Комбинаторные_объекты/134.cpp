#include <iostream>
#include <vector>

using namespace std;

void ps(vector<int>& sq, int ss, int n, int k) {
    if (k == 0) {
        for (int num : sq) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    for (int i = ss; i <= n - k + 1; ++i) {
        sq.push_back(i);
        ps(sq, i + 1, n, k - 1);
        sq.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sq;
    ps(sq, 1, n, k);
    return 0;
}