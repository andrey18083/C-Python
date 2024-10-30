#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int N, px, py;
    cin >> N >> px >> py;
    vector<Point> polygon(N);
    for (int i = 0; i < N; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    Point p = {px, py};
    int count = 0;
    for (int i = 0; i < N; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % N];
        if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y) && (b.y - a.y) * (p.x - a.x) == (p.y - a.y) * (b.x - a.x)) {
            cout << "YES" << endl;
            return 0;
        }
        if ((a.y > p.y) != (b.y > p.y)) {
            double xIntersect = (double)(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x;
            if (p.x < xIntersect)
                count++;
        }
    }
    if (count % 2 == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
