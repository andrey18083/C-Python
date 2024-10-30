#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int zero = 0;
const int usd = 1;

int n;
vector<vector<vector<int>> > list1;
struct Point {
    int x, y, z;
    Point() {}
    Point(int Z, int X, int Y) : z(Z), x(X), y(Y) {}
};
Point start;

void input() {
    cin >> n;
    list1 = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
    char c;
    for (int z = 0; z < n; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cin >> c;
                if (c == 'S')
                    start = Point(z, x, y);
                list1[z][x][y] = (c == '#' ? usd : zero);
            }
        }
    }
}

int moveX[6] = {0, 0, 0, 0, -1, 1};
int moveY[6] = {0, 0, -1, 1, 0, 0};
int moveZ[6] = {-1, 1, 0, 0, 0, 0};

bool isValid(int z, int x, int y) {
    return z >= 0 && x >= 0 && y >= 0 && z < n && x < n && y < n;
}

void BFS() {
    int sts = -1;
    queue<Point> q;
    int init = 2;
    list1[start.z][start.x][start.y] = init;
    q.push(start);
    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        if (cur.z == 0) {
            sts = list1[cur.z][cur.x][cur.y];
            break;
        }
        for (int i = 0; i < 6; i++) {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            int z = cur.z + moveZ[i];
            if (isValid(z, x, y) && list1[z][x][y] == zero) {
                list1[z][x][y] = list1[cur.z][cur.x][cur.y] + 1;
                q.push(Point(z, x, y));
            }
        }
    }
    cout << sts - init;
}

int main() {
    input();
    BFS();
    return 0;
}