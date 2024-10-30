#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& list1, vector<vector<bool>>& list2, int row, int col, int& rs) {
    if (row < 0 || row >= list1.size() || col < 0 || col >= list1[0].size() || list1[row][col] == '*' || list2[row][col]) {
        return;
    }
    list2[row][col] = true;
    ++rs;
    dfs(list1, list2, row + 1, col, rs);
    dfs(list1, list2, row - 1, col, rs);
    dfs(list1, list2, row, col + 1, rs);
    dfs(list1, list2, row, col - 1, rs);
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> list1(N, vector<char>(N));
    vector<vector<bool>> list2(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> list1[i][j];
        }
    }
    int str, stc;
    cin >> str >> stc;
    int rs = 0;
    dfs(list1, list2, str - 1, stc - 1, rs);
    cout << rs << endl;
    return 0;
}