#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int target = n+1;
    vector<pair<int, int>> pairs;

    for (int d = 1; d<=sqrt(target); ++d) {
        if (target % d == 0) {
            int a1 = d - 1;
            int b1 = (target/d) - 1;
            if (a1>=0 && b1>=0) {
                pairs.push_back({a1, b1});
            }
            if (d != target/d) {
                int a2 = (target/d)-1;
                int b2 = d-1;
                if (a2 >=0 && b2>=0) {
                    pairs.push_back({a2, b2});
                }
            }
        }
    }
    cout << pairs.size();
}