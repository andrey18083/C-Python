#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    int tw = 0;
    vector<int> bp(N);
    int mw = INT_MIN;
    for (int msk = 0; msk < (1 << N); ++msk) {
        int wgh = 0;
        vector<int> part(N);
        for (int i = 0; i < N; ++i) {
            part[i] = (msk & (1 << i)) ? 1 : 2;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (part[i] != part[j]) {
                    wgh += graph[i][j];
                }
            }
        }
        if (wgh > mw) {
            mw = wgh;
            tw = wgh;
            bp = part;
        }
    }
    cout << tw << endl;
    for (int i = 0; i < N; ++i) {
        cout << bp[i] << " ";
    }
    cout << endl;
    return 0;
}