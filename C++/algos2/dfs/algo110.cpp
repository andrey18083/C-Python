#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000000000;

int N, M;
vector<vector<int>> list1;

bool crt(int x, int y, int tH) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if (list1[x][y] >= tH) return false;
    if (x == 0 || x == N - 1 || y == 0 || y == M - 1) return true;
    
    bool result = false;
    result |= crt(x+1, y, tH);
    result |= crt(x-1, y, tH);
    result |= crt(x, y+1, tH);
    result |= crt(x, y-1, tH);
    
    return result;
}

int mT() {
    int mtp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i > 0 && i < N - 1 && j > 0 && j < M - 1 && list1[i][j] != maxn) {
                if (!crt(i, j, list1[i][j])) {
                    ++mtp;
                }
            }
        }
    }
    return mtp;
}
int main() {
    cin >> N >> M;
    list1.resize(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> list1[i][j];
        }
    }
    cout << mT() << endl; 
    return 0;
}