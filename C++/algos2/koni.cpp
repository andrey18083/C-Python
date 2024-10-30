#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct Cell {
    int row, col;
    Cell(int r, int c): row(r), col(c) {}

    bool operator<(const Cell& other) const {
        if (row == other.row){
            return col<other.col;
        }
        return row<other.row;
    }
};

bool isv(int row, int col) {
    return row >=0 && col < 8 && col>=0 && row < 8;
}

int bfs(Cell start, Cell end) {
    int a[] = {-2,-2,-1,-1,1,1,2,2};
    int b[] = {-1,1,-2,2,-2,2,-1,1};
    map<Cell, int> dl;
    queue<Cell> q;
    dl[start] = 0;
    q.push(start);
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        if (cur.row == end.row && cur.col == end.col) {
            return dl[cur];
        }
        for (int i = 0; i<8; i++) {
            int nrow = cur.row + a[i];
            int ncol = cur.col + b[i];
            if (isv(nrow, ncol) && dl.find(Cell(nrow,ncol)) == dl.end()) {
                dl[Cell(nrow,ncol)] = dl[cur]+1;
                q.push(Cell(nrow,ncol));
            }
        }
    }
    return -1;
}

int main() {
    string red, green;
    cin >> red >> green;
    Cell redCell(red[1]-'1', red[0]-'a');
    Cell greenCell(green[1]-'1', green[0] - 'a');
    int dl = bfs(redCell, greenCell);
    if (dl == -1 || dl%2 == 1){
        cout << -1 << endl;
    } else {
        cout << dl/2 <<endl;
    }
    return 0;
}